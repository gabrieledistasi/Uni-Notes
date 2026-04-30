/*scrivere una funzione in C che, dato un intero n restituisce in posizione 
0<=i<=n è contenuto il valore di i!*/
#include <stdio.h>
#include <stdlib.h>

int *erfattoriale(int n){
    int *a = malloc((n+1)*sizeof(int)); 
    int i = 1; 
    a[0]=1; 
    while (i<=n){
        a[i] = a[i-1]*i; 
        i++; 
    }

    return a; 
}

int main(){
    int n = 5; 
    int *fattoriale = erfattoriale(n); 

    for(int i=0; i<n+1; i++){
        printf("%d, ", fattoriale[i]); 
    }
    printf("\n"); 




}