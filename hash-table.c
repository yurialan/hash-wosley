#include <malloc.h>
#include <assert.h>
#include "hash-table.h"
#define SIZE 20

int hash_func(int key) {
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
hashentry *hashtable_create() 
{
	hashentry hashtable[SIZE];
	return hashtable;
}

/* 
* BOAS PRATICAS NA CRIACAO DA TABELA:
* Escolher numeros de potencia 2
* Escolher numeros primos
*/

void hashtable_insert(hashentry **table, hashentry *entry) 
{
	int index = hash_func(entry->key);
	if (table[index]->next == NULL) 
	{
		table[index]->next = entry;
		return;
	}
	table[index] = entry;
}

hashentry *hashtable_search(hashentry *table, int key) 
{
	int index = hash_func(key);
	if (table[index].key == key) 
	{
		return &table[index];
	}
	else if (table[index].next != NULL) 
	{
		hashentry *temp = &table[index];
		while (temp->next != NULL) 
		{
			if (temp->key == key) 
				return temp;

			temp = temp->next;
		}
	}
	return NULL;
}