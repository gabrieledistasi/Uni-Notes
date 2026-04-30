//scrivere una funzione che determini se un triangolo è isoscele, equilatero o scaleno

#include <stdio.h>
int main(){
    int l1; 
    int l2; 
    int l3; 

    printf("inserisci il primo lato:\n"); 
    scanf("%d", &l1); 
    printf("inserisci il secondo lato:\n"); 
    scanf("%d", &l2); 
    printf("inserisci il terzo lato: \n"); 
    scanf("%d", &l3); 



    if(l1==l2 && l2==l3){
        printf("il triangolo è equilatero"); 
    }
    else if(l1==l3||l1==l2||l2==l3){
        printf("il triangolo è isoscele"); 
    }
    else{
        printf("è scaleno"); 
    }
}