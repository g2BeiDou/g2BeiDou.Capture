//
// Created by GengG on 2022/11/29.
//
#include "../g2BeiDou.Capture/include/g2BeiDou.Capture.hpp"
#include <windowsx.h>
#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

TEST_CASE("Capture.Test CreateCapture WindowHandle", "[CreateCapture WindowHandle]") {
    g2::Capture *capture = g2::CreateCapture(g2::CaptureType::WindowHandle);
    REQUIRE(capture != nullptr);
    g2::CaptureOptions options;
    options.window_handle = (long long int)GetDesktopWindow();
    g2::SetWindowHandle(capture, options);
    //REQUIRE(g2::Initialize(capture));
    
    g2::DestroyCapture(capture);
    REQUIRE(capture == nullptr);
}

TEST_CASE("Capture.Test CreateCapture DirectShow", "[CreateCapture DirectShow]") {
    g2::Capture *capture = g2::CreateCapture(g2::CaptureType::DirectShow);
    REQUIRE(capture != nullptr);
    
    g2::DestroyCapture(capture);
    REQUIRE(capture == nullptr);
}

TEST_CASE("Capture.Test CreateCapture Video", "[CreateCapture Video]") {
    g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video);
    REQUIRE(capture != nullptr);
    
    g2::DestroyCapture(capture);
    REQUIRE(capture == nullptr);
}

TEST_CASE("Capture.Test CreateCapture Video2", "[CreateCapture Video2]") {
    g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video2);
    REQUIRE(capture != nullptr);
    
    g2::DestroyCapture(capture);
    REQUIRE(capture == nullptr);
}

TEST_CASE("Capture.Test CreateCapture Video3", "[CreateCapture Video3]") {
    g2::Capture *capture = g2::CreateCapture(g2::CaptureType::Video3);
    REQUIRE(capture != nullptr);
    
    g2::DestroyCapture(capture);
    REQUIRE(capture == nullptr);
}