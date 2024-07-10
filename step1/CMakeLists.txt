cmake_minimum_required(VERSION 3.10)

# Providing VERSION 1.0 will cause CMake to define Tutorial_VERSION_MAJOR and Tutorial_VERSION_MINOR variables for us
project(Tutorial VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(tutorial_config.h.in tutorial_config.h)

add_executable(Tutorial tutorial.cpp)

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")