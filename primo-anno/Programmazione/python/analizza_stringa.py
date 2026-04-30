#scrivere una funzione in python che data una stringa in input 
#restituisce un dizionario con 
# -lunghezza : numero totale di caratteri 
# -num parole: numero di parole (separate da spazi)
# -palindroma: True 

def analizza_stringa(s): 

    wc = 1
    i = 0
    #conta quanti caratteri ci sono
    lunghezza = len(s) #tempo O(n)


    #conta il numero di parole separate da spazi
    num_parole = len(s.split()) #tempo O(n)
    
    #controlla se la parola è palindroma 
    palindroma = True
    n = len(s)
    for i in range(n // 2):
        if s[i] != s[n - 1 - i]:
            palindroma = False
        break

    return {"Lunghezza": lunghezza,
            "Numero Parole": num_parole,
            "Palindroma": palindroma }
# qui il valore palindroma è corretto


print(analizza_stringa("i topi non avevano nipoti"))

    




