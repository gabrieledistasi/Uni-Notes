#include <stdio.h>

int main(){
    int a[100] = {1, 0, -1}; 
    int *b = a; 
    char *c = a; 
    int z = a[10], w; 

    c = c+1;    
    b = b+ 1; 

    if (b==c){
        z = 0; 
    }
    else if(b < c){
        z = 0; 
    }
    else if( b> c){
        z = 1; 
    }
    else {
        z = a; 
    }

    printf("%d", z); 

}