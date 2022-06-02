cmake_minimum_required(VERSION 3.22)
project(demo)

set(CMAKE_CXX_STANDARD 14)

add_executable(demo main.cpp 头文件/class_diction.h 源文件/class_diction.cpp 头文件/mytool.h 源文件/mytool.cpp)

include_directories("头文件")