#crea una funzione che, data una lista in input restituisca in output la lista senza liste vuote all'interno




def removeblank(numeri):

    for i in range(len(numeri) -1, -1, -1): 
        if numeri[i] == []: 
            numeri.pop(i)
        

    return numeri

print(removeblank([3, 11, [4,3], [], 4, [1], 18]))
