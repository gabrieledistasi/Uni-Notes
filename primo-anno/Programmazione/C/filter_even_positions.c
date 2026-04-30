/*
scrivere una funzione in che riceve un array a di n interi 
restituisce un nuovo array contenente solo gli elementi in posizione pari 
scrive in *m la dimensione del nuovo array
usa allocazione dinamica 
*/

#include <stdio.h>
#include <stdlib.h>

int *filter_even_positions(int *a, int n, int *m){

    int c = 0; 
    for(int i = 0; i < n; i++){
        if (i % 2 == 0){

            c++; 

        }
    }

    int *res = malloc(c*sizeof(int)); 

    if (res == NULL){
        printf("Errore durante l' allocazione di memoria"); 
        return NULL; 
    }

    int idx = 0; 
    for(int j = 0; j < n; j++){

        if(j % 2 == 0){

            res[idx] = a[j]; 
            idx++; 

        }
    }

    *m = c; 

    return res; 
}


int main(){
    int a[] = {10, 20, 30, 40, 50}; 
    int n = sizeof(a)/sizeof(int); 
    int m; 
    int *b = filter_even_positions(a, n, &m); 

    for(int k = 0; k < m; k++){
        printf("%d\n", b[k]); 
    }

    free(b); 

}

//complessità temporale: 2 for dipendenti da n per cui O(2n) ---> O(n)
//complessità spaziale: dipesa da malloc, caso peggiore circa O(n/2) ---> O(n)