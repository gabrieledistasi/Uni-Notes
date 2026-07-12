#include <stdio.h>
#include <stdlib.h>


void stampa_report(int* codici, float* potenze, int k){
    for(int i = 0; i < k; i++){
        printf("dispositivo: %d, potenza %f", codici[i], potenze[i]); 
    }
}


int main(){

    int n; 
    scanf("%d", &n); 

    int codici[n]; 
    float potenze[n]; 

    int k = 0; 

    for(int i=0; i<n; i++){
        int codice; 
        float potenza; 

        scanf("%d %f", &codice, &potenza); 

        if(potenza > 10.0){
            codici[k]=codice; 
            potenze[k]=potenza; 
            k++; 
        }

    }

    stampa_report(codici, potenze, k); 

    return 0; 


}

