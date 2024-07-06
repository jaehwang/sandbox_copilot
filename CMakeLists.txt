# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(sandbox)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add the directory containing the util.h header file
include_directories(${CMAKE_SOURCE_DIR})

# Download and configure GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# Add the main executable
add_executable(sandbox main.c util.c)

# Add the test executable
add_executable(test_util test_util.cc util.c)

# Link the test executable with Google Test library
target_link_libraries(test_util gtest_main)

# Add a custom target to run the tests
add_custom_target(run_tests COMMAND test_util DEPENDS test_util)
