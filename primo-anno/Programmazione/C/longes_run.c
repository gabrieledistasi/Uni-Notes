/*scrivere una funzione: int longest_run(int *a, int n)
dove a è un array interi di lunghezza n; 
n > 0, la funzione deve restituire la lunghezza della sequenza più lunga di elementi consecutivi uguali*/

#include <stdio.h>


int longest_run(int *a, int n){

    int best_len = 1;
    int curr_len = 1;

    for(int i = 1; i < n; i++){

        if(a[i] == a[i-1]){
            curr_len++;
        }
        else{

            if(curr_len > best_len){
                best_len = curr_len;
            }

            curr_len = 1;
        }
    }

    if(curr_len > best_len){
        best_len = curr_len;
    }

    return best_len;
}