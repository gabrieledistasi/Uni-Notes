/*Si scriva una funzione in C, denominata iniziali, che valuti quanti caratteri iniziali sono in
comune tra due stringhe date. La funzione riceve due parametri, entrambi di tipo stringa,
e restituisce il numero intero.
Ad esempio:
• se la funzione venisse chiamata come iniziali("ciao", "cielo"), dovrebbe restituire
2 in quanto i primi due caratteri sono identici.
• se la funzione venisse chiamata come iniziali("ciao", "salve"), dovrebbe restituire
0 in quanto nessun carattere iniziale è in comune*/
#include <stdio.h>



int iniziali(char *A, char *B){
    int sizeA = sizeof(A)/sizeof(A[0]); 
    int sizeB = sizeof(B)/sizeof(B[0]); 
    int shortest; 
    int c; 

    if(sizeA > sizeB){
        shortest = sizeB; 

    }

    else if(sizeA<=sizeB){
        shortest = sizeA; 
    }

    for(int i = 0; i < shortest; i++){

        if(A[i]==B[i]){
            c++; 
        }

    }

    return c; 


}

int main(){
    char A[]="ciao"; 
    char B[]="salve"; 

    printf("%d", iniziali(A,B)); 
}