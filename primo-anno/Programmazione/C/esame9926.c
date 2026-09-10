/*
Scrivere una funzione in C che prenda in ingresso un numero intero positivo d e restituisca
una stringa allocata dinamicamente ( char* ) della dimensione esatta necessaria a contenere
la sua rappresentazione formattata con i separatori delle migliaia. 
La funzione deve rispettare il seguente prototipo char *prepara_buffer_migliaia(int d); 
Dove d è l'intero da cui ottenere la stringa. 
La funzione deve ritornare il puntatore alla stringa creata oppure NULL in caso di errore. 
Esempio Se d = 12345678 , la funzione prepara_buffer_migliaia(int d)
 deve restituire un array di 11 char .
*/

#include <stdio.h>
#include <stdlib.h>

char *prepara_buffer_migliaia(int d) {
    if (d < 0) {
        return NULL; // Gestione errore per valori negativi
    }

    // 1. Calcolo del numero di cifre
    int temp = d;
    int n_cifre = 0;
    do {
        n_cifre++;
        temp /= 10;
    } while (temp > 0);

    // 2. Calcolo dei separatori delle migliaia
    int n_separatori = (n_cifre - 1) / 3;

    // 3. Dimensione esatta: cifre + separatori + terminatore nullo '\0'
    int dimensione_totale = n_cifre + n_separatori + 1;

    // 4. Allocazione dinamica esatta della memoria
    char *buffer = (char *)malloc(dimensione_totale * sizeof(char));
    if (buffer == NULL) {
        return NULL; // Gestione errore di allocazione
    }

    // 5. Scrittura della stringa a partire dal fondo
    buffer[dimensione_totale - 1] = '\0';
    int pos = dimensione_totale - 2;
    int contatore_cifre = 0;

    do {
        // Aggiunge il separatore ogni 3 cifre elaborate
        if (contatore_cifre > 0 && contatore_cifre % 3 == 0) {
            buffer[pos--] = '.';
        }
        buffer[pos--] = (d % 10) + '0';
        d /= 10;
        contatore_cifre++;
    } while (d > 0);

    return buffer;
}

int main(){

    int d = 12345678; 

    char *sol = prepara_buffer_migliaia(d); 
    int n = sizeof(sol)/sizeof(char); 
    for(int i = 0; i <n; i++){
        printf("%c", sol[i]); 
    }



}