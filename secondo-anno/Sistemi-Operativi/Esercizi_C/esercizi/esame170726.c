/*scrivere un programma in linguaggio C che utilizzi thread posix, mutex e variabili di condizione

il processo principale: 
    inizializza una variabile condivisa X a 0
    inizializza una variabile condivisa di terminazione a 0
    apre in scrittura il file risultati.txt
    crea tre thread produttori e uno controllore 

Ogni thread controllore attende, senza attesa attiva e utilizzando una variabile, che X diventi maggiore o uguale
a 100. Raggiunta la soglia, stampa il valore di X e imposta la variabile condivisa di terminazione 

Ogni thread produttore, finché la variabile di terminazione non risulta impostata: 
    genera un numero casuale 
    somma il numero generato pari a X
    stampa a schermo il proprio identificare 
    scrive nel file risultato.txt il numero generato in formato binario
    segnala al controllore l'avvenuta modifica di X tramite la variabile di condizione 
    attende da 1 a 3 secondi prima di effettuare 

L'accesso a X, al file e alla variabile di terminazione deve avvenire in mutua esclusione 
Il processo principale attende la terminazione di tutti i thread, chiude il file e conclude il programma*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/signal.h>
#include <time.h>



int X; 
int done; 
int fd; 
pthread_t t1, t2, t3, t4; 
pthread_mutex_t mutex; 
pthread_cond_t cond; 


void *producers(void *args){

    while(1){
        sleep(rand()%3 + 1); 

        int n = rand() % 10 + 1; 

        pthread_mutex_lock(&mutex); 

        if(done){
            pthread_mutex_unlock(&mutex); 
            break; 
        }

        X+=n; 

        printf("Thread %ld ha prodotto %d\n", pthread_self(), n);
        
        write(fd, &n, sizeof(int)); 

        pthread_cond_signal(&cond); 

        pthread_mutex_unlock(&mutex); 
    }



}
void *controller(void *args){

    pthread_mutex_lock(&mutex); 

    while(X < 100){
        pthread_cond_wait(&cond, &mutex); 
    }

    if(X>=100){
        printf("%d", X); 

        done = 1; 
    }

    pthread_mutex_unlock(&mutex); 


}
int main(){
    X = 0; 
    done = 0; 
    fd = open("risultati.txt", O_WRONLY | O_CREAT | O_APPEND, 0644); 

    pthread_mutex_init(&mutex, NULL); 
    pthread_cond_init(&cond, NULL); 

    pthread_create(&t1, NULL, producers, NULL); 
    pthread_create(&t2, NULL, producers, NULL); 
    pthread_create(&t3, NULL, producers, NULL); 
    pthread_create(&t4, NULL, controller, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    pthread_join(t4, NULL); 

    pthread_mutex_destroy(&mutex); 
}