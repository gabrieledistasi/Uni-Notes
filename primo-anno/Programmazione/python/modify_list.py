#scrivere una funzione in python che, data una lista di interi in input, esegue le seguenti
#operazioni: 
# -rimuove i duplicati dalla lista 
# -crea una tupla a partire dalla lista modificata 
# -restituisce l'elemento massimo e l'elemento minimo della tupla 

def modify_list(a): 

    i = 0

    while i < len(a): 
        j = i + 1
        while j < len(a): 
            if a[i]==a[j]: 
                del a[j]
            else: 
                j+=1
        i+=1 
    
    numbers_tuple = ()

    for e in a: 
        numbers_tuple += (e,)
    
    print(numbers_tuple)


    maximum = max(numbers_tuple)
    minimum = min(numbers_tuple)

    return maximum, minimum


print(modify_list([3, 23, 3432, 43, 42342,34, 342,3,434323445]))