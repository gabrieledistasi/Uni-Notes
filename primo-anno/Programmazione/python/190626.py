#modificare la funzione bubble_sort vista L lezione in modo che ritorni la lista dei k elementi più piccoli della 
#lista di input. Più precisamente, la funzione da implementare deve soddisfare le specifiche indicate nella seguente 
#docstring

def partial_bubble_sort(L, k): 


    for c in range(k): # per n-1 volte
        for i in range(n-2, -1, -1): # per n-1 volte, non è necessario considerare gli ultimi c elementi
            if L[i] > L[i+1]:
                L[i], L[i+1] = L[i+1], L[i]

    return(L[:k])

# complessità temporale O(n**2)
# complessità spaziale O(1)


L = [3,12,1,7,4,2,6,7,2,1]
n = len(L)
k=3
print(partial_bubble_sort(L, k))