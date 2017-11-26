//
// Created by yalan on 26/11/2017.
//

#include <malloc.h>
#include <assert.h>
#include "hash-table.h"
#define SIZE 20

int hashfunc(int key) {
    return key % SIZE; //Tem que ver se pode usar esta função, Wasosley falou que n era pra usar mod...
}

hashentry *hashentry_create(int key, char *name, int idade, char *cidade) {
    hashentry *x = malloc(sizeof(hashentry));
    assert(x);
    x->key = key;
    x->name = name;
    x->idade = idade;
    x->cidade = cidade;
    x->next = NULL;
    return x;
}

hashentry *hashtable_create() {
   hashentry hashtable[SIZE];
    return hashtable;
}

void hashtable_insert(hashentry **table, hashentry *entry) {
    int index = hashfunc(entry->key);
    if (table[index]->next == NULL) {
        table[index]->next = entry;
        return;
    }
    table[index] = entry;
}

hashentry *hashtable_search(hashentry *table, int key) {
    int index = hashfunc(key);
    if (table[index].key == key) {
        return &table[index];
    }
    else if (table[index].next != NULL) {
        hashentry *temp = &table[index];
        while (temp->next != NULL) {
            if (temp->key == key) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}


