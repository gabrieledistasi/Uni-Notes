/*scrivere una funzione: 
int *rimuovi_ripetuti(int *a, int n, int *m)
a è un array di lunghezza n
la funzione deve restituire un nuovo array contenente solo i valori non ripetuti 
m deve contenere la lunghezza dell'array restituito*/

#include <stdio.h>
#include <stdlib.h>

int *rimuovi_ripetuti(int *a, int n, int *m) {
    int *res = malloc(n * sizeof(int));
    if (res == NULL) {
        *m = 0;
        return NULL;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        int trovato = 0;

        for (int j = 0; j < count; j++) {
            if (res[j] == a[i]) {
                trovato = 1;
                break;
            }
        }

        if (!trovato) {
            res[count] = a[i];
            count++;
        }
    }

    *m = count;
    return res;
}

int main() {
    int n;
    printf("Inserisci n: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    if (a == NULL) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int m;
    int *b = rimuovi_ripetuti(a, n, &m);

    printf("Array senza ripetuti:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}