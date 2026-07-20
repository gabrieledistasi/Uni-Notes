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
pthread_mutex_t mdone; 


void *producers(void *args){

    while(!done){
        sleep(rand()%3 + 1); 

        int n = rand() % 10 + 1; 

        pthread_mutex_lock(&mutex); 


        X+=n; 

        printf("Thread %ld ha prodotto %d\n", pthread_self(), n);
        
        write(fd, &n, sizeof(int)); 



        pthread_mutex_unlock(&mutex); 
    }



}
void *controller(void *args){

    while(!done){


        pthread_mutex_lock(&mutex); 


        if(X>=100){
            printf("%d", X); 

            pthread_mutex_lock(&mdone); 
            done = 1; 
            pthread_mutex_unlock(&mdone); 
            pthread_mutex_unlock(&mutex); 

        }

        pthread_mutex_unlock(&mutex); 
    }

    pthread_exit(NULL); 
}

int main(){
    X = 0; 
    done = 0; 
    fd = open("risultati.txt", O_WRONLY | O_CREAT | O_APPEND, 0644); 

    pthread_mutex_init(&mutex, NULL); 
    pthread_cmutex_init(&mdone, NULL); 

    pthread_create(&t1, NULL, producers, NULL); 
    pthread_create(&t2, NULL, producers, NULL); 
    pthread_create(&t3, NULL, producers, NULL); 
    pthread_create(&t4, NULL, controller, NULL); 

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    pthread_join(t3, NULL); 
    pthread_join(t4, NULL); 

    pthread_mutex_destroy(&mutex); 
    pthread_mutex_destroy(&mdone); 
}