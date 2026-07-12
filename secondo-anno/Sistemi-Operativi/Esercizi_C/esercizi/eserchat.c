/*Scrivere un programma in C che utilizzi thread POSIX.

Il processo principale apre un file "numeri.txt" contenente interi.

Successivamente crea 3 thread.

Ogni thread:

• legge un numero dal file condiviso;
• ne calcola il quadrato;
• scrive il risultato su output.txt.

Il programma termina quando tutti i numeri sono stati elaborati.

Requisiti:

• il file deve essere aperto una sola volta;
• la lettura deve avvenire in mutua esclusione.*/


#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define true 1


pthread_t t1, t2, t3; 
pthread_mutex_t mutex; 
pthread_mutex_t mdone; 

int done = 0; 

FILE *fp; 
FILE *fd; 


void *job(void *args){



    while(!done){

 

        int numero; 

        pthread_mutex_lock(&mutex); 


        if(fscanf(fp, "%d", &numero)!=1){


            done = 1; 
            pthread_mutex_unlock(&mdone); 

            pthread_mutex_unlock(&mutex); 

            break; 
        }

        pthread_mutex_unlock(&mutex); 


         //leggo il numero e lo salvo in una variabile
        numero = numero*numero; //faccio il quadrato


        pthread_mutex_lock(&mutex); 

        fprintf(fd, "%d\n", numero); //scrivo il numero nel file output

        pthread_mutex_unlock(&mutex); 

        




    }

    pthread_exit(NULL); 


    
}


int main(){

    fp = fopen("numeri.txt", "r");
    fd = fopen("output.txt", "w");

    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&t1, NULL, job, NULL); 
    pthread_create(&t2, NULL, job, NULL); 
    pthread_create(&t3, NULL, job, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 

    pthread_mutex_destroy(&mutex); 
    pthread_mutex_destroy(&mdone); 

}
