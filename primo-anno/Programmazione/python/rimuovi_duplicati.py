#scrivere una funzione con il seguente prototipo: 
#def rimuovi_duplicati
#In particolare la funzione ritorna la lista senza duplicati 

def rimuovi_duplicati(lst):
    new_lst = []

    for x in lst : 
        if not new_lst or new_lst[-1] != x: 
            new_lst.append(x)

    return new_lst





lst = [1, 1, 1, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7 , 8, 9, 9, 9, 10]
print(rimuovi_duplicati(lst))