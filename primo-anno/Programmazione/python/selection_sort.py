
lst = [7, 12, 9, 11, 3]
k = 2


def selection_smallest_k(lst, k): 

    lst = lst.copy() #non modifico la lista originale

    for i in range(k): #posiziono i minimi nelle prime k posizioni
        min_index = i   #assumo che il minimo sia i

        #cerco il minimo tra gli elementi rimanenti
        for j in range(i+1, len(lst)): 
            if lst[j] < lst[min_index]: 
                min_index = j 

        #scambio il minimo trovato con l'elemento trovato in posizione i
        lst[i], lst[min_index] = lst[min_index], lst[i] 
    
    return lst[:k]

print(selection_smallest_k(lst, k))




    

