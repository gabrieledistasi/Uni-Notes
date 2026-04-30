/*Il servizio di rivendita di biglietti percepisce una provvigione sul prezzo del biglietto. La
provvigione è pari al 15% del prezzo del biglietto, ma in ogni caso è pari ad almeno 5 C.
Scrivere un programma che, dato il prezzo di un biglietto, calcoli e stampi:
• il valore della provvigione
• il prezzo finale del biglietto*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int price = 10; 
    float min_provv = 5; 
    float prezzo_biglietto; 
    float value_provv; 

    value_provv = (price*15)/100; 


    if (value_provv < min_provv){
        value_provv = min_provv; 
    }

    prezzo_biglietto = price + value_provv; 

    printf("%f \n", value_provv);
    printf("%f \n", prezzo_biglietto); 



}


