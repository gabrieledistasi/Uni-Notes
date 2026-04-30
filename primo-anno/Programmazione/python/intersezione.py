#la funzione prende in input due liste a e b e restituisce una nuova lista contenente 
#tutti gli elementi comuni a entrambe, senza duplicati 


def intersezione(a, b): 

    intersezione = []
    
    for i in a: 
        if i in b and i not in intersezione:
            intersezione.append(i) 

    return intersezione 

print(intersezione([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [2, 4, 6, 8, 10]))


#complessità temporale O(n^2), spaziale O(1)