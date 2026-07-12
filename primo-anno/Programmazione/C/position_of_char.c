/*
si scriva una funzione 

int* position_of_char(char *s, char c, int* size)

dove: 
s è una stringa 
c è un carattere
size è un parametro di output
la funzione deve: individuare tutte le posizioni in cui compare il carattere c, allocare dinamicamente un array di interi
inserire nell'array gli indici delle occorrenze 
memorizzare in *size il numero di occorrenze
restituire il puntatore all'array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* position_of_char(char *s, char c, int* size){

    int counter = 0; 

    for(int i = 0; s[i]!='\0'; i++){
        if(s[i]==c){
            counter++; 
        }
    }

    int* res = malloc(sizeof(int)*counter); 
    if(res == NULL){
        return NULL; 
    }

    int index = 0;
    for(int i = 0; s[i]!='\0'; i++){
        if(s[i]==c){
            res[index] = i;
            index++;
        }    
    }   

    
    
    *size = counter;

    return res; 

}

