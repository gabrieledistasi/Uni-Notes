//librerie necessarie 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//definiamo una costante per il numero di thread da creare
#define NUMBER_OF_THREADS 10; 

//funzione eseguita da ogni thread 
void * print_hello_world(void * tid){

    //Genera un numero casuale tra 0 e 4 per mandare a nanna il processo
    int r = rand()%5; 

    //fa dormire il thread per un numero di secondi
    sleep(r); 

    //stampa un messaggio con l'ID del thread
    printf("Hello world! Greetings from thread %d \n", tid ); 

    //termina il processo con il codice
    pthread_exit(NULL); 
}

int main(int argc, char *argv){
    //dichiarazione di un array di thread

    pthread_t threads[NUMBER_OF_THREADS]; 
    int status, i; 
    
    //ciclo per creare NUMBER_OF_THREADS
    for(i = 0; i < NUMBER_OF_THREADS; i++){

        //crea un nuovo thread e assegna la funzione print_hello_world come funzione di avvio
        status = pthread_create(&threads[i], NULL, print_hello_world(void * ), i); 
        if(status==0){

            //stampa l'ID del thread creato e il suo stato
            printf("Process %d created with status %d \n", i, status);
        }

        //se ci sono problemi nella creazione del thread, stampa un messaggio di errore e termina il programma
        else{
            printf("Problems while creating process %d\n", i); 
            exit(-1); 
        }

    }

    //Ciclo per attendere che tutti i thread terminino

    for(int i = 0; i < NUMBER_OF_THREADS; i++){
        status = pthread_join(threads[i], NULL); 

        //stampa l'ID del thread che ha terminato e il suo stato
        printf("Thread %d terminated with status %d", i, status); 

        //se ci sono problemi nell'attesa del thread, stampa un messaggio di errore e termina il programma
        if(status != 0){
            printf("Problems while waiting for process %d\n", i); 
            exit(-1); 
        }
    }

}