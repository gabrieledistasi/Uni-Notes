//Programma di copia di file con controllo minimale e reportistica

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 4096 //dimensione del buffer: 4096 byte
#define OUTPUT_MODE 0700 //bit di protezione per file di output 

#define TRUE 1

//Prototipo della funzione main
int main(int argc, char *argv){

    int in_fd, out_fd; //File descriptor per i file di input e output 
    int rd_count, wt_count; //contatori per la lettura e scrittura
    char buffer[BUF_SIZE]; //buffer per la lettura e scrittura dei dati

    //controllo del numero di argomenti
    if(argc != 3){
        //Stampa un messaggio di errore se il numero di argomenti non è corretto
        fprintf(stderr, "Errore di sintassi. Uso: %s input_file_path output_file_path\n", argv[0]); 
        exit(1); 
    }

    //apertura del file di input 

    in_fd = open(argv[1], O_RDONLY); //apre il file di origine
    if(in_fd<0) exit(2); //se non può aprirlo esce

    //ciclo di copia 
    while(TRUE){
        rd_count = read(in_fd, buffer, BUF_SIZE); //legge un blocco dati 
        if(rd_count <= 0) break; //Se fine del file o errore esce dal ciclo

        wt_count = write(out_fd, buffer, rd_count); //scrive i dati 
        if(wt_count <= 0) exit(4); //wt_count <= 0 è un errore 
    }

    //chiusura dei file 

    close(in_fd); 
    close(out_fd); 

    if(rd_count == 0) exit(0); //nessun errore sull'ultima lettura
    else exit(5); //errore sull'ultima lettura



}