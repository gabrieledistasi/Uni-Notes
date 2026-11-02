#questo algoritmo calcola il numero di foglie presenti in un albero 

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

def CalcolaNumeroFoglie(r): 

    if r == None: 
        return 0
    if r.sinistro == None and r.destro == None: 
        return 1

    sin = CalcolaNumeroFoglie(r.sinistro)
    des = CalcolaNumeroFoglie(r.destro)

    return des+sin

radice = albero()
print(CalcolaNumeroFoglie(radice))
    
        