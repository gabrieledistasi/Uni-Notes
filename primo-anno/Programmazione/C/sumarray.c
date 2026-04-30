/*scrivere una funzione in C che dato un array in input restituisca la sua somma*/

#include <stdio.h>

int sumarray(int *a, int n){

    int somma = 0; 

    for(int i=0; i < n; i++){
        somma += a[i]; 
    }

    return somma; 
}

int main(){

    int a[] = {1, 2, 3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    
    printf("%d", sumarray(a, n)); 
}