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

void MergeSort(Lista *lista, Indice i, Indice j){
    if(!lista) return;
    Indice k;
    /*printf("merge(%d-%d) - ", i, j);
    for(int b = i;b < j;b++){
        printf("%d ", lista->item[b].chave);
    }
    printf("\n");*/
    if(i+1 < j){
        k = i+(j-i)/2;
        if(i+1 < k) MergeSort(lista, i, k);
        if(k+1 < j) MergeSort(lista, k, j);
        /*printf("intercala(%d-%d) - ", i, j);
        for(int b = i;b < j;b++){
            printf("%d ", lista->item[b].chave);
        }
        printf("\n");*/
        intercala(lista, i, k, j);
        /*printf("intercalado(%d-%d) - ", i, j);
        for(int b = i;b < j;b++){
            printf("%d ", lista->item[b].chave);
        }
        printf("\n");*/
    }
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
    MergeSort(lista, 0, 11);
    imprimeLista(lista);
    liberaLista(&lista);
    return 0;
}
