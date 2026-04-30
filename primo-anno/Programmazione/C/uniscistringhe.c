/*scrivere una funzione in C che dati due array a e b int, crea un'array in cui vengono inseriti prima gli elementi 
di a e poi gli elementi di b*/
#include <stdio.h>
#include <stdlib.h>


int *f(int *a, int sizeA, int *b, int sizeB){

    int i = 0; 

    int *c = malloc(sizeof(int)*(sizeA+sizeB)); 
    if (c==NULL){
        return NULL;
    }


    for(int j=0; j < sizeA; j++){
        c[i] = a[j]; 
        i++; 
    }

    for(int j = 0; j < sizeB; j++){
        c[i] = b[j]; 
        i++; 
    }
    return c; 
}

int main(){
    int a[]={1, 2, 3, 4}; 
    int b[]={5, 6, 7, 8}; 
    int sizeA = sizeof(a)/sizeof(int); 
    int sizeB = sizeof(b)/sizeof(int); 

    int *c = f(a, sizeA,b, sizeB); 
    for (int i = 0; i<sizeA+sizeB; i++){
        printf("%d, ", c[i]); 
    }
    free(c); 
    return 0; 

}