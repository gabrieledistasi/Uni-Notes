/*si scriva una funzione col seguente prototipo
int *pos_dei_minori(int *a, int n, int k, int *m)
Dove a è un array di n interi. La funzione deve ritornare un nuovo array di interi contenente gli indici 
degli elementi in a che sono strettamente minori del parametro k. La funzione dovrà scrivere nella posizione 
di memoria indicata dal puntatore m la dimensione dell'array restituito.*/
#include <stdio.h>
#include <stdlib.h>

int *pos_dei_minori(int *a, int n, int k, int *m){

    //scorro l'array e quando incontro un valore < k lo aggiungo a un contatore j

    int j = 0; 

    for(int i = 0; i < n; i++){
        if(a[i]<k){
            j ++; 
        }
    }

    int *res = malloc(sizeof(int)*j); 

    //il contatore idx serve come indice per res

    int idx = 0; 

    /*for(int i = 0; i < n; i++){
        if(a[i] < k){

            res[idx] = i; 
            idx++; 

        }
    }*/

    for(int i = 0, idx = 0; i < n && idx != j; i++){
        if(a[i] < k){ 
            res[idx] = i; 
            idx++;
        }
    }

    *m = j; 
    return res; 
}


int main(){
    int a[] = {1, 3, 4, 5, 2, 4, 24}; 
    int n = sizeof(a)/sizeof(int); 
    int m; 
    int *b = pos_dei_minori(a, n, 4, &m); 

    for(int i = 0; i < m; i++){
        printf("%d\n", b[i]); 
    }
}