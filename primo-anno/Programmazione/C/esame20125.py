'''si scriva una funzione deep_mean ricorsiva che calcoli la media di tutti i numeri presenti in una lista, anche se la lista contiene altre liste annidate. La funzione deve restituire la media come un numero float.'''

def deep_mean(a):
    somma, quanti = conta(a)

    if quanti == 0:
        return 0

    return somma / quanti


def conta(a):
    somma = 0
    quanti = 0

    for x in a:
        if type(x) == list:
            s, c = conta(x)
            somma += s
            quanti += c
        else:
            somma += x
            quanti += 1

    return somma, quanti