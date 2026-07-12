/*scrivere una funzione che prende in input un array di float e restituisca una sequenza ordinata delle posizioni
dei massimi nell'array. La sequenza di output deve essere rappresentata tramite la struttura dati int_array, definita come
segue: 
struct int_array {
    int dim;
    int *v
}
typedef struct int_array int_array;


il campo v rappresenta un array di dim interi. La funzione da implementare deve avere il seguente prototipo: 
    int_array pos_max(float *a, int n);
dove a è l'array di float di dimensione n.*/


#include <stdio.h>
#include <stdlib.h> 

struct int_array
{
    int dim;
    int *v;
};

typedef struct int_array int_array;

int_array pos_max(float *a, int n)
{
    int_array ris;

    ris.dim = 0;
    ris.v = NULL;

    if (n <= 0)
        return ris;

    float max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == max)
            ris.dim++;
    }

    ris.v = malloc(ris.dim * sizeof(int));

    if (ris.v == NULL)
    {
        ris.dim = 0;
        return ris;
    }

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == max)
        {
            ris.v[j] = i;
            j++;
        }
    }

    return ris;
}