/*scrivere una funzione in C che riceva in input un array a di interi
comprime l'array in blocchi contigui
restituisce una matrice con
    una riga per ogni blocco
    2 colonne
        colonna 0 valore del blocco
        colonna 1 lunghezza del blocco
        
    scrive in *rows il numero di blocchi*/


#include <stdio.h>
#include <stdlib.h>


int **compress_list(int *a, int n, int *rows){

    if(n == 0){

        *rows = 0; 
        return NULL; 

    }

    int current_value = a[0]; 
    int current_count = 1; 
    int c = 1; 

    //ciclo che indica quanti blocchi di elementi contigui sono presenti nell'array

    for(int i = 1; i < n; i++){

        if(a[i] != a[i-1]){ //quando due elementi sono diversi, c indica un nuovo blocco
            c++; 


        }

        
    }

    int **res = malloc(c*sizeof(int *)); 

    
    int k = 0; 
    for(int i = 1; i < n; i++){

        if(a[i] != a[i-1]){

            res[k] = malloc(2*sizeof(int)); 

            
            res[k][0] = a[i-1]; //il blocco finisce, salvo il valore di quel blocco
            res[k][1] = current_count; //inserisco il conteggio a cui sono arrivato
            

            current_value = a[i]; // ora il valore corrente diventa a[i]
            current_count = 1; //inizializzo current_count a 1

            k++; 

        }

        else{

            current_count++; 


        }

        

    }
    res[k] = malloc(2*sizeof(int)); 
    res[k][0] = current_value; 
    res[k][1] = current_count; 

    *rows = c; 

    return res; 
}


int main(){
    int a[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 3, 5, 5, 5}; 
    int n = sizeof(a)/sizeof(int); 
    int rows; 
    int **california = compress_list(a, n, &rows); 

    for(int i = 0; i < rows; i++){
        printf("valore: %d conteggio: %d\n", california[i][0], california[i][1]); 
    }

    //free
    for(int i = 0; i<rows; i++){
        free(california[i]);
    }
    free(california);

}
