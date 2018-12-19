#include   <stdio.h>
#include   <stdlib.h>
#include   "lista.c"

void intercala(Lista *lista, Indice p, Indice q, Indice r){
    Indice i, j, k, len, len1;
    len = r - p;
    len1 = q - p;
    Item *aux = malloc(sizeof(Item)*len);
    Item *vec = lista->item;
    for(i = 0; i < len; i++){
        aux[i] = vec[i+p];
    }
    i = 0; j = len1; k = p;
    while(i < len1 && j < len){
        if(aux[i].chave < aux[j].chave){
            vec[k] = aux[i];
            i++;
        }
        else{
            vec[k] = aux[j];
            j++;
        }
        k++;
    }
    if(i < len1)
        for(;k < r; k++, i++)
            vec[k] = aux[i];
    else if(j < len)
        for(;k < r; k++, j++)
            vec[k] = aux[j];
    free(aux);
}

void Merge(Lista *lista, Indice i, Indice j){
    Indice k;
    if(i+1 < j){
        k = i+(j-i)/2;
        if(i+1 < k) Merge(lista, i, k);
        if(k+1 < j) Merge(lista, k, j);
        intercala(lista, i, k, j);
    }
}

void MergeSort(Lista *lista){
    if(!lista) return;
    Merge(lista, 0, lista->length);
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
    MergeSort(lista);
    imprimeLista(lista);
    liberaLista(&lista);
    return 0;
}
