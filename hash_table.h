#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *buckets[TABLE_SIZE];
} HashTable;

void table_init(HashTable *table);
int hash(int key);
void put(HashTable *table, int key, int value);
int get(const HashTable *table, int key);
void remove_key(HashTable *table, int key);
void print_table(const HashTable *table);
void table_free(HashTable *table);

#endif