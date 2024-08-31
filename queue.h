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
    void enqueue(Queue* queue, int* x);
    int* dequeue(Queue* queue);
    int* peek(Queue* queue);
    int empty(Queue* queue);
    Queue* queue_create();
    void queue_destroy(Queue* queue);

#ifdef __cplusplus
}
#endif
   
#endif // QUEUE_H
