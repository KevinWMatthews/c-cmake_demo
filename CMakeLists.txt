cmake_minimum_required (VERSION 3.5)
project (Tutorial)

# The version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# configure a header file to pass CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files so that it will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

# add the executable
add_executable (Tutorial tutorial.c)
target_link_libraries (Tutorial m)
