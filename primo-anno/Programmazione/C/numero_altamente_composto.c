//scrivere una funzione che stampi i primi numeri altamente composti 
//un numero altamente composto è un numero naturale che ha più divisori di qualsiasi numero naturale precedente

// voglio i primi 20 numeri composti ----> il codice sta in un ciclo che arriva a 20, da lì termina
//come trovo un numero composto? calcolo tutti i divisori di quel numero, poi lo confronto con i divisori del precedente
//se il numero n ha più divisori di tutti i numeri precedenti, lo aggiungo ad una lista

#include <stdio.h>
#include <stdlib.h>

int *numericomposti(int x){
    int maxdivisori = 0; 
    int contHCN = 0; 
    int numero = 1; 

    while(contHCN<=20){
        for(int n = 1; n <= x; n++){

            if(n%x == 0){

            }

        }
        


    }
}