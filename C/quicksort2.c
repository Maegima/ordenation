#include   <stdio.h>
#include   <stdlib.h>
#include   "lista.c"

void Particao(Lista *lista, Indice b, Indice e){
    Indice i, j;
    Item aux, pivo;
    Item *vec = lista->item;
    pivo = vec[(e+b)/2];
    i = b;
    j = e - 1;
    do{
        while(pivo.chave > vec[i].chave) i++;
        while(pivo.chave < vec[j].chave) j--;
        if(i <= j){
            aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
            i++;
            j--;
        }
    }
    while(i <= j);
    if(b < j)Particao(lista, b, j+1);
    if(i < e)Particao(lista, i, e);
}

void QuickSort(Lista *lista){
    if(!lista) return;
    Particao(lista, 0, lista->length);
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
    QuickSort(lista);
    imprimeLista(lista);
    liberaLista(&lista);
    return 0;
}
