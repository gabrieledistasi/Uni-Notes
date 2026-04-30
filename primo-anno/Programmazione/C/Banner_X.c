//si vuole stampare una X utilizzando una sequenza di n stringhe composte a spazi e *. 
//stampando le stringhe una sotto l'altra le * dovranno formare la x. 
//la funzione banner_X deve prendere in input n e i ritorni la stringa che compone la riga i della precedente rappresentazione

#include <stdio.h>
#include <stdlib.h>

char *banner_X(int n, int i){

    if (i < 0 || i >= n){
        return NULL; 
    }

    char *X = malloc((n+1)*sizeof(char));

    if (X == NULL){
        return NULL; 
    }

    

    for(int j = 0; j < n; j++){
        if(j == i || j == n-1-i){

            X[j] = '*'; 

        }
        
        else{

            X[j] = ' '; 

        }
    }


    X[n] = '\0'; 

    return X; 




}



int main(){
    int n = 5; 
    
    for(int i = 0; i < n; i++){
        char *riga = banner_X(n, i); 
        if(riga != NULL){
            printf("%s\n", riga); 
            free(riga); 
        }
    }


    return 0; 
}