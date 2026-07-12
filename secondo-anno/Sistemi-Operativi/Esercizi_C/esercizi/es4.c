/*scrivere un programma in C che utilizza tre thread su un buffer di 15 interi inizializzati a zero

*   il thread incrementa casualmente posizioni del buffer aggiungendo +2 
*   Il secondo thread decrementa casualmente posizioni del buffer sottraendo -3
*   Il terzo thread verifica periodicamente il contenuto del buffer e calcola la differenza tra valore massimo e minimo

il programma termina quando la differenza supera una soglia prefissata
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#define true 1
#define false 0
#define soglia 14

void *work(void *arg); 
void *check(void *arg); 
int buffer[15]; 
int done = false; 
pthread_mutex_t mbuffer; 
pthread_mutex_t mdone; 



int main(){

    for(int i = 0; i < 15; i++){
        buffer[i] = 0; 

    }

    pthread_t due, meno_tre, chk; 
    pthread_mutex_init(&mbuffer, NULL); 
    pthread_mutex_init(&mdone, NULL); 

    srand(time(NULL)); 


    int value = 2; 
    pthread_create(&due, NULL, work, (void*)(long) value); 
    value = -3; 
    pthread_create(&meno_tre, NULL, work, (void*)(long) value);
    pthread_create(&chk, NULL, check, NULL); 
    
    pthread_join(due, NULL); 
    pthread_join(meno_tre, NULL); 
    pthread_join(chk, NULL);

    pthread_mutex_destroy(&mdone); 
    pthread_mutex_destroy(&mbuffer); 




    

    

}

void *work(void *arg){

    int value =(int)(long) arg; 
    int done_local = false; 
    while(!done_local){
        pthread_mutex_lock(&mdone);//proteggo quello che c'è nella riga sotto 
        done_local = done; 
        pthread_mutex_unlock(&mdone); 

        if(done_local) break; 

        //lavoro del thread
        int rand_idx = rand() % 15; 
        pthread_mutex_lock(&mbuffer); 
        buffer[rand_idx] += value; 
        pthread_mutex_unlock(&mbuffer); 



    }

    pthread_exit(0); 
}

void *check(void *arg){
    int max_n = buffer[0]; 
    int min_n = buffer[0]; 
    while(true){
        pthread_mutex_lock(&mbuffer); 

        for(int i = 0; i < 15; i++){
            max_n = (buffer[i]>max_n) ? buffer[i] : max_n; 
            min_n= (buffer[i]<min_n) ? buffer[i] : min_n; 

        }

        if((max_n-min_n) > soglia){
            pthread_mutex_unlock(&mbuffer); 
            break; 
        }
        pthread_mutex_unlock(&mbuffer); 

    }
    pthread_mutex_lock(&mdone); 
    done = true; 
    pthread_mutex_unlock(&mdone); 
    pthread_exit(NULL); 
}