/*un processo padre genera due processi figli.
*    il primo processo figlio invia al padre un numero casuale da 0 a 100
*    il padre legge questo numero, lo moltiplica per un k casuale e lo invia al secondo figlio
*    Il secondo figlio legge il numero inviato dal padre e lo stampa a video */


#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <wait.h>
#include <unistd.h>
#include <time.h>

int main(){

    

    int fd1[2]; 
    int fd2[2]; 

    pipe(fd1); 
    pipe(fd2); 

    srand(time(NULL));
    int k = rand()%10; 

    __pid_t p1 = fork(); 
    if(p1 == 0){
        close(fd1[0]); //p1 deve scrivere sulla pipe

        srand(time(NULL)); //genera numeri casuali
        int random = rand()%101; 
        printf("ciao sono il figlio, invio: %d\n", random); 
        write(fd1[1], &random, sizeof(random)); 


        close(fd1[1]); 
        exit(0); 
    }
    

    else{
        close(fd1[1]); 
        

        int numero; 
        
        read(fd1[0], &numero, sizeof(int));
        int send = numero*k; 
        
        printf("ciao sono il padre e ho ricevuto: %d\n", numero); 
        printf("ora invierò il numero: %d\n", send); 

        write(fd2[1], &send, sizeof(send)); 

        close(fd1[0]); 



    }
    __pid_t p2 = fork();

 
    if(p2 == 0){

        close(fd2[1]); 
        int res; 
        read(fd2[0], &res, sizeof(int)); 

        printf("ciao, sono il processo 2 e mio padre mi ha inviato il numero: %d\n", res); 
        exit(0); 
        

    }

    else{
        close(fd2[0]); 
        wait(NULL); 
        wait(NULL); 
    }


}


