/*scrivere una funzione con il seguente prototipo: 
int *intersezione(int *a, int n, int *b, int m, int *k)

a e b sono due array di interi rispettivamente di lunghezza n e m
la funzione deve restituire un nuovo array contenente gli elementi che sono presenti in entrambi gli array 
l'ordine deve essere quello dell'array a 
non devono esserci duplicati nel risultato 
*k deve contenere la dimensione del nuovo array
se non esistono elementi comuni, restituire null e scrivere 0 in *k */

#include <stdio.h>
#include <stdlib.h>

int *intersezione(int *a, int n, int *b, int m, int *k){

    int j = 0; 

    for(int i = 0; i < n; i++){

        for(int e = 0; e < m; e++){
            if (a[i]==b[e]){

                j++; 

            }
        }
    }

    int *res = malloc(sizeof(int)*j); 

    if(res==NULL){
        printf("Errore di allocazione di memoria"); 
        return NULL; 
    }

    int x = 0; 
    for(int i = 0; i < n; i++){

        for(int e = 0; e < m; e++){
            if (a[i]==b[e]){

                res[x] = a[i]; 

                x++; 

            }
        }
    }

    if(j == 0){
        *k = 0; 
        return NULL; 
    }

    *k = j; 

    return res; 

}


int main(){
    int a[]={1, 2, 3, 4, 5, 6,6,  7, 8, 9, 10}; 
    int n = sizeof(a)/sizeof(int); 

    int b[]={2, 4, 6, 8, 10}; 
    int m = sizeof(b)/sizeof(int); 

    int k; 

    int *c = intersezione(a, n, b, m, &k); 

    for(int i = 0; i < k; i++ ){
        printf("%d\n", c[i]); 
    }
}