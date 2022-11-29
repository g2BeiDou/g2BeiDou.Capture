cmake_minimum_required(VERSION 3.21.0)
project(g2BeiDou_Capture VERSION 0.1.0 LANGUAGES CXX)

# 设置是否启用 Enable_WindowHandle
option(Enable_WindowHandle "启用Window" ON)
# 启用宏 Def_Enable_WindowHandle
if(Enable_WindowHandle)
    add_compile_definitions(Def_Enable_WindowHandle)
endif()
# 设置是否启用 Enable_DirectShow
option(Enable_DirectShow "启用DirectShow" OFF)
# 启用宏 Def_Enable_DirectShow
if(Enable_DirectShow)
    add_compile_definitions(Def_Enable_DirectShow)
endif()
# 设置是否启用 Enable_Video
option(Enable_Video "启用Video" ON)
# 启用宏 Def_Enable_Video
if(Enable_Video)
    add_compile_definitions(Def_Enable_Video)
endif()
# 设置是否启用 Enable_Video
option(Enable_Video2 "启用Video2" OFF)
# 启用宏 Def_Enable_Video2
if(Enable_Video2)
    add_compile_definitions(Def_Enable_Video2)
endif()
# 设置是否启用 Enable_Video
option(Enable_Video3 "启用Video3" OFF)
# 启用宏 Def_Enable_Video3
if(Enable_Video3)
    add_compile_definitions(Def_Enable_Video3)
endif()


add_subdirectory(g2BeiDou.Capture)

enable_testing()

add_subdirectory(g2BeiDou.Capture.Test)

