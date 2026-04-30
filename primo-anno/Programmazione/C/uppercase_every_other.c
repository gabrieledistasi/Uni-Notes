/*
scrivere una funzione che: 
riceve una stringa s 
rende maiuscolo ogni carattere in posizione dispari e modifichi la stringa in place 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void uppercase_every_other(char *s){

    int n = strlen(s); 

    for(int i = 0; i < n; i++ ){

        if (i%2 != 0){
            s[i] = toupper(s[i]); 
        }
        
    }
    
}


int main(){

    char s[] = "ciao"; 
    uppercase_every_other(s); 
    printf("%s\n", s); 


}


//complessità temporale O(n)
//complessità spaziale O(1)