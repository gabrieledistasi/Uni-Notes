
/*creare un risolutore di equazioni di secondo grado*/
#include <math.h>
#include <stdio.h>

int main(){

    int a = 2; 
    int b = 1; 
    int c = 1; 


    float delta = sqrt(pow(b, 2)-(4*a*c));

    if( delta < 0){
        printf("Delta < 0, l'equazione non ha soluzione nei reali");
    }

    if (delta > 0){
        printf( "Delta > 0, l'equazione ha due soluzioni"); 
    }

    if(delta == 0){
        printf( "Delta = 0, una sola soluzione");
    } 

    float soluzione_pos = (-b + delta)/2; 
    float soluzione_neg = (-b - delta)/2; 

    printf("soluzione positiva: %f", soluzione_pos); 
    printf("soluzione negativa: %f", soluzione_neg); 



}