/*Un programma deve leggere dall’utente due vettori di 5 elementi ciascuno. Il programma
deve creare un ulteriore vettore, che contenga la copia dei soli elementi pari presenti nei
due vettori di partenza, e stampare tale vettore*/




#include <stdio.h>
#include <stdlib.h>

int *stampa_pari(int *A, int *B, int m, int n, int *size) {
    int *C = malloc(sizeof(int) * (m + n));
    int idx = 0;

    for(int i = 0; i < m; i++) {
        if(A[i] % 2 == 0) {
            C[idx++] = A[i];
        }
    }

    for(int j = 0; j < n; j++) {
        if(B[j] % 2 == 0) {
            C[idx++] = B[j];
        }
    }

    *size = idx;  // return the number of even numbers
    return C;
}

int main() {
    int A[] = {1, 3, 5, 6, 35};
    int B[] = {2, 3, 67, 2, 1};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
    int size;

    int *result = stampa_pari(A, B, m, n, &size);

    for(int k = 0; k < size; k++) {
        printf("%d, ", result[k]);
    }

    free(result);  // free allocated memory
    return 0;
}
