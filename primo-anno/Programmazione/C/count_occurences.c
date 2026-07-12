//scrivere una funzione che restituisca il numero di occorrenze del carattere c nella stringa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_occurences(char* s, char c){

    int count = 0; 

    for(int i=0; s[i]!='\0'; i++){
        
        if(s[i] == c){
            count++; 
        }

    }
    return count; 

}

int main(){
    char s[] = "coccodrillo"; 
    char c = 'c'; 
    printf("%d\n", count_occurences(s, c)); 
}

//complessità spaziale O(1), temporale O(n)