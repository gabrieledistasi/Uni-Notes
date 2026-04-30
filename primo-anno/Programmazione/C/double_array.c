/*
Scrivere una funzione in C che, dato un array di lunghezza m di interi e un intero n, 
crea un array di lunghezza m+n che contiene:
nelle prime m posizioni, gli interi contenuti nell'array in input nello stesso ordine;
in ognuna delle m+1⩽i⩽m + n posizioni successiva, la somma di tutti gli interi nelle posizioni precedenti ad i
*/
#include <stdio.h>
#include <stdlib.h>

int *double_array(int *array, int m, int n) {

    int *new_array = malloc((m + n) * sizeof(int));
    if (new_array == NULL) {
        printf("Errore nella locazione di memoria");
        return NULL;
    }

    // Copia i primi m elementi
    for (int i = 0; i < m; i++) {
        new_array[i] = array[i];
    }

    // Calcola la somma iniziale dei primi m elementi
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += new_array[i];
    }

    // Inserisce la somma nelle prossime n posizioni
    for (int i = m; i < m + n; i++) {
        new_array[i] = sum;
        sum += new_array[i];
    }

    return new_array;
}




int main(){

    int array[] = {1, 2, 3}; 
    int m = sizeof(array)/sizeof(int); 
    int n = 5; 
    int *result = double_array(array, m, n); 

    for (int i=0; i<m+n; i++ ){
        printf("%d, ", result[i]); 
    }
    

}