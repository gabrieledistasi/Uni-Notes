/*scrivere una funzione in C, denominata cerca, che ricerchi la presenza di un elemento in un vettore di interi
La funzione deve ricevere in ingresso tre parametri: 
1 un vettore di interi v[]
2 un valore intero N che indica quanti elementi contiene il vettore
3 il valore intero x che deve essere ricercato 

La funzione deve restituire un valore intero, ed in particolare: 
-   se il valore x è presente nel vettore 
-   se il valore x è presente più volte, si restituisca l'indice della prima occorrenza 
-   se il valore x non è presente nel vettore, si restituisca -1*/
 
#include <stdio.h>
#include <stdlib.h>

int cerca(int *v, int N, int x){

    for(int i = 0; i < N; i++){
        if (v[i]==x){

            return i; 
        }
    }

    return -1; 
}


int main(){
    int v[] = {1, 4, 6, 2, 5, 3, 1, 5,10, 24}; 
    int N = sizeof(v)/sizeof(v[0]); 
    int x = 5; 
    printf("il valore %d è presente in posizione %d", x,  cerca(v, N, x)); 
}