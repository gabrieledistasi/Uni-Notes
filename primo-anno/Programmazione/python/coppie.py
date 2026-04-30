#scrivere una funzione in python che: 
#prenda in input una lista di interi lst 
#restituisce il numero di coppie (i, j) con i<j tali che lst[i]+lst[j] è pari

A = [1, 2, 3, 4, 5]

def coppie(A): 
    pairs = 0
    for i in range(len(A)): 
        for j in range(len(A)-1, -1, -1): 
            if (A[i]+A[j])%2 == 0: 
                pairs += 1
            elif j<i: 
                break

    return pairs
                
            
print(coppie(A))

#complessità O(n^2) temporale, spaziale O(1)