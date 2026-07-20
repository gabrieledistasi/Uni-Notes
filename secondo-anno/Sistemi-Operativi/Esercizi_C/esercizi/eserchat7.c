/*Scrivere un programma C con due thread.

Il thread A genera un numero casuale compreso tra 1 e 100.
Il thread B stampa il numero generato.

Vincoli:

B non può stampare prima che A abbia generato il numero.
A non può generare un nuovo numero finché B non ha stampato quello precedente.
Devono essere stampati 20 numeri.*/

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t t1, t2; 
sem_t mutex; 
sem_t prod; 
sem_t cons; 
int number; 

void *A(void *args){

    for(int i = 0; i < 20; i++){

        sem_wait(&prod);
        sem_wait(&mutex); 
        number = (rand()%100)+1;
        
        sem_post(&mutex); 
        sem_post(&cons); 


    }

    pthread_exit(NULL); 

}
void *B(void *args){

    for(int i = 0; i < 20; i++){

        sem_wait(&cons); 
        sem_wait(&mutex); 
        printf("%d", number); 
    
        sem_post(&mutex); 
        sem_post(&prod);

    }


    pthread_exit(NULL); 

}


int main(){

    sem_init(&mutex, 0, 1); 
    sem_init(&cons, 0, 0);
    sem_init(&prod, 0, 1); 
    pthread_create(&t1, NULL, A, NULL); 
    pthread_create(&t2, NULL, B, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 

    sem_destroy(&mutex);
    sem_destroy(&prod); 
    sem_destroy(&cons); 
    
    return 0; 
    



}