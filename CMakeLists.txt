# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.28)

# Set the project name
project(sandbox)

# Genrate commit_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

# Add library
add_library(tool lib/queue.c lib/stack.c lib/util.c)

# Add the main executable
add_executable(sandbox 
    src/main.c 
)

target_link_libraries(sandbox tool)

# Add the test executable
add_executable(test_util
    test/test_util.cc 
)

add_executable(test_queue
    test/test_queue.cc 
)

add_executable(test_stack
    test/test_stack.cc 
)

# Link the test executable with Google Test library
target_link_libraries(test_util gtest_main tool)
target_link_libraries(test_queue gtest_main tool)
target_link_libraries(test_stack gtest_main tool)

# Add a custom target to run the tests
add_custom_target(run_tests COMMAND test_main DEPENDS test_main)

enable_testing()

add_test(NAME test_util COMMAND $<TARGET_FILE:test_util>)
add_test(NAME test_queue COMMAND $<TARGET_FILE:test_queue>)
add_test(NAME test_stack COMMAND $<TARGET_FILE:test_stack>)
