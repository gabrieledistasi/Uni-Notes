/*si scriva una funzione avente il seguente prototipo: 
char *minstr(char *a, int n); 
dove a è un array di stringhe 
La funzione deve ritornare il puntatore ad una nuova stringa contenente una copia della stringa più corta in a*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *minstr(char *a[], int n){

    if (a == NULL || n <= 0 ){
        return NULL; 
    }

    int min = 0;

    for(int i = 1; i < n; i++ ){

        if(strlen(a[i]) < strlen(a[min])){
            min = i; 
        }
    }

    char *res = malloc(strlen(a[min])+1); 
    strcpy(res, a[min]); 
    return res; 
}


int main(){
    char a[] = {"cane", "gatto", "programmazione", "oro"}; 

}