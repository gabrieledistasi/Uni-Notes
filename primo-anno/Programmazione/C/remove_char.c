/*
scrivere una funzione: char* remove_char(char *s, char c); 
restituisce una nuova stringa che è la stringa s senza i caratteri c.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* remove_char(char* s, char c){
    
    // trovo il numero di occorrenze di c
    int counter = 0; 

    for(int i = 0; s[i]!='\0'; i++ ){
        if(s[i]==c){
            counter++;
        }
    }

    char* res = malloc(sizeof(char)*(strlen(s)-counter+1)); 

    if(res == NULL){
        return NULL; 
    }

    int index = 0; 
    for(int i = 0; s[i]!= '\0'; i++){
        if(s[i]==c){
            continue; 
        }

        res[index] = s[i]; 
        index++; 
    }
    
    res[index] = '\0'; 

    return res; 


}