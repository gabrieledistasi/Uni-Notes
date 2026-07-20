/*scrivere un programma in linguaggio C che, data una stringa di N caratteri N/2 threads che stampano ciascuno
un carattere dalla stringa in minuscolo*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>

#define N 10

char c[N + 1];
pthread_t t[N / 2];

void *workers(void *args) {

    int indice = *(int *)args;

    printf("%c\n", tolower(c[indice]));

    pthread_exit(NULL);
}

int main() {

    int indici[N / 2];

    scanf("%10s", c);

    for (int i = 0; i < N / 2; i++) {
        indici[i] = i;
        pthread_create(&t[i], NULL, workers, &indici[i]);
    }

    for (int i = 0; i < N / 2; i++) {
        pthread_join(t[i], NULL);
    }

    return 0;
}





