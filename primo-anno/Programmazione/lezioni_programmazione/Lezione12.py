def argmax(L):
    """
    Parametri: L, lista di numeri
    Ritorna: la posizione del massimo in L
    """

    cur_max, pos = None, None
    
    for i, x in enumerate(L):
        if  cur_max == None or x > cur_max:
            cur_max, pos = x, i

    return pos


#seconda versione 

def argmax(L):
    """
    Parametri: L, lista di elementi tutti confrontabili con >
    Ritorna: la posizione del massimo in L
    """

    cur_max, pos = None, None
    
    for i, x in enumerate(L):
        if  cur_max == None or x > cur_max:
            cur_max, pos = x, i

    return pos


#second max

def second_max( L ):
        """
        Parametri: L una lista di numeri
        
        Ritorna il secondo valore più grande della lista L;
        se la lista contiene almeno due elementi, None altrimenti.
        
        Nel caso di due massimi, la funzione ritorna il massimo
        """
        if len(L) >= 2:
            p = argmax(L) # O(n) tempo; O(1) spazio extra
            del(L[p])     # O(n) tempo nel caso peggiore; O(1) spazio extra
            return max(L) # O(n) tempo; O(1) spazio extra
       
        # complessità temporale: O(n)
        # complessità spaziale: O(1) <====== spazio extra
        
        return None