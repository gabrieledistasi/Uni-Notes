#Dizionari
'''Un dizionario è una struttura dati astratta composta da coppie (k, v) con la proprietà che le chiavi k, il primo elemento della coppia, non sono ripetute. Questo crea una associazione tra k ed il corrispondente valore v. Sul dizionario sono definite le seguenti operazioni:

Creazione: crea un dizionario vuoto;
Lettura/Ricerca: data una chiave, ritorna il valore ad essa associata;
Aggiornamento: data una coppia (k, v1), se k è una chiave del dizionario, l'operazione sostituisce il vecchio valore con v1;
Inserimento: inserisce una nuova coppia (k, v) nel caso k non sia già presente come chiave nel dizionario.
Cancellazione: data una chiave k, cancella dal dizionario la coppia con chiave k.
# implementazione di un dizionario con una lista'''

def crea_dizionario():
    """
    Ritorna un dizionario vuoto
    """
    return []

    # complessità temporale O(1)
    # complessità spaziale O(1)

def cerca(D, k):
    """
    Parametri:  D una lista che implementa un dizionario come lista di coppie (chiave, valore)
        k una potenziale chiave
    Ritorna, se esise, la posizione in D della coppia che ha per chiave k, altrimenti None
    """
    for i in range(len(D)):
        if D[i][0] == k:
            return i
    return None

    # complessità temporale O(len(D))
    # complessità spaziale O(1)

def inserisci(D, k, v):
    """
    Parametri:  D una lista che implementa un dizionario come lista di coppie (chiave, valore)
        k una chiave
        v un valore 
    Ritorna None

    Effeti collaterali: se k è una chiave, sostituisce il suo valore con v; altrimenti aggiunge la coppia (k,v)
    """
    p = cerca(D, k)
    if p ==  None:
        D.append( (k,v) )
    else:
        D[p] = (k,v)

    # complessità temporale O(len(D))
    # complessità spaziale O(1)

def appartiene(D, k):
    """
    Parametri:  D una lista che implementa un dizionario come lista di coppie (chiave, valore)
        k una potenziale chiave
    Ritorna True se e solo se k è una chiave di D
    """
    if cerca(D,k) == None:
        return False
    else:
        return True
    
    # complessità temporale O(len(D))
    # complessità spaziale O(1)

def cancella(D, k):
    """
    Parametri:  D una lista che implementa un dizionario come lista di coppie (chiave, valore)
        k una chiave
    Ritorna None

    Effeti collaterali: se k è una chiave, cancella da D la coppia con quella chiave
    """
    p = cerca(D,k)
    if p != None:
        del(D[p])

    # complessità temporale O(len(D))
    # complessità spaziale O(1)
d = crea_dizionario()
inserisci(d, "uno", 1)
inserisci(d, "zero", 0)
inserisci(d, "uno", 1.0)
inserisci(d, "due", 2.0)
inserisci(d, 3, "tre")
cancella(d, "due")
print(appartiene(d, "zero"))

print(d)
True
[('uno', 1.0), ('zero', 0), (3, 'tre')]
#La struttura dati Dizionario incorporata in Python
d = {} # dizionario vuoto
d["uno"] = 1
d["zero"] = 0
d["uno"] = 1.0
d["due"] = 2.0
d[3] = "tre"
print(d["zero"])
print(d)

del(d["due"])
print(d)

print("uno" in d)

print(len(d))

a = [1,2,3]

d["lista0"] = a
d["lista1"] = a
print(d)

del(d["lista0"])

print(d)
0
{'uno': 1.0, 'zero': 0, 'due': 2.0, 3: 'tre'}
{'uno': 1.0, 'zero': 0, 3: 'tre'}
True
3
{'uno': 1.0, 'zero': 0, 3: 'tre', 'lista0': [1, 2, 3], 'lista1': [1, 2, 3]}
{'uno': 1.0, 'zero': 0, 3: 'tre', 'lista1': [1, 2, 3]}
#Le operazioni su dizionario Python hanno costo costante in media.

#Soluzione efficiente del problema dell'intersezione tra liste.

a = [1,3,2,1,6,7,3,1,8]
b = [0,4,3,1,3,5,7]

da, db = {}, {}



for x in a: # O(len(a))
    da[x] = None

for x in b: # O(len(b))
    db[x] = None

c = []

for k in da: # per al più O(len(a)) volte 
    if k in db: # O(1)
        c.append(k) # O(1)

print(c)

# complessità temporale: O(len(a) + len(b) )
[1, 3, 7]
