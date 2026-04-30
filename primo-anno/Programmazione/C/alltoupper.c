/*scrivere una funzione in C, denominata alltoupper, che converta in maiuscolo tutti i caratteri della stringa
passata come parametro.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *alltoupper(char *str){
    
    int len = strlen(str); 
    char *C = malloc((sizeof(char)*len)+1); 

    if (C== NULL){
        printf("Errore di allocazione di memoria"); 
    }
    
    

    for(int i = 0; i < len; i++ ){
        C[i] = toupper((unsigned char)str[i]); 
    }
    

    C[len] = '\0'; 
    return C; 
}


int main(){
    char str[] = "ciao";  
    char *result = alltoupper(str); 
    int len = strlen(str);

    printf("%s\n", result); 

    free(result); 
}