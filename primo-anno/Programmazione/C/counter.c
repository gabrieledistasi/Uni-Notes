/*Un utente inserisce da tastiera una serie di numeri interi positivi, ed il termine della serie
è indicato dall’inserimento del valore -1. Il programma, al termine dell’inserimento, deve
stampare quanti numeri pari l’utente aveva inserito, e quanti numeri in totale sono stati
inseriti.*/

#include <stdio.h>


int main(){

    int j; 
    int numeri_pari;
    int n; 


    while(j != -1){

        printf("inserisci un numero: "); 
        scanf("" &j); 

        if(j%2 == 0){
            numeri_pari++; 

        }

        n = n++; 

        printf("numeri inseriti: %d", n); 
        printf("di cui numeri pari: %d", numeri_pari); 
    }
}