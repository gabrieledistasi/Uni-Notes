/*scrivere una funzione in C che legga da tastiera una serie di numeri interi fino a quando la somma di tutti
i numeri introdotti fino a quel momento non supera il valore 1000. A quel punto, il programma stampa il valore
del prodotto di tutti i numeri inseriti */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
    int c; 
    int sum=0; 
    int molt=1;


    while(true){

        printf("inserisci un numero\n"); 
        scanf("%d", &c); 

        sum = c+sum; 
        molt = c*molt;

        if (sum >= 1000){

            printf("%d", molt);
            break; 

        }

        
        

    }
}