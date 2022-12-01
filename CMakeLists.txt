cmake_minimum_required(VERSION 3.21.0)
project(g2BeiDou_Capture VERSION 0.1.0 LANGUAGES CXX)

#=============================================
# 设置是否编译动态库
#=============================================
option(Set_Build_Shared_libs "编译动态库" ON)
if(Set_Build_Shared_libs)
    set(BUILD_SHARED_LIBS ON)
else()
    set(BUILD_SHARED_LIBS OFF)
endif()
#=============================================
# 设置是否静态链接opencv
#=============================================
option(Set_Static_Link_Opencv "静态链接opencv" ON)
if(Set_Static_Link_Opencv)
    set(STATIC_LINK_OPENCV ON)
else()
    set(STATIC_LINK_OPENCV OFF)
endif()
#=============================================
# 设置opencv路径
#=============================================
option(库opencv路径 "LIBRARY_OPENCV_DIR")
set(LIBRARY_OPENCV_DIR "D:/opencv/opencv-4.5.3/build/x64/vc16/lib")

#=============================================
# 设置是否生成文档
#=============================================
option(生成文档 "BUILD_DOCUMENTATION" OFF)
set(BUILD_DOCUMENTATION)
#=============================================
# 设置是否启用编译Cpp接口
#=============================================
option(启用编译Cpp接口 "BUILD_CPP_INTERFACE" OFF)
set(BUILD_CPP_INTERFACE)
# 启用宏 Def_Build_CPP_INTERFACE
if(启用编译Cpp接口)
    add_compile_definitions(Def_Build_CPP_INTERFACE)
endif()
#=============================================
# 设置是否启用 Enable_WindowHandle
#=============================================
option(Enable_WindowHandle "启用WindowHandle" ON)
# 启用宏 Def_Enable_WindowHandle
if(Enable_WindowHandle)
    add_compile_definitions(Def_Enable_WindowHandle)
endif()
#=============================================
# 设置是否启用 Enable_DirectShow
#=============================================
option(Enable_DirectShow "启用DirectShow" ON)
# 启用宏 Def_Enable_DirectShow
if(Enable_DirectShow)
    add_compile_definitions(Def_Enable_DirectShow)
endif()
#=============================================
# 设置是否启用 Enable_Video
#=============================================
option(Enable_Video "启用Video" ON)
# 启用宏 Def_Enable_Video
if(Enable_Video)
    add_compile_definitions(Def_Enable_Video)
endif()
#=============================================
# 设置是否启用 Enable_Video
#=============================================
option(Enable_Video2 "启用Video2" OFF)
# 启用宏 Def_Enable_Video2
if(Enable_Video2)
    add_compile_definitions(Def_Enable_Video2)
endif()
#=============================================
# 设置是否启用 Enable_Video
#=============================================
option(Enable_Video3 "启用Video3" OFF)
# 启用宏 Def_Enable_Video3
if(Enable_Video3)
    add_compile_definitions(Def_Enable_Video3)
endif()


add_subdirectory(g2BeiDou.Capture)

enable_testing()

add_subdirectory(g2BeiDou.Capture.Test)


#=============================================
# 安装
#=============================================
# 安装头文件
install(DIRECTORY g2BeiDou.Capture/include/ DESTINATION include)
# 安装库文件
install(DIRECTORY g2BeiDou.Capture/lib/ DESTINATION lib)
# 安装动态库
install(DIRECTORY g2BeiDou.Capture/bin/ DESTINATION bin)

#=============================================
# 打包
#=============================================
if (打包)
    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
endif ()

#=============================================
# 生成文档
#=============================================
if (生成文档)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        message("Doxygen build started")
        add_custom_target( doc_doxygen ALL
                COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                COMMENT "Generating API documentation with Doxygen"
                VERBATIM )
    else(DOXYGEN_FOUND)
        message("Doxygen need to be installed to generate the doxygen documentation")
    endif(DOXYGEN_FOUND)
endif ()

#=============================================
message("\n-----------------------------")
message("编译动态库: ${BUILD_SHARED_LIBS}")
message("静态链接opencv: ${STATIC_LINK_OPENCV}")
message("库opencv路径: ${LIBRARY_OPENCV_DIR}")
message("生成文档: ${BUILD_DOCUMENTATION}")
message("启用编译Cpp接口: ${BUILD_CPP_INTERFACE}")
message("启用WindowHandle: ${Enable_WindowHandle}")
message("启用DirectShow: ${Enable_DirectShow}")
message("启用Video: ${Enable_Video}")
message("启用Video2: ${Enable_Video2}")
message("启用Video3: ${Enable_Video3}")
message("打包: ${BUILD_PACKAGE}")
message("-----------------------------\n")
#=============================================
