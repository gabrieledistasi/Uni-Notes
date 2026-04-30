/*scrivere una funzione in C che: 
legge un array di N interi 
calcola: 
media 
valore massimo e minimo
quanti numeri sono sopra la media*/


#include <stdio.h>

void trovamedia(int *a, int N, int *media, int *count_numbers){
    int somma = 0; 

    for(int i = 0; i < N; i++){

        somma = somma + a[i]; 

    }
    *media = somma/N; 

    *count_numbers = 0; 

    for(int i = 0; i < N; i++){
        if(a[i] > *media){
            
            *count_numbers = *count_numbers + 1; 
    
        }
    }
 
}

void maxmin(int *a, int N, int *max, int *min){ //{1, 2, 3}
    *max = a[0]; 
    *min = a[0]; 

    for(int i = 1; i < N; i++){
        if(*max < a[i]){
            *max = a[i]; 
        }

        if(a[i]<*min){
            *min = a[i]; 
        }
    }
}

int main(){
    int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int N = sizeof(a)/sizeof(int); 

    int media; 
    int count_numbers; 
    int max, min; 
    trovamedia(a, N, &media, &count_numbers); 
    maxmin(a, N, &max, &min); 

    printf("media: %d \n", media); 
    printf("massimo e minimo: %d, %d \n", max, min); 
    printf("numeri sopra la media: %d \n", count_numbers); 
}