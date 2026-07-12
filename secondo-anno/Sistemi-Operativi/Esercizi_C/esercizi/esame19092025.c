/*scrivere un programma in C che utilizzi processi e pipe per implementare il seguente comportamento.
Un processo padre genera un processo figlio
*   il padre disabilita la gestione del segnale SIGINT, genera numeri casuali tra 1 e 100 in un ciclo infinito e li 
    invia al figlio tramite una pipe 

*   Il figlio apre la directory corrente "." conta quali file regolari sono presenti ed esegue fino a 100 iterazioni.
    In ciascuna iterazione legge il numero inviato dal padre e, se il numero ricevuto è uguale al numero di file presenti
    stampa un messaggio ed esce dal ciclo

In ogni caso, una volta terminato il ciclo, il figlio termina il padre e poi termina anch'esso*/


#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#define true 1


int main(int argc, char *argv[]){

    int fd[2]; 
    pipe(fd); 
    pid_t p1 = fork();
 

 
    if(p1 == 0){

        close(fd[1]); 
        int count = 0; 
        int x; 

        DIR *d = opendir("."); 

        struct dirent *entry; 

        while((entry=readdir(d))!=NULL){

            if (entry->d_type == DT_REG){
                count++; 
            } 

        }

        closedir(d); 

        for(int i = 0; i < 100; i++){
            read(fd[0], &x, sizeof(int)); 

            if(x==count){
                fprintf(stdout, "Il numero ricevuto è uguale al numero di file presenti"); 
                break; 

            }



        }

        kill(getppid(), SIGTERM); 
        exit(0); 


    }
    else{

    close(fd[0]); //chiudiamo la pipe

    signal(SIGINT, SIG_IGN); //disabilitiamo i segnali nel padre

    srand(time(NULL)); 
    while(true){

        int r_value = (rand()%100)+1; 
        write(fd[1], &r_value, sizeof(int)); 
        sleep(2); 
    }

    }
}

