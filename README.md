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

### step5

1. To demo this without messing with permissions create a new folder called `step5_install` but do not cd into it. Instead cd into `step5_build` and run `cmake --install . --prefix "../step5_install"`
2. To demo the tests cd into the `step5_build` directory, rebuild, and run `cmake -N` to list the tests that will run, and then run `ctest -VV` to run the tests with verbose output

### step6

1. To create a simple online test dashboard navigate to the build directory and run `ctest [-VV] -D Experimental` (not sure how well this works, there are some undocumented dependencies that are needed in the tutorial and I didn't care enough about this step to get them figured out and set up, as I'd potentially use a different testing solution for my own projects)

### step10

1. cd into the `step9_build` directory and build the project as usual. Then run `cpack` to build a binary distribution.
2. Run the installer in the build directory, then run the installed executable and verify it works

## Misc notes

1. The tutorial itself is quite poorly maintained, with some references to removing code that we never added in the first place. Seems like the tutorial has been updated over time, but not consistently
2. Tutorial was quite painful to follow unless you're looking at the provided source files. Otherwise there's no way of knowing where in a file a certain line should be added
