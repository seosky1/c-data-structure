    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    #include "hash_table.h"

    #define TABLE_SIZE 10

    int main(void) {
        HashTable table;

        table_init(&table);

        put(&table, 1, 100);
        put(&table, 11, 200);  // 1과 같은 bucket: 충돌
        put(&table, 2, 300);

        print_table(&table);

        printf("key 11: %d\n", get(&table, 11));

        put(&table, 11, 999);  // 이미 있으면 value 갱신
        printf("key 11: %d\n", get(&table, 11));

        remove_key(&table, 1);
        print_table(&table);

        table_free(&table);
        return 0;
    }

    void table_init(HashTable *table) {
        // TODO
        for(int i=0;i<TABLE_SIZE;i++) {
            table->buckets[i] = NULL;
        }
    }

    int hash(int key) {
        // TODO
        return key % TABLE_SIZE;
    }

    void put(HashTable *table, int key, int value) {
        // TODO
        if (get(table,key) != -1) {
            int ind = hash(key);
            Node* cur = table->buckets[ind];
            while(cur!=NULL) {
                if(cur->key == key) {break;}
                cur = cur->next;
            }
            cur->value = value;
            return;
        }
        int ind = hash(key);
        Node* new = malloc(sizeof(Node));
        new->key = key;
        new->value = value;
        Node* cur = table->buckets[ind];
        new->next = cur;
        table->buckets[ind] = new;
    }

    int get(const HashTable *table, int key) {
        // TODO
        int ind = hash(key);
        Node* cur = table->buckets[ind];
        while(cur!=NULL) {
            if(cur->key == key) {return cur->value;}
            cur = cur->next;
        }
        return -1;
    }

    void remove_key(HashTable *table, int key) {
        // TODO
        int ind = hash(key);
        Node* cur = table->buckets[ind];
        Node* prev = NULL;
        while(cur!=NULL) {
            if(cur->key == key) {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        assert(cur!=NULL && "key not found");
        if(prev == NULL) {
            table->buckets[ind] = cur->next;
        } else {
            prev->next = cur->next;
        }
        free(cur);
    }

    void print_table(const HashTable *table) {
        // TODO
        for(int i=0;i<TABLE_SIZE;i++) {
            Node* cur = table->buckets[i];
            printf("buckets[%d] : ",i);
            while(cur!=NULL) {
                printf("(%d, %d)",cur->key,cur->value);
                cur = cur->next;
            }
            printf("\n");
        }
    }

    void table_free(HashTable *table) {
        // TODO
        for(int i=0;i<TABLE_SIZE;i++) {
            Node* cur = table->buckets[i];
            while(cur!=NULL) {
                Node* nxt = cur->next;
                free(cur);
                cur = nxt;
            }
            table->buckets[i] = NULL;
        }
    }