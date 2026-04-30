/*scrivere una funzione che controlli se tutti i numeri da 1 a n sono contenuti nell'array
i numeri possono essere disposti anche come effetto pacman*/

// a = {5, 6, 1, 2, 3, 4} n = 6

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


int orderedarray(int *a, int n){

    int somma = (n*(n+1))/2; 

    for(int j = 0; j < n; j++){
        if (a[j]<n){
           somma = somma-a[j];

        }


    }

    if(somma==0){
        return 1 ;
    }
    else{
        return 0; 
    }
    
}

int main(){
    int a[] = { 3, 4, 5, 6, 1, 2}; 
    int n = sizeof(a)/sizeof(a[0]); 

    printf("%d", orderedarray(a, n)); 
}