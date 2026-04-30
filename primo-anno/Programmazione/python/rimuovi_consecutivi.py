'''
scrivere una funzione 
def rimuovi_consecutivi(a): 

a è una lista di interi 
la funzione deve restituire una nuova lista 
deve eliminare gli elementi consecutivi uguali, lasciando solo una copia per ogni blocco
non usare itertools
'''

def rimuovi_consecutivi(a): 
    result = []

    for i in range(len(a)): 
        if a[i] == a[i-1]:
            a.pop(a[i])
    
    result = a
    return result

a = [1, 2, 3, 4, 5, 5, 6, 6, 7, 8]
print(rimuovi_consecutivi(a))

    




