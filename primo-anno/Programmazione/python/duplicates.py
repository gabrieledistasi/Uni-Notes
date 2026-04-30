#scrivere una funzione che data una lista di interi restituisce una lista contenente i duplicati 
lista = [10, 20, 30, 20, 20, 30, 40, 50, -20, 60, 60, -20, -20]



def duplicates(lista): 
    duplicati = []

    for i in lista: 
        if lista.count(i)>1 and i not in duplicati: 
            duplicati.append(i)
    
    return duplicati



print(duplicates(lista))




