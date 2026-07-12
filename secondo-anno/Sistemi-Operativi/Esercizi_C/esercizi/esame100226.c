/*scrivere un programma in linguaggio c 
il processo principale: 
    conta il numero di file presenti nelal directory corrente . e memorizza il valore in una variabile 
    condivisa X
    *apre un file output.txt in scrittura
successivamente il processo crea 5 thread 
ogni thread, in un ciclo infinito: 
    *genera un numero casuale compreso da 1 a 100
    *se il numero è uguale alla variabile X:
        se uguale, stampa a schermo che il thread t ha trovato il numero giusto
        se diverso scrive il numero nel file 
        aspetta tre secondi prima di riprovare
    
Requisiti: 
    il file deve essere aperto una sola volta dal processo principale e condiviso tra i thread
    la verifica del numero , l'eventuale scrittura sul file e eventuale segnalazione di terminazione devono avvenire
    in mutua esclusione 
    alla vittoria di un thread, tutti i thread devono terminare ordinatamente
*/


#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define true 1
pthread_t t1, t2, t3, t4, t5; 
pthread_mutex_t mutex; 
FILE *fp; 

int X = 0; 

void *jobt(void *args){

    while(true){

    pthread_mutex_lock(&mutex); 

    

    

    int t1_guess = rand()%100 + 1;

    if(t1_guess == X){

        printf("Thread T: %d, numero corretto trovato N: %d\n", pthread_self(), t1_guess); 
        fclose(fp); 
        pthread_mutex_unlock(&mutex); 
        pthread_cancel(t1);
        pthread_cancel(t2); 
        pthread_cancel(t3); 
        pthread_cancel(t4); 
        pthread_cancel(t5);
          

    }
    else{

        fprintf(fp, "%d \n", t1_guess); 
        fclose(fp);     
        pthread_mutex_unlock(&mutex); 
        sleep(rand()%3 + 1); 



    }
    }







}


int main(){

    srand(time(NULL)); 

    DIR *d = opendir("."); 

    struct dirent *entry;
    
    while((entry=readdir(d)) != NULL){

        X++; 

    }

    if(X > 100){

        X = 100; 
    }

    closedir(d); 

    fp = fopen("output.txt", "w"); 

    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&t1, NULL, jobt, NULL);
    pthread_create(&t2, NULL, jobt, NULL);
    pthread_create(&t3, NULL, jobt, NULL);
    pthread_create(&t4, NULL, jobt, NULL);
    pthread_create(&t5, NULL, jobt, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    pthread_join(t4, NULL); 
    pthread_join(t5, NULL); 

    pthread_mutex_destroy(&mutex); 




    
}


