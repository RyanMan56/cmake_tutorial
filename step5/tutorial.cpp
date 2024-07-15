
#include "tutorial_config.h"
#include "MathFunctions.h"

#include <iostream>

int main()
{
    std::cout << "CMake tutorial project version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << '\n';
#if __cplusplus >= 202002L
    std::cout << "Compiled for C++20\n";
#endif
    std::cout << "Sqrt 10 = " << mathfunctions::sqrt(10.0) << '\n';
    return 0;
}