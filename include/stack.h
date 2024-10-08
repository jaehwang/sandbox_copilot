#ifndef STACK_H
#define STACK_H

typedef struct _Stack Stack;

#ifdef __cplusplus
extern "C" {
#endif

void stack_push(Stack* stack, int* x);
int* stack_pop(Stack* stack);
int* stack_peek(Stack* stack);
int stack_empty(Stack* stack);
void stack_destroy(Stack* stack);
Stack* stack_create();

#ifdef __cplusplus
}
#endif

#endif // STACK_H


