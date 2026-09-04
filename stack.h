#ifndef STACK_H
#define STACK_H

#include "vector.h"

typedef Vector Stack;

void stack_init(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(const Stack *s);
int is_empty(const Stack *s);
void print_stack(const Stack *s);
void stack_free(Stack *s);

#endif