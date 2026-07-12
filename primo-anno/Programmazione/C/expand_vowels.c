/*Si scriva una funzione con il seguente prototipo:

char *expand_vowels(char *s);

dove s è una stringa.

La funzione deve restituire una nuova stringa allocata dinamicamente nella quale ogni vocale viene duplicata.

Le consonanti e gli altri caratteri devono rimanere invariati.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *expand_vowels(char *s){

    int n = strlen(s); 
    char *vocali = "aeiouAEIOU"; 
    int c = 0; 


    for(int i = 0; i<n; i++){
        if(strchr(vocali, s[i]) != NULL){

            c++; 

        }
    }

    char *new_word = malloc(sizeof(char)*(n+c+1)); 
    if(new_word==NULL){
        return NULL; 
    }

    int j = 0;

    for(int i = 0; i < n; i++){

        new_word[j] = s[i];
        j++;

        if(strchr(vocali, s[i]) != NULL){
            new_word[j] = s[i];
            j++;
        }
    }

    new_word[j] = '\0'; 

    return new_word; 
}

int main(){
    char *s = "gianluca"; 
    char *sol = expand_vowels(s); 
    printf("%s, ", sol); 
}