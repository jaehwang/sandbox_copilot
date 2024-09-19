# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.30)

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
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# Add the include directory
include_directories(include)

# Add the main executable
add_executable(sandbox 
    src/main.c 
    src/util.c 
    src/queue.c
)

# Add the test executable
add_executable(test_main 
    test/test_util.cc 
    test/test_queue.cc 
    src/util.c 
    src/queue.c
)

# Link the test executable with Google Test library
target_link_libraries(test_main gtest_main)

# Add a custom target to run the tests
add_custom_target(run_tests COMMAND test_main DEPENDS test_main)

enable_testing()
add_test(NAME test_main COMMAND test_main)
