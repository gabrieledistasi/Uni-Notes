#Scrivere una funzione in Python che, data una lista composta da interi e sottoliste annidate 
#(composte da interi e altre sottoliste), restituisce in output la somma di tutti gli interi.

def totalsum(a): 
    tmp = 0
    for i in a: 
        if type(i)!=list: 
            tmp += i
        else: 
            tmp += totalsum(i)
    return tmp 

a = [1, 2, 3, [4, 5], [6, 7, [5]], [8,9], [10]]

print(totalsum(a))




