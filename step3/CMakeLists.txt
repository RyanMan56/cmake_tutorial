cmake_minimum_required(VERSION 3.10)

# Providing VERSION 1.0 will cause CMake to define Tutorial_VERSION_MAJOR and Tutorial_VERSION_MINOR variables for us
project(Tutorial VERSION 1.0)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Provide a single source of truth for compiler flags
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)

configure_file(tutorial_config.h.in tutorial_config.h)

add_subdirectory(MathFunctions)

add_executable(Tutorial tutorial.cpp)

# Link the libraries to our executable
target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")