#Scrivere una funzione in Python che, data una lista a 
#di numeri ordinati in modo non decrescente ed un numero k,
#restituisce la posizione dell'occorrenza più a sinistra di k in a. 
# Se k non è in a, ritorna -1.


def findk(a, k): 

    for i in range(len(a)): 
        if a[i]==k: 
            return i
    
    return -1

print(findk([1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9, 11, 10, 11], 11))

#complessità O(n) temporale e spaziale 

#con ricerca binaria 

def binary_search_left(a, k): 
    n = len(a)
    lx, rx = 0, len(a)-1
