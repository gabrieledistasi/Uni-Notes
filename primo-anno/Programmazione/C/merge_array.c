/*scrivere una funzione in C che fonda due array di interi ordinati in modo crescente, il programma deve eseguire le seguenti operazioni: 
leggere due vettori di N interi. il numero n viene inserito dall'utente ed è minore di 20. I due vettori possono avere lunghezza diversa. 
I due vettori si suppongono già ordinati in maniera crescente

creare un terzo vettore di lunghezza pari alla somma dei due vettori dati. Il vettore dovrà contenere i numeri contenuti nei due vettori di partenza. 
I numeri nel vettore devono essere ordinati in modo crescente 

stampare il vettore generato*/

#include <stdio.h>
#include <stdlib.h>


void merge(int *A, int left, int mid, int right){
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    int leftArr[n1], rightArr[n2]; 

    for( i=0; i< n1; i++){

        leftArr[i] = A[left+i];

    }

    for (j = 0; j < n2; j++){
        rightArr[j] = A[mid+1+j]; 

    }


    i = 0; 
    k = left;  
    j = 0;

    while(i < n1 && j< n2){
        if(leftArr[i] <= rightArr[j]){

            A[k] = leftArr[i]; 
            i++; 

        }
        else{
            A[k] = rightArr[j]; 
            j++; 

        }
        k++; 


    }

    while(i<n1){

        A[k] = leftArr[i]; 
        i++; 
        k++; 

    }


    while(j<n2){
        A[k] = rightArr[j]; 
        j++; 
        k++; 
    }


}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}


int *merge_array(int *A, int *B, int m, int n){



    int *C = malloc(sizeof(int)*(m+n)); 


    for(int i = 0; i < m; i++){

        C[i] = A[i]; 

    }

    int k = 0; 


    for(int j = m; j < m+n; j++){
        C[j] = B[k]; 
        k++; 
    }


    mergeSort( C, 0, (m+n)-1); 
    



    





    return C; 

}


int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 10, 22, 23}; 
    int B[] = {1, 2, 10, 45, 100, 202, 890}; 
    int m = sizeof(A)/sizeof(A[0]); 
    int n = sizeof(B)/sizeof(B[0]); 
    int *result = merge_array(A, B, m, n); 

    for(int k = 0; k < m+n; k++){
    
        printf("%d, ", result[k]); 
    }

}