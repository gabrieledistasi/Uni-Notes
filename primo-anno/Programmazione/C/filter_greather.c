/*scrivere una funzione 
che restituisce un nuovo array contenente tutti gli elementi di a strettamente maggiori di x.

Il parametro size deve contenere la dimensione del nuovo array.

Esempio*/
#include <stdio.h>
#include <stdlib.h>

int* filter_greater(int *a, int n, int x, int* size){

    //conto quanti numeri sono maggiori di x

    int c= 0; 

    for(int j = 0; j < n; j++){
        if (a[j] > x){
            c++; 
        }
    }

    *size = c; 

    //gestione errore malloc 
    int* res = malloc(sizeof(int)*c); 
    if(res == NULL){
        printf("errore di allocazione di memoria"); 
        return NULL; 
    }

    int k = 0; 
    for(int i = 0; i < n; i++ ){
        if(a[i] > x){
            res[k] = a[i]; 
            k++; 
        }
    }

    return res; 
}   

int main(){

}