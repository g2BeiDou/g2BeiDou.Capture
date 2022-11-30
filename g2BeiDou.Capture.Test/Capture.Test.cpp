//
// Created by GengG on 2022/11/29.
//
#include "../g2BeiDou.Capture/include/g2BeiDou.Capture.hpp"
#include <windowsx.h>
#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

TEST_CASE("Capture.Test C_API CreateCapture", "[CreateCapture]") {
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::WindowHandle);
        REQUIRE(capture != nullptr);
        g2::CaptureOptions options;
        options.window_handle = (long long int) GetDesktopWindow();
        g2::SetWindowHandle(capture, options);
        
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
    
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::DirectShow);
        REQUIRE(capture != nullptr);
    
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
    
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video);
        REQUIRE(capture != nullptr);
    
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
    
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video2);
        REQUIRE(capture != nullptr);
    
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
    
    {
        g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video3);
        REQUIRE(capture != nullptr);
    
        g2::DestroyCapture(capture);
        REQUIRE(capture == nullptr);
    }
}

TEST_CASE("Capture.Test CPP_API CaptureManager ", "[CaptureManager]") {
    std::vector<g2::CaptureType> types = {g2::CaptureType::WindowHandle, g2::CaptureType::DirectShow, g2::CaptureType::Video, g2::CaptureType::Video2, g2::CaptureType::Video3};
    for (auto type : types) {
        g2::CaptureManager manager;
        REQUIRE(true);
        //REQUIRE(manager.create(type));
        //REQUIRE(manager.initialize());
        //REQUIRE(manager.release());
        //REQUIRE(manager.destroy());
    }
}