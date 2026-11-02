#Questo algoritmo calcola l'altezza di un albero in modo ricorsivo

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

def CalcolaAltezza(r): 
    if r == None: 
        return -1

    sin = CalcolaAltezza(r.sinistro)
    des = CalcolaAltezza(r.destro)

    return 1+max(sin, des)


radice = albero()
print(CalcolaAltezza(radice))





        