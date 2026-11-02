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

def dfs_preordine(r): 

    if r is None: 
        return 

    print(r.valore)
    dfs_preordine(r.sinistro)
    dfs_preordine(r.destro)


radice = albero()
dfs_preordine(radice)


 

