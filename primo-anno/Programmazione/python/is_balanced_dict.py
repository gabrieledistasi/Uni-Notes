#scrivere una funzione python che: 
#riceve un dizionario d con valori interi 
#restituisce true se tutti i valori sono uguali 
#false altrimenti 


def is_balanced_dict(d): 

    x = list(d.values())
    i = 0
    
    while i < len(x): 

        if x[0] != x[i]: 
            return False 
        
        i+= 1
    
    return True 


    





d = {"a": 2, "b": 2, "c": 2, "d": 2} 
print(is_balanced_dict(d))

