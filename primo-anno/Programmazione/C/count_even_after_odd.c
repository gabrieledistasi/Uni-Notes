//scrivere una funzione che riceve un array a di n interi
//conta quante volte un numero pari è immediatamente preceduto da un numero dispari
//restituisci il conteggio 
#include <stdio.h>

int count_even_after_odd(int *a, int n){

    int i = 0; 
    for(int c = 1; c < n; c++){

        if(a[c]%2==0 && a[c-1]%2!=0){
            i++; 
        }

        

    }

    return i; 
}



int main(){
    int a[] = {1, 4, 3, 6, 8, 5, 2}; 
    int n = sizeof(a)/sizeof(int); 
    printf("%d\n", count_even_after_odd(a, n)); 

}