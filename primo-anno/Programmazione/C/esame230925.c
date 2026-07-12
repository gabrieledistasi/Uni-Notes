/*scrivere una funzione in C avente il seguente prototipo: 
float *linspace(float start, float stop, int num). La funzione deve ritornare un array con num numeri in virgola 
mobile, equidistanti, in cui il primo è start e l'ultimo è stop*/

#include <stdio.h>
#include <stdlib.h>

float *linspace(float start, float stop, int num){

    float *v = malloc(num*sizeof(float)); 
    
    if(v == NULL){
        return NULL; 
    }

    if(num== 1){
        v[0] = start; 

        return v; 
    }

    float passo = (stop-start)/(num-1); //formula per determinare l'equidistanza

    for(int i = 0; i < num; i++){

        v[i] = start + i * passo; //a v[0] corrisponde start + 0*passo

    }

    return v; 

}

int main(){
    int start = 3; 
    int stop = 10; 
    int num = 5; 
    float *res = linspace(start, stop, num); 
    for(int i = 0; i < num; i++ ){
        printf("%f, ", res[i]); 
    }

}