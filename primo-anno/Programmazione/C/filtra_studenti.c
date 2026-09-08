/*Si scriva una funzione in C con il seguente prototipo:
Studente *filtra_studenti(const Studente *a, int n, float soglia, int *out_len);

Requisiti:

La funzione riceve un array a di n studenti e una soglia di voto.

Deve allocare dinamicamente e restituire un nuovo array contenente solo gli studenti con media >= soglia.

La dimensione del nuovo array deve essere salvata nella variabile puntata da out_len.

Se n <= 0, se nessun elemento soddisfa il criterio o se l'allocazione fallisce, 
la funzione deve impostare *out_len = 0 e restituire NULL.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50]; 
    int matricola; 
    float media; 
} studente; 

studente *filtra_studenti(const studente *a, int n, float soglia, int *out_len){

    if (a == NULL || out_len==NULL){
        if(out_len!=NULL){
            return 0; 
        }

        return NULL;
    }


    int count = 0; 
    for(int i = 0; i < n; i++){

        if(a[i].media >= soglia){
            count++; 
        }

        if(count==0){
            *out_len = 0; 
            return NULL; 
        }

        studente *res = malloc(sizeof(studente)*count);

        if(res == NULL){
            return NULL; 

        }

        int j = 0; 

        for(int i = 0; i < n; i++){
            if(a[i].media >= soglia){
                res[j] = a[i]; 
                j++; 
            }
        }

        *out_len = count; 
        return res; 


        
        
    }
}

/*
 * COMPLESSITÀ TEMPORALE: O(n)
 * La funzione effettua due cicli sequenziali non annidati sull'array di dimensione n. 
 * Ogni operazione all'interno dei cicli (confronto, assegnamento, incremento) ha costo O(1).
 * Il tempo totale cresce quindi linearmente con n.
 *
 * COMPLESSITÀ SPAZIALE: O(k)
 * Dove k è il numero di studenti filtrati (nel caso peggiore k = n).
 * La memoria allocata dinamicamente mediante malloc è esattamente proporzionale a k.
 */