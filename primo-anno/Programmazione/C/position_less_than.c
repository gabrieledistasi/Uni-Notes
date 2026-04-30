#include <stdio.h> 
#include <stdlib.h>

int *position_less_than(int *a, int n, int x, int *m){

    int c = 0; 

    for(int i = 0; i < n; i++ ){
        if(a[i] < x){
            c++; 
        }
    }

    int *res = malloc(sizeof(int)*c); 

    if(res == NULL){
        printf("Errore di allocazione di memoria"); 
        return NULL; 
    }


    int idx = 0; 

    for(int j = 0; j < n; j++){
        if(a[j] < x){
            res[idx] = j; 
            idx++; 
        }
    }

    *m = c; 

    return res; 
}


int main(){
    int a[] = {1, 2, 3, 4, 5, 6 ,7 ,8 ,9, 10, 11, 12, 13, 14}; 
    int n = sizeof(a)/sizeof(int); 
    int x = 7; 
    int m; 
    int *b = position_less_than(a, n, x, &m); 

    for(int k = 0; k < m; k++){
        printf("%d\n", b[k]); 
    }

    free(b); 

}

//complessità temporale O(n)
//complessità spaziale O(n)