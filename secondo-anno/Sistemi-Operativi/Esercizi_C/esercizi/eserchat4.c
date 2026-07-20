/*
Scrivere un programma in C che utilizzi thread POSIX.

Il processo principale:

apre il file numeri.txt utilizzando open();
apre il file pari.txt utilizzando open();
crea 3 thread lavoratori e 1 thread controllore.
I tre thread lavoratori

In un ciclo:

leggono un carattere alla volta dal file numeri.txt tramite read();
se il carattere rappresenta una cifra pari (0,2,4,6,8), lo scrivono nel file pari.txt tramite write();
attendono un secondo.
Il thread controllore

Ogni due secondi:

utilizza lseek() per determinare la dimensione del file pari.txt;
stampa:
Byte presenti nel file: X

Il programma termina quando il file pari.txt supera 100 byte.
*/

#include <pthread.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define true 1 

int X; 
int done = 0; 
pthread_t t1, t2, t3, t4; 
int f1; 
int f2; 
pthread_mutex_t mutex; 
pthread_mutex_t mdone; 

void workers(void *args){

    while(!done){
        pthread_mutex_lock(&mutex); 

        char c; 

        int n = read(f1, &c, 1); 

        int number = c - '0'; 

        if(n==0){

            pthread_mutex_unlock(&mutex); 
            pthread_mutex_lock(&mdone); 

            done = 1; 

            pthread_mutex_unlock(&mdone); 

            break; 

        }

        if(number % 2 ==0 ){

            write(f2, &c, 1); 

        }

        pthread_mutex_unlock(&mutex);
        sleep(1); 

    }

    pthread_exit(NULL); 


}



void controller(void *args){

    while(!done){
        pthread_mutex_lock(&mutex); 

        int dim = lseek(f2, 0, SEEK_END); 

        printf("byte presenti nel file: %d\n", dim ); 

        pthread_mutex_unlock(&mutex); 


        if(dim > 100){
            pthread_mutex_lock(&mdone); 
            done = 1; 
            pthread_mutex_unlock(&mdone); 
            break; 
        }

        sleep(2); 
    

    }
    pthread_exit(NULL);
    
}

int main(){

    f1 = open("numeri.txt", O_RDONLY); 
    f2 = open("pari.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); 

    pthread_mutex_init(&mutex, NULL); 
    pthread_mutex_init(&mdone, NULL); 

    pthread_create(&t1, NULL, workers, NULL); 
    pthread_create(&t2, NULL, workers, NULL); 
    pthread_create(&t3, NULL, workers, NULL); 
    pthread_create(&t4, NULL, controller, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    pthread_join(t4, NULL); 


    pthread_mutex_destroy(&mdone); 
    pthread_mutex_destroy(&mutex);
    close(f1); 
    close(f2); 
    

}