//
// Created by GengG on 2022/11/29.
//

#ifndef G2BEIDOU_CAPTURE_BASECAPTURE_H
#define G2BEIDOU_CAPTURE_BASECAPTURE_H
#include "BaseCapture.include.hpp"
class BaseCapture
{
public:
    BaseCapture();
    ~BaseCapture();
    
    <typename T>
    virtual bool init() = 0;
    
    virtual bool start() = 0;
    
    virtual cv::Mat capture() = 0;
    
};


#endif //G2BEIDOU_CAPTURE_BASECAPTURE_H
