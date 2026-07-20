/*

Scrivere un programma C che:

crei un thread produttore e due thread consumatori;
il produttore inserisce i numeri da 1 a 100 in un buffer condiviso;
ciascun consumatore legge un numero e lo stampa;
il buffer deve essere protetto da mutex;
il main deve attendere tutti i thread.*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define N 100




pthread_t producer, consumer1, consumer2;
pthread_mutex_t mutex; 



int buffer[N]; 

void *producers(void *args){

    pthread_mutex_lock(&mutex); 

    for(int i = 0; i < N; i++){
        buffer[i] = i+1; 
    }
    
    pthread_mutex_unlock(&mutex); 

    pthread_exit(NULL); 
}

void *consumers(void *args){

    pthread_mutex_lock(&mutex); 

    printf("numero casuale %d \n", buffer[rand()%N]); 

    pthread_mutex_unlock(&mutex); 
    pthread_exit(NULL); 

    
}

int main(){

    srand(time(NULL)); 

    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&producer, NULL, producers, NULL); 
    pthread_create(&consumer1, NULL, consumers, NULL); 
    pthread_create(&consumer2, NULL, consumers, NULL); 

    pthread_join(producer, NULL); 
    pthread_join(consumer1, NULL); 
    pthread_join(consumer2, NULL); 

    pthread_mutex_destroy(&mutex); 
}