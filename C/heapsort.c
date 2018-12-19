#include   <stdio.h>
#include   <stdlib.h>
#include   "lista.c"

void refazHeap(Lista *lista, Indice raiz, Indice tamanho){
    Indice esq, dir, maior;
    //printf("heap(%d) - ", raiz);
    //imprimeLista(lista);
    Item *vec = lista->item;
    esq = 2*raiz + 1;
    dir = 2*raiz + 2;
    if(dir < tamanho)
        maior = vec[esq].chave > vec[dir].chave ? esq : dir;  
    else
        maior = esq;
    if(vec[maior].chave > vec[raiz].chave){
        trocarItem(&vec[maior], &vec[raiz]);
        if(maior < (tamanho/2))
            refazHeap(lista, maior, tamanho);
    }
}

void constroiHeap(Lista *lista){
    Indice i;
    for(i = lista->length/2 - 1; i >= 0; i--){
        //imprimeLista(lista);
        refazHeap(lista, i, lista->length);
    }
}

void HeapSort(Lista *lista){
    if(!lista) return;
    Indice i, n;
    Item *vec = lista->item;
    Item aux;
    n = lista->length - 1;
    constroiHeap(lista);
    for(i = 0; i < n-1; i++){
        aux = vec[0];
        vec[0] = vec[n-i];
        vec[n-i] = aux;
        refazHeap(lista, 0, n-i);
    }
    aux = vec[0];
    vec[0] = vec[n-i];
    vec[n-i] = aux;
}

int main(){
    int arr[] = {25, 40, 55, 20, 44, 35, 38, 99, 10, 65, 50};
    Lista *lista;
    lista = alocaLista(11);
    Item a;
    for(int i = 0; i < 11; i++){
        a.chave = arr[i];
        InsereItem(lista, a);
    }
    imprimeLista(lista);
    HeapSort(lista);
    imprimeLista(lista);
    liberaLista(&lista);
    return 0;
}
