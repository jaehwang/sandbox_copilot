
#include <gtest/gtest.h>
#include "stack.h"

class StackTest : public ::testing::Test {
protected:
    Stack* stack;

    void SetUp() override {
        stack = stack_create();
    }

    void TearDown() override {
        stack_destroy(stack);
    }
};

TEST_F(StackTest, StackCreateAndDestroy) {
    ASSERT_NE(stack, nullptr);
    EXPECT_TRUE(stack_empty(stack));
}

TEST_F(StackTest, Push) {
    int value = 10;
    stack_push(stack, &value);
    EXPECT_FALSE(stack_empty(stack));
}

TEST_F(StackTest, Pop) {
    int value1 = 10;
    int value2 = 20;
    stack_push(stack, &value1);
    stack_push(stack, &value2);

    int* poppedValue = stack_pop(stack);
    ASSERT_NE(poppedValue, nullptr);
    EXPECT_EQ(*poppedValue, value2);

    poppedValue = stack_pop(stack);
    ASSERT_NE(poppedValue, nullptr);
    EXPECT_EQ(*poppedValue, value1);

    EXPECT_TRUE(stack_empty(stack));
}

TEST_F(StackTest, Peek) {
    int value1 = 10;
    int value2 = 20;
    stack_push(stack, &value1);
    stack_push(stack, &value2);

    int* peekedValue = stack_peek(stack);
    ASSERT_NE(peekedValue, nullptr);
    EXPECT_EQ(*peekedValue, value2);

    stack_pop(stack);
    peekedValue = stack_peek(stack);
    ASSERT_NE(peekedValue, nullptr);
    EXPECT_EQ(*peekedValue, value1);
}

TEST_F(StackTest, EmptyCheck) {
    EXPECT_TRUE(stack_empty(stack));
    int value = 10;
    stack_push(stack, &value);
    EXPECT_FALSE(stack_empty(stack));
    stack_pop(stack);
    EXPECT_TRUE(stack_empty(stack));
}
