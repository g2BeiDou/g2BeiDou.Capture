//
// Created by GengG on 2022/11/29.
//

#include "VideoCapture.h"
namespace g2
{
    
    VideoCapture::VideoCapture() {
    
    }
    VideoCapture::~VideoCapture() {
    }
    bool VideoCapture::initialize() {
        return true;
    }
    bool VideoCapture::release()  {
        return true;
    }
    cv::Mat VideoCapture::get()  {
        return cv::Mat();
    }
    bool VideoCapture::reinitialize(std::string path) {
        video_path = path;
        return true;
    }
}