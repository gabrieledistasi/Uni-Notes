/*
si scriva una funzione: int is_rotation(int *a, int *b, int n)
dove a e b sono due array interi di lunghezza n; 
n > 0, la funzione deve restituire 1 se b è una rotazione circolare di a, altrimenti 0
*/
#include <stdio.h>

int is_rotation(int *a, int *b, int n){
    int i, j;
    for(i = 0; i < n; i++){
        if(a[i] == b[0]){
            for(j = 0; j < n; j++){
                if(a[(i + j) % n] != b[j]){
                    break;
                }
            }
            if(j == n){
                return 1;
            }
        }
    }
    return 0;


}