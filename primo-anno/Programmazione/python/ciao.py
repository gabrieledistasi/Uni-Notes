#dato un array  di numeri non ordinati, calcola la sequenza di numeri decrescenti più lunga

A = [1, 2, 3, 45, 10, 6 , 5, 6,2 , 6, 5, 6, 50, 39, 40, 11, 15, 2, 39]


def find_seq(A): 
    k = 0
    massimo = 0
    s = 0
    e = 0
    
    
    for i in range(1, len(A)): 
        if A[i-1] > A[i]: #controlla se sto nella sequenza è decrescente 
            k += 1 



        else: #se è finita o se non sto nella seq dec
            if massimo < k: 
                massimo = k 
                e = i-1
                s = e-k
            k = 0

    for i in range(s, len(A)-massimo-1): 
        A[i] = A[i+massimo+1]    

    #return A[:len(A)-massimo-1]
    #return [el for i, el in enumerate(A) if i < len(A) - massimo - 1]
    return [A[i] for i in range(len(A) - (massimo + 1))]

print(find_seq(A))

