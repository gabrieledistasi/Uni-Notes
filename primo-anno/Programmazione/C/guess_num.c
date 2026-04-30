/*scrivere un programma in cui l'utente deve indovinare un numero*/
#include <stdio.h>

int main(){

    int guess; 

    int i = 10; 
    int secret_num = 69; 

    while(i > 0){

    printf("inserisci un numero: ");
    scanf("%d", &guess);

        if(secret_num > guess){
            printf("troppo basso\n");
        }

        else if(secret_num < guess){
            printf("troppo alto\n");
        }

        else{
            printf("hai indovinato\n"); 
        }

        i--;
    }
}