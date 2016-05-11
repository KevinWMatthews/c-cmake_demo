set (my_PROJECT Tutorial)

cmake_minimum_required (VERSION 3.5)
project (${my_PROJECT})

# The version number
set (${my_PROJECT}_VERSION_MAJOR 1)
set (${my_PROJECT}_VERSION_MINOR 0)

# configure a header file to pass CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/${my_PROJECT}Config.h.in"
    "${PROJECT_BINARY_DIR}/${my_PROJECT}Config.h"
)

# add the binary tree to the search path for include files so that it will find <my_PROJECT>Config.h
include_directories ("${PROJECT_BINARY_DIR}")

# add the executable
add_executable (${my_PROJECT} tutorial.c)
target_link_libraries (${my_PROJECT} m)
