#scrivere una funzione che, data una lista di numeri interi distinti non negativi e ordinati in modo crescente
#restituisca il più piccolo elemento non negativo mancante in essa. Se non ci sono elementi mancanti restituisce -1


def missing_element(a): 

    for i in range(len(a)-1): 
        if a[i+1] != a[i] + 1: 
            return a[i] + 1
    
    return -1



print(missing_element([1, 2, 3, 4, 5, 7, 8, 10]))