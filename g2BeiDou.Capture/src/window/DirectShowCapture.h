//
// Created by GengG on 2022/11/29.
//

#ifndef CAPTURE_DIRECTSHOWCAPTURE_H
#define CAPTURE_DIRECTSHOWCAPTURE_H
#include "Capture.h"
#include <windows.h>

#include <Unknwn.h>
#include <inspectable.h>

#include <winrt/Windows.Graphics.Capture.h>

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.System.h>
#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Composition.Desktop.h>
#include <winrt/Windows.UI.Popups.h>
#include <winrt/Windows.Graphics.Capture.h>
#include <winrt/windows.graphics.directx.h>
#include <winrt/windows.graphics.directx.direct3d11.h>
#include <winrt/windows.foundation.metadata.h>

#include <winrt/Windows.Graphics.Capture.h>
#include <windows.graphics.capture.interop.h>
#include <windows.graphics.capture.h>

#include <d3d11.h>
#include <dxgi.h>
#include <d3d11_4.h>

namespace g2
{
    class DirectShowCapture : public Capture
    {
        winrt::Windows::Graphics::Capture::GraphicsCaptureItem item{ nullptr };
        winrt::Windows::Graphics::Capture::GraphicsCaptureSession session{ nullptr };
        winrt::Windows::Graphics::Capture::Direct3D11CaptureFramePool frame_pool{ nullptr };
        winrt::Windows::Graphics::Capture::Direct3D11CaptureFrame frame{ nullptr };
        winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice device{ nullptr };
        winrt::com_ptr<ID3D11Texture2D> texture{ nullptr };
        winrt::com_ptr<ID3D11Device> d3d_device{ nullptr };
        winrt::com_ptr<IDXGIDevice> dxgi_device{ nullptr };
        
        winrt::com_ptr<ID3D11DeviceContext> d3d_context{ nullptr };
    public:
        DirectShowCapture();
        ~DirectShowCapture() override;
    public:
        bool initialize() override;
        bool release() override;
        cv::Mat get() override;
        
        bool reinitialize(HWND handle);
    
    public:
        HWND window_handle;
    };
}

#endif //CAPTURE_DIRECTSHOWCAPTURE_H
