#Sia n una variabile intera, scrivere un programma che crei una lista contenente i primi n interi
n = 10 # input

a = [] # lista vuota. Costo O(1)

for x in range(n): # inserimento in coda degli interi da 0 a n-1
    a.append(x) # costo O(1)

# costo totale O(n)

print(a)



#Sia a una lista contenente soltanto numeri, si costruisca la lista delle somme parziali di a, ovvero una lista, denominata somme della stessa dimensione di a tale che somme[i] contiene la somma dei primi i+1 elementi in a.
#Nel risolvere gli esercizi si utilizzino soltanto gli strumenti fin qui introdotti a lezione.

a = [6,3,2,4,1,3]

# sia n = len(a), la complessità temporale dipenderà da n

somme = [] # costo O(1)

for x in a:  # per n volte
    if somme == []: # verifica lista vuota, anche con len(somme) == 0, costo O(1)
        somme.append(x) # O(1)
    else:
        c = somme[-1] + x  # valore inserito al passo precedente + x, # O(1) perché indicizzazione richiede tempo costante
        somme.append(c) # O(1)

# tempo totale O(n)

print(somme)


'''
Il costo computazionale, in termini di tempo di calcolo, 
della soluzione è lineare nella lunghezza della lista in quanto, 
per n volte si eseguono: un confronto con la lista vota 
(tempo che non dipende dalla lunghezza della lista, indicizzazione e operazioni aritmetiche). 
Il costo dell'indicizzazione è costante perché gli elementi della lista sono memorizzati in posizioni 
consecutive di memoria e ogni elemento occupa lo stesso spazio.

'''

def cumsum( L ): # L parametro formale
    '''
    Parmetri: L una lista di numeri (int o float)

    Stampa la lista delle somme comulative
    '''

    somme = [] # variabile locale, visibilità interna alla funzione. Lo sono anche i parametri formali

    for x in L:  # x, variabile locale
        if somme == []: 
            somme.append(x) 
        else:
            c = somme[-1] + x  # c, variabile locale
            somme.append(c) 

    return somme # definisce il risultato, interrompe la funzione
