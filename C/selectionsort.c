#include   <stdio.h>
#include   <stdlib.h>
#include   "lista.c"

void SelectionSort(Lista *lista){
    if(!lista) return;
    Item *vec = lista->item;
    Item aux;
    int i, j, menor;
    for(i = 0; i < lista->length; i++){
        menor = i;
        for(j = i+1; j < lista->length; j++){
            if(vec[menor].chave > vec[j].chave){
                menor = j;
            }
        }
        if(menor != i){
            aux = vec[menor];
            vec[menor] = vec[i];
            vec[i] = aux;
        }
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
    SelectionSort(lista);
    imprimeLista(lista);
    liberaLista(&lista);
    return 0;
}
