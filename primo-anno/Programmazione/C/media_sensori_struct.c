/*
Definisci la seguente struttura per un sensore di rilevamento:Ctypedef struct {
    int id;
    double *letture; // Array dinamico di misurazioni
    int n_letture;   // Dimensione dell'array letture
} Sensore;
Si scriva una funzione in C con il seguente prototipo:
double *medie_sensori(const Sensore *vettore, int n);
Requisiti:Dato un array vettore di n sensori, 
la funzione deve allocare e restituire un nuovo array di double di dimensione n.
L'elemento $i$-esimo del nuovo array deve contenere la media aritmetica delle letture del sensore 
$i$-esimo.Se un sensore ha n_letture <= 0 o se il puntatore letture è NULL, 
la media per quel singolo sensore deve essere impostata a 0.0.In caso di parametri non validi 
(vettore == NULL o n <= 0) o errore di allocazione, la funzione deve restituire NULL.*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id; 
    double *letture; 
    int n_letture; 
} sensore; 

double *medie_sensori(const sensore *vettore, int n){


    double *res = malloc((sizeof(double)*n));
    if(res==NULL){
        return NULL; 
    } 

    

    for(int i = 0; i < n-1; i++){

        if(vettore[i].letture != NULL && vettore[i].n_letture > 0){
            double somma = 0.0; 


            for(int j = 0; j< vettore[i].n_letture; j++){
                somma+=vettore[i].letture[j]; 

            }

            res[i] = somma / vettore[i].n_letture; 
        }

        else{
            res[i] = 0.0; 
        }
        
        
    }

    return res; 

    
}