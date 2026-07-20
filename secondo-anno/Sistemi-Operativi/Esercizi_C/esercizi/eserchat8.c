/*Un programma crea tre thread:

T1 legge una riga da un file e la salva in una variabile condivisa buffer.
T2 converte tutti i caratteri della riga in maiuscolo.
T3 stampa la riga elaborata.

Il programma deve elaborare 10 righe.

Vincoli

L'ordine deve essere sempre:

T1 → T2 → T3

e poi ricominciare:

T1 → T2 → T3
T1 → T2 → T3
...

Mai:

T1 → T1

oppure

T2 → T3 → T2
Regole
Usa solo semafori (sem_t).
Usa un mutex per proteggere il buffer condiviso.
Non usare variabili globali di controllo (flag, turn, ecc.).*/
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

sem_t s1; 
sem_t s2; 
sem_t s3; 

pthread_mutex_t mutex; 
int *buffer; 
int *f1; 

pthread_t t1, t2, t3; 

void *jobt1(void *args){

    sem_wait(&s1)
    pthread_mutex_lock(&mutex); 
    f1 = open("input.txt", O_RDONLY); 
    char c; 
    int i = 0; 

    while(read(f1, &c, 1) > 0 && c !=  '\n'){
        buffer[i++] = c; 
    }
    buffer[i] = '\0'; 
    pthread_mutex_unlock(&mutex); 
    sem_post(&s2); 

    pthread_exit(NULL); 

}

void *jobt2(void *args){
    
    sem_wait(&s2); 
    pthread_mutex_lock(&mutex); 
    
}


int main(){

    sem_init(); 
    sem_init(); 
    sem_init(); 

    pthread_create(); 
    
    pthread_join(); 

    sem_destroy(); 
}