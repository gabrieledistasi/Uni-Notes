#questo algoritmo calcola il grado medio di un nodo 
#il grado di un nodo è il numero di figli che un nodo possiede

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

def SommaGradi(r): 
    nodo_di_r = 0

    if r == None: 
        return 0
    
    if r.sinistro==None and r.destro==None: 
        return 0
    
    if r.sinistro==None or r.destro == None: 
        nodo_di_r+=1
    
    else: 
        nodo_di_r+=2

    des = SommaGradi(r.destro)
    sin = SommaGradi(r.sinistro)

    return nodo_di_r+des+sin

def ContaNodi(r): 
    
    if r == None: 
        return 0

    des = ContaNodi(r.destro)
    sin = ContaNodi(r.sinistro)

    return 1+des+sin

def ContaNodiInterni(r): 

    if r == None: 
        return 0
    
    if r.sinistro == None and r.destro == None: 
        return 0


    
    return 1+ContaNodiInterni(r.sinistro)+ContaNodiInterni(r.destro)


    
    
    

def CalcolaGradoMedio(r): 

    return SommaGradi(r)/ ContaNodiInterni(r)






radice = albero()
print(CalcolaGradoMedio(radice))
