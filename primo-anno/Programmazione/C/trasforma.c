/*scrivere una funzione: 
char *trasforma(const char *s)
che, data una stringa s restituisce una nuova stringa allocata dinamicamente così composta 
tutti i caratteri di s in maiuscolo 
seguiti da s al contrario
seguita dal numero di caratteri della stringa, come cifra*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *trasforma(const char *s){

    int n = strlen(s); 
    char *res = malloc((sizeof(char)*(2*n+2))); 
    int c = 0; 

    if (res==NULL){

        printf("Errore nell'allocazione di memoria"); 
        return NULL; 

    }

    for(int i = 0; i < n; i++ ){

        res[i] = toupper(s[i]); //stringa in maiuscolo
        res[n+i] = s[n-i-1]; //stringa al contrario
        c++; 

    }

    
    res[(2*n)]= n+'0'; 
    res[2*n+1] = '\0'; 

    

    return res; 

}

int main(){
    char *s = "ciao"; 
    char *b = trasforma(s); 
    printf("%s\n", b); 

}