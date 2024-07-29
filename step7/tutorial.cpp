
#include "tutorial_config.h"
#include "MathFunctions.h"

#include <iostream>
#include <string>
#include <stdexcept>

int main(int argc, char *argv[])
{
    double value{0};
    if (argc >= 2)
    {
        try
        {
            value = std::stod(argv[1]);
        }
        catch (const std::exception &e)
        {
            std::cout << "Invalid input, expected a number but got \"" << argv[1] << "\"\n";
            return 0;
        }
    }

    std::cout << "CMake tutorial project version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << '\n';
#if __cplusplus >= 202002L
    std::cout << "Compiled for C++20\n";
#endif
    std::cout << "Sqrt " << value << " = " << mathfunctions::sqrt(value) << '\n';
    return 0;
}