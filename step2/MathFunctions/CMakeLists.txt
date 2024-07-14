add_library(MathFunctions MathFunctions.cxx)

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

  # When USE_MYMATH is ON, link SqrtLibrary to the MathFunctions Library
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()
