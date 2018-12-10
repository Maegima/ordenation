#include   <stdio.h>
#include   <stdlib.h>
#include   "lista.c"

void InsertionSort(Lista *lista){
    if(!lista) return;
    Item atual;
    Item *vec = lista->item;
    Indice i, j;
    for(i = 1; i < lista->length; i++){
        atual = vec[i];
        j = i-1;
        while((j >= 0) && (vec[j].chave > atual.chave)){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = atual;
    }
}

int main(){
    int arr[] = {3, 4, 9, 2, 5, 1, 8};
    Lista *lista;
    lista = alocaLista(7);
    Item a;
    for(int i = 0; i < 7; i++){
        a.chave = arr[i];
        InsereItem(lista, a);
    }
    imprimeLista(lista);
    InsertionSort(lista);
    imprimeLista(lista);
    liberaLista(&lista);
    return 0;
}
