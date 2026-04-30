/*Si scriva un programma in linguaggio C per calcolare il minimo comune multiplo (MCM)
di due numeri interi positivi. Dati due numeri interi N1 e N2, il minimo comune multiplo
è il più piccolo numero M che è divisibile (con resto pari a zero) sia per N1 che per N2.
Suggerimento. Si considerino due numeri interi N1 e N2. Sia N1 più grande di N2. Il MCM
è il primo multiplo di N1 che è divisibile (con resto uguale a zero) per N2.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero1, numero2; 
    int massimo, minimo; 
    int conta; 
    int fine; 

    int mcm; 

    printf("inserisci il primo numero: \n"); 
    scanf("%d", &numero1 ); 

    printf("inserisci il secondo numero \n"); 
    scanf("%d", &numero2); 

    if(numero1<=0 || numero2<=0){
        printf("Errore: hai inserito uno o due numeri negativi"); 
    }
    else{

        if(numero1 > numero2){
            massimo = numero1;
            minimo = numero2;
        }
        
        else{
            massimo = numero2; 
            minimo = numero1; 
        }


    }

    conta = 1; 
    mcm = 0; 

    fine = 0; 

    while ( fine == 0 )
    {
        /* CALCOLA IL SUCCESSIVO MULTIPLO DI "massimo". QUESTO VALORE E’
        UN CANDIDATO MINIMO COMUNE MULTIPLO */
        mcm = conta * massimo ;
        /* VERIFICA SE "minimo" E’ DIVISORE DI "mcm" */
        if ( mcm % minimo == 0 )
        {
        /* LA RICERCA E’ TERMINATA. AGGIORNA IL FLAG "fine" */
        fine = 1 ;
        }
        else
        {
        /* INCREMENTA LA VARIABILE "conta" */
        conta = conta + 1 ;
        }

        }
        /* STAMPA IL RISULTATO */
        printf("\n") ;
        printf("Il MCM per %d e %d e’ %d\n", numero1, numero2, mcm);
}