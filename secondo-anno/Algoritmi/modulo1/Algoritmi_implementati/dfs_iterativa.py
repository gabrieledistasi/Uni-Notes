
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

def dfs_iterativa(r): 
    pila = []
    pila.append(r)
    if r == None: 
        return 
    
    while pila != []: 
        u = pila.pop()
        if u != None:
            print(u.valore)
            pila.append(u.destro)
            pila.append(u.sinistro)

radice = albero()
dfs_iterativa(radice)