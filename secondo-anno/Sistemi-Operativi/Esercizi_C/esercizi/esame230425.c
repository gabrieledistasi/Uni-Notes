#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>

#define PIPE_RD 0
#define PIPE_WR 1


int main(){

    int fd[2]; 
    pipe(fd); 

    pid_t P1 = fork(); 



    if(P1 == 0){

        close(fd[PIPE_WR]); 



        DIR *d = opendir("."); 

        if(d==NULL){ //controllo sulla directory corrente 
            perror("opendir"); 
            exit(0); 
        }

        struct stat info; 
        struct dirent *entry; 
        int c = 0; 
        int i = 0; 
        int rec; 


        


        while((entry=readdir(d))!=NULL){

            stat(entry->d_name, &info); 

            if(S_ISREG(info.st_mode)){
                c++; 
            } 



        }

        while(i < 1000){

            read(fd[PIPE_RD], &rec, sizeof(int));

            if(rec==c){
                printf("il numero di file nella directory è uguale al numero ricevuto"); 
                break; 
            }


            i++; 
        }


        closedir(d); 
        close(fd[PIPE_RD]); 

        kill(getppid(), SIGTERM); 
        exit(0); 




    }

    else{

        srand(time(NULL)); 
        signal(SIGINT, SIG_IGN); 
        close(fd[PIPE_RD]); 
    

        
        while(1){

            int num = (rand()%100)+1; 

            write(fd[PIPE_WR], &num, sizeof(int));
            sleep(1);

        }


    }
}