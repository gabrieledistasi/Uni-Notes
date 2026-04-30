def conta_parole(frase): 
    
    d = {}
    frase = frase.lower()
    parole = frase.split()
    

    for w in parole: 
        if w in d: 
            d[w] += 1
        else: 
            d[w] = 1

    return d
    


frase = "al cor gentil rempaira sempre amore"
print(conta_parole(frase))

#complessità O(n)