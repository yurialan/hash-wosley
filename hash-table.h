#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

typedef struct hashentry
{
    int key;
    char *name;
    int age;
    char *city;
    struct hashentry *next;
} hashentry;

int hash_func(int key);
hashentry *hashentry_create(int key, char *name, int idade, char *cidade);
hashentry **hashtable_create(); // retorna um vetor de Person.
hashentry *hashtable_search(hashentry **table, int key);
void hashtable_insert(hashentry **table, hashentry *entry);
void hashtable_print(hashentry **table);

#endif
