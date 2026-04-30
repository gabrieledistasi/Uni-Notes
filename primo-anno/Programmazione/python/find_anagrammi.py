#hai una lista di stringhe, ad esempio 

parole = ["roma", "amor", "ramo", "sato", "taso", "osat", "ciao"]

def find_anagrammi(parole): 

    d = {}



    for parola in parole: 
        chiave = "".join(sorted(parola))
        

        if chiave not in d: 
            d[chiave] = []
        
        d[chiave].append(parola)


            
    
    return d

print(find_anagrammi(parole))

