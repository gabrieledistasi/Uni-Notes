/*
scrivere una funzione con il seguente prototipo: 
int *greather_than(int *a, int n, int x, int *m) che: 
restituisce un nuovo array contenente tutti gli elementi di a maggiori di x 
scrive in m la dimensione dell'array
*/

#include <stdio.h>
#include <stdlib.h>

int *greater_than(int *a, int n, int x, int *m){

    int c = 0; 

    for(int i = 0; i < n; i++){

        if(a[i] > x){

            c++; 

        }
    }

    int *res = malloc(sizeof(int)*c); 
    int idx = 0; 

    for(int j = 0; j < n; j++){
        if(a[j] > x){

            res[idx] = a[j]; 
            idx++; 

        }
    }

    *m = c; 

    return res; 

}


int main(){
    int a[] = {1, 2, 4, 3, 1, 34, 54, 3, 43, 13, 43, 4}; 
    int n = sizeof(a)/sizeof(int); 
    int x = 10; 
    int m; 
    int *b = greather_than(a, n, x, &m); 
    for(int k = 0; k < m; k++){
        printf("%d\n", b[k]); 
    }

    free(b); 

}