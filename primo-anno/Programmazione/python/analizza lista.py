'''scrivere una funzione: 
def analizza(lista): 

che riceve una lista di numeri interi e restiuisce una tupla contenente: 
la somma dei numeri pari
una lista con tutti i numeri dispari moltiplicati per 2 
il numero di elementi negativi presenti nella lista'''


def analizza(lista): 

    somma = 0
    dispari = []
    negativi = 0

    for i in lista: 
        if i%2 == 0: 
            somma+=i
        else: 
            i*=2
            dispari.append(i)
        
        if i < 0:
            negativi+=1

    return somma, dispari, negativi

        


lista = [3, -2, 4, -5, 7]
print(analizza(lista))

#complessità temporale O(n)
#complessità spaziale O(n)