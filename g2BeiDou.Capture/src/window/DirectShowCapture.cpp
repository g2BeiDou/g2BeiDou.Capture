//
// Created by GengG on 2022/11/29.
//

#include "DirectShowCapture.h"
g2::DirectShowCapture::DirectShowCapture() {}
namespace g2
{
    
    DirectShowCapture::~DirectShowCapture() {
    }
    bool DirectShowCapture::initialize() {
        return true;
    }
    bool DirectShowCapture::release()  {
        return true;
    }
    cv::Mat DirectShowCapture::get()  {
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
        cv::Mat mat = cv::Mat(bmp.bmHeight, bmp.bmWidth, CV_8UC4, bmp.bmBits);
        DeleteObject(hCaptureBitmap);
        DeleteDC(hCaptureDC);
        ReleaseDC(window_handle, hWindowDC);
        return mat;
    }
    bool DirectShowCapture::reinitialize(HWND handle) {
        window_handle = handle;
        return true;
    }
}