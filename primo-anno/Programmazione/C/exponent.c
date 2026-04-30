/*scrivere una funzione per l'elevazione a potenza di un numero*/

#include <stdio.h>

int expo(int B, int E){

    int risultato = 1; 
    int i = 0; 

    while(i < E){

        risultato = risultato * B; 
        
        i++; 
    }

    return risultato; 
}


int main(){
    int B = 2; 
    int E = 5; 

    printf("%d", expo(B, E)); 
}