#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct _Stack {
    int* data;
    int capacity;
    int top;
};

void stack_push(Stack* stack, int* x) {
    if (stack->top == stack->capacity) {
        stack->capacity *= 2;
        int* new_data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
        if (new_data == NULL) {
            // 메모리 할당 실패 처리
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        stack->data = new_data;
    }
    stack->data[stack->top++] = *x;
}

int* stack_pop(Stack* stack) {
    if (stack->top == 0) {
        return NULL;
    }
    --stack->top;
    return stack->data + stack->top;
}

int* stack_peek(Stack* stack) {
    if (stack->top == 0) {
        return NULL;
    }
    return stack->data + (stack->top - 1);
}

int stack_empty(Stack* stack) {
    return stack->top == 0;
}

void stack_destroy(Stack* stack) {
    free(stack->data);
    free(stack);
}

/**
 * @brief Creates a new stack and returns a pointer to it.
 *
 * This function creates a new stack and returns a pointer to it.
 * The stack is initially empty.
 *
 * @return A pointer to the newly created stack.
 */
Stack* stack_create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        // 메모리 할당 실패 처리
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->data = (int*)malloc(sizeof(int));
    if (stack->data == NULL) {
        // 메모리 할당 실패 처리
        fprintf(stderr, "Memory allocation failed\n");
        free(stack);
        exit(EXIT_FAILURE);
    }
    stack->capacity = 1;
    stack->top = 0;
    return stack;
}
