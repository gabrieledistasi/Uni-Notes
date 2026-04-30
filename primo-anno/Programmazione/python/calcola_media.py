#gestione di una lista di studenti 
#data una lista di tuple (nome, voto)
#calcola la media dei voti 
#restituisci i nomi degli studenti sopra la media, ordinati alfabeticamente 


def calcola_media(nomi_voti): 

    somma = 0
    i = 0
    j = 0
    bravissimi = []

    if nomi_voti == []: 
        return "La lista è vuota"

    while i < len(nomi_voti): 
        somma += nomi_voti[i][1]
        i += 1


    media = somma/len(nomi_voti)

    while j < len(nomi_voti): 
        if nomi_voti[j][1] > media: 
            bravissimi.append(nomi_voti[j][0])
        j+=1

    bravissimi.sort()


    return bravissimi
        

    







nomi_voti = [("gabriele", 10), 
             ("giorgio", 7), 
             ("cizzeta", 10), 
             ("davide", 7), 
             ("daniele", 1)]

print(calcola_media(nomi_voti))