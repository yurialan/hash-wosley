#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include "hash-table.h"
#define SIZE 20

//DO YOU LIKE... MY CAR???

int hash_func(int key)
{
    return key % SIZE; //Tem que ver se pode usar esta função, Wasosley falou que n era pra usar mod...
}

// Construtor personalizado da Hash
hashentry *hashentry_create(int key, char *name, int age, char *city)
{
    hashentry* aux = (hashentry*)malloc(sizeof(hashentry));
    if (aux != NULL)
    {
        assert(aux);
        aux->key = key;
        aux->name = name;
        aux->age = age;
        aux->city = city;
        aux->next = NULL;
    }
    return aux;
}

// Construtor da Hash
hashentry **hashtable_create()
{
    int i;
    hashentry **hashtable;
    hashtable = malloc(sizeof(hashentry) * SIZE);
    assert(hashtable);
    for (i = 0; i < SIZE; i++)
    {
       hashtable[i] = NULL;
    }
    return hashtable;
}

/*
* BOAS PRATICAS NA CRIACAO DA TABELA:
* Escolher numeros de potencia 2
* Escolher numeros primos q
*/

void hashtable_insert(hashentry **table, hashentry *entry)
{
    int index = hash_func(entry->key);
    hashentry *search = hashtable_search(table, entry->key);
    if(search) //se já existir esta key na hash, return;
    {
        if (search->key == entry->key)
        {
            return;
        }
    }
    if (table[index] == NULL)
    {
        table[index] = entry;
        return;
    }
    else if (table[index]->next != NULL)
    {
        hashentry *aux = table[index]->next;
        while (aux->next)
        {
            aux = aux->next;
        }
        aux->next = entry;
    }
    else
    {
        table[index]->next = entry;
    }
}

hashentry *hashtable_search(hashentry **table, int key)
{
    int index = hash_func(key);
    if (table[index] == NULL)
    {
        return NULL;
    }
    if (table[index]->key == key)
    {
        return table[index];
    }
    else if (table[index]->next != NULL)
    {
        hashentry *temp = table[index];
        while (temp != NULL)
        {
            if (temp->key == key)
                return temp;
            temp = temp->next;
        }
    }
    return NULL;
}

void hashtable_print(hashentry **table) {
    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (table[i] == NULL)
        {
            printf("\n");
        }
        else
        {
            printf("%d",table[i]->key);
            if (table[i]->next != NULL)
            {
                hashentry *aux = table[i]->next;
                while(aux)
                {
                    printf("->%d",aux->key);
                    aux = aux->next;
                }
            }
            printf("\n");
        }
    }
}

