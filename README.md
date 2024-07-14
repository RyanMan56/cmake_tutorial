# CMake Tutorial

Created by following [the official CMake tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

## How to build/run

1. cd into a project build directory, e.g. `cd step1_build`
2. run cmake to configure the project and generate a native build system, e.g. `cmake ../step1`
3. call that build system to compile/link the project, e.g. `cmake --build .`
4. run the program, e.g. `./Tutorial`

## Step-specific notes

These are some notes relevant for specific steps. Some notes may also apply to the steps that come after it

### step2

1. To build Tutorial with the USE_MYMATH flag disabled, run from the `step2_build` directory: `cmake ../step2 -DUSE_MYMATH=OFF`. You may have to delete your `step2_build/CMakeCache.txt` file
