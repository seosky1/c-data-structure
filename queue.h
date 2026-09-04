#ifndef QUEUE_H
#define QUEUE_H

#include "vector.h"

typedef Vector Queue;

void queue_init(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int front(const Queue *q);
int is_empty(const Queue *q);
void print_queue(const Queue *q);
void queue_free(Queue *q);

#endif