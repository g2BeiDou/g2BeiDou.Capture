//
// Created by GengG on 2022/11/29.
//

#ifndef CAPTURE_DIRECTSHOWCAPTURE_H
#define CAPTURE_DIRECTSHOWCAPTURE_H
#include "Capture.h"
#include <windows.h>
namespace g2
{
    class DirectShowCapture : public Capture
    {
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
