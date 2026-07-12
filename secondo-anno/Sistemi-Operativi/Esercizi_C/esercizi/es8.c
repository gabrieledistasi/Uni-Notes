 /*Si richiede di implementare un programma in linguaggio C che utilizzi il metodo delle fork per la comunicazione tra processi.
 Il programma dovrà creare un file di testo e poi creare due processi figli. Uno dei processi figli dovrà scrivere una sequenza di
 N numeri interi pari da 0 a 9 nel file, mentre l'altro processo figlio dovrà scrivere una sequenza di N numeri interi dispari da 0 a 9, attraverso
 la funzione seek va a scriverli subito dopo la sequenza degli N numeri pari nello stesso file.
 Il processo padre dovrà leggere i dati dal file e stamparli a video.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <wait.h>
#include <sys/stat.h>

#define N 5
#define PIPE_RD 0
#define PIPE_WR 1 


 int main(int argc, char *argv[]){


    int fd = open("ciao.txt", O_CREAT | O_RDWR, 0644); 

    

    

    pid_t P1 = fork(); 

    if(P1 == 0){

        srand(time(NULL) ^ getpid()); 

        int fd = open("ciao.txt", O_RDWR, 0644); 
        

        lseek(fd, 0, SEEK_SET); 

        

        for(int i = 0; i < N; i++){

            int p1_value = (rand()%5)*2; 
            write(fd, &p1_value, sizeof(int)); 


        }

    }
    else{
        pid_t P2 = fork(); 

        if(P2 == 0){

            srand(time(NULL) ^ getpid()); 

            int fd = open("ciao.txt", O_RDWR, 0644); 




            lseek(fd, sizeof(int)*N, SEEK_SET ); 

        

            for(int i = 0; i < N; i++){

                int p2_value = (rand()%5)*2 + 1; 
                write(fd, &p2_value, sizeof(int)); 

            }

        }
        else{

            wait(NULL);
            wait(NULL);

            int fd = open("ciao.txt", O_RDONLY);

            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            lseek(fd, 0, SEEK_SET);

            int value;

            printf("Contenuto del file:\n");

            for (int i = 0; i < 2 * N; i++) {

                if (read(fd, &value, sizeof(int)) != sizeof(int)) {
                    perror("read");
                    break;
                }

                printf("%d ", value);
            }

            printf("\n");

            close(fd);
            exit(0);

        }
    }
 }


