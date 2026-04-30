//scrivere una funzione con questo prototipo int *sotto_array(int a, int start, int end, int *m)
//la funzione crea un sotto array dalla posizione start alla posizione end dove sono copiati gli elementi contenuti nel dato intervallo
//la funzione deve restituire anche la dimensione del nuovo array


#include <stdio.h>
#include <stdlib.h>

int *sotto_array(int *a, int start, int end, int *m){
    
    
    int *res = malloc(sizeof(int)*(end-start+1)); 

    if(res == NULL){
        printf("Errore di allocazione di memoria");
        return NULL; 
    }
    
    int j = 0; 
    for(int i = start; i <= end; i++){

        res[j] = a[i]; 
        j++; 
    }

    *m = j; 

    return res; 
}


int main(){
    int a[] = {1, 2, 3, 4, 76, 3,4, 6, 2, 5}; 
    int n = sizeof(a)/sizeof(int); 
    int m; 
    int *b = sotto_array(a, 2, 6, &m); 
    for(int k = 0; k < m; k++){
        printf("%d\n", b[k]); 
    }
}

//complessità temporale O(n)
//complessità spaziale O(n)