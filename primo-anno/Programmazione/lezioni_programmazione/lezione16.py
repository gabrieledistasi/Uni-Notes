#Modificare l'algoritmo Bubble-Sort in modo che il ciclo esterno termini, e quidi l'algoritmo si arresti, non appena la lista risulti ordinata.

#Utilizzare il codice risultante per implementare la funzione con la seguente specifica

def bubble_sort( L ):
        """
        Parametro: una lista con elementi tutti confrontabili
        Ritorna: None

        Come effetto collaterale, ordina gli elementi di L dal più piccolo al più grande
        """
#Calcolare la complesità della funzione.
def bubble_sort( L ):
    """
    Parametro: una lista con elementi tutti confrontabili
    Ritorna: None

    Come effetto collaterale, ordina gli elementi di L dal più piccolo al più grande
    """
    n = len(L)
    for c in range(n-1): # per n-1 volte
        ordinata = True
        for i in range(n-1-c): # per n-1 volte, non è necessario considerare gli ultimi c elementi
            if L[i] > L[i+1]:
                ordinata = False
                L[i], L[i+1] = L[i+1], L[i]
        # valuto ordinata
        if ordinata:
            break

    # complessità temporale: caso migliore O(n), peggiore O(n**2)
    # complessità spaziale: O(1) memoria extra

b = [100, 10, 9, 8, 7, 6, 5, 2]
print(b)
[100, 10, 9, 8, 7, 6, 5, 2]
#Intersezione tra due liste ordinate

a = [-10, -10, 1, 3, 3, 6, 8, 9, 9, 10]
b = [-10, -10, 0, 2, 3, 3, 4, 5, 6, 6, 10]

def intersezione(L0, L1):
    """
    Parametri: L0 e L1, due liste ordinate rispetto l'operatore <=

    Ritorna: la lista Lc contenente l'intersezione di L0 e L1. Gli elementi in
        Lc sono ordinati secondo <= e senza ripetizioni
    """
    Lc = []

    i, j = 0, 0

    while i < len(L0) and j < len(L1):
        if L0[i] == L1[j]:
            if len(Lc) == 0 or Lc[-1] != L0[i]:
                Lc.append(L0[i])
            i += 1
            j += 1
        elif L0[i] < L1[j]:
            i+=1
        else:
            j+=1

    return Lc

# Complessità temporale: siano n e m le dimensioni di L0 e L1, il while termina dopo al più n+m iterazioni. Ogni iterazione ha costo costante. Quindi la funzione ha costo lineare nella lunghezza delle liste.
# Complessità spaziale: usa O(1) spazio extra
#Ricerca su liste ordinate: da una lista ordinata, cercare la posizione di k.

def ricerca_binaria( L, k):
    """
    Parametri: L, una lista ordinata secondo <=; k un valore
    Ritorna la posizione di una occorrenza di k in L, se k non è presente in L ritorna -1
    """
    n = len(L)

    lx, rx = 0, n

    while lx <= rx-1:
        cx =int( (lx+rx)/2 )

        if L[cx] == k:
            return cx
        if k < L[cx]:
            rx = cx
        else:
            lx = cx+1

    return -1
'''Complessità temporale

il caso peggiore è quello in cui k non è presente in L.
ad ogni iterazione lo spazio di ricerca si riduce ella metà;
dopo k iterazioni questo misura n2'''
