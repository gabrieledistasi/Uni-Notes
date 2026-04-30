/*scrivere una funzione in C per calcolare la somma di un insieme di numeri inseriti da tastiera. il programma deve
- fermarsi quando viene inserito 0
-leggere una sequenza di numeri 
-visualizzare il valore corrispondente alla somma dei valori introdotti*/
#include <stdio.h>



int main(){

    int input; 
    int somma = 0; 

    while (input != 0){
        printf("inserisci un numero "); 
        scanf("%d", &input); 

        somma+=input;
        

    }

    printf("%d", somma); 
     
}
