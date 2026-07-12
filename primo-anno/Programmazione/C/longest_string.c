/*scrivere una funione dove a è un array di n stringhe, n > 0
la funzione deve: individuare la stringa più lunga presente nell'array
allocare dinamicamente una nuova stringa
copiarvi il contenuto della stringa più lunga 
restituire il puntatore alla nuova stringa*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longest_string(char* a[], int n) {

    int max_index = 0;

    /* trova l'indice della stringa più lunga */
    for(int i = 1; i < n; i++) {

        if(strlen(a[i]) > strlen(a[max_index])) {
            max_index = i;
        }
    }

    /* alloca memoria per la copia */
    char* res = malloc(strlen(a[max_index]) + 1);

    if(res == NULL) {
        return NULL;
    }

    strcpy(res, a[max_index]);

    return res;
}

int main() {

    char* a[] = {
        "ciao",
        "programmazione",
        "gatto",
        "universita"
    };

    int n = sizeof(a) / sizeof(a[0]);

    char* s = longest_string(a, n);

    if(s != NULL) {
        printf("%s\n", s);
        free(s);
    }

    return 0;
}

/*
Complessità temporale:

Il ciclo esegue n-1 iterazioni.
Ad ogni iterazione vengono eseguite due strlen.
Se m è la lunghezza massima di una stringa,
ogni strlen richiede O(m).

Tempo: O(n * m)

Complessità spaziale:

Viene allocata una nuova stringa lunga al più m caratteri.

Spazio: O(m)
*/