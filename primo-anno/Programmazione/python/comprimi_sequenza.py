'''Esercizio: Compressione di sequenze (Python)
Sia data una lista di interi a che rappresenta una sequenza di valori 
registrati nel tempo da un sensore. Scrivere una funzione Python chiamata comprimi_sequenza(a)
che raggruppi i valori consecutivi identici.
La funzione deve restituire una lista di tuple, dove ogni tupla (valore, conteggio) 
indica l'elemento rilevato e il numero di volte che appare ininterrottamente in quella specifica
porzione della lista.Esempio di comportamento atteso:
Se la lista in input è a = [4, 4, 4, 2, 2, 7, 4, 4], la funzione deve restituire 
[(4, 3), (2, 2), (7, 1), (4, 2)]. Nel caso in cui la lista sia vuota, 
deve restituire una lista vuota.Requisito teorico:
Proprio come richiesto per l'esercizio sulle liste a e t nel file "Programmazione",
per la funzione implementata devi descrivere in un commento la complessità temporale e spaziale,
motivando in modo chiaro e convincente la tua analisi.  '''

def comprimi_sequenza(a):

    c = 1
    res = []

    if a == []:
        return None

    for i  in range(1, len(a)): 

        if a[i] != a[i-1]: 

            
            res.append((a[i-1], c))
        
            c = 1

        else: 
            c+=1

    res.append((a[-1],c))

    return res

a = [4, 4, 4, 2, 2, 7, 4, 4]
print(comprimi_sequenza(a))


'''
Complessità Temporale: $O(N)$, dove $N$ è la lunghezza della lista a. 
Il ciclo for scorre l'intera lista esattamente una sola volta, 
ed esegue al suo interno operazioni elementari a tempo costante (confronti, 
incrementi e append).
Complessità Spaziale: $O(N)$ nel caso peggiore. 
Se la lista di input è composta da elementi tutti diversi tra loro 
(ad esempio [1, 2, 3, 4]), la lista res di output conterrà esattamente $N$ tuple. 
Nel caso migliore (tutti gli elementi uguali), la complessità spaziale scenderebbe a $O(1)$
extra (una sola tupla generata).
'''
