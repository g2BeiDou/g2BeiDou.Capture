//
// Created by GengG on 2022/11/29.
//

#include "DirectShowCapture.h"
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#include <d3d9.h>

extern "C"
{
HRESULT __stdcall CreateDirect3D11DeviceFromDXGIDevice(::IDXGIDevice* dxgiDevice,
                                                       ::IInspectable** graphicsDevice);
}
namespace g2
{
    DirectShowCapture::DirectShowCapture() {
        isBaseCapture = false;
    
    
        //winrt::check_hresult(D3D11CreateDevice(
        //        nullptr,
        //        D3D_DRIVER_TYPE_HARDWARE,
        //        nullptr,
        //        0,
        //        nullptr,
        //        0,
        //        D3D11_SDK_VERSION,
        //        d3d_device.put(),
        //        nullptr,
        //        d3d_context.put()));

        winrt::com_ptr<ID3D11Device> device;
        winrt::com_ptr<ID3D11DeviceContext> context;
        D3D_FEATURE_LEVEL feature_level = D3D_FEATURE_LEVEL_11_0;
        auto hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT, &feature_level, 1, D3D11_SDK_VERSION, device.put(), nullptr, context.put());
        if (DXGI_ERROR_UNSUPPORTED==hr) {
            hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT, &feature_level, 1, D3D11_SDK_VERSION, device.put(), nullptr, context.put());
        }
        winrt::check_hresult(hr);
        
        this->d3d_device = device;
        this->d3d_context = context;
        this->dxgi_device = device.as<IDXGIDevice>();
        winrt::com_ptr<::IInspectable> _device;

        winrt::check_hresult(CreateDirect3D11DeviceFromDXGIDevice(dxgi_device.get(), _device.put()));
        
        this->device = _device.as<winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>();
    }
    DirectShowCapture::~DirectShowCapture() {
        release();
    }
    bool DirectShowCapture::initialize() {
        if (isInitialized) {
            return true;
        }
        
        auto activation_factory = winrt::get_activation_factory<winrt::Windows::Graphics::Capture::GraphicsCaptureItem>();
        auto interop_factory = activation_factory.as<IGraphicsCaptureItemInterop>();
        interop_factory->CreateForWindow(window_handle, winrt::guid_of<ABI::Windows::Graphics::Capture::IGraphicsCaptureItem>(), reinterpret_cast<void**>(winrt::put_abi(this->item)));
        if(!item) {
            auto monitor_handle = MonitorFromWindow(window_handle, MONITOR_DEFAULTTONEAREST);
            interop_factory->CreateForMonitor(monitor_handle, winrt::guid_of<ABI::Windows::Graphics::Capture::IGraphicsCaptureItem>(), reinterpret_cast<void**>(winrt::put_abi(this->item)));
        }
        if (nullptr == this->item) {
            error = {1,"CreateForWindow failed"};
            return false;
        }
        
        frame_pool = winrt::Windows::Graphics::Capture::Direct3D11CaptureFramePool::Create(
            device,
            winrt::Windows::Graphics::DirectX::DirectXPixelFormat::B8G8R8A8UIntNormalized,
            2,
            item.Size());
        session = frame_pool.CreateCaptureSession(item);
        
        // 判断 WindowsSDK 版本大于等于 10.0.22000.0
#if (WINVER >= _WIN32_WINNT_WIN10_21H1)
        try
        {
            if (winrt::Windows::Foundation::Metadata::ApiInformation::IsPropertyPresent(L"Windows.Graphics.Capture.GraphicsCaptureSession", L"IsBorderRequired"))
            {
                winrt::Windows::Graphics::Capture::GraphicsCaptureAccess::
                RequestAccessAsync(
                        winrt::Windows::Graphics::Capture::
                        GraphicsCaptureAccessKind::Borderless)
                        .get();
                session.IsBorderRequired(false);
                session.IsCursorCaptureEnabled(false);
            }
        }
        catch (...)
        {
            // Ignore any errors
        }
#endif
        
        session.StartCapture();
        isInitialized = true;
        return true;
    }
    bool DirectShowCapture::release()  {
        if (!isInitialized) {
            return true;
        }
        session.Close();
        session = nullptr;
        frame_pool.Close();
        frame_pool = nullptr;
        item = nullptr;
        isInitialized = false;
        return true;
    }

#include <winrt/windows.graphics.directx.direct3d11.h>
    
    struct __declspec(uuid("A9B3D012-3DF2-4EE3-B8D1-8695F457D3C1"))
    IDirect3DDxgiInterfaceAccess : ::IUnknown
    {
        virtual HRESULT __stdcall GetInterface(GUID const& id, void** object) = 0;
    };
    
    cv::Mat DirectShowCapture::get()  {
        if (isInitialized==false) {
            initialize();
            error ={1, "DirectShowCapture is not initialized"};
            return {};
        }
        auto que = frame_pool.DispatcherQueue();
       
        frame = frame_pool.TryGetNextFrame();
        
        if (nullptr == frame) {
            error = {2, "DirectShowCapture get frame failed"};
            return {};
        }
        auto frame_size = frame.ContentSize();
        
        
        winrt::Windows::Foundation::IInspectable _surface = frame.Surface();
        auto access = _surface.as<IDirect3DDxgiInterfaceAccess>();
        winrt::com_ptr<ID3D11Texture2D> frameSurface;
        winrt::check_hresult(access->GetInterface(winrt::guid_of<ID3D11Texture2D>(), frameSurface.put_void()));
        //auto frameSurface = GetDXGIInterfaceFromObject<ID3D11Texture2D>(frame.Surface());
    
        D3D11_TEXTURE2D_DESC desc_type{ (unsigned int)frame_size.Width,(unsigned int)frame_size.Height,1,1,DXGI_FORMAT_B8G8R8A8_UNORM,{1,0},D3D11_USAGE_STAGING,0,D3D11_CPU_ACCESS_READ,0 };
        static ID3D11Texture2D* bufferTexture;
    
        d3d_device->CreateTexture2D(&desc_type, nullptr, &bufferTexture);
        d3d_context->CopyResource(bufferTexture, frameSurface.get());
        if (bufferTexture == nullptr) {
            error = {3, "DirectShowCapture get bufferTexture failed"};
            return {};
        }
        D3D11_MAPPED_SUBRESOURCE mappedTex;
        d3d_context->Map(bufferTexture, 0, D3D11_MAP_READ, 0, &mappedTex);
    
        auto data = mappedTex.pData;
        auto pitch = mappedTex.RowPitch;
    
        // 将画面转换为OpenCV的Mat
        auto frame_mat = cv::Mat(frame_size.Height, frame_size.Width, CV_8UC4, (void*)data, pitch);
        // 释放资源
        bufferTexture->Release();
        return frame_mat;
        /*
        winrt::com_ptr<ID3D11Texture2D> texture = frame.Surface().as<ID3D11Texture2D>();
        D3D11_TEXTURE2D_DESC desc;
        texture->GetDesc(&desc);
        D3D11_MAPPED_SUBRESOURCE mapped;
        //winrt::check_hresult(frame.Context().Map(texture.get(), 0, D3D11_MAP_READ, 0, &mapped));
        //cv::Mat mat(desc.Height, desc.Width, CV_8UC4, mapped.pData, mapped.RowPitch);
        //frame.Context().Unmap(texture.get(), 0);
        //return mat;
    */
    }
    
    bool DirectShowCapture::reinitialize(HWND handle) {
        if (window_handle == handle) {
            return true;
        }
        this->window_handle = handle;
        if (isInitialized)
        {
            release();
            return initialize();
        }else
        {
            return true;
        }
    }
}