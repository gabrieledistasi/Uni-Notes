/*Scrivere una funzione in C che, date in input due stringhe a e b, 
crea una nuova stringa che è la concatenazione delle due stringhe.
In particolare, se a precede o è uguale a b, allora la concatenazione deve avere prima la stringa a e poi b; 
viceversa, se b precede a, allora la concatenazione deve avere prima la stringa b e poi a.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int m, int n){
    if(n>=m){
        return m; 
    }

    else{
        return n; 
    }

}


char *str_concatenation(char *a, char *b){
    int m = strlen(a); 
    int n = strlen(b);
    int total_length = n+m; 
    char *p = malloc((n+m)*sizeof(char)); 
    int j = -1; 
    int i=0; 

    for(i ; i<min(m, n); i++){

        if (a[i] > b[i]){
            j = 1; 
            break; 
        }

        else if( a[i] < b[i]){
            j = 0; 
            break; 
        }


        p[i] = a[i]; 


    }


    if(j == 1){
        for(i; i<n ; i++){
            p[i] = b[i]; 

        }
        for(int k = 0; k<m; k++){
            p[n+k]=a[k]; 
        }
    }

    if(j==0){
        for(i; i< m; i++){
            p[i]= a[i]; 
        }
        for(int k = 0; k<n; k++){
            p[m+k]=b[k]; 
        }


    }
    



    return p; 



}



int main(){

    char *b = "programmazione"; 
    char *a = "prolog"; 

    char *result = str_concatenation(a, b); 


    for(int s = 0; s < strlen(result); s++){
        printf("%c", result[s]); 
    }



}

//complessità O(n+m) temporale, spaziale O(1)

