/* Scrivere un programma in C con tre thread che operano su un array di dimensione N.
    - Il primo thread riempie un array con numeri casuali tra 0 e 100.
    - Il secondo thread trova il valore massimo nell'array.
    - Il terzo trova il valore minimo. (senza utilizzare pthread_cond_t)
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

pthread_t init_t; 
pthread_t max_t; 
pthread_t min_t;

int buffer[N] = {0}; 
int done = 0; 

void print_buffer(){

    printf("["); 

    for(int i = 0; i < N; i++){
        printf(" %d, ", buffer[i]); 
    }

    printf("]\n"); 
}

void *init(void *args){

     
    if(done==0){
        for(int i = 0; i < N; i++){
            buffer[i] = rand() % 101; 
            print_buffer(); 
            sleep(1); 
        }
    }

     
    done = 1; 
    pthread_exit(NULL); 

}

void *max(void *args){
    
    while(done!=1); 
    int m = buffer[0]; 
    for(int i = 0; i < N; i++){
        if(buffer[i] > m){
            m = buffer[i]; 
        }
    }

    printf("Max number is: %d\n", m); 

    pthread_exit(NULL); 

}

void *min(void *args){
    
    
    while(done!=1); 
    int m = buffer[0]; 
    for(int i = 0; i < N; i++){
        if(buffer[i] < m){
            m = buffer[i]; 
        }
    }

    printf("Min number is: %d\n", m); 

    pthread_exit(NULL); 
}

int main(int argc, char *argv[]){

    srand(time(NULL)); 


    pthread_create(&init_t, NULL, init, NULL); 
    pthread_create(&max_t, NULL, max, NULL); 
    pthread_create(&min_t, NULL, min, NULL); 

    pthread_join(init_t, NULL); 
    pthread_join(max_t, NULL); 
    pthread_join(min_t, NULL); 


}