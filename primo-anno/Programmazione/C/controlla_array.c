/*Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri
interi. I numeri sono memorizzati in un vettore. Il valore N è inserito dall’utente, ma il
vettore può contenere al massimo 30 numeri. Terminato l’inserimento della sequenza di
numeri, il programma deve verificare se gli elementi del vettore sono tutti uguali tra loro.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 

bool controlla_array(int *A, int n){

    for(int i = 0; i < n; i++){

        if(A[i] != A[0]){
        return false; 
    }

    }


    return true; 



}


int main(){
    int A[] = {0,0,0,0,0,0,0,0,0 }; 
    int n = sizeof(A)/sizeof(A[0]); 

    printf("%d ", controlla_array(A, n)); 
}