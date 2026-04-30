/*Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri
interi. I numeri sono memorizzati in un vettore. Il valore N è inserito dall’utente, ma il
vettore può contenere al massimo 30 numeri. Terminato l’inserimento della sequenza di
numeri, l’utente inserisce un valore di riferimento. Il programma deve indicare se tale
valore di riferimento è contenuto nel vettore.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool ricerca_num(int *A, int n, int c){

    printf("inserisci un numero: "); 
    scanf("%d", &c); 

    int i = 0; 

    while (i<n){
        if (A[i]==c){
            return true;
        }

        i++; 
    }

    return false; 
}

int main(){
    int A[] = {1, 2, 4, 6, 3,43, 10, 94}; 
    int n = sizeof(A)/sizeof(A[0]); 
    int c = 10; 
    int result = ricerca_num(A, n, c); 

    printf("%d ", result); 

}