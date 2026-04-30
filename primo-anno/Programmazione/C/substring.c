/*Scrivere una funzione in C che, data in input una stringa a, 
la sua lunghezza n e due interi i, j con i <= j, 
crea una nuova stringa che è la sottostringa di a compresa tra gli indici i e j. 
La funzione ritorna l'indirizzo in cui è memorizzata la stringa appena creata in questo modo.*/

#include <stdio.h>
#include <stdlib.h> 


char *substring(char *a, int i, int j){

    char *sub = malloc((j-i+2)*sizeof(char));  //allochiamo memoria per copiare nella nuova stringa a[i] ad a[j] 


    if(sub == NULL){
        printf("Errore di allocazione di memoria \n"); 
        return NULL; 
    }

    for(int k = i; k<=j; k ++ ){
        sub[k-i] = a[k]; 
    }

    sub[j-i+1] = '\0';  


    return sub; 

}