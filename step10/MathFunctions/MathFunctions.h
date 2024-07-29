#pragma once

// The below snippet is necessary for creating portable shared libraries that
// work across different platforms.
// It first checks if the code is being run on a windows platform.
// When compiling the DLL we will define the EXPORTING_MYMATH macro.
// If enabled, DECLSPEC will be set to __declspec(dllexport),
// otherwise it will be set to __declspec(dllimport).
// DECLSPEC is placed before the function declaration, and will ensure the
// function is imported/exported from the DLL.
// On non-windows platforms no special keywords are required,
// so DECLSPEC is defined as empty
#if defined(_WIN32)
#if defined(EXPORTING_MYMATH)
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif
#else // non windows
#define DECLSPEC
#endif

namespace mathfunctions
{
    double DECLSPEC sqrt(double x);
}
