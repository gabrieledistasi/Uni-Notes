/*
Scrivere un programma C che utilizzi 2 thread:

un produttore, che produce i numeri da 1 a 10;
un consumatore, che li consuma.

È presente un solo buffer condiviso, quindi:

il produttore deve aspettare se il buffer è pieno;
il consumatore deve aspettare se il buffer è vuoto.

Utilizzare:

pthread
semafori POSIX (sem_t)
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

int buffer; 
sem_t mutex; 
sem_t empty; 
sem_t full; 
pthread_t t1, t2; 

void *producer(void *args){
    sem_wait(&empty); //prima controlla se c'è spazio nel buffer
    sem_wait(&mutex); 
    buffer = rand()%10 + 1;
    sem_post(&mutex);
    sem_post(&full);

}
void *consumer(void *args){
    sem_wait(&full);
    sem_wait(&mutex);
    //consuma elemento 
    sem_post(&mutex);
    sem_post(&full);
}

int main(){
    srand(time(NULL));
    sem_init(&mutex, 0, 1); 
    sem_init(&empty, 0, 1); 
    sem_init(&full, 0, 0); 
}