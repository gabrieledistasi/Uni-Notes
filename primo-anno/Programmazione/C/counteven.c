/*un programma deve leggere in input dall'utente due vettori di 5 elementi ciascuno. Il programma deve creare un ulteriore
vettore, che contenga la copia dei soli elementi pari presenti in quelli di partenza e stampare tale vettore*/

#include <stdio.h>
#include <stdlib.h>

int *printeven(int *A, int sizeA, int *B, int sizeB, int *sizeC){

    int *C = malloc((sizeA+sizeB)*sizeof(int)); 

    if(C==NULL){
        printf("Errore nell'allocazione di memoria"); 
        return NULL; 
    }

    int m = 0; 
     

    for(int i=0; i < sizeA; i++){

        if(A[i]%2==0){
            C[m]=A[i]; 
            
            m++; 
        }

        
    }

    for(int j = 0; j< sizeB; j++){
        
        if(B[j]%2==0){
            C[m] = B[j]; 
            m++; 
        }
    }

    *sizeC = m;
    return C; 

}

int main(){

    int A[5] = {10, 20, 30, 40, 50}; 
    int B[5] = {2, 4, 6, 7, 9}; 
    int sizeC; 
    int sizeB = sizeof(B)/sizeof(B[0]); 
    int sizeA = sizeof(A)/sizeof(A[0]); 
    int *C = printeven(A, sizeA, B, sizeB, &sizeC); 

    
    

    for(int k = 0; k < sizeC; k++){
        printf("%d, ", C[k]); 

    }

    free(C); 
    
}