/*Sei thread, un scrittore e 5 lettori. 
Lo scrittore scrive su un buffer numeri dispari da 0 a 50 nelle posizioni pari 
e numeri pari da 50 a 100 nelle posizioni dispari. I lettori
leggono coppie di numeri (paro, disparo), li somma e li stampa.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define N 100


pthread_t t1, t2, t3, t4, t5, t6;
pthread_mutex_t mutex; 

int buffer[N] = {0}; 

void *writer(void *args){

    pthread_mutex_lock(&mutex); 

    int dispari = 1; 
    int pari = 50; 

    for(int i = 0; i < N; i++){

        if(i%2==0){ //se sono in una posizione dispari

            buffer[i] = dispari; 
            dispari+=2; 
            
        }
        else{
            buffer[i] = pari; 
            pari+=2; 

            if(pari > 100){
                pari = 50; 
            }
        }
    }

    pthread_mutex_unlock(&mutex); 

    pthread_exit(NULL); 
}

void *readers(void *args){

    pthread_mutex_lock(&mutex); 

    for(int i = 1; i < N; i+=2){

        int sum = buffer[i]+buffer[i-1]; 
        printf("Somma tra %d e %d: %d\n", buffer[i], buffer[i-1], sum); //primo e ultimo, secondo e penultimo ecc...
        sleep(2); 
        

    }

    pthread_mutex_unlock(&mutex); 
    pthread_exit(NULL); 
    
}

int main(){

    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&t1, NULL, writer, NULL); 
    pthread_create(&t2, NULL, readers, NULL); 
    pthread_create(&t3, NULL, readers, NULL); 
    pthread_create(&t4, NULL, readers, NULL); 
    pthread_create(&t5, NULL, readers, NULL); 
    pthread_create(&t6, NULL, readers, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    pthread_join(t4, NULL); 
    pthread_join(t5, NULL); 
    pthread_join(t6, NULL); 

    pthread_mutex_destroy(&mutex); 

}



