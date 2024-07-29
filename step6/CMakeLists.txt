cmake_minimum_required(VERSION 3.15)

# Providing VERSION 1.0 will cause CMake to define Tutorial_VERSION_MAJOR and Tutorial_VERSION_MINOR variables for us
project(Tutorial VERSION 1.0)

# Provide a single source of truth for compiler flags
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)

# Logical expression in the format "$<CONDITION:...>"
# If condition is false, "$<0:...>" results in an empty string
# If condition is true, "$<1:...>" results in the contents of ...
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# Add compile warning flags based on the compiler used from the flags above
target_compile_options(tutorial_compiler_flags INTERFACE 
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

configure_file(tutorial_config.h.in tutorial_config.h)

add_subdirectory(MathFunctions)

add_executable(Tutorial tutorial.cpp)

# Link the libraries to our executable
target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

# Install executable to the bin directory
install(TARGETS Tutorial DESTINATION bin)
# Install header file to the include directory
install(FILES "${PROJECT_BINARY_DIR}/tutorial_config.h" DESTINATION include)

include(CTest)

add_test(NAME Runs COMMAND Tutorial 25)

add_test(NAME Usage COMMAND Tutorial a)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Invalid input, expected a number but got \".*\"")

add_test(NAME StandardUse COMMAND Tutorial 4)
set_tests_properties(StandardUse PROPERTIES PASS_REGULAR_EXPRESSION "Computing sqrt of 4 to be 2")

function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()

do_test(Tutorial 4 "Computing sqrt of 4 to be 2")
do_test(Tutorial 9 "Computing sqrt of 9 to be 3")
do_test(Tutorial 5 "Computing sqrt of 5 to be 2.236")
do_test(Tutorial 7 "Computing sqrt of 7 to be 2.645")
do_test(Tutorial 25 "Computing sqrt of 25 to be 5")
do_test(Tutorial -25 "(-nan|nan|0)")
do_test(Tutorial 0.0001 "Computing sqrt of 0.0001 to be 0.01")
