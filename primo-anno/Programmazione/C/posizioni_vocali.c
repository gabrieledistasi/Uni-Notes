#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *a;  // array di indici
    int n;   // numero di elementi
} array_int;

array_int posizione_vocali(char s[]) {
    array_int a = {NULL, 0};   // inizializzazione corretta
    int n = strlen(s);
    int i, k, j = 0;

    // conto il numero di vocali
    for (i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            a.n++;
        }
    }

    // alloco la memoria
    a.a = malloc(sizeof(int) * a.n);
    if (a.a == NULL) {
        fprintf(stderr, "Errore di allocazione memoria.\n");
        a.n = 0;
        return a;
    }

    // salvo gli indici delle vocali
    for (k = 0; k < n; k++) {
        if (s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' || s[k] == 'u' ||
            s[k] == 'A' || s[k] == 'E' || s[k] == 'I' || s[k] == 'O' || s[k] == 'U') {
            a.a[j] = k;
            j++;
        }
    }

    return a;
}

// Esempio d’uso
int main() {
    char str[] = "Ciao Mondo";
    array_int pos = posizione_vocali(str);

    printf("Numero di vocali: %d\n", pos.n);
    printf("Posizioni: ");
    for (int i = 0; i < pos.n; i++) {
        printf("%d ", pos.a[i]);
    }
    printf("\n");

    free(pos.a); // libera la memoria
    return 0;
}


