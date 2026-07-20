/*Due thread, il produttore inserisce numeri pari da 0 a 100 in posizioni pari e numeri dispari
da 100 a 200 in posizioni dispari all'interno di un buffer contenente N elementi, inizializzato a -1, il consumatore
legge dal buffer un numero pari e un numero dispari, li somma e stampa la loro somma*/

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 20

sem_t prod; 
sem_t cons;

pthread_mutex_t mutex; 
pthread_t t1, t2; 

int buffer[N]; 


void *producer(void *args){

    sem_wait(&prod); 
    pthred_mutex_lock(&mutex); 
    for(int i = 0; i < N; i++){
        if (i%2==0){
            buffer[i] = (rand()%51)*2; 
        }
        else{
            buffer[i] = 101 + (rand()%50)*2; 
        }
    }

    pthread_mutex_unlock(&mutex); 
    sem_post(&cons); 

    pthread_exit(NULL); 
}
void *consumer(void *args){

    sem_wait(&cons);
    pthread_mutex_lock(&mutex); 
    int sum = 0; 
    for(int i = 1; i < N; i++){
        sum = buffer[i-1] + buffer[i]; 
        printf("somma tra i due numeri: %d\n", sum); 
        i++; 
        sum = 0; 

    }
    pthread_mutex_unlock(&mutex); 
    sem_post(&prod); 

    pthread_exit(NULL); 
}



int main(){

    for(int i = 0; i < N; i++){ //inizializzazione del buffer
        buffer[i] = -1; 
    }

    sem_init(&prod, 0, 1); 
    sem_init(&cons, 0, 0); 

    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&t1, NULL, producer, NULL); 
    pthread_create(&t2, NULL, consumer, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 

    pthread_mutex_destroy(&mutex); 
    sem_destroy(&cons); 
    sem_destroy(&prod); 
}
