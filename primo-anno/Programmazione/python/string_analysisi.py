#scrivere una funzione che analizzi una stringa

def analizza_stringa(a): 
    
    
    vocali = "aeiouAEIOU"
    d = {"vocali": 0, 
         "consonanti": 0, 
         "cifre" : 0, 
         "spazi": 0, 

         
         }

    

    for i in a: 
        if i in vocali: 
            d["vocali"]+=1
        elif i.isdigit(): 
            d["cifre"] += 1
        elif i.isspace(): 
            d["spazi"]+=1 
        elif i.isalpha(): 
            d["consonanti"]+=1
    
    return d

a = "al cor gentil rempaira sempre amore"
print(analizza_stringa(a))


