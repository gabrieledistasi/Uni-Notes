/*si scriva una funzione per calcolare la media aritmetica di una serie di numeri inseriti da tastiera. 
L'introduzione di un valore particolare pari a "0" indica il termine del caricamento dei dati*/
#include <stdio.h>
#include <stdbool.h>

double media() {

    int user; 
    int i = 0; 
    int sum = 0; 

    while (true) {

        printf("inserisci un numero (0 per terminare)\n"); 
        scanf("%d", &user); 

        if (user == 0) {
            if (i == 0) return 0;   // evita divisione per zero se il primo input è 0
            return (double)sum / i;
        }

        sum += user; 
        i++; 
    }
}

int main() {
    printf("%f\n", media()); 
}
