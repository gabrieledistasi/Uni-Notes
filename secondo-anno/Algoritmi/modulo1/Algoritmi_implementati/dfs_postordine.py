
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

def dfs_postordine(r): 

    if r is None: 
        return 

    dfs_postordine(r.sinistro)
    dfs_postordine(r.destro)
    print(r.valore)

radice = albero()
dfs_postordine(radice)