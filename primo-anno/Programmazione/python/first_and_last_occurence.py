def first_and_last_occurrence(A, k): 

    for i in range(len(A)): 
        if A[i]==k: 
            prima_posizione = i
    for j in range(len(A -1, -1, -1)): 
        if A[j] == k: 
            seconda_posizione = j
            break
    
    return "Prima occorrenza: posizione", prima_posizione, "Ultima occorrenza",  seconda_posizione

A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 4]

k = 3

print(first_and_last_occurrence(A, k))