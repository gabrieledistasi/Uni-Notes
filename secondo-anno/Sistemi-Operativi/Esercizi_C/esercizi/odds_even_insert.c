/*
Si scriva un programma con tre thread che risolvono il seguente problema:
Un buffer di n elementi inizializzato con a -1 viene riempito nel seguente modo:
    - Il primo thread aggiunge nelle posizioni pari del buffer un numero casuale da 0 a 100.
    - Il secondo thread aggiunge nelle posizioni dispari del buffer un casuale da 100 a 200.
    - Il terzo thread somma gli elementi e modifica il buffer nel seguente modo:
        buff[0] = buff[0], buff[1] = buff[1] + buff[0], buff[2] = buff[1] + buff[2]
Si proponga una soluzione di mutua esclusione.
*/


#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define n 10



pthread_t t1; 
pthread_t t2; 
pthread_t t3; 
pthread_mutex_t mutex; 

int buffer[n] = {-1}; 




void *t1(void *args){



        pthread_mutex_lock(&mutex); 
        for(int i= 0; i < n; i++){

            if(i%2==0){

                buffer[i] = rand()%101; 

            }


        }

        pthread_mutex_unlock(&mutex);  


    
    pthread_exit(NULL); 
}

void *t2(void *args){
    
        pthread_mutex_lock(&mutex); 
        for(int i = 0; i < n; i++){
            if(i%2!=0){
                buffer[i] = rand()%101 + 100; 
            }
        }

        pthread_mutex_unlock(&mutex); 
    

    
    pthread_exit(NULL); 
}

void *t3(void *args){
    

        pthread_mutex_lock(&mutex); 
        for(int i = 1; i < n; i++){
            buffer[i] = buffer[i]+buffer[i-1]; 

        }

        pthread_mutex_unlock(&mutex); 


    
    pthread_exit(NULL); 
}

int main(){

    srand(time(NULL)); 


    for(int i = 0; i < n; i++){
        buffer[i] = -1; 
    }

    pthread_mutex_init(&mutex, NULL); 
    pthread_create(&t1, NULL, t1, NULL); 
    pthread_create(&t2, NULL, t2, NULL);
    
    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 

    pthread_create(&t3, NULL, t3, NULL); 
    pthread_join(t3, NULL); 


    pthread_mutex_destroy(&mutex);

}