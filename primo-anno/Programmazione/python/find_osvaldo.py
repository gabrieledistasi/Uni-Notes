#in una lista c'è un intruso: osvaldo
#scrivere una funzione in python che data una lista di elementi, tra cui sottoliste annidate, ritorna 
#True se trova osvaldo, False altrimenti

def find_osvaldo(a): 

    for i in a: 
        if type(i)== str: 
            if i.lower() == "osvaldo": 
                return True 
        elif type(i) == list : 
            if find_osvaldo(i): 
                return True
    return False 


print(find_osvaldo([1,2,3,[1,2,3,4],[1,5,4,2,[1,2,"osvaldo "],4,3,2]]
))

            