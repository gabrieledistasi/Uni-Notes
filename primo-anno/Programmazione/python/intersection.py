#Scrivere una funzione in Python che, date due liste l1 e l2, 
#restituisce una lista senza duplicati che è l'intersezione delle due liste l1 e l2.

def intersection(l1, l2): 

    intersezione = []


    for i in l1: 
        if i in l2 and i not in intersezione: 
                intersezione.append(i)
    return intersezione

print(intersection([1, 2, 3, 4], [3, 4, 5, 6, 7]))
    