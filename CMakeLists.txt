set (my_PROJECT Tutorial)

cmake_minimum_required (VERSION 3.5)
project (${my_PROJECT})

# I have this option conditionally included. Be sure to:
#     edit or remove the cache (either remove CMakeCache.txt or run make edit_cache).
#     appropriately edit the #cmakedefine in <my_PROJECT>Config.h.in.
option (USE_MYMATH "Use custom math library" ON)

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

if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory (MathFunctions)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
else ()
    set (EXTRA_LIBS ${EXTRA_LIBS} m)
endif ()

# add the executable
add_executable (${my_PROJECT} tutorial.c)
target_link_libraries (${my_PROJECT} ${EXTRA_LIBS})
