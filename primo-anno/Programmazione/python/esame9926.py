'''
Si scriva una funzione, denominata find_max_base , 
che riceve in ingresso una lista composta da n elementi 
(ciascuno dei quali è una lista o una tupla, potenzialmente annidata) 
e restituisce l'elemento che contiene il maggior numero complessivo di elementi scalari, 
considerando tutti i livelli di annidamento. Per elemento scalare si intende qualsiasi valore 
base (es. interi, float, stringhe) che non sia a sua volta una lista o una tupla. 
Esempio 
dati = 
[ [1, 2, 3], # 3 elementi scalari 
[1, [2, [3, 4]]], # 4 elementi scalari 
[3, [4, 3]] # 3 elementi scalari ] 

# risultato = find_max_base(dati) print(risultato) # Output: [1, [2, [3, 4]]]
'''

def conta(x):
    if type(x) == list or type(x) == tuple or type(x) == set:
        n = 0

        for elemento in x:
            n += conta(elemento)

        return n

    return 1


def find_max_base(dati):
    massimo = -1
    risultato = None

    for elemento in dati:
        n = conta(elemento)

        if n > massimo:
            massimo = n
            risultato = elemento

    return risultato

'''complessità temporale: O(n) senza contare il numero di chiamate ricorsive perché dipendono dalla struttura
complessità spaziale: O() '''