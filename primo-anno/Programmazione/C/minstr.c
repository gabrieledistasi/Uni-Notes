/*
si scriva una funzione avente il seguente prototipo: 
char *minstr(char *a[], int n)
dove a è un array di n stringhe 
la funzione deve ritornare il puntatore ad una stringa contenente una copia della stringa più corta in a; 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *minstr(char *a[], int n){

    int min_index = 0; 

    for(int i = 1; i < n; i++) {

        if(strlen(a[i]) < strlen(a[min_index])) {
            min_index = i;
        }
    }

    char *res = malloc(strlen(a[min_index])+1); 

    if(res == NULL){
        return NULL; 
    }

    strcpy(res, a[min_index]); 
    return res; 

    

}


int main(){
    char* a[]={"cane", "gatto", "gallo", "bue"}; 
    int n = sizeof(a)/sizeof(a[0]); 

    char *s = minstr(a, n);

    if(s!=NULL){
        printf("%s\n", s); 
        free(s); 
    }

}