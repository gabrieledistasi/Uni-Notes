/*scrivere un programma in linguaggio c che utilizzi processi e pipe per implementare il seguente comportamento.
Un processo padre apre il file dati.txt presente nella stessa directory
successivamente crea un processo figlio tramite la chiamata fork() e instaura una comunicazione bidirezionale tramite pipe
il padre disabilita la gestione del segnale SIGINT ed entra in un ciclo in cui: 
*   genera un numero casuale compreso tra 1 e 10 e lo sottrae a X 
*   invia il valore aggiornato al figlio tramite pipe 
*   riceve dal figlio un nuovo valore tramite pipe che assegna a X
*   stampa: Padre - pid P: valore corrente = X; 
*   se il valore ricevuto è minore o uguale a zero il padre termina il processo figlio e conclude il programma

il figlio disabilita anch'esso il segnale SIGINT ed entra in un ciclo in cui: 
*   riceve un valore dal padre 
*   genera un numero casuale da 1 a 5 e lo somma al valore ricevuto     
*   invia il nuovo valore al padre tramite pipe

*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>
#define true 1
#define false 0

int main(){
    int fd = open("dati.txt", O_RDONLY); 

    if(fd < 0){
        perror("error file"); 
        return -1; 
    }

    int X = lseek(fd, 0, SEEK_END); //dimensione del file
    close(fd); 

    int ab_pipe[2], ba_pipe[2]; 

    if(pipe(ab_pipe)<0 || pipe(ba_pipe)<0){

        perror("pipe error"); 

        return -1; 
    }

    signal(SIGINT, SIG_IGN); //disabilitazione dei segnali

    pid_t b = fork(); 
    if(b == 0){


        close(ab_pipe[1]); 
        close(ba_pipe[0]); 
        srand(time(NULL) ^ getpid()); 
        

        while(true){

            int rec; 
            int r_value = 0; 

            
            read(ab_pipe[0], &rec, sizeof(int)); 
            r_value += ((rand()%5)+1); 
            write(ba_pipe[1], &r_value, sizeof(int)); 
            


        }

    }

    pid_t pid = getpid(); 
    close(ab_pipe[0]); 
    close(ba_pipe[1]); 

    srand(time(NULL) ^ getpid()); 

    while(X > 0){

        int random = (rand()%10) + 1; 
        X -= random; 

        write(ab_pipe[1], &X, sizeof(int)); //invio al figlio 
        read(ba_pipe[0], &X, sizeof(int)); 

        printf("Padre - pid %d: valore corrente = %d\n", pid, X); 

    }


    close(ab_pipe[1]); 
    close(ba_pipe[0]); 

    kill(b, SIGTERM); 
    wait(NULL); 
    
    return 0; 


}
