/*scrivere una funzione che restituisce il massimo elemento di un array*/
#include <stdio.h>

int max_array(int *A, int n){
    int max = A[0]; 
    for(int i = 1; i < n; i++){
        if (max < A[i]){

            max = A[i]; 
        }
    }

    return max; 
}

int main(){
    int A[] = {1, 2, 3, 4, 6}; 
    int n = sizeof(A)/sizeof(A[0]); 
    printf("%d", max_array(A, n) ); 
}