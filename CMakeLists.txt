cmake_minimum_required(VERSION 2.8)
project(container)

set(CMAKE_CXX_STANDARD 11)
include_directories(src)
add_subdirectory(src)

add_executable(container main.cpp)