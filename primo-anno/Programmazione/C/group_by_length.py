'''
Scrivere la funzione

def group_by_length(words):

che riceve una lista di stringhe words e restituisce un dizionario.

Le chiavi devono essere le lunghezze delle parole.

I valori devono essere liste contenenti tutte le parole di quella lunghezza, mantenendo l'ordine di comparsa.'''


def group_by_length(words): 

    d = {}

    for parola in words: 
        length = len(parola)

        if length not in d: 
            
            d[length] = []
            
        d[length].append(parola)

    return d
        

    







words = ["ciao", "cane", "gatto", "topo"]
print(group_by_length(words))
        
        