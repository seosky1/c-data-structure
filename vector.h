#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void init(Vector *v);
void push_back(Vector *v, int value);
void pop_back(Vector *v);
void print_vector(const Vector *v);
void free_vector(Vector *v);
void insert(Vector *v, int index, int value);
void erase(Vector *v, int index);
int get(const Vector *v, int index);
void set(Vector *v, int index, int value);

#endif