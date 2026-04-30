#Scrivere una funzione in Python che, data una lista di numeri interi distinti non negativi ordinati in modo crescente, 
#restutisce il più piccolo elemento non negativo mancante in essa. 
#Se non ci sono elementi mancanti, restituisce -1.


A = [0, 1, 2, 3, 4, 5, 6, 7, 8]


def find_missing_elem(A): 

    new_array = []

    if A[0] != 0: 
        return 0

    for i in range(len(A)-1): 
        if A[i+1]-A[i] != 1: 
            app=A[i]
            for _ in range(A[i], A[i+1]-1):
                app=app+1
                new_array.append(app)

    if new_array == []: 
        return -1




    return new_array
    
        
            


print(find_missing_elem(A))