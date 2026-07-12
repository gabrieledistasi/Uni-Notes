/*
creare un programma che legge un file e conta le occorrenze di una parola nel seguente modo: 
    - Il primo processo legge dall'inizio alla metà e conta le occorrenze della parola
    - Il secondo processo legge dalla metà fino alla fine e conta le occorrenze della parola
    - Inviano poi il numero di occorrenze al padre il quale le somma e le stampa a video*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <string.h>
#define true 1
#define PIPE_RD 0
#define PIPE_WR 1 

int main(int argc, char *argv[]){

    int fd1[2]; 
    int fd2[2]; 
    pipe(fd1); 
    pipe(fd2); 

    int fd = open("file.txt", O_CREAT | O_RDWR, 0644); 

    struct stat file_info; //creo la struttura contenente i dati del file 

    fstat(fd, &file_info); //riempio file_info con le informazioni 

    int size = file_info.st_size; 
    int meta = size/2; 

    pid_t P1 = fork(); 
    
    if(P1 == 0){

        char *wanted_word = "aragosta"; 
        close(fd2[PIPE_RD]); 
        close(fd2[PIPE_WR]); 
        close(fd1[PIPE_RD]); //il figlio 1 deve solo scrivere sulla pipe

        int count = 0; //conta le occorrenze della parola nella prima metà del file
        lseek(fd, 0, SEEK_SET);     
        int pos = 0; 
        char c; 
        char buffer[100]; 
        int i = 0; 

        while(pos < meta){

            read(fd, &c, sizeof(char)); 
            buffer[i] = c; 
            i++; 
            if(c == ' ' || c == '\n' || c == '\0'){

                if(strcmp(wanted_word, ))

                count++; 
                i = 0; 
            }
            pos++; 

        }


    }
    else{

        pid_t P2 = fork(); 
        if(P2 == 0){

        }
        else{

        }
    }




}