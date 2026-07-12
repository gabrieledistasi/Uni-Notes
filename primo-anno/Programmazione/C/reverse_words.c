/*scrivere una funzione che restituisca una stringa al contrario*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_words(char *s){

    int n = strlen(s);

    char *res = malloc(n + 1);

    if(res == NULL){
        return NULL;
    }

    int k = 0;
    int i = n - 1;

    while(i >= 0){

        /* salta gli spazi */
        while(i >= 0 && s[i] == ' '){
            i--;
        }

        if(i < 0){
            break;
        }

        int end = i;

        /* trova l'inizio della parola */
        while(i >= 0 && s[i] != ' '){
            i--;
        }

        int start = i + 1;

        /* copia la parola */
        for(int j = start; j <= end; j++){
            res[k++] = s[j];
        }

        /* aggiunge spazio se ci sono altre parole */
        if(i >= 0){
            res[k++] = ' ';
        }
    }

    /* rimuove eventuale spazio finale */
    if(k > 0 && res[k-1] == ' '){
        k--;
    }

    res[k] = '\0';

    return res;
}

int main(){

    char s[] = "ciao come stai";

    char *res = reverse_words(s);

    if(res != NULL){
        printf("%s\n", res);
        free(res);
    }

    return 0;
}

/*
Complessità temporale: O(n)
Ogni carattere viene visitato al più una volta.

Complessità spaziale: O(n)
Viene allocata una nuova stringa lunga n+1.
*/

//ciao come stai
