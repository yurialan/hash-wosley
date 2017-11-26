//
// Created by yalan on 26/11/2017.
//

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

typedef struct hashentry {
    int key;
    char *name;
    int idade;
    char *cidade;
    struct hashentry *next;
}hashentry;


int hashfunc(int key);

hashentry *hashentry_create(int key, char *name, int idade, char *cidade);

hashentry *hashtable_create(); //retorna um vetor de hashentry.
void hashtable_insert(hashentry **table, hashentry *entry);
hashentry *hashtable_search(hashentry *table, int key);

#endif
