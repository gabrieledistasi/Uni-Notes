#include <stdio.h>

int somma_primi_k(int *a, int n, int k){

    int somma = 0; 

    if(k > n){
        for(int i = 0; i < n; i++){
            somma = somma + a[i]; 
        }
    }
    else{

        for (int i = 0; i < k; i++){
        somma = somma+a[i]; 
        
    }


    }
    
    


    return somma; 
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int n = sizeof(a)/sizeof(int); 
    int k = 2; 
    printf("%d", somma_primi_k(a, n, k));  
}
