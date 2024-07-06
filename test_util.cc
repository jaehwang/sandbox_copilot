#include <gtest/gtest.h>
#include "util.h"

// Test case for parse_args function
TEST(UtilTest, ParseArgsTest) {
    int argc = 3;
    char* argv[] = {"program", "-n", "10"};

    int n = 0;
    int err = parse_args(argc, argv, &n);

    // Check if the function returns 0 (no error)
    EXPECT_EQ(err, 0);

    // Check if the value of n is correctly parsed
    EXPECT_EQ(n, 10);
}


// Test case for parse_args function with missing argument
TEST(UtilTest, ParseArgsMissingTest) {
    int argc = 2;
    char* argv[] = {"program", "-n"};

    int n = 0;
    int err = parse_args(argc, argv, &n);

    // Check if the function returns non-zero (error)
    EXPECT_NE(err, 0);
}

// Test case for parse_args function with no arguments
TEST(UtilTest, ParseArgsNoArgsTest) {
    int argc = 1;
    char* argv[] = {"program"};

    int n = 0;
    int err = parse_args(argc, argv, &n);

    // Check if the function returns non-zero (error)
    EXPECT_NE(err, 0);
}

// Test case for is_prime function with a prime number
TEST(UtilTest, IsPrimeTest) {
    int num = 17;
    bool result = is_prime(num);

    // Check if the function correctly identifies the prime number
    EXPECT_TRUE(result);
}

// Test case for is_prime function with a non-prime number
TEST(UtilTest, IsNotPrimeTest) {
    int num = 15;
    bool result = is_prime(num);

    // Check if the function correctly identifies the non-prime number
    EXPECT_FALSE(result);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}