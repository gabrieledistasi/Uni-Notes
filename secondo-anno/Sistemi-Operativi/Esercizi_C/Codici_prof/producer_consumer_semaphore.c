//esempio schema produttore consumatore 


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define N 10
#define true 1

//dichiarazione dei semafori

sem_t mutex; //semaforo per accesso esclusivo alla regione critica 
sem_t empty; //semaforo per contare i posti vuoti nel buffer 
sem_t full;  //semaforo per contare i posti pieni nel buffer

int buffer[N]; //Buffer condiviso tra produttore e consumatore
int in = 0; //indice dove inserire il prossimo elemento nel buffer

//funzioni helper per utilizzare i semafori 

void down(sem_t *sem){
    sem_wait(sem); 
}

void up(sem_t *sem){
    sem_post(sem); 
}

//funzione per inserire un elemento nel buffer
void remove_item(){
    printf("%i", in); 
    int item = buffer[in-1]; 
    printf("Prelevo %d da posizione %d\n", item, in); 
    in--; //decrementa l'indice
}

//funzione per stampare a video il contenuto del buffer
void print_buffer(){
    
    for(int i = 0; i < in; i++){
        printf("%d ", buffer[i]); 

    }

    printf("\n"); 
}

//funzione eseguita dal thread del produttore
void *producer(void *arg){
    while(true){
        down(&empty); //attende finché ci sono posti vuoti nel buffer
        down(&mutex); //entra nella regione critica

        insert_item(); //Inserisce un elemento nel buffer
        print_buffer(); //stampa il contenuto del buffer

        up(&mutex); //Esce dalla regione critica
        up(&full); //segnala che c'è un posto pieno in più nel buffer

    }
}


//funzione eseguita dal thread del consumatore 
void *consumer(void *arg){
    while(true){
        down(&full); //attende finché ci sono posti pieni nel buffer
        down(&mutex); //entra nella regione critica

        remove_item(); //preleva un item dal buffer
        print_buffer(); //stampa il buffer

        up(&mutex); //esce dalla regione critica
        up(&empty); //segnala che c'è un posto vuoto nel buffer
    }
}


int main(){
    pthread_t prod, cons; //dichiarazione dei thread

    //inizializzazione dei semafori
    sem_init(&mutex, 0, 1); 
    sem_init(&empty, 0, N); 
    sem_init(&full, 0, 1); 

    //creazione dei thread
    pthread_create(&prod, NULL, producer, NULL); 
    pthread_create(&cons, NULL, consumer, NULL); 

    //attesa della terminazione dei thread
    pthread_join(prod, NULL); 
    pthread_join(cons, NULL); 

    //distruzione dei semafori
    sem_destroy(&mutex); 
    sem_destroy(&empty); 
    sem_destroy(&full); 

    return 0; 

}