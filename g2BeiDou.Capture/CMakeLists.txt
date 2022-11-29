cmake_minimum_required(VERSION 3.20.0)
project(g2BeiDou.Capture LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    message(STATUS "Configuring for MSVC")
    add_compile_options(
            $<$<CONFIG:>:/MT> #---------|
            $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
            $<$<CONFIG:Release>:/MT> #--|
    )
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../bin)
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECTORY: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

set(cmake_env__src_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(cmake_env__include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(g2BeiDou.Capture SHARED
        ${cmake_env__include_dir}/g2BeiDou.Capture.hpp
        )

target_include_directories(g2BeiDou.Capture
        PUBLIC
        "${cmake_env__include_dir}"
        PRIVATE
        "${cmake_env__src_dir}"
        )

set(OpenCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../3rdpart/opencv/x64/vc17/staticlib")
find_package(OpenCV REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../3rdpart/opencv)

target_include_directories(g2BeiDou.Capture PRIVATE ${OpenCV_INCLUDE_DIRS})
# 静态链接Opencv
target_link_libraries(g2BeiDou.Capture PRIVATE ${OpenCV_LIBS})


target_sources(g2BeiDou.Capture
        PRIVATE
        ${cmake_env__src_dir}/g2BeiDou.Capture.cpp
        ${cmake_env__src_dir}/Capture.h
        ${cmake_env__src_dir}/Capture.cpp
        ${cmake_env__src_dir}/window/WindowHandleCapture.h
        ${cmake_env__src_dir}/window/WindowHandleCapture.cpp
        ${cmake_env__src_dir}/window/DirectShowCapture.h
        ${cmake_env__src_dir}/window/DirectShowCapture.cpp
        ${cmake_env__src_dir}/video/VideoCapture.h
        ${cmake_env__src_dir}/video/VideoCapture.cpp


        PUBLIC
        ${cmake_env__include_dir}/g2BeiDou.Capture.hpp
        )

