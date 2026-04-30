/*si scriva una funzione avente il seguente prototipo
float *linspace(float start, float stop, int num)
la funzione deve ritornare un array con num numeri in virgola mobile, equidistanti, in cui
il primo è start e l'ultimo è stop
*/

//input start = 0, stop = 1, num = 5, 
//output result = [0, 0.25, 0.5, 0.75, 1] --> 1-0/5-(1-0)

#include <stdio.h>
#include <stdlib.h>

float *linspace(float start, float stop, int num){

    float *result = malloc(sizeof(float)*num); 
    if (result == NULL){
        return NULL; 
    }

    for(int i = 0; i < num; i++){
        result[i] = start + i*(stop-start)/(float)(num-1); 
    }

    return result; 

}

int main(){
    float start = 0.0;
    float stop = 1.0; 
    int num = 5; 
    float *result = linspace(start, stop, num); 

    for(int k=0; k<num; k++){
        printf("%f, ", result[k]); 
    }
}