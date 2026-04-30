/*scrivere una funzione in C che dato un array di float in input 
crea un'array che è l'inverso di a, ossia, il nuovo array memorizza gli elementi di a al contrario
*/
#include <stdio.h>
#include <stdlib.h>

float *arcontrario(float *a, int n) {
    float *new_a = malloc(n * sizeof(float));
    if (new_a == NULL) {
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        new_a[i] = a[n - 1 - i];
    }

    return new_a;
}

int main() {
    float a[] = {1.2, 3.5, 4.5};
    int n = sizeof(a) / sizeof(float);

    float *b = arcontrario(a, n);

    printf("Array originale: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }

    printf("\nArray inverso: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", b[i]);
    }

    printf("\n");

    free(b); // libera la memoria allocata

    return 0;
}
