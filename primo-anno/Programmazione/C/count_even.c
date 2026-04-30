#include <stdio.h>

int count_even(int *a, int n){

    int c = 0; 

    for(int i = 0; i < n; i++){
        if(a[i]%2==0){
            c+=1; 
        }

    }

    return c; 
}

int main(){

    int a[] = {1, 2, 3, 4, 5, 6}; 
    int n = sizeof(a)/sizeof(a[0]); 

    printf("%d", count_even(a, n)); 


}