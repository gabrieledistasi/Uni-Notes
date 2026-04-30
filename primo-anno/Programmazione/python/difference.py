#scrivere una funzione in python che, date due liste l1 e l2 entrambe ordinate, 
#restituisce una lista che è la differenza delle due liste l1 e l2, ovvero, 
#la nuova lista deve contenere tutti gli elementi di l1 tranne quelli che sono presenti anche in l2. 
#La soluzione deve avere complessità lineare in len(l1)+len(l2), e memoria supplementare costante, possibilmente


l1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 99, 100]
l2 = [2, 4, 6, 8, 10, 12,13, 14, 15, 32, 45, 50, 61, 99, 101]


def difference(l1, l2): 

    diff= []

    n, m = len(l1), len(l2)
    i, j = 0, 0

    while i < n and j < m: 

        if l1[i] == l2[j]: 
        
            i+=1 
            j+=1

        elif l1[i]<l2[j]: 
            diff.append(l1[i])
            i+=1
        else: 
            j+=1
    

    if j == m: 
        while i < n: 
            diff.append(l1[i])
            i+=1
    return diff

        
        

        
            
    

print(difference(l1, l2))