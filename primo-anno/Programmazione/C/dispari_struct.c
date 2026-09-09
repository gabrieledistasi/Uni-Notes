/*Scrivere una funzione che prenda in input un array di interi e restituisca una sequenza 
contenente esclusivamente gli elementi in posizione dispari 
(indici 1, 3, 5, ecc.) che sono strettamente maggiori di zero. 
La sequenza di output deve essere rappresentata tramite la struttura dati int_array, 
definita come segue:  
struct int_array {
    int dim;
    int *v;
}
typedef struct int_array int_array;
Il campo v rappresenta un array di dim interi. 
La funzione da implementare deve allocare dinamicamente la memoria necessaria 
e avere il seguente prototipo:  int_array pos_dispari_positivi(int *a, int n);
dove a è l'array ed n la sua dimensione. */

#include <stdio.h>
#include <stdlib.h>

typedef struct int_array{
    int dim; 
    int *v;
} int_array; 

int_array pos_dispari_positivi(int *a, int n){

    int m = 0;

    for(int i = 1; i < n; i+=2){
        if(a[i]>0){
            m++; 
        }
    }

    int_array res;
    res.dim = m; 
    res.v = malloc(sizeof(int)*m); 

    int j = 0; 

    for(int i = 0; i < n; i++){
        if(i%2!=0 && a[i]>0){
            res.v[j]=a[i]; 
            j++; 
        }
    }

    return res; 
}

/*
complessità temporale: 
data la lunghezza n del vettore a, per l'analisi della complessità
consideriamo il primo ciclo che eseguirà circa n/2 iterazioni, il secondo ciclo esegue invece
n iterazioni nel caso peggiore, all'interno di esso le operazioni hanno costo costante. 
Dunque possiamo stimare complessità O(n)

complessità spaziale: 
La complessità spaziale è determinata dall'allocazione di m*sizeof(int) byte di memoria aggiuntivi
dove m è il numero di elementi che vengono inseriti nel nuovo vettore. Dunque complessità O(m)

*/