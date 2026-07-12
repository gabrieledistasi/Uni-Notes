/*
Scrivere un programma in C che utilizzi thread POSIX.

Il processo principale:

• inizializza un buffer di 20 interi a zero;
• crea 4 thread.

I primi tre thread, in un ciclo infinito:

• scelgono casualmente una posizione del buffer;
• incrementano il valore della posizione scelta di un valore casuale compreso tra 1 e 5;
• attendono un secondo prima di ripetere.

Il quarto thread:

• ogni due secondi calcola la somma di tutti gli elementi del buffer;
• stampa la somma.

Il programma termina quando la somma supera 200.

Requisiti:

• il buffer deve essere condiviso tra tutti i thread;
• ogni accesso al buffer deve avvenire in mutua esclusione;
• tutti i thread devono terminare ordinatamente.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


#define N 20
#define true 1

pthread_t t1, t2, t3, t4; 
pthread_mutex_t mutex; 

int buffer[N] = {0}; 
int done = 0; 


void *randinc(void *args){

    while(!done){

        pthread_mutex_lock(&mutex); 

        buffer[rand()%N] += (rand()%5)+1;  //scegli una posizione casuale e incrementala di un numero casuale da 1 a 5


        pthread_mutex_unlock(&mutex); 

        sleep(1); 



    }


    pthread_exit(NULL); 


    

}

void *sum(void *args){

    int sum = 0; 

    

    while(!done){

        pthread_mutex_lock(&mutex); 

        for(int i = 0; i < N; i++){

            sum += buffer[i]; 
            
            

        }
        
        if(sum > 200){
                done = true; 
                
            } 

        pthread_mutex_unlock(&mutex); 

        printf("La somma tra gli elementi del buffer è: %d\n", sum); 

        sum = 0; 

        sleep(2); 
    }

    pthread_exit(NULL); 


    

}


int main(){

    srand(time(NULL)); 

    for(int i = 0; i < N; i++){
        buffer[i] = 0; 
    }

    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&t1, NULL, randinc, NULL); 
    pthread_create(&t2, NULL, randinc, NULL);
    pthread_create(&t3, NULL, randinc, NULL); 
    pthread_create(&t4, NULL, sum, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    pthread_join(t4, NULL); 

    pthread_mutex_destroy(&mutex); 
}