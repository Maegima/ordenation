#include <stdlib.h>
#include <stdio.h>

typedef long Chave;
typedef struct Item{
    Chave chave;
} Item;

typedef int Indice;

typedef struct Lista{
    Item *item;
    Indice length, size;   
} Lista;

void trocarItem(Item *a, Item *b){
    Item c;
    c = *a;
    *a = *b;
    *b = c; 
}

Lista *alocaLista(int n){
    if(n < 1)
        return NULL;
    Lista *lista = malloc(sizeof(Lista));
    lista->item = malloc(sizeof(Item)*n);
    lista->size = n;
    lista->length = 0;
    return lista;
}

int InsereItem(Lista *lista, Item novo){
    if(lista->length < lista->size){
        lista->item[lista->length] = novo;
        lista->length++;
        return 1;
    }
    return 0;
}

void liberaLista(Lista **lista){
    if((*lista) != NULL){
        free((*lista)->item);
        free(*lista);
        (*lista) = NULL;
    }
}

void imprimeLista(Lista *lista){
    int i;
    if(lista->length > 0){
        printf("%lu", lista->item[0].chave);
        for(i = 1; i < lista->length; i++)
            printf(" %lu", lista->item[i].chave);
        printf("\n");
    }
}