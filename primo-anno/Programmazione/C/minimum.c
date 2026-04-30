#include <stdio.h>
#include <stdlib.h>

// Funzione che trova il minimo in un array
int *minimum(int *a, int n) {
    int *k = malloc(sizeof(int));
    if (k == NULL) {
        return NULL;
    }

    *k = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < *k) {
            *k = a[i];
        }
    }

    return k;
}

int main() {
    int a[] = {5, 56, 23, 143, 32, 54, 3, 5, 67};
    int n = sizeof(a) / sizeof(a[0]);

    int *min = minimum(a, n);
    if (min != NULL) {
        printf("Il minimo è: %d\n", *min);
        printf("è allocato in: %p\n", &min); 
        free(min);
    } else {
        printf("Errore di allocazione.\n");
    }

    return 0;
}