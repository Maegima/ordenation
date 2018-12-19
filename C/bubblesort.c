#include   <stdio.h>
#include   <stdlib.h>
#include   "lista.c"

void BubbleSort(Lista *lista){
    if(!lista) return;
    Item *vec = lista->item;
    Indice i = 0, j;
    int trocado = 1;
    while((i < lista->length) && trocado){
        trocado = 0;
        for(j = i+1; j < lista->length; j++){
            if(vec[j].chave < vec[i].chave){
                trocarItem(&vec[j], &vec[i]);
                trocado = 1;
            }
        }
        i++;
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
    BubbleSort(lista);
    imprimeLista(lista);
    liberaLista(&lista);
    return 0;
}
