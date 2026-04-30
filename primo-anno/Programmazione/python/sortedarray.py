#scrivere in python una funzione che dato un array restituisce TRUE se è strettamente 
#crescente, FALSE altrimenti

A = [1, 2, 3, 4, 5, 6, 7, 10]

def sortedarray(A): 
    for i in range(len(A)-1): 
        if A[i] > A[i+1]: 
            return False
    
    return True 

print(sortedarray(A))

#complessità temporale O(n), complessità spaziale O(1)