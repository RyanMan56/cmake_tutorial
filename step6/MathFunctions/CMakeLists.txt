add_library(MathFunctions MathFunctions.cxx)

# Ensure anybody linking to MathFunctions needs to include the current source directory, while MathFunctions itself doesn't
# (CMAKE_CURRENT_SOURCE_DIR is the path to the source directory currently being processed)
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create a variable USE_MYMATH using option and set default to ON
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# If USE_MYMATH is ON, use target_compile_definitions to pass
# USE_MYMATH as a precompiled definition to our source files
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # When USE_MYMATH is ON, add a library for SqrtLibrary with
  # source mysqrt.cxx. Static libraries are a collection of object files
  # linked into an executable at compile time
  add_library(SqrtLibrary STATIC mysqrt.cxx)

  # Link SqrtLibrary to tutorial_compiler_flags
  target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)

  # When USE_MYMATH is ON, link SqrtLibrary to the MathFunctions Library
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()

# Link MathFunctions to tutorial_compiler_flags
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

# Set installable_libs to the libraries we want
set(installable_libs MathFunctions tutorial_compiler_flags)
if (TARGET SqrtLibrary)
  list(APPEND installable_libs SqrtLibrary)
endif()

# Install libraries to the lib directory
install(TARGETS ${installable_libs} DESTINATION lib)
# Install header file to the include directory
install(FILES MathFunctions.h DESTINATION include)