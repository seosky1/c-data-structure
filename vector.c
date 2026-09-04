#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vector.h"
/*
int main(void) {
    Vector v;

    init(&v);

    push_back(&v, 10);
    push_back(&v, 20);
    push_back(&v, 30);

    print_vector(&v);

    pop_back(&v);
    print_vector(&v);

    insert(&v, 1, 99);
    print_vector(&v);

    erase(&v, 1);
    print_vector(&v);

    printf("%d\n", get(&v, 1));

    set(&v, 1, 777);
    print_vector(&v);

    free_vector(&v);
    return 0;
}
*/
void init(Vector *v) {
    // TODO:
    v->size = 0;
    v->capacity = 2;
    v->data = malloc(sizeof(int)*v->capacity);
}

void push_back(Vector *v, int value) {
    // TODO:
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data,sizeof(int) * v->capacity);
    }
    v->data[v->size++] = value;
}

void pop_back(Vector *v) {
    // TODO:
    assert(v->size > 0);
    v->size--; 
}

void print_vector(const Vector *v) {
    // TODO:
    for(int i=0;i<v->size;i++) {
        printf("%d ",v->data[i]);
    }
    printf("\n");
}

void free_vector(Vector *v) {
    // TODO:
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void insert(Vector *v, int index, int value) {
    // TODO:
    assert(index >= 0 && index <= v->size);
    if(v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data,sizeof(int) * v->capacity);        
    }
    for (int i=v->size++;i>index;i--) {
        v->data[i] = v->data[i-1];
    }
    v->data[index] = value;
}

void erase(Vector *v, int index) {
    assert(index >= 0 && index < v->size);
    v->size--;
    for (int i=index;i<v->size;i++) {
        v->data[i] = v->data[i+1];
    }
}

int get(const Vector *v, int index) {
    assert(index >= 0 && index < v->size);
    return v->data[index];
}
void set(Vector *v, int index, int value) {
    assert(index >= 0 && index < v->size);
    v->data[index] = value;
}