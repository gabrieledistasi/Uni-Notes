/* Si scriva una funzione con il seguente prototipo
int *unisci_dispari(int *a, int n, int *m)

a è un array di n interi 
la funzione deve restituire un nuovo array contenente solo gli elementi dispari presenti in a
l'ordine deve rimanere lo stesso 
*m deve contenere la dimensione del nuovo array 
se non ci sono elementi dispari, restituire NULL e scrivere 0 in *m */

#include <stdio.h>
#include <stdlib.h>

int *unisci_dispari(int *a, int n, int *m){
    
    //quanti sono gli elementi del nuovo array
    int j = 0; 

    for(int i = 0; i < n; i++){
        if(a[i]%2!=0){
            j++; 
        }
    }

    int *res = malloc(sizeof(int)*j); 

    if(res == NULL){
        printf("Errore nell'allocazione della memoria"); 
        return NULL; 

    }

    int k = 0;  

    for(int i = 0; i < n; i++){
        if(a[i]%2!=0){

            res[k]=a[i]; 
            k++; 

        }
    }

    *m = j; 
    return res; 
}

int main(){
    int a[] = {1, 2, 34, 33, 23, 12,3, 45, 34,1, 23, 65,6 ,5}; 
    int n = sizeof(a)/sizeof(int); 
    int m; 
    int *b = unisci_dispari(a, n, &m); 

    for(int i = 0; i < m; i++){
        printf("%d\n", b[i]); 
    }

    

}