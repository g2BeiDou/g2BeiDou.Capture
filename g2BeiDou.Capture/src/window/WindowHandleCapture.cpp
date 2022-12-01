//
// Created by GengG on 2022/11/29.
//

#include "WindowHandleCapture.h"
namespace g2
{
    WindowHandleCapture::WindowHandleCapture() {
    }
    WindowHandleCapture::~WindowHandleCapture() {
    }
    bool WindowHandleCapture::initialize() {
        return true;
    }
    bool WindowHandleCapture::release()  {
        return true;
    }
    cv::Mat WindowHandleCapture::get()  {
        if (window_handle == nullptr) {
            return cv::Mat();
        }
        RECT rect;
        GetWindowRect(window_handle, &rect);
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        HDC hWindowDC = GetDC(window_handle);
        HDC hCaptureDC = CreateCompatibleDC(hWindowDC);
        HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hWindowDC, width, height);
        SelectObject(hCaptureDC, hCaptureBitmap);
        BitBlt(hCaptureDC, 0, 0, width, height, hWindowDC, 0, 0, SRCCOPY | CAPTUREBLT);
        BITMAP bmp;
        GetObject(hCaptureBitmap, sizeof(BITMAP), &bmp);
        cv::Mat mat;
        mat.create(bmp.bmHeight, bmp.bmWidth, CV_8UC4);
        GetBitmapBits(hCaptureBitmap, bmp.bmWidthBytes * bmp.bmHeight, mat.data);
        DeleteObject(hCaptureBitmap);
        DeleteDC(hCaptureDC);
        ReleaseDC(window_handle, hWindowDC);
        return mat;
    }
    
    bool WindowHandleCapture::reinitialize(HWND handle) {
        window_handle = handle;
        return true;
    }
}