#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#define true 1


int main(){

    int fd[2]; 
    pipe(fd); 
    pid_t p1 = fork(); 

    if(p1==0){

        close(fd[1]); 

        while(true){

            int no_bytes;
            read(fd[0], &no_bytes, sizeof(int)); 

            if(no_bytes > 20){
                printf("Figlio - pid %d: blocco di %d byte ricevuto\n", getpid(), no_bytes); 

                kill(getppid(), SIGTERM); 
                exit(0); 
            }

            
        }
        
    }
    else{

        close(fd[0]); 
        srand(time(NULL)); 

        int file = open("dati.txt", O_RDONLY); 
        signal(SIGINT, SIG_IGN); 

        while(true){


            int k = (rand()%32)+1; 
            
            char buffer[32]; 

            int bytes_read = read(file, buffer, k);

            for(int i = 0; i < bytes_read; i++){
                printf("%c", buffer[i]); 
            }
            
            

            write(fd[1], &bytes_read, sizeof(int)); 
            sleep(1); 

            if(bytes_read==0){

                close(file); 
                close(fd[1]); 

                kill(p1, SIGTERM); 
                exit(0); 

            }


        }






    }

    

}