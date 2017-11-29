#include <stdio.h>
#include <stdlib.h>
#include "hash-table.h"

void menu()
{
    int op = -1;

    // Instancia a nova Hash
    hashentry** hash = hashtable_create();
    hashfile_fileinit();
    //person.cpf = 6121232212;

    //hashtable_insert(hash, person);

    //person.cpf = 6121232212;
    //hashtable_insert(hash, person);
    //hashtable_search(hash, 6121232212, &person);
    hashentry *person = hashentry_create(20,"Garcia",18,"OI");
    hashtable_insert(hash, person);
    hashentry *person2 = hashentry_create(222222,"AHA",129,"EA");
    hashtable_insert(hash, person2);

    hashentry *search = hashtable_search(hash, 20);
    if (search)
    {
        printf("Nome: %s\nIdade: %d\nCidade: %s\n\n", search->name, search->age, search->city);
    }
    while (op != 0)
    {
        printf("\n*MENU*\n\n[0] sair\n[1] inserir\n[2] excluir\n[3] atualizar\n[4] buscar\nSelecione: ");
        scanf("%d", &op);

        switch (op)
        {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                printf("\nERRO: Opcao Invalida!\n");
                break;
        }
    }
}

void main()
{
    printf("*TABELA HASH.wosley*\n\n");
    menu();
}