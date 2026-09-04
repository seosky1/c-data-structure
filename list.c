#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main(void) {
    List list;

    list_init(&list);

    push_front(&list, 20);
    push_front(&list, 10);
    push_back(&list, 30);

    print_list(&list);

    printf("popped: %d\n", pop_front(&list));
    print_list(&list);

    list_free(&list);
    return 0;
}

void list_init(List *list) {
    // TODO
    list->head = NULL;
    list->size = 0;
}

void push_front(List *list, int value) {
    // TODO
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = list->head;
    list->head = new;
    list->size++;
}

void push_back(List *list, int value) {
    // TODO
    Node *new = malloc(sizeof(Node));
    new->data = value;
    if (list->size==0) {
        list->head = new;
        new->next = NULL;
        list->size++;
        return;
    }
    Node* cur = list->head;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new;
    new->next = NULL;
    list->size++;
}

int pop_front(List *list) {
    // TODO
    assert(list->size > 0);
    Node *old = list->head;
    int ret = old->data;
    list->head = old->next;
    free(old);
    list->size--;
    return ret;
}

int pop_back(List *list) {
    //TODO
    assert(list->size > 0);
    if(list->size == 1) {
        return pop_front(list);
    }
    Node *cur = list->head;
    Node *nxt = cur->next;
    while(nxt->next != NULL) {
        cur = nxt;
        nxt = nxt->next;
    }
    int ret = nxt->data;
    free(nxt);
    cur->next = NULL;
    list->size--;
    return ret;
}

void insert(List *list, int index, int value){
    assert(index >= 0 && index <= list->size);

    if(index == 0) {
        push_front(list,value);
        return;
    }

    Node* new = malloc(sizeof(Node));
    new->data = value;
    
    Node* cur = list->head;
    Node* prev = list->head;
    for(int i=0;i<index;i++) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = new;
    new->next = cur;
    list->size++;
}

int erase(List *list, int index) {
    assert(index >= 0 && index < list->size);
    
    if(index==0) {
        return pop_front(list);
    }

    Node* cur = list->head;
    Node* prev = list->head;
    for(int i=0;i<index;i++) {
        prev = cur;
        cur = cur->next;
    }
    prev->next=cur->next;
    int ret = cur->data;
    free(cur);
    list->size--;
    return ret;
}

void print_list(const List *list) {
    // TODO
    Node* cur = list->head;
    while(cur != NULL) {
        printf("%d ",cur->data);
        cur = cur->next;
    }  
    printf("\n");
}

void list_free(List *list) {
    // TODO
    Node *cur = list->head;

    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }

    list->head = NULL;
    list->size = 0;
}