/*Scrivere un programma in linguaggio C che utilizzi thread POSIX.

Il processo principale:

apre il file input.txt in sola lettura utilizzando open();
apre il file output.txt in scrittura utilizzando open();
crea 3 thread lavoratori e 1 thread controllore.
I tre thread lavoratori

In un ciclo infinito:

leggono un carattere alla volta dal file input.txt mediante read();
se il carattere è una lettera minuscola (a-z), lo convertono in maiuscolo;
scrivono il carattere (eventualmente convertito) nel file output.txt mediante write();
attendono 1 secondo prima di leggere il carattere successivo.
Il thread controllore

Ogni 2 secondi:

utilizza lseek() per determinare la dimensione corrente del file output.txt;
stampa:
Dimensione file output: X byte

dove X è il numero di byte presenti nel file.

Il programma termina quando

Il file output.txt raggiunge o supera 80 byte.

Requisiti
input.txt deve essere aperto una sola volta e condiviso tra tutti i thread.
output.txt deve essere aperto una sola volta e condiviso tra tutti i thread.
La lettura dal file, la scrittura sul file e la verifica della condizione di terminazione devono avvenire in mutua esclusione.
Tutti i thread devono terminare ordinatamente utilizzando una variabile condivisa done.
Utilizzare esclusivamente primitive POSIX per l'accesso ai file.*/

#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>


int f1; 
int f2; 
int done;


pthread_t t1, t2, t3, t4; 
pthread_mutex_t mutex; 
pthread_mutex_t mdone; 

void *workers(void *args){

    while(!done){

        pthread_mutex_lock(&mutex); 

        char c;
        int n = read(f1, &c, 1);
        if(n==0){
            pthread_mutex_unlock(&mutex); 
            pthread_mutex_lock(&mdone); 
            done = 1; 
            pthread_mutex_unlock(&mdone);
            break; 
        }

        if(c>='a' && c<='z'){

            c = c-('a'-'A'); 
            write(f2, &c, 1);

        }
        

        pthread_mutex_unlock(&mutex); 
        sleep(1); 


    }

    pthread_exit(NULL); 


}
void *controller(void *args){
    while(!done){
        pthread_mutex_lock(&mutex); 

        int dim = lseek(f2, 0, SEEK_END); 

        printf("Dimensione del file di output: %d\n", dim ); 

        if(dim >= 80){
            pthread_mutex_unlock(&mutex); 
            pthread_mutex_lock(&mdone); 
            done = 1; 
            pthread_mutex_unlock(&mdone); 
            break; 
        }
        pthread_mutex_unlock(&mutex); 
        sleep(2); 
        
    }


    pthread_exit(NULL); 

}
int main(){

    f1 = open("input.txt", O_RDONLY); 
    f2 = open("output.txt", O_RDWR | O_TRUNC | O_CREAT | O_APPEND, 0644); 
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

    pthread_mutex_destroy(&mutex); 
    pthread_mutex_destroy(&mdone); 

    close(f1); 
    close(f2); 




}
