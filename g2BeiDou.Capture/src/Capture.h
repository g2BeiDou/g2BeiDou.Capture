//
// Created by GengG on 2022/11/29.
//

#ifndef CAPTURE_CAPTURE_H
#define CAPTURE_CAPTURE_H
#include <opencv2/opencv.hpp>
namespace g2
{
    class Capture
    {
    public:
        Capture(){}
        virtual ~Capture() = default;
    public:
        virtual bool initialize() = 0;
        virtual bool release() = 0;
        virtual cv::Mat get() = 0;
    public:
        bool isInitialized = false;
        bool isBaseCapture = true;
    };
}

#endif //CAPTURE_CAPTURE_H
