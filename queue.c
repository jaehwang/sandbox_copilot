#include <stdio.h>
#include <stdlib.h> // Add this line to include the <stdlib.h> header file
#include <string.h> // Add this line to include the <string.h> header file
#include "queue.h"

void stack_push(Stack* stack, int* x) {
    if (stack->top == stack->capacity) {
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[stack->top++] = *x;
}

// stack_pop 함수를 구현해 주세요.
// 스택에서 가장 위에 있는 요소를 제거하고 반환합니다.
// 반환 값은 데이터에 대한 포인터입니다.
// 데이터가 없으면 NULL을 반환합니다.
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

Stack* stack_create() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int));
    stack->capacity = 1;
    stack->top = 0;
    return stack;
}

void enqueue(Queue* queue, int* x) {
    stack_push(queue->s1, x);
}

int* dequeue(Queue* queue) {
    if (stack_empty(queue->s2)) {
        while (!stack_empty(queue->s1)) {
            stack_push(queue->s2, stack_pop(queue->s1));
        }
    }
    return stack_pop(queue->s2);
}

int* peek(Queue* queue) {
    if (stack_empty(queue->s2)) {
        while (!stack_empty(queue->s1)) {
            stack_push(queue->s2, stack_pop(queue->s1));
        }
    }
    return stack_peek(queue->s2);
}

int empty(Queue* queue) {
    return stack_empty(queue->s1) && stack_empty(queue->s2);
}

Queue* queue_create() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->s1 = stack_create();
    queue->s2 = stack_create();
    return queue;
}

void queue_destroy(Queue* queue) {
    stack_destroy(queue->s1);
    stack_destroy(queue->s2);
    free(queue);
}
