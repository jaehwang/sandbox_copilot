#include "queue.h"

// Test cases for queue.c
#include <gtest/gtest.h>
#include "queue.h"

class QueueTest : public ::testing::Test {
protected:
    Queue* queue;

    void SetUp() override {
        queue = queue_create();
    }

    void TearDown() override {
        queue_destroy(queue);
    }
};

TEST_F(QueueTest, PushAndPop) {
    int x = 1;
    enqueue(queue, &x);
    int* result = dequeue(queue);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(*result, x);
}

TEST_F(QueueTest, Peek) {
    int x = 1;
    enqueue(queue, &x);
    int* result = peek(queue);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(*result, x);
}

TEST_F(QueueTest, Empty) {
    EXPECT_TRUE(empty(queue));
    int x = 1;
    enqueue(queue, &x);
    EXPECT_FALSE(empty(queue));
    dequeue(queue);
    EXPECT_TRUE(empty(queue));
}

TEST_F(QueueTest, QueueCreateAndDestroy) {
    Queue* new_queue = queue_create();
    ASSERT_NE(new_queue, nullptr);
    EXPECT_TRUE(empty(new_queue));
    queue_destroy(new_queue);
}