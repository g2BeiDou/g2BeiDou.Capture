//
// Created by GengG on 2022/11/29.
//

#ifndef CAPTURE_WINDOWHANDLECAPTURE_H
#define CAPTURE_WINDOWHANDLECAPTURE_H
#include "Capture.h"
#include <windows.h>
namespace g2
{
    class WindowHandleCapture : public Capture
    {
    public:
        WindowHandleCapture();
        ~WindowHandleCapture() override;
    public:
        bool initialize() override;
        bool release() override;
        cv::Mat get() override;
        
        bool reinitialize(HWND handle);

    public:
        HWND window_handle;
    };
}

#endif //CAPTURE_WINDOWHANDLECAPTURE_H
