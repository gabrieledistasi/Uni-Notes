/*scrivere un programma in C che utilizzi processi e pipe. Il processo principale disabilita la gestione del segnale 
SIGINT, crea una pipe e genera un processo figlio tramite fork()
Il processo padre: 
    *Apre il file dati.txt presente nella directory corrente 
    *A ogni iterazione legge un numero casuale k compreso tra 1 e 32
    *Legge dal file al massimo k byte
    *Stampa a schermo i caratteri letti
    *Invia al figlio, tramite pipe, il numero di byte effettivamente letti 
    *Attende un secondo prima di effettuare la lettura successiva
    *se raggiunge la fine del file, termina il figlio e conclude il programma

Il processo figlio: 
    *Riceve dal padre il numero di byte letti
    *Se riceve un valore maggiore di 20 stampa il messaggio: 
        Figlio - pid P: blocco di N byte ricevuto (dove P è il PID del figlio e N è il valore ricevuto)
    dopo aver stampato il messaggio, termina il processo padre e conclude la propria esecuzione.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define true 1


int main(){


    int fd[2]; 
    pipe(fd); 

    pid_t p1 = fork(); 

    if(p1==0){

        close(fd[1]); 

        read(fd[0], )

    }
}
