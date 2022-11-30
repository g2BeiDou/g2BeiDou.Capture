cmake_minimum_required(VERSION 3.21.0)
project(g2BeiDou_Capture VERSION 0.1.0 LANGUAGES CXX)

#=============================================
# 设置是否编译动态库
#=============================================
option(编译动态库 "BUILD_SHARED_LIBS" ON)
#=============================================
# 设置是否静态链接opencv
#=============================================
option(静态链接opencv "STATIC_LINK_OPENCV" ON)
#=============================================
# 设置opencv路径
#=============================================
option(库opencv路径 "LIBRARY_OPENCV_DIR")
set(库opencv路径 "D:/opencv/opencv-4.5.3/build/x64/vc16/lib")

#=============================================
# 设置是否生成文档
#=============================================
option(生成文档 "BUILD_DOCUMENTATION" OFF)

#=============================================
# 设置是否启用 Enable_WindowHandle
#=============================================
option(启用WindowHandle "Enable_WindowHandle" ON)
# 启用宏 Def_Enable_WindowHandle
if(启用WindowHandle)
    add_compile_definitions(Def_Enable_WindowHandle)
endif()
#=============================================
# 设置是否启用 Enable_DirectShow
#=============================================
option(启用DirectShow "Enable_DirectShow" OFF)
# 启用宏 Def_Enable_DirectShow
if(启用DirectShow)
    add_compile_definitions(Def_Enable_DirectShow)
endif()
#=============================================
# 设置是否启用 Enable_Video
#=============================================
option(启用Video "Enable_Video" ON)
# 启用宏 Def_Enable_Video
if(启用Video)
    add_compile_definitions(Def_Enable_Video)
endif()
#=============================================
# 设置是否启用 Enable_Video
#=============================================
option(启用Video2 "Enable_Video2" OFF)
# 启用宏 Def_Enable_Video2
if(启用Video2)
    add_compile_definitions(Def_Enable_Video2)
endif()
#=============================================
# 设置是否启用 Enable_Video
#=============================================
option(启用Video3 "Enable_Video3" OFF)
# 启用宏 Def_Enable_Video3
if(启用Video3)
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


