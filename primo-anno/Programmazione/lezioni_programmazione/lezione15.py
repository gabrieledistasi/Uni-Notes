#L'implementazione ricorsiva della funzione argmax non rispetta le specifiche indicate. Dire perché e proporre una soluzione ricorsiva che le rispetti.
#Soluzione. La specifica originale non prevedeva il parametro i. Si risolve isolando la ricorsione con una seconda funzione.

def argmax_r( L, i ):
    """
    Parametri: L una lista di valori confrontabili tra di loro, un indice della lista (i < n)
    Ritorna la posizione del massimo tra gli elementi L[i], L[i+1],...,L[n-1] se n > 0, altrimenti None
    """
    n = len(L)
    if n == 0:
        return None
    if i == n-1:
        return i

    p = argmax_r( L, i+1 )
    if L[i] > L[p]:
        return i
    else:
        return p
    

def argmax( L ):
    """
    Parametri: L una lista di valori confrontabili tra di loro
    Ritorna: se |L| > 0, la posizione del massimo in L, altrimenti None
    """
    return argmax_r(L, 0)



def argmax( L ):
    """
    Parametri: L una lista di valori confrontabili tra di loro
    Ritorna: se |L| > 0, la posizione del massimo in L, altrimenti None
    """
    def argmax_r( L, i ):
        """
        Parametri: L una lista di valori confrontabili tra di loro, un indice della lista (i<n)
        Ritorna la posizione del massimo tra gli elementi L[i], L[i+1],...,L[n-1] se n > 0, altrimenti None
        """
        n = len(L)
        if n == 0:
            return None
        if i == n-1:
            return i

        p = argmax_r( L, i+1 )
        if L[i] > L[p]:
            return i
        else:
            return p

    return argmax_r(L, 0)


#clonazione profonda

#La soluzione ricorsiva clona ricorsivamente tutti gli elementi della lista di partenza aggiungendoli 
# in fondo alla lista di output.

def deep_cloning( x ):
    """
    Parametro: x una lista, eventualmente contenente liste annidate
    Ritorna una copia profonda di x, ovvero clona x e tutte le sottoliste annidate 
    """

    if type(x) != list:
        return x
    
    C = []

    for e in x:
        C.append( deep_cloning(e) )

    return C





