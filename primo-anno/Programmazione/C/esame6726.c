/* Si scriva una funzione che, dato un array di n numeri in virgola mobile (double), 
generi un nuovo array contenente i valori
originali inframmezzati dalle medie aritmetiche delle coppie di elementi adiacenti.
La funzione deve rispettare il seguente prototipo
double *interleave_means(double *a, int n);
Dove a è l'array e n la sua dimensione. La funzione deve ritornare il puntatore all'array creato 
oppure NULL in caso di errore.*/

#include <stdio.h>
#include <stdlib.h>

double *interleave_means(double *a, int n){


    double *res = malloc(sizeof(double) * (2*n - 1));

    if(res == NULL){
        return NULL;
    }

    int j = 0; 

    for(int i = 0; i < n-1; i++){

        res[j] = a[i]; 
        j++; 

        res[j] = ((a[i]+a[i+1])/2); 
        j++; 

    }

    res[j] = a[n-1]; 

    return res; 

}

/*complessità temporale: 
sia n la dimensione della lista di partenza, i due cicli hanno costo n ciascuno, 
all'interno del ciclo tutte le operazioni hanno costo O(1), dunque la complessità temporale è O(n+n) = O(2n) approssimabile a O(n)

complessità spaziale:
data la lista di dimensione n, il programma alloca (2*n)-1 spazio riservato alla nuova lista, approssimabile a O()
*/

