#scrivere un programma che, dati due insiemi a e b, restituisca gli elementi che stanno solo in a e solo in b

def sym(A, B): 
    C = []

    if len(B) > len(A): 

        for i in B:  
            if i not in A and i in B: 
                C.append(i)
    else: 
        for i in A:  
            if i not in B  and i in A: 
                C.append(i)
            

    return C


A = [1, 2, 3]
B = [5, 2, 1, 4]
print(sym(A, B))
