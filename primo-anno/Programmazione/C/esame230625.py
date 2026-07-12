'''Lungo un’autostrada ci sono diverse stazioni di servizio, ciascuna identificata da un nome e dalla sua
posizione in chilometri dalla partenza.
Implementare una funzione denominata max_gap che restituisce la lunghezza del tratto più lungo
dell’autostrada in cui non è presente alcuna stazione di servizio.
L'input della funzione è costituito da una lista di coppie (nome_stazione, km) ordinata
alfabeticamente per nome.
Esempio:
Con input la lista
[("Caianello", 230), ("Caserta", 250), ("Casilina", 40), ("Cassino Sud",
115), ("Frascati", 20), ("La Macchia", 30), ("San Nicola", 90), ("San
Vittore", 80), ("Teano", 210) ]
la funzione max_gap deve restituire 95 .'''


def max_gap(lista):
    km = []

    for nome, pos in lista:
        km.append(pos)

    km.sort()

    massimo = 0

    for i in range(len(km) - 1):
        diff = km[i + 1] - km[i]

        if diff > massimo:
            massimo = diff

    return massimo