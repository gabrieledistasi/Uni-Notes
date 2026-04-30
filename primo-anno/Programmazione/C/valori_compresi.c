/*si scriva una funzione con il seguente prototipo: 
int *valori_compresi(int *a, int n, int x, int y, int *m)
a è un array di interi 
la funzione deve restituire un nuovo array contenente tutti gli elementi di a compresi tra x e y inclusi 
l'ordine degli elementi deve essere lo stesso dell'array originale 
nella variabile puntata da m deve essere scritta la dimensione del nuovo array 
se non esistono elementi che soddisfano la condizione, la funzione deve restituire NULL e scrivere 0 in *m */

#include <stdio.h>
#include <stdlib.h>

int *valori_compresi(int *a, int n, int x, int y, int *m){

    if(x > y){
        int tmp = 0; 
        tmp = x ; 
        x = y;
        y = tmp;    

    }

    int k = 0; 
    for(int c = 0 ; c < n; c++){
        if(a[c]<=y && a[c] >= x){
            k++; 
        }

    }

    if(k == 0){
        *m = 0; 
        return NULL; 
    }

    int *res = malloc(sizeof(int)*(k)); 

    

    if(res == NULL){
        printf("Errore di allocazione di memoria"); 
        return(NULL);
    }

    int j = 0; 

    for(int i = 0; i < n; i++){

        if((a[i]>= x && a[i] <= y)){
            res[j] = a[i]; 
            j++; 
        }
       
        
    }

    *m = j; 

    return res; 
}


int main(){

    int a[] = {2, 5, 3, 3,4 ,6 ,25, 6}; 
    int n = sizeof(a)/sizeof(int); 
    int x = 4;
    int y = 6; 
    int m; 
    int *b = valori_compresi(a, n, x, y, &m); 

    for(int k = 0; k < m; k++){
        printf("%d\n", b[k]); 
    }



}

//complessità temporale: O(y-x+1)---> caso peggiore O(n)
//complessità spaziale: O(y-x+1)---> caso peggiore O(n)

