'''Si scriva una funzione chiamata elementi_comuni che prenda come argomento due liste di interi 
a e b e restituisca una nuova lista contenente soltanto gli elementi che compaiono in entrambe 
le liste, senza duplicati e ordinati in modo decrescente. 
Non è consentito l'utilizzo di funzioni di librerie esterne.  
(Suggerimento: fai attenzione a gestire correttamente i casi in cui gli elementi si ripetono più 
volte all'interno della stessa lista di input).'''


def union_list(a, b): 

    risultato = []

    for i in a: 

        if i in b and i not in risultato: 
            risultato.append(i)

    risultato.sort()
    return risultato

'''
Siano N la lunghezza della lista 'a', M la lunghezza della lista 'b' 
# e K il numero di elementi unici in comune (K <= min(N, M)).
#
# - Complessità Temporale: O(N * (M + K) + K log K)
#   Motivazione: Il ciclo 'for' itera N volte. Ad ogni iterazione, 
#   l'operazione 'elemento in b' richiede nel caso peggiore tempo O(M), 
#   mentre l'operazione 'elemento not in risultato' richiede O(K). 
#   L'append richiede tempo costante O(1). 
#   Questo porta la complessità del ciclo a O(N * (M + K)).
#   Successivamente, l'ordinamento della lista richiede O(K log K).
#   La complessità temporale è quindi decisamente più alta rispetto 
#   alla soluzione con i set (che è O(N+M)), poiché stiamo facendo 
#   ricerche lineari all'interno di liste non ordinate.
#
# - Complessità Spaziale: O(K)
#   Motivazione: L'unica struttura dati aggiuntiva che allochiamo è 
#   la lista 'risultato', la quale memorizza al massimo K elementi 
#   (il numero di elementi in comune senza duplicati). Oltre a questo 
#   utilizziamo solo memoria O(1) per le variabili interne del ciclo.
# '''





