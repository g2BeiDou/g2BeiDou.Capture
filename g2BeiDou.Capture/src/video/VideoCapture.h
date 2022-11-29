//
// Created by GengG on 2022/11/29.
//

#ifndef CAPTURE_VIDEOCAPTURE_H
#define CAPTURE_VIDEOCAPTURE_H
#include "Capture.h"
namespace g2
{
    class VideoCapture : public Capture
    {
    public:
        VideoCapture();
        ~VideoCapture() override;
    public:
        bool initialize() override;
        bool release() override;
        cv::Mat get() override;
        
        bool reinitialize(std::string path);
    
    public:
        std::string video_path;
    };
}

#endif //CAPTURE_VIDEOCAPTURE_H
