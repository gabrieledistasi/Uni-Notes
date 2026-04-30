#Scrivere una funzione in Python che, date due liste l1 e l2, 
#restituisce True se ogni elemento di l1 è contenuto anche in l2, False altrimenti.


def listcontain(l1, l2): 

    tmp = []

    for i in l1: 
        for j in l2: 
            if i==j: 
                tmp.append(i)
    result = []
    for e in tmp: 
        if e not in result: 
            result.append(e)
    return result 


print(listcontain("bastoni", "bastoncino"))

#ciao gabriele =) 