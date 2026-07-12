/*
1.  Il programma crea un file chiamato dati.txt" contenente un array di 10 numeri interi, inizializzati a zero.
    Ogni numero deve essere separato da uno spazio.
2.  Genera tre thread utilizzando le librerie POSIX:
    • Il primo thread legge il contenuto del file "dati.txt", imposta 1 una cella causale
    scrive i nuovi valori nel file.
    Il thread esegue questa operazione in un ciclo infinito con una pausa casuale tra le iterazioni.
    • Il secondo thread legge il contenuto del file "dati.txt", imposta -1 una cella casuale
    scrive i nuovi valori nel fie.
    Il thread esegue questa operazione in un ciclo infinito con una pausa casuale tra le iterazioni.
    • Il terzo thread, in un ciclo infinito, controlla se tutti i valori nel file sono diversi da 0, se lo sono, conta gli +- uni.
    In caso affermativo, termina entrambi i thread.
4.  Assicurati che un thread abbia accesso esclusivo al file mentre legge o scrive. Utilizza I mutex per gestire
    l'accesso concorrente al file.
5.  Introduci una pausa casuale tra le operazioni di lettura e scrittura del thread.
*/


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define N 10
#define true 1


pthread_t t1; 
pthread_t t2; 
pthread_t t3; 

pthread_mutex_t mutex; 
int buffer[N] = {}; 

void *jobt1(void *args){

    while(true){

        sleep(rand()%4); 

        pthread_mutex_lock(&mutex); 
        FILE *fp = fopen("dati.txt", "r"); 

        for(int i = 0; i < N; i++){
            fscanf(fp, " %d ", &buffer[i]); 
        }

        fclose(fp); 

        buffer[rand()%N] = 1; 

        fp = fopen("dati.txt", "w"); 

        for(int i = 0; i < N; i++){
            fprintf(fp, " %d ", buffer[i]); 
        }
        fclose(fp); 

        pthread_mutex_unlock(&mutex); 

    
    }
    pthread_exit(NULL); 

    


}
void *jobt2(void *args){

    while(true){

        sleep(rand()%4); 

        pthread_mutex_lock(&mutex); 
        FILE *fp = fopen("dati.txt", "r"); 

        for(int i = 0; i < N; i++){
            fscanf(fp, " %d ", &buffer[i]); 
        }

        fclose(fp); 

        buffer[rand()%N] = -1; 

        fp = fopen("dati.txt", "w"); 

        for(int i = 0; i < N; i++){
            fprintf(fp, " %d ", buffer[i]); 
        }
        fclose(fp); 

        pthread_mutex_unlock(&mutex); 

    
    }
    pthread_exit(NULL); 

    



}
void *jobt3(void *args){

    while(true){
        sleep(rand()%4); 
        int c = 0; 
        int pos = 0; 
        int neg = 0; 
        pthread_mutex_lock(&mutex); 
        FILE *fp = fopen("dati.txt", "r"); 

        for(int i = 0; i < N; i++){

            fscanf(fp, "%d", &buffer[i]); 

            if(buffer[i]!=0){
                c++; 
            }

        }

        fclose(fp);


        

        

        if(c == N){

            for(int i = 0; i < N; i++){
                
                
                if(buffer[i]==1){
                    pos++; 

                }
                else{
                    neg++; 
                }
            
            }

            pthread_mutex_unlock(&mutex); 

            pthread_cancel(t1); 
            pthread_cancel(t2); 
            pthread_exit(NULL); 
            

        }
        else{
        
            pthread_mutex_unlock(&mutex); 
        }

    }


}





int main(){


    FILE *fp = fopen("dati.txt", "w"); 
    


    for(int i = 0; i < 10; i++ ){
        fprintf(fp, "%d ", 0); 
    }
    
    fclose(fp); 

    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&t1, NULL, jobt1, NULL); 
    pthread_create(&t2, NULL, jobt2, NULL); 
    pthread_create(&t3, NULL, jobt3, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 

    pthread_mutex_destroy(&mutex); 




}