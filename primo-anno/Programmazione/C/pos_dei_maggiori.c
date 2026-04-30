//scrivere una funzione col seguente prototipo int *pos_dei_maggiori(int *a, int n, int k, int *m)
//dove a è un array di interi. La funzione deve ritornare un nuovo array contenente gli indici degli elementi
//strettamente maggiori di k 

#include <stdio.h>
#include <stdlib.h>

int *pos_dei_maggiori(int *a, int n, int k, int *m){
    
    int j = 0; 

    for(int i = 0; i < n; i++){

        if(a[i]>k){
            j++; 
        }
        
    }

    int *res = malloc(sizeof(int)*j); 
    
    int idx = 0; 

    for(int c = 0; c < n; c++){

        if(a[c]>k){

            res[idx] = c; 

            idx++; 
        }
    }

    *m = j; 
    return res; 


}

int main(){
    int a[]={1, 4, 5, 3, 1, 6, 15, 6, 32, 355, 56}; 
    int n = sizeof(a)/sizeof(int); 
    int k = 3; 
    int m; 
    int *b = pos_dei_maggiori(a, n, k, &m); 
    for(int i = 0; i < m; i++){
        printf("%d\n", b[i]); 
    }
}