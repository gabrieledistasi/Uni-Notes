/*Si consideri il seguente main di esempio
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
char *a = malloc(50);
a = strcpy(a, "Hello\tWorld\t!");
a = realloc(a, strlen(a)+1);
printf("Originale: \"%s\"\n", a);
a = tab2spaces(a, 2);
printf("Modificata: \"%s\"\n", a);
return 0;
}La funzione tab2spaces ha il seguente prototipo
char *tab2spaces(char *a, int s);
Questa riceve in ingresso una stringa a , allocata dinamicamente con malloc (o calloc o realloc ), ed un
intero positivo s . Modifica a sostituendo ogni carattere di tabulazione con esattemente s spazi e ritorna l'indirizzo di
a aggiornato.
Si implementi la funzione tabs2spaces facendo in modo che il precedente main sia sicuro.*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char *tab2spaces(char *a, int s) {
    int i, j;
    int len = strlen(a);
    int new_len = len;
    for (i = 0; i < len; i++) {
        if (a[i] == '\t') {
            new_len += s - 1;
        }
    }
    a = realloc(a, new_len + 1);
    for (i = len - 1, j = new_len - 1; i >= 0; i--, j--) {
        if (a[i] == '\t') {
            for (int k = 0; k < s; k++) {
                a[j - k] = ' ';
            }
            j -= s;
        } else {
            a[j] = a[i];
        }
    }
    return a;
}

int main(void) {
char *a = malloc(50);
a = strcpy(a, "Hello\tWorld\t!");
a = realloc(a, strlen(a)+1);
printf("Originale: \"%s\"\n", a);
a = tab2spaces(a, 2);
printf("Modificata: \"%s\"\n", a);
return 0;
}