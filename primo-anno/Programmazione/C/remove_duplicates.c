#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* remove_duplicates(const char* s) {

    int len = strlen(s);
    char* res = malloc(len + 1);
    if (res == NULL){

        return NULL;

    }

    int c = 0;

    for (int i = 0; i < len; i++) {
        int trovato = 0;

        for (int j = 0; j < c; j++) {
            if (res[j] == s[i]) {
                trovato = 1;
                break;
            }
        }

        if (!trovato) {
            res[c] = s[i];
            c++;
        }
    }

    res[c] = '\0';
    return res;
}

//complessità temporale O(n^2), spaziale O(n)