#include <stdio.h>
#include <stdlib.h> // Add this line to include the <stdlib.h> header file
#include <string.h> // Add this line to include the <string.h> header file
#include "queue.h"

static void stack_push(Stack* stack, int* x) {
    if (stack->top == stack->capacity) {
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[stack->top++] = *x;
}

static int* stack_pop(Stack* stack) {
    if (stack->top == 0) {
        return NULL;
    }
    --stack->top;
    return stack->data + stack->top;
}

static int* stack_peek(Stack* stack) {
    if (stack->top == 0) {
        return NULL;
    }
    return stack->data + (stack->top - 1);
}

static int stack_empty(Stack* stack) {
    return stack->top == 0;
}

static void stack_destroy(Stack* stack) {
    free(stack->data);
    free(stack);
}

static Stack* stack_create() {
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
