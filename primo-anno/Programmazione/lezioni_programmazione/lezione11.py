'''
Si scriva una funzione argfind che prende in 
input una lista di numeri L e un valore k e restituisce la posizione della prima occorrenza di k in L. 
Se L non contiene k, la funzione restituisca -1.

'''

L = [2,1.9,4,6,7,4.3,2,9,2]
k = 0

n = len(L)

for i in range(n):
    if k == L[i]:
        #return i
        print(i)
        break # esce dal ciclo più interno

print(i)



#funzione
def argfind(L, k):
    """
    Parametri: L una lista di numeri
                k un valore
    Ritorna i tale che L[i] == k oppure -1 se tale i non esiste
    """
    n = len(L)

    for i in range(n): # al più n volte
        if k == L[i]: # costo costante
            return i
    
    return -1

    # complessità temporale O(n) nel caso peggiore
    # nel caso migliore? k in testa, O(1)
    # nel caso medio? O(n), vedere conti per la soluzione al problema stringa palindroma 