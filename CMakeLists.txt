# Defines the minimum version of cmake required and what to do when condition is not met
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# Defines the project details
project(
    "setup-environment-Nick07242000"
    VERSION 0.0.2
    DESCRIPTION "Lab 0 - Set up Environment - FCEFyN - UNC - 2024"
    LANGUAGES C
)

# Sets a standard for the language version
set(CMAKE_C_STANDARD 17)

# Defines where the header files to include are located
include_directories(include)

# Defines where the source files to include are located
file(GLOB_RECURSE SOURCES "src/*.c")

# Defines name and source for executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Defines paths for libraries compilation
add_subdirectory(lib/libsta)
add_subdirectory(lib/libdyn)

# Defines paths for libraries headers
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)

# Link libraries
target_link_libraries(${PROJECT_NAME} static_library dynamic_library)

# Enable testing and add tests
include(CTest)

# Automatic external dependency download
include(FetchContent)

# Enable debug
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    Unity
    GIT_REPOSITORY "https://github.com/ThrowTheSwitch/Unity.git"
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND "" # Disables the update command
)

# Ensure named dependencies population
FetchContent_MakeAvailable(Unity)

# Defines test subdirectory
if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests)
endif()