#include   <stdio.h>
#include   <stdlib.h>
#include   "lista.c"

void Particao(Lista *lista, Indice b, Indice e, Indice *i, Indice *j){
    Item pivo;
    Item *vec = lista->item;
    pivo = vec[(e+b)/2];
    e--;
    do{
        while(pivo.chave > vec[b].chave)b++;
        while(pivo.chave < vec[e].chave)e--;
        if(b <= e){
            trocarItem(&vec[b], &vec[e]);
            b++;
            e--;
        }
    }
    while(b <= e);
    (*i) = b;
    (*j) = e;
}

void Ordena(Lista *lista, Indice b, Indice e){
    Indice i, j;
    Particao(lista, b, e, &i, &j);
    if(b < j)Ordena(lista, b, j+1);
    if(i < e)Ordena(lista, i, e);
}

void QuickSort(Lista *lista){
    if(!lista) return;
    Ordena(lista, 0, lista->length);
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
