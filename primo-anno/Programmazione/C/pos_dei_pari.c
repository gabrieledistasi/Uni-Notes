#include <stdio.h>
#include <stdlib.h>


int *pos_dei_pari(int *a, int n, int *m){
    
    int j = 0; 
    for(int i = 0; i < n; i++){
        if(a[i]%2==0){
            j++; 
        }
    }

    int *res = malloc(sizeof(int)*j); 

    int idx = 0; 
    for(int i = 0; i < n; i++){
        if(a[i]%2==0){

            res[idx]=i; 

            idx++; 
        }
    }

    *m = j; 
    return res; 
    return m; 

}

int main(){
    int a[] = {1, 2, 5,45 , 23, 54, 23, 14, 10}; 
    int n = sizeof(a)/sizeof(int); 
    int m; 
    int *b = pos_dei_pari(a, n, &m); 
    for (int i = 0; i< m; i++){
        printf("%d\n", b[i]); 
    }
}