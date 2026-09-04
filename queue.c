#include <stdio.h>
#include <assert.h>
#include "queue.h"


int main(void) {
    Queue q;

    queue_init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    print_queue(&q);

    printf("front: %d\n", front(&q));
    printf("dequeued: %d\n", dequeue(&q));

    print_queue(&q);

    queue_free(&q);
    return 0;
}

void queue_init(Queue *q) {
    init(q);
}

void enqueue(Queue *q, int value) {
    push_back(q, value);
}

int dequeue(Queue *q) {
    // TODO:
    assert(q->size > 0);
    int ret = *q->data;
    erase(q,0);
    return ret;
}

int front(const Queue *q) {
    // TODO:
    assert(q->size > 0);
    return *q->data;
}

int is_empty(const Queue *q) {
    return q->size == 0;
}

void print_queue(const Queue *q) {
    print_vector(q);
}

void queue_free(Queue *q) {
    free_vector(q);
}