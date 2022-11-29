cmake_minimum_required(VERSION 3.21.0)
project(Capture.Test)

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

add_executable(Capture.Test Capture.Test.cpp)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../bin)

target_link_libraries(Capture.Test PUBLIC g2BeiDou.Capture)

target_link_libraries(Capture.Test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
message(STATUS "OpenCV_LIBS: ${CMAKE_CURRENT_SOURCE_DIR}/../lib")


add_test(NAME Capture.Test COMMAND Capture.Test)
