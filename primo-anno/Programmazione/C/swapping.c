/*scrivere una funzione che, dati in input a, b e c tre interi li scambi in modo che a<=b<=c */

#include <stdio.h>


void ordina(int *a, int *b, int *c){
    int temp; 
    if (*a>*b){
        temp  = *a; 
        *a=*b; 
        *b= temp; 
    }
    if (*a>*c){
        temp = *a; 
        *a = *c; 
        *c = temp; 
    }
    if (*b>*c){
        temp = *b; 
        *b = *c; 
        *c = temp; 
    }
}



void main(){
    int a, b, c; 
    printf("inserisci tre numeri interi: ");
    scanf("%d %d %d", &a, &b, &c); 
    ordina(&a, &b, &c); 
    printf("i numeri ordinati sono: %d %d %d\n", a, b, c);
}
