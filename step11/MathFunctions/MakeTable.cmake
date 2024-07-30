add_executable(MakeTable MakeTable.cxx)

target_link_libraries(MakeTable PRIVATE tutorial_compiler_flags)

# Defines a command that will generate an output file if the
# file is missing or its dependencies have changed.

# CURRENT_BINARY_DIR is where cmake is building the project

# COMMAND MakeTable calls the MakeTable executable passing in 
# the desired filename of the new file

# DEPENDS MakeTable will re-run the command if the MakeTable executable changes
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
)