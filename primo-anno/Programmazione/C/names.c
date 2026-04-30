/*Un programma legge dall’utente una serie di nomi di persona. L’inserimento termina
quando l’utente immette il nome fasullo *.
Il programma dovrà stampare:
• quanti nomi sono stati inseriti
• qual è il nome che, nell’ordine alfabetico, verrebbe per primo
• qual è il nome più lungo, e di quanti caratteri è composto.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char name[100];   // buffer per il nome
    int count = 0;

    while (true) {
        printf("Inserisci un nome (o * per terminare): ");
        scanf("%99s", name);  // legge una parola

        if (strcmp(name, "*") == 0) {  // confronta stringhe
            break;
        }

        count++;
    }



    printf("Numero di nomi inseriti: %d\n", count);

    

    return 0;
}
