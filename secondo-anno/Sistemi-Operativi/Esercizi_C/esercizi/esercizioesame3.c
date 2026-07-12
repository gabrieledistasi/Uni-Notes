/*scrivere un programma, in linguaggio C, che utilizza processi e pipe per implementare quanto specificato di seguito.
Un processo padre P genera genera due processi figli P1 e P2. Inizialmente, tutti i processi devono disabilitare il 
segnale di interruzione SIGINT, in particolare all'arrivo di tale segnale deve essere visualizzato il messaggio
di avviso "interruzione disabilitata". I due figli P1 e P2 generano ogni secondo un numero intero casuale compreso tra 
0 e 100. I numeri generati dai figli vengono inviati al padre che provvede a sommarli, a stamparli a schermo e a 
memorizzarli in un file. L'esecuzione di tutti e tre i processi viene terminata dal processo padre quando 
verifica che la somma dei due numeri avuti dai processi figli assume il valore di 100, altrimenti 
si mette in attesa per 2 secondi prima di ricontrollare i due numeri inviati dai processi figli.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#define true 1


void handler(int sig){
    printf("interruzione disabilitata"); 
    fflush(stdout); 
}



int main(){




    int fd1[2]; //pipe p e p1
    int fd2[2]; //pipe p e p2
    pipe(fd1); 
    pipe(fd2); 

    signal(SIGINT, handler); 
    
    pid_t p1 = fork(); 
    

    if(p1==0){

        srand(time(NULL)+getpid()); 
        close(fd1[0]);


        while(true){



            int p1_value = rand()%101; 
            write(fd1[1], &p1_value, sizeof(int)); 
            sleep(1); //aspetta un secondo



        }
        
        

    }
    else{
        pid_t p2 = fork(); 
        if(p2==0){

            srand(time(NULL)+getpid()); 
            close(fd2[0]);

            while(true){

            

            int p2_value = rand()%101; 
            write(fd2[1], &p2_value, sizeof(int)); 
            sleep(1); //aspetta un secondo



            }



        }

        else{

            int p1_result; 
            int p2_result; 
            int sum = 0; 

            close(fd1[1]); 
            close(fd2[1]); 

            FILE *fp = fopen("numeri.txt", "w"); 
            

            while(true){


            read(fd1[0], &p1_result, sizeof(int)); 
            read(fd2[0], &p2_result, sizeof(int)); 

            sum = p1_result + p2_result; 
            printf("%d %d %d\n", p1_result, p2_result, sum); 

            fflush(fp); 
            if(sum == 100){

                kill(p1, SIGTERM); 
                kill(p2, SIGTERM); 
                wait(NULL);
                wait(NULL); 
                exit(0); 

            }

            else{
                sleep(2); 
            }


            }




        }
    }




}
