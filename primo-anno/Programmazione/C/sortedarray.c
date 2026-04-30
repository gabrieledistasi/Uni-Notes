//scrivere una funzione in C che dato un vettore, determina se esso è ordinato in modo crescente
#include <stdio.h>
#include <stdbool.h>

bool sortedarray(int *A, int sizeA){
    
    for(int i = 1; i < sizeA; i++){

        if(A[i-1]>A[i]){
            return false; 
        }
    }

    return true; 
}

int main(){
    int A[] = {1, 2, 4, 3 ,1, 34}; 
    int sizeA = sizeof(A)/sizeof(A[0]); 
    printf("%d", sortedarray(A, sizeA)); 

}