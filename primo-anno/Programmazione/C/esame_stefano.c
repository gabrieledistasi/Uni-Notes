#include <stdio.h>
#include <stdlib.h>

int* pos_dei_minori(int* a, int n, int k, int *m) {
    int i;
    int cont = 0;

    for(i = 0; i < n; i++) {
        if(a[i] < k)
            cont = cont + 1;
    }

    *m = cont;

    int *ris = malloc(sizeof(int) * cont);
    if(ris == NULL)
        return NULL;

    int pos = 0;
    i = 0;
    while(i < n) {
        if(a[i] < k) {
            ris[pos] = i;
            pos++;
        }
        i++;
    }

    return ris;

}


int main(){
    int a[] = {1, 2, 3, 4, 6,6, 6, 3, 3, 2, 1, 1}; 
    int n = sizeof(a)/sizeof(int); 
    int k = 3; 
    int m; 
    int *b = pos_dei_minori(a, n, k, &m); 
    for(int i = 0; i < m; i++){
        printf("%d\n", b[i]); 
    }
}
