
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

def BFS_iterativa(r): 

    lista = []
    lista.append(r)

    while(lista != []): 
        u = lista.pop(0)

        if u !=None: 
            print(u.valore)
            lista.append(u.sinistro)
            lista.append(u.destro)

radice = albero()
BFS_iterativa(radice)




