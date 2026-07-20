/*
Scrivere un programma in linguaggio C che utilizzi thread POSIX.

Il processo principale:

inizializza un buffer di 25 interi a zero;
crea 4 thread.

I primi tre thread, in un ciclo infinito:

scelgono casualmente una posizione del buffer;
generano un numero casuale compreso tra 1 e 10;
aggiungono tale numero alla posizione scelta;
attendono 1 secondo prima di ripetere l'operazione.

Il quarto thread, ogni 3 secondi:

calcola il valore massimo presente nel buffer;
stampa:
Valore massimo corrente: X

dove X è il massimo trovato.

Il programma termina quando

Il valore massimo del buffer supera 100.

Requisiti
Il buffer deve essere condiviso tra tutti i thread.
Tutti gli accessi al buffer devono avvenire in mutua esclusione.
Alla terminazione, tutti i thread devono concludere la propria esecuzione ordinatamente.
Il buffer deve essere inizializzato una sola volta dal processo principale.*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define true 1 
#define N 25

pthread_t t1, t2, t3, t4; 
int buffer[25]={0}; 
pthread_mutex_t mutex; 
pthread_mutex_t mdone; 
int done = 0; 
int X; 

void *randbuff(void *args){

    while(!done){

        pthread_mutex_lock(&mutex); 

        buffer[rand()%N] += (rand()%10)+1; 


        pthread_mutex_unlock(&mutex); 
        sleep(1); 
    }


    pthread_exit(NULL);

}

void *jobt4(void *args){

    while(!done){
        
        pthread_mutex_lock(&mutex); 
        X = buffer[0]; 
        for(int i = 1; i<N; i++){

            if(buffer[i]>X){
                X = buffer[i]; 
                
            }

        }

        
        pthread_mutex_unlock(&mutex); 
        if(X >= 100){

            pthread_mutex_lock(&mdone); 
            done = 1; 
            pthread_mutex_unlock(&mdone);

        }
        printf("Massimo nel buffer: %d\n", X); 
        sleep(3); 
            
            
        

    }

    pthread_exit(NULL); 
}

int main(){

    srand(time(NULL)); 

    pthread_mutex_init(&mutex, NULL); 
    pthread_mutex_init(&mdone, NULL); 

    pthread_create(&t1, NULL, randbuff, NULL); 
    pthread_create(&t2, NULL, randbuff, NULL); 
    pthread_create(&t3, NULL, randbuff, NULL); 
    pthread_create(&t4, NULL, jobt4, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    pthread_join(t4, NULL); 

    pthread_mutex_destroy(&mutex); 
    pthread_mutex_destroy(&mdone); 
}