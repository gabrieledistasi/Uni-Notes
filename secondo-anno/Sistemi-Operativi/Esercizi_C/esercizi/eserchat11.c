/*
Scrivere un programma in C che utilizzi thread POSIX, mutex e variabili di condizione.

Il processo principale:

inizializza un buffer circolare di dimensione 5
inizializza una variabile condivisa di terminazione a 0
crea 2 thread produttori e 2 thread consumatori
Ogni thread produttore

Finché la variabile di terminazione non è impostata:

genera un numero casuale tra 1 e 100
inserisce il numero nel buffer
stampa
Produttore <id> ha inserito <numero>
segnala ai consumatori che è disponibile un elemento
attende un tempo casuale tra 1 e 2 secondi

Se il buffer è pieno deve attendere senza busy waiting.

Ogni thread consumatore

Finché la variabile di terminazione non è impostata:

attende che il buffer non sia vuoto
estrae un elemento
stampa
Consumatore <id> ha letto <numero>
se il numero letto è 100
imposta la variabile di terminazione
risveglia tutti gli altri thread
termina
Vincoli
Il buffer deve essere protetto mediante mutex.
La variabile di terminazione deve essere protetta dal mutex.
È vietata l'attesa attiva.
Devono essere utilizzate una o più variabili di condizione.
Il processo principale deve attendere la terminazione di tutti i thread.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>


int buffer[5]; 
int done; 
int in = 0;  
int out = 0;  
int count = 0; 


pthread_t t1, t2, t3, t4; 
pthread_mutex_t mutex;
pthread_mutex_t mdone; 

pthread_cond_t not_empty; 
pthread_cond_t not_full; 

void *producers(void *args){
    
    while(1){

        int n = rand()%10 + 1; 

        pthread_mutex_lock(&mutex); 

        while(count == 5 && !done)
            pthread_cond_wait(&not_full, &mutex);
            
        if(done){
            pthread_mutex_unlock(&mutex); 
            break; 
        }
        
        buffer[in] = n; 
        in = (in+1)%5; 
        count++; 
        printf("thread produttore: %ld ha inserito il numero: %d\n", pthread_self(), n); 

        pthread_cond_signal(&not_empty);
        
        pthread_mutex_unlock(&mutex); 
        sleep(rand()%2+1); 




    }
    pthread_exit(NULL); 
}

void *consumers(void *args){
    while(1){

        pthread_mutex_lock(&mutex); 

        while(count==0 && !done){

            pthread_cond_wait(&not_empty, &mutex); 


        }

        if(done){
            pthread_mutex_unlock(&mutex); 
            break; 
        }

        int number = buffer[out]; 
        out = (out+1)%5; 
        count--; 
        printf("Thread %ld ha stampato il numero %d\n", pthread_self(), number); 

        if(number == 100){

            pthread_mutex_lock(&mdone); 
            done = 1; 
            pthread_mutex_unlock(&mdone); 
            break; 
        }

    }

    pthread_exit(NULL); 
}

int main(){

    for(int i = 0; i < 5; i++){
        buffer[i]=0; 
    }

    done = 0; 

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mdone, NULL); 

    pthread_cond_init(&not_empty, NULL); 
    pthread_cond_init(&not_full, NULL); 

    pthread_create(&t1, NULL, consumers, NULL); 
    pthread_create(&t2, NULL, consumers, NULL); 
    pthread_create(&t3, NULL, producers, NULL); 
    pthread_create(&t4, NULL, producers, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    pthread_join(t4, NULL); 

    pthread_mutex_destroy(&mutex); 
    pthread_mutex_destroy(&mdone); 
    
    pthread_cond_destroy(&not_empty); 
    pthread_cond_destroy(&not_full); 

    exit(0);

}