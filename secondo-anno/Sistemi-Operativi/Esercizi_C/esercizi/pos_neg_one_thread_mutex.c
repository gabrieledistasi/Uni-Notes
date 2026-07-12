/*
Scrivere un programma C che segue le seguenti specifiche.
Il processo eseguito, inizialmente crea un buffer come array di 11 numeri interi, inizializzati a zero.
In seguito genera tre thread utilizzando le librerie POSIX secondo le seguenti specifiche:
•   Il primo thread sceglie casualmente una cella del buffer e vi scrive il numero +1,
    qualsiasi sia il valore presente nella cella.
•   Il secondo thread sceglie casualmente una cella del buffer e vi scrive il numero -1,
    qualsiasi sia il valore presente nella cella.
•   Il terzo thread controlla se tutte le celle del buffer sono state inizializzate.
    In caso positivo, determina se il numero di celle contententi un valore pari a +1 è maggiore di quelle con -1
    e termina tutti e tre i thread.
•  Mentre un thread ha accesso al buffer, nessun altro thread deve accedervi.
•  Una volta che un thread ha acceduto in lettura o scrittura al buffer,
   deve attendere un numero di secondi random tra 0 e 3.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

#define N 11
#define true 1

pthread_t t1; 
pthread_t t2; 
pthread_t t3; 

pthread_mutex_t mutex; 
int buffer[N] = {0}; 


void *jobt1(void *args){

    while(true){


    pthread_mutex_lock(&mutex); 

    sleep(rand()%4); 
    buffer[rand()%N] = 1; 

    pthread_mutex_unlock(&mutex); 





    }
    pthread_exit(NULL); 


}

void *jobt2(void *args){

    while (true){

    pthread_mutex_lock(&mutex); 

    sleep(rand()%4); 
    buffer[rand()%N] = -1; 

    pthread_mutex_unlock(&mutex); 


    }

    pthread_exit(NULL); 

}

void *jobt3(void *args){

    int count_pos = 0; 
    int count_neg = 0; 

    pthread_mutex_lock(&mutex); 

    sleep(rand()%4); 

    for(int i = 0; i < N; i++){
        
        if(buffer[i]==1){
            count_pos++; 
        } 
        else if(buffer[i]==-1){
            count_neg++; 
        }
    }

    pthread_mutex_unlock(&mutex); 

    if(count_pos > count_neg){
        printf("numero di elementi positivi maggiori degli elementi negativi"); 
    }
    else if(count_neg > count_pos){
        printf("numero di elementi negativi maggiore degli elementi positivi"); 
    }
    else{
        printf("numero di elementi negativi uguale al numero di elementi positivi"); 
    }

    pthread_cancel(t1); 
    pthread_cancel(t2); 
    pthread_exit(NULL);     


}

int main(){

    srand(time(NULL)); 

    for(int i = 0; i < N; i++){
        buffer[i] = 0; 
    }

    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&t1, NULL, jobt1, NULL); 
    pthread_create(&t2, NULL, jobt2, NULL); 
    pthread_create(&t3, NULL, jobt3, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL);



    pthread_mutex_destroy(&mutex); 
    return 0; 

}
