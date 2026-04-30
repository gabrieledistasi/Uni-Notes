#scrivere una funzione che riceve una lista interi lst 
#restituisce una nuova lista contenente solo i numeri >= 0
#preservando l'ordine 


def remove_negative_keep_order(lst): 

    new_lst = []
    

    for i in range(len(lst)): 
        
        if lst[i] < 0: 
            continue 
        else: 
            new_lst.append(lst[i])
        
    
    return new_lst





lst = [3, -1, 0, -5, 2]
print(remove_negative_keep_order(lst))

#complessità temporale O(n)
#complessità spaziale O(n)