#include <stdio.h>

float seriearmonica(int n){

    float risultato = 0.0; 
    int i = n; 

    while(i!=0){

        risultato = risultato + 1.0f/i; 
        i--; 
    }

    return risultato; 
}

int main(){
    int n = 2; 
    printf("%f", seriearmonica(n)); 
}