//
// Created by GengG on 2022/11/29.
//
#include "../g2BeiDou.Capture/include/g2BeiDou.Capture.hpp"
#include <windowsx.h>
#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

TEST_CASE("Capture.Test C_API CreateCapture", "[all type]") {

#ifdef Def_Enable_WindowHandle
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::WindowHandle);
        REQUIRE(capture != nullptr);
        g2::CaptureOptions options;
        options.window_handle = (long long int) GetDesktopWindow();
        g2::SetWindowHandle(capture, options);
        
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
#endif
#ifdef Def_Enable_DirectShow
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::DirectShow);
        REQUIRE(capture != nullptr);
    
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);

    }
#endif
#ifdef Def_Enable_Video
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video);
        REQUIRE(capture != nullptr);
    
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
#endif
#ifdef Def_Enable_Video2
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video2);
        REQUIRE(capture != nullptr);
    
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
#endif
#ifdef Def_Enable_Video3
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video3);
        REQUIRE(capture != nullptr);
    
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
#endif
}

TEST_CASE("Capture.Test C_API Get", "[all type]") {
#ifdef Def_Enable_WindowHandle
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::WindowHandle);
        REQUIRE(capture != nullptr);
        g2::CaptureOptions options;
        options.window_handle = (long long int) GetDesktopWindow();
        g2::SetWindowHandle(capture, options);
        
        auto image = g2::CaptureImage(capture);
        REQUIRE(image != nullptr);
        REQUIRE(image->cols > 0);
        REQUIRE(image->rows > 0);
        REQUIRE(image->channels() > 0);
        // get desktop size
        RECT desktop;
        const HWND hDesktop = GetDesktopWindow();
        GetWindowRect(hDesktop, &desktop);
        REQUIRE(image->cols == desktop.right);
        REQUIRE(image->rows == desktop.bottom);
        
        g2::ReleaseImage(image);
        REQUIRE(image == nullptr);
        
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
#endif
#ifdef Def_Enable_DirectShow
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::DirectShow);
        REQUIRE(capture != nullptr);
        g2::CaptureOptions options;
        options.direct_handle = (long long int) GetDesktopWindow();
        g2::SetDirectHandle(capture, options);
        
        auto image = g2::CaptureImage(capture);
        REQUIRE(image != nullptr);
        REQUIRE(image->cols > 0);
        REQUIRE(image->rows > 0);
        REQUIRE(image->channels() > 0);
        // get desktop size
        RECT desktop;
        const HWND hDesktop = GetDesktopWindow();
        GetWindowRect(hDesktop, &desktop);
        REQUIRE(image->cols == desktop.right);
        REQUIRE(image->rows == desktop.bottom);
        
        g2::ReleaseImage(image);
        REQUIRE(image == nullptr);
        
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
#endif
}

TEST_CASE("Capture.Test CPP_API CaptureManager", "[all type]") {
    std::vector<g2::CaptureType> types = {g2::CaptureType::WindowHandle, g2::CaptureType::DirectShow, g2::CaptureType::Video, g2::CaptureType::Video2, g2::CaptureType::Video3};
    for (auto type : types) {
        g2::CaptureManager manager;
        REQUIRE(true);
    }
}

TEST_CASE("Capture.Test CPP_API Get 0", "[WindowHandle]") {
    auto type = g2::CaptureType::WindowHandle;
    g2::CaptureManager manager(type);
    REQUIRE(true);
    
    g2::CaptureOptions options;
    options.window_handle = (long long int) GetDesktopWindow();
    manager.set(options);
    
    cv::Mat image = manager.get();
    REQUIRE(image.empty() == false);
    REQUIRE(image.cols > 0);
    REQUIRE(image.rows > 0);
    //std::cout << "width:" << width << " height:" << height << std::endl;
    // get desktop window size
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    REQUIRE(image.cols == desktop.right);
    REQUIRE(image.rows == desktop.bottom);
}

TEST_CASE("Capture.Test CPP_API Get 1", "[DirectShow]") {
        auto type = g2::CaptureType::DirectShow;
        g2::CaptureManager manager(type);
        REQUIRE(true);
    
        g2::CaptureOptions options;
        options.window_handle = (long long int) GetDesktopWindow();
        manager.set(options);
        
        for (int i=0;i<10;i++)        cv::Mat image = manager.get();
    
        cv::Mat image = manager.get();
        auto err=  manager.get_last_error();
        std::cout << "err:" << err.message << std::endl;
        
        
        //REQUIRE(err == g2::CaptureError::NoError);
        /*
        //REQUIRE(image.empty() == false);
        REQUIRE(image.cols > 0);
        REQUIRE(image.rows > 0);
        //std::cout << "width:" << width << " height:" << height << std::endl;
        // get desktop window size
        RECT desktop;
        const HWND hDesktop = GetDesktopWindow();
        GetWindowRect(hDesktop, &desktop);
        REQUIRE(image.cols == desktop.right);
        REQUIRE(image.rows == desktop.bottom);
         */
}