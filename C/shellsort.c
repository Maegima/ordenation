#include   <stdio.h>
#include   <stdlib.h>
#include   "lista.c"

void ShellSort(Lista *lista){
    if(!lista) return;
    Indice i, j, h;
    Item aux;
    Item *vec = lista->item;
    if(lista->length > 0){
        for(h = 1; h < lista->length; h = 3*h+1);

        while(h > 0){
            h = (h-1)/3;
            for(i = h; i < lista->size; i++){
                aux = vec[i];
                j = i;
                while( j >= h && vec[j-h].chave > aux.chave ){
                    //printf("   (%d)-(%d)-(%d) - ",i,j,h);imprimeLista(lista);
                    vec[j] = vec[j - h];
                    j -= h;
                }
                vec[j] = aux;
                //printf("res(%d)-(%d)-(%d) - ",i,j,h);imprimeLista(lista);
                //printf("\n");
            }
            //printf("--------------\n");
        }
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
    ShellSort(lista);
    imprimeLista(lista);
    liberaLista(&lista);
    return 0;
}