/*
Si scriva una funzione che, dato un array di n numeri interi, 
generi un nuovo array contenente le somme di tutte le coppie di elementi adiacenti. 
Nello specifico, il nuovo array avrà dimensione n - 1 e l'elemento in posizione i 
sarà pari alla somma degli elementi in posizione i e i+1 dell'array originale.
La funzione deve rispettare il seguente prototipo:
int *adjacent_sums(int *a, int n);
Dove a è l'array e n la sua dimensione. 
La funzione deve ritornare il puntatore all'array creato oppure 
NULL in caso di errore 
(ad esempio se la dimensione n è minore di 2 o in caso di fallimento dell'allocazione di memoria).*/


#include <stdio.h>
#include <stdlib.h>

int *adjacent_sums(int *a, int n){

    if(n<2){
        return NULL; 
    }

    int *res = malloc(sizeof(int)*(n-1)); 

    if(res == NULL){

        return NULL; 

    }

    int j = 0; 

    for(int i = 0; i < n-1; i++){

        res[i] = a[i]+a[i+1]; 

    }


    return res; 

}

/*complessità temporale: 
sia n la lunghezza dell'array a, il ciclo che calcola i nuovi elementi del vettore res
esegue n-1 iterazioni, dunque il costo temporale è O(n-1), approssimabile a O(n)

complessità spaziale: 
Con un'array di lunghezza n, è necessario allocare (n-1)*4 byte di memoria, e dunque costo O(n)  */