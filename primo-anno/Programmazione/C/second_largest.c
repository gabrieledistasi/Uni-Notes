//scrivere una funzione in C che deve trovare il secondo valore più grande dell'array

// a = [8, 9, 5, 3]

#include <stdio.h>


int second_largest(int *a, int n){
     int max = a[0]; 
    int second_max = a[1]; 

    if(max < second_max){
        int tmp; 
        tmp = max; 
        max = second_max; 
        second_max = tmp; 
    }
   
   
   for(int i = 0; i < n; i++){

    if (a[i]> second_max && a[i] != max){
        second_max = a[i]; 
    }


    if(a[i] > max){
        second_max = max; 
        max = a[i]; 


    }

    

   }

   return second_max; 
}


int main(){
    int a[] = {1, 2, 3, 5, 2, 6,6, 2, 1};
    int n = sizeof(a)/sizeof(a[0]); 
    int result = second_largest(a, n);

    printf("%d", result); 
}
