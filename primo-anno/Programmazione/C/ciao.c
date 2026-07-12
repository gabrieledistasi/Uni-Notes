/*Si scriva una funzione in C che riceva in input:
un array dinamico a di numeri in virgola mobile ( float ), ordinato in modo crescente,
un intero n che rappresenta la dimensione attuale dell’array,
e che inserisca nell’array un nuovo elemento con valore pari alla media aritmetica dei due elementi
consecutivi di a che presentano la massima distanza tra di loro. La funzione deve ritornare l'array
modificato.
La funzione dovrà avere il seguente prototipo
float* inserisci_media(float* a, n);*/


#include <stdlib.h>
#include <stdio.h>

float *inserisci_media(float *a, int n)
{
    if (a == NULL || n < 2)
        return a;

    int pos = 0;
    float max = a[1] - a[0];

    for (int i = 1; i < n - 1; i++)
    {
        float diff = a[i + 1] - a[i];

        if (diff > max)
        {
            max = diff;
            pos = i;
        }
    }

    float media = (a[pos] + a[pos + 1]) / 2.0;

    float *nuovo = realloc(a, (n + 1) * sizeof(float));

    if (nuovo == NULL)
        return a;

    a = nuovo;

    for (int i = n; i > pos + 1; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos + 1] = media;

    return a;
}