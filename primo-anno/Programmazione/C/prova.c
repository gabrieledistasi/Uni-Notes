
//data una stringa da riga comando crea un array che sia lungo 3 volte la stringa originaria e che abbia nelle prime n(n lunghezza stinga) 
//la stringa stessa, nella n-2*n posizioni i caratteri in ascii della stringa, nelle ultime 2*n+1 - 3n posizioni la stringa palindroma
//posso usare un solo ciclo for che vada da 0 a n

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convertistringa(char *a, int n){

    char *res = malloc((3*n+1)*sizeof(char)); 
    if(res == NULL){
        printf("Errore nell'allocazione di memoria"); 
        return NULL; 
    }

    for(int i = 0; i < n; i++){
            res[i]=a[i]; //nei primi n elementi metti la parola 
            res[n+i] = a[i]; //metti l'ASCII
            res[(2*n)+i] = a[n-i-1]; //stringa al contrario
 


    }

    res[3*n] = '\0'; 

    return res; 
}


int main(){
    char *a = "ciao"; 
    int n = strlen(a); 
    char *b = convertistringa(a, n); 
    


    printf("%s", b); 


    
}