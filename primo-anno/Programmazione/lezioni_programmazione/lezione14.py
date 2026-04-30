#Implementare in modo ricorsivo la seguente funzione

def argmax( L ):
        """
        Parametri: L una lista di valori confrontabili tra di loro
        Ritorna: se |L| > 0, la posizione del massimo in L, altrimenti None
        """

def argmax( L, i ):
    """
    Parametri: L una lista di valori confrontabili tra di loro, un indice della lista (i<n)
    Ritorna la posizione del massimo tra gli elementi L[i], L[i+1],...,L[n-1] se n > 0, altrimenti None
    """
    n = len(L)
    if n == 0:
        return None
    if i == n-1:
        return i

    p = argmax( L, i+1 )
    if L[i] > L[p]:
        return i
    else:
        return p

def argmax( L, i ):
    """
    Parametri: L una lista di valori confrontabili tra di loro, un indice della lista (i<n)
    Ritorna la posizione del massimo tra gli elementi L[i], L[i+1],...,L[n-1] se n > 0, altrimenti None
    """
    n = len(L)
    if n == 0:
        return None
    if i == n-1:
        return i

    p = argmax( L, i+1 )
    if L[i] > L[p]:
        return i
    else:
        return p
    

