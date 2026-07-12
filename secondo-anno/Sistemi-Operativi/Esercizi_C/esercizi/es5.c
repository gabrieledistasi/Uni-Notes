/*Si richiede di implementare un programma in linguaggio C che utilizzi il metodo delle fork per la comunicazione tra processi.
 Il programma dovrà creare un file di testo e poi creare due processi figli. Uno dei processi figli dovrà scrivere una sequenza di
 N numeri interi pari da 0 a 9 nel file, mentre l'altro processo figlio dovrà scrivere una sequenza di N numeri interi dispari da 0 a 9, attraverso
 la funzione seek va a scriverli subito dopo la sequenza degli N numeri pari nello stesso file.
 Il processo padre dovrà leggere i dati dal file e stamparli a video.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

#define PIPE_RD 0
#define PIPE_WR 1


int main(){
    srand(time(NULL)); 

    int N = 5; 

    int fd = open("numeri.txt", O_CREAT | O_TRUNC | O_RDWR, 0644); 

    if(fd < 0){
        perror("open"); 
        exit(1); 

    }
    

    pid_t P1 = fork(); 

    if(P1==0){

        

        for(int i=0; i < N; i++){
            dprintf(fd, "%d", (2*i)%10); 

            
        }


        close(fd); 
        exit(0); 

    }

    else{
        pid_t P2 = fork(); 

        if(P2 == 0){

            

            lseek(fd, 2*N, SEEK_SET); 

            for(int i = 0; i < N; i++){
                dprintf(fd, "%d", (2*i+1)%10); 

            }

            close(fd); 
            exit(0); 




        }

        else{


            wait(NULL); 
            wait(NULL); 

            
            lseek(fd, 0, SEEK_SET); 
            char c; 

            printf("File finale:\n"); 

            while(read(fd, &c, 1) > 0){
                putchar(c); 
            }

            printf("\n"); 
            close(fd); 


            return 0; 

        }
    }
}