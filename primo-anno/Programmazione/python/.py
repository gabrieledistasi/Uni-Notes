#scrivere una funzione chiamata flatten che prende in input una lista a che può 
#contenere sia elementi singoli, sia liste annidate a più livelli, la funzione 
#deve restituire una nuova lista contenente tutti gli elementi di a, eliminando 
#qualsiasi tipo di annidamento e mantenendo l'ordine degli elementi come nella
#lista originale 

def flatten(a): 
    tmp = []
    for i in a: 
        if type(i) != list: 
            tmp.append(i)
        else: 
            tmp.extend(flatten(i))
    i = 0


    return tmp


        

a = [1, 2, [4, 5, [6, 7, [8, 9], 'a', ['z'], 'ciao'], 10.1], 'sono stanco']
print(flatten(a))