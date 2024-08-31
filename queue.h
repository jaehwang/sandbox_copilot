#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int* data;
    int capacity;
    int top;
} Stack;

typedef struct {
    Stack* s1;
    Stack* s2;
} Queue;

#ifdef __cplusplus
extern "C" {
#endif

    void stack_push(Stack* stack, int* x);
    int* stack_pop(Stack* stack);
    int* stack_peek(Stack* stack);
    int stack_empty(Stack* stack);
    void stack_destroy(Stack* stack);
    Stack* stack_create();
    void push(Queue* queue, int* x);
    int* pop(Queue* queue);
    int* peek(Queue* queue);
    int empty(Queue* queue);
    Queue* queue_create();
    void queue_destroy(Queue* queue);

#ifdef __cplusplus
}
#endif
   
#endif // QUEUE_H