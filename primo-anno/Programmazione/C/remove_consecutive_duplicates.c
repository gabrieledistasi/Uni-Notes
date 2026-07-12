/*
Si scriva una funzione con il seguente prototipo:

char *remove_consecutive_duplicates(char *s);

dove s è una stringa.

La funzione deve restituire una nuova stringa allocata dinamicamente ottenuta 
eliminando tutti i caratteri consecutivi ripetuti*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_consecutive_duplicates(char *s){

    int c = 0; 
    int len = strlen(s); 


    char *res = malloc((strlen(s))+1); 

    int j = 0; 

    for(int i = 1; i < len; i++){

        if(s[i] != s[i-1]){

            res[j]=s[i-1]; 
            j++; 
        }
    }

    res[j] = s[len-1]; 
    j++; 

    res[j] = '\0'; 

    return res; 

}


int main(){

    char *s = "aaabbbcccddd"; 
    char *sol = remove_consecutive_duplicates(s); 

    printf("%s", sol); 
    free(sol); 

}
/*complessità temporale: 
    strlen() --> O(n)
    sia n la lunghezza della stringa
    vengono eseguite nel caso peggiore n iterazioni dal ciclo for, quindi O(n)
    
    
complessità spaziale: 
    sia n la lunghezza della stringa, 
    se la stringa ha tutti caratteri diversi la malloc avrà lunghezza n
    dunque complessità O(n)*/