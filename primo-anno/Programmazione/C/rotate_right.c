/*scrivere una funzione in C che, dato un array, la sua lunghezza n e un intero k
ruoti l'array di k posizioni*/

//a = {1, 2, 3, 4, 5}, n=5, k = 2
//a = {4, 5, 1, 2, 3}

#include <stdio.h>
#include <stdlib.h>


void rotate_right(int *a, int n, int k){

    int *tmp = malloc(sizeof(int)*n); 
    if (k>n){
        k = k%n; 
    }

    for(int i=0; i<n; i++){
        tmp[i] = a[(i+k)%n]; 
        
    }
    for(int i = 0; i<n; i++){
        a[i] = tmp[i]; 
    }

}

int main(){

    int a[]={1, 2, 3, 4, 5};
    int n = sizeof(a)/sizeof(int); 
    int k = 2; 
    rotate_right(a, n, k); 

    for(int j = 0; j<n; j++){
        printf("%d, ", a[j]); 
    }


}