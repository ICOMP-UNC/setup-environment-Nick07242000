cmake_minimum_required (VERSION 3.25 FATAL_ERROR)

project(
    "dynamic_library"
    VERSION 0.0.1
    DESCRIPTION "Dynamic_library demo"
    LANGUAGES C
)

set (CMAKE_C_STANDARD 17)

include_directories (include)

file (GLOB_RECURSE SOURCES "src/*.c")

# Makes a library executable
# Used instead of add_executable
add_library (${PROJECT_NAME} SHARED ${SOURCES})