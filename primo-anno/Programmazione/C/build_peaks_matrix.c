/*scrivere una funzione col seguente prototipo 
int **build_peaks_matrix(int *a, int n, int *rows, int *cols)
che riceva un array di n interi 
individua tutti i picchi dell'array 
gli estremi non sono mai picchi 
costruisce e restituisce una matrice dinamica con: 
    una riga per ogni picco
    due colonne: 
        colonna 0 indice del picco
        colonna 1 valore del picco 
    scrive in *rows numero di picchi trovati 
    cols valore 2

se non ci sono picchi la funzione deve restituire null e scrivere *rows e *cols = 0
*/


#include <stdio.h>
#include <stdlib.h>


int **build_peaks_matrix(int *a, int n, int *rows, int *cols){

    if (n < 3){
        *rows = 0; 
        *cols = 0; 
        return NULL; 
    }

    int c = 0; 
    


    for(int i = 1; i < n-1; i++){

        
        if (a[i] > a[i-1] && a[i] > a[i+1]){ //se a[i] è più grande dell'elemento precedente e del successivo

            c++; 

        }




    }

    if(c==0){
        *rows = 0; 
        *cols = 0; 
        return NULL; 
    }


    int **matrixpeaks = malloc(c *sizeof(int *)); 
    int k = 0; 
    for(int i = 1; i < n-1; i++){


        if (a[i] > a[i-1] && a[i] > a[i+1]){ //se a[i] è più grande dell'elemento precedente e del successivo

            matrixpeaks[k] = malloc(2 * sizeof(int));


            matrixpeaks[k][0] = i; 
            matrixpeaks[k][1] = a[i]; 
            k++; 



    }

    }

    *rows = c; 
    *cols = 2; 

    return matrixpeaks; 



}


int main(void) {
    int a[] = {1, 3, 2, 4, 1, 5, 0};
    int n = sizeof(a) / sizeof(a[0]);

    int rows, cols;
    int **peaks = build_peaks_matrix(a, n, &rows, &cols); 

    if (peaks == NULL) {
        printf("Nessun picco trovato.\n");
        return 0;
    }

    printf("Trovati %d picchi:\n", rows);
    for (int i = 0; i < rows; i++) {
        printf("Picco %d -> indice: %d, valore: %d\n",
               i, peaks[i][0], peaks[i][1]); 
    }

    /* free corretto */
    for (int i = 0; i < rows; i++) {
        free(peaks[i]);
    }
    free(peaks);

    return 0;
}

