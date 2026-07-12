#include <stdio.h>
#include <stdlib.h>


int *verifica_sequenziale(int *a, int na, int *t, int nt){

    int j = 0; 

    int *p = malloc(sizeof(int)*nt); 
    if(p == NULL){
        return NULL; 
    }

    for(int i = 0; i < na; i++){

        if (j < nt && a[i] == t[j]){
            p[j] = i; 
            j++;
        }

    }
    
    if(j != nt){
        return NULL;
        }

    return p; 

}

int main(){

    int a[] = {33, 43, 35, 31, 50, 49, 35, 37, 50, 100}; 
    int na = sizeof(a)/sizeof(int); 
    int t[] = {43, 35, 31, 49, 35, 50}; 
    int nt = sizeof(t)/sizeof(int); 

    int *res = verifica_sequenziale(a, na, t, nt); 
    for(int i = 0; i < nt; i++){
        printf("%d \n", res[i]); 
    }

}

/*complessità temporale O(n), spaziale O(n)*/