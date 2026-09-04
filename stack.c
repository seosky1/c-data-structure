#include <stdio.h>
#include <assert.h>
#include "stack.h"

void stack_init(Stack *s) {
    init(s);
}

void push(Stack *s, int value) {
    push_back(s, value);
}

int pop(Stack *s) {
    assert(s->size > 0);
    s->size--;
    return s->data[s->size];
}

int peek(const Stack *s) {
    // TODO
    assert(s->size > 0);
    return s->data[s->size-1];
}

int is_empty(const Stack *s) {
    return s->size == 0;
}

void print_stack(const Stack *s) {
    print_vector(s);
}

void stack_free(Stack *s) {
    free_vector(s);
}
/*
int main(void) {
    Stack s;

    stack_init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    print_stack(&s);

    printf("top: %d\n", peek(&s));
    printf("popped: %d\n", pop(&s));

    print_stack(&s);

    stack_free(&s);
    return 0;
}
*/