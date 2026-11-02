# Questo algoritmo ricerca un elemento in un albero 

class Nodo: 
    def __init__(self, valore):
        self.valore = valore
        self.sinistro = None
        self.destro = None


def albero(): 
    a = Nodo("A")
    l = Nodo("L")
    b = Nodo("B")
    e = Nodo("E")
    r = Nodo("R")
    o = Nodo("O")

    a.sinistro = l
    a.destro = b
    l.sinistro = e
    l.destro = r
    b.destro = o

    return a

def cerca_elemento(r, k): 
    if r == None: 
        return None

    if r.valore == k: 
        return r

    sin = cerca_elemento(r.sinistro, k)

    if sin!= None: 
        return sin

    return cerca_elemento(r.destro, k)