/*
Generare due processi figli che comunicano con il padre.
    - Uno dei processi genera numeri casuali [0-50] ed invia al padre solo i numeri multipli di 3.
    - L'altro processo genera numeri casuali [51-100] ed invia al padre solo i numeri multipli di 2.
    - Il padre stampa i numeri ricevuti ed esegue la loro somma, quando la somma > 130 termina i processi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>

#define PIPE_RD 0
#define PIPE_WR 1
#define true 1 

int main(){

     

    int fd1[2]; 
    int fd2[2]; 

    pipe(fd1); 
    pipe(fd2); 

    pid_t P1 = fork(); 

    if(P1==0){
        srand(time(NULL) ^ getpid());

        close(fd1[PIPE_RD]); 
        close(fd2[PIPE_RD]); 
        close(fd2[PIPE_WR]); 
    
        

        while(true){

            int p1_value = rand()%51; 
            if(p1_value%3==0){

                write(fd1[PIPE_WR], &p1_value, sizeof(int)); 


            }

            
            
        }


    }
    else{

        pid_t P2 = fork(); 
        if(P2 == 0){
            srand(time(NULL)^getpid());

        close(fd2[PIPE_RD]); 
        close(fd1[PIPE_RD]); 
        close(fd1[PIPE_WR]); 
        
        

        while(true){

            int p2_value = 51 + rand() % (100-51+1); 
            if(p2_value % 2==0){

                write(fd2[PIPE_WR], &p2_value, sizeof(int)); 


            }

            
            
        }

        }
        else{

            close(fd1[PIPE_WR]); 
            close(fd2[PIPE_WR]); 

            int rec1; 
            int rec2; 
            int sum = 0; 



            while(true){


                read(fd1[PIPE_RD], &rec1, sizeof(int)); 
                read(fd2[PIPE_RD], &rec2, sizeof(int)); 

                printf("number received from p1 = %d, number received from p2 = %d\n", rec1, rec2); 

                sum = rec1+rec2; 

                if(sum > 130){
                    break; 
                }        
                
                printf("\nsum between p1 and p2 = %d \n", sum);
                
                
            }

            

            kill(P1, SIGTERM); 
            kill(P2, SIGTERM); 

            wait(NULL); 
            wait(NULL); 

            exit(0); 

        }


    }
}