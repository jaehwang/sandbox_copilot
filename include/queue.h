#ifndef QUEUE_H
#define QUEUE_H

typedef struct _Queue Queue;

#ifdef __cplusplus
extern "C" {
#endif

void enqueue(Queue *queue, int *x);
int *dequeue(Queue *queue);
int *peek(Queue *queue);
int empty(Queue *queue);
Queue *queue_create();
void queue_destroy(Queue *queue);

#ifdef __cplusplus
}
#endif

#endif // QUEUE_H
