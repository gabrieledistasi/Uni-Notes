/*generazione sequenza di numeri consecutivi
Un utente introduce da tastiera due numeri interi, chiamati INIZIO e LUN. Il programma
deve stampare una serie di numeri interi consecutivi. La serie inizia al valore INIZIO ed è
lunga LUN elementi.*/
#include <stdio.h>
#include <stdlib.h> 

int *seqgen(int INIZIO, int LUN){


    int j = INIZIO; 
    int i = 0; 
    int *sequence = malloc(sizeof(int)*LUN);

    while(i<=LUN){

        sequence[i]=j; 
        i++;
        j++; 
    }

    return sequence; 

}

int main(){
    int INIZIO = 7; 
    int LUN = 4 ;  

    int *result = seqgen(INIZIO, LUN); 
    printf("La serie è: \n"); 
    for(int k = 0; k < LUN; k++){
        printf("%d ", result[k]); 
    }
}