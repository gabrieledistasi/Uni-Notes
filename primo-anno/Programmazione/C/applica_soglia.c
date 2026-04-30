/*se x è una variabile di tipo array_int, allora x.a è un puntatore ad array
di interi e x.n è l dimensione di quest'ultimo.
scrivere una funzione in C che, dato un array di interi b, la sua dimensione m e 
un intero t detto soglia, restituisce un array_int contenente nel campo a gli indici di b
che contengono un valore al di sotto della soglia t. In altre parole, l'indice i di b è 
contenuto in x.a se e soltanto se b[i]<t*/
#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int *a; 
    int n; 
} array_int; 


array_int cacioepepe(int *b, int m, int t){

    int j = 0; 
    array_int x = {NULL, 0}; 




    //calcolo il numero di elementi sotto la soglia
    for (int i = 0; i < m; i++){
        if (b[i]<t){
            x.n += 1; 
        }
    }

    //dal calcolo fatto prima posso allocare la memoria necessaria 

    x.a = malloc(sizeof(int)*x.n); 

    for(int i=0; i < m; i++){
        if (b[i] < t){
            x.a[j] = i; 
            j++; 
        }
    }

    return x; 

}



int main(){
    int b[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int m = sizeof(b)/sizeof(int); 
    int t = 7; 
    array_int x = cacioepepe(b, m, t); 

    for(int k=0; k<x.n; k++){
        printf("%d, ", x.a[k]); 
    }

}