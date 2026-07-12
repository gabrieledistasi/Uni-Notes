/*un processo genera due processi figli P1 e P2

*   il figlio p1 esegue un ciclo indeterminato durante il quale genera casualmente numeri interi compresi tra 0 e 100
    p1 comunica ad ogni iterazione il numero al padre solo se esso è dispari    

*   P2 fa la stessa cosa ma comunica al padre solo i numeri pari 

*   Il padre, per ogni coppia di numeri che riceve, ne fa la somma e la visualizza

*   Il programma deve terminare quando la somma dei due numeri ricevuti supera il valore di 190: il padre, allora,
    invia un segnale di terminazione a ciascuno dei figli */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#define true 1


int main(int argc, char *argv[]){

    int fd1[2]; //pipe P0 con P1
    int fd2[2]; //pipe P0 con P2
    int p1_value; 
    int p2_value; 

    pipe(fd1); 
    pipe(fd2); 

    __pid_t p1 = fork(); 

    srand(time(NULL)); 

    if(p1 == 0){

        close(fd1[0]); 

        while(true){
            
            p1_value = rand()%101;

            if(p1_value%2 != 0){

                write(fd1[1], &p1_value, sizeof(int)); 

            }
            


        }

        close(fd1[1]);

        


    }

    else{
        __pid_t p2 = fork();

        if(p2 == 0){

        close(fd2[0]); 

        while(true){
            
            p2_value = rand()%101;

            if(p2_value%2 == 0){

                write(fd2[1], &p2_value, sizeof(int)); 

            }
            


        }

        close(fd2[1]);


    }

    else{
        close(fd1[1]); 
        close(fd2[1]); 
        int rec1 = read(fd1[0], &rec1, sizeof(int)); 
        int rec2 = read(fd2[0], &rec2, sizeof(int)); 
        int sum=0; 

        while(sum < 190){
            printf("received: %d, %d\n", rec1, rec2 );
            sum = rec1+rec2;
            printf("sum of received numbers: %d\n", rec1+rec2);
        }

        signal(getpid(), SIGTERM);
        signal(getpid(), SIGTERM);

    }
    }




    
}