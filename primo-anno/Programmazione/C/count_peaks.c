/*scrivere una funzione che: 
riceve un array di n interi 
conta quanti elementi sono picchi 
a[i] è un picco se a[i] > a[i-1] e a[i] > a[i+1], gli estremi non sono mai picchi */

#include <stdio.h>



int count_peaks(int *a, int n){

    int c = 0; 

    for(int i = 1; i < n-1; i++){


        if (a[i] > a[i-1] && a[i] > a[i+1]){ //se a[i] è più grande dell'elemento precedente e del successivo

            c++; 

        }
    }

    return c;
}


int main(){

    int a[] = {1, 3, 2, 4, 1}; 
    int n = sizeof(a)/sizeof(int); 
    printf("%d", count_peaks(a, n)); 


}

//complessità temporale O(n)
//complessità spaziale O(1)