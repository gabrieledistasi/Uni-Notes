'''scrivere una funzione def duplica_pari(a): 
a è una lista di interi 
la funzione deve restituire una nuova lista 
ogni elemento pari deve essere duplicato nella lista risultante 
gli elementi dispari devono rimanere una sola volta
non usare list comprehension '''

def duplica_pari(a): 

    result = []
    for i in range(len(a)): 
        if a[i]%2==0: 
            result.append(a[i])
            result.append(a[i])
            
        else: 
            result.append(a[i])
    return result



a = [1, 2, 4, 5, 6, 7, 8, 9, 10]
print(duplica_pari(a))

#complessità temporale O(n)
#complessità spaziale O(n)