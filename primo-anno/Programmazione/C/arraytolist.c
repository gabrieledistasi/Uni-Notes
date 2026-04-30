/*scrivere una funzione in C che, dato in input un array di elementi b 
di lunghezza n, crea e restituisce in output una lista contenente gli elementi di b*/
#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
    int valore; 
    struct nodo *next; 
} nodo ; //creo un nuovo tipo di dato chiamato nodo 

nodo *arraytolist(int b[], int n){
    nodo *head = NULL; 
    nodo *current = NULL; 

    for (int i = 0; i < n; i++){
        nodo *nuovo = malloc(sizeof(nodo));
        nuovo->valore = b[i]; 
        nuovo->next = NULL; 

        if(head == NULL){
            head = nuovo; 
            current = nuovo; 
        }
        else{
            current->next = nuovo; 
            current = nuovo; 

        }
    }
    return head; 
}


int main(){
    int b[]= {10, 20, 30, 40}; 
    int n = sizeof(b)/sizeof(int);
    nodo *lista = arraytolist(b, n); 

    nodo *p = lista; 
    while (p!=NULL){
        printf("%d, ", p->valore); 
        p = p->next; 
    }
    return 0; 
}