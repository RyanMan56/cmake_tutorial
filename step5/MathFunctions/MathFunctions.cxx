#include "MathFunctions.h"

#include <cmath>
#include <iostream>

// Wrap the mysqrt include in a precompiled ifdef based on USE_MYMATH
#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

namespace mathfunctions
{
    double sqrt(double x)
    {
// If USE_MYMATH is defined, use detail::mysqrt.
// Otherwise, use std::sqrt.
#ifdef USE_MYMATH
        std::cout << "Using detail::mysqrt\n";
        return detail::mysqrt(x);
#else
        std::cout << "Using std::sqrt\n";
        return std::sqrt(x);
#endif
    }
}
