/*scrivere una funzione in C che dato un array di numeri restituisca il massimo numero nell'array*/

#include <stdio.h>

int find_max(int *A, int n){
    int massimo = 0; 
    for(int i = 0; i < n; i++){
        if(massimo < A[i]){
            massimo = A[i]; 
        }
    }

    return massimo; 

}

int main(){
    int A[] = {1, 2, 3, 45, 1, 3, 5, 65, 1, 3, 5, 6, 98}; 
    int n = sizeof(A)/sizeof(A[0]); 

    int result = find_max(A, n); 
    printf("%d", result); 
}