'''Sia tracks una lista di percorsi ciascuno dei quali identiﬁcato da una sequenza di punti 
di controllo di tipo intero, eventualmente ripetuti. 
Si scriva un programma che stampi, per ogni punto di controllo, 
il numero di percorsi distinti che lo attraversano.
Esempio. Se
tracks = [[31,33,34,44,33], [32,31,33,37,45,31], [43, 44, 34, 37]]'''

def conta_percorsi(tracks):
    conta = {}

    for percorso in tracks:
        visti = []

        for punto in percorso:
            if punto not in visti:
                visti.append(punto)

        for punto in visti:
            if punto in conta:
                conta[punto] += 1
            else:
                conta[punto] = 1

    for punto in sorted(conta):
        print(punto, conta[punto])

        
    

            

