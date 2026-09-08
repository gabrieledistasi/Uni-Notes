/*Si scriva una funzione avente il seguente prototipo:
char *concatena_iniziale(char *a[], int n, char c);
Dove a è un array di n stringhe (array di puntatori a carattere).
La funzione deve allocare dinamicamente e ritornare una nuova stringa 
contenente la concatenazione di tutte le stringhe presenti in a che iniziano esattamente 
con il carattere c (distinguendo tra maiuscole e minuscole).
Nel caso in cui nessuna stringa inizi con il carattere c, la funzione deve ritornare una stringa
vuota (non NULL, ma una stringa di lunghezza zero allocata dinamicamente).
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *concatena_iniziale(char *a[], int n, char c){

    int i; 
    int total_len = 0; 

    for (int i = 0; i < n; i++){
        if(a[i][0]==c){
            total_len = strlen(a[i]); 
        }
    }

    char *risultato = malloc((total_len+1)*sizeof(char)); 

    if(risultato == NULL){
        return NULL;
    }

    for(int i = 0; i < n; i++){
        if(a[i][0]==c){
            strcat(risultato, a[i]); 
        }
    }

    return risultato; 
}

/*Complessità Temporale: O(S) dove S è la somma del numero di caratteri di tutte le 
stringhe nell'array. La funzione `strlen` itera sui caratteri della stringa, e 
così fa `strcat`. Anche se scorriamo l'array due volte, il tempo totale è 
proporzionale alla lunghezza dei caratteri elaborati.

Complessità Spaziale: O(K) dove K è la somma delle lunghezze delle sole stringhe 
che iniziano con il carattere 'c'. Questa è la memoria allocata dinamicamente 
tramite malloc per contenere la stringa risultante (più 1 byte per il terminatore).
Spazio ausiliario per le variabili è O(1).*/