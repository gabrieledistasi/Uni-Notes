/*scrivere una funzione in c che data una lista L e un indice p elimina l'elemento 
in posizione p di L*/

#include <stdio.h>
#include <stdlib.h>

int *removep(int *L, int sizeL,  int p){

    int *a = malloc(sizeof(int)*(sizeL-1)); 

    int i = 0; 

    while( i!=p){
        a[i]=L[i]; 
        i++; 

    }
    for(i=p+1; i < sizeL-1; i++){
        a[i-1] = L[i]; 
    }

    return a; 

}

int main(){

        int L[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10}; 
        int p = 10; 
        int sizeL = sizeof(L)/sizeof(int); 
        int *c = removep(L,sizeL, p); 

        for(int k = 0; k<sizeL; k++){
            printf("%d, ", c[k]); 
        }

}