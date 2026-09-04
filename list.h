#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} List;

void list_init(List *list);
void push_front(List *list, int value);
void push_back(List *list, int value);
int pop_front(List *list);
int pop_back(List *list);
void insert(List *list, int index, int value);
int erase(List *list, int index);
void print_list(const List *list);
void list_free(List *list);

#endif