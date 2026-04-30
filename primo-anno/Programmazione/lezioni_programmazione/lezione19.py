#def merge_sort(L, key=lambda x:x, lx=0, rx=None):
"""
    Parametro: L, una lista di elementi confrontabili con <=
        lx < rx, due indici in L
    Ritorna: None

    Effetto collaterale: ordina gli elementi di L dalla posizione lx a rx-1;
    
    se rx è None, ordina fino all'ultimo elemento della lista
    """

def merge(L, lx, cx, rx):
        """
        Parametri: L una lista di elementi confrontabili con <=
            lx <= cx < rx, tre indici di L e tali che
            L[lx] <= L[lx+1] <= ... <= L[cx-1] e
            L[cx] <= L[cx+1] <= ... <= L[rx-1]
        Output: None

        Effetto collaterale: al termine della funzione
        L[lx] <= L[lx+1] <= ... <= L[rx-1]
        """

        M = []

        i, j = lx, cx

        while i < cx and j < rx:
            if key(L[i]) <= key(L[j]):
                m = L[i]
                i += 1
            else:
                m = L[j]
                j += 1
            M.append(m)

        while i < cx:
            M.append(L[i])
            i += 1

        while j < rx:
            M.append(L[j])
            j += 1

        for i in range(len(M)):
            L[lx+i] = M[i]

        # complessità temporale O(rx-lx), nel caso peggiore O( len(L) )
        # complessità spaziale O(rx-lx), nel caso peggiore O( len(L) )

    if rx == None:
        rx = len(L)

    if lx >= rx-1:
        return None
    cx = (lx+rx)//2 # divisione intera

    merge_sort(L, key, lx, cx)
    merge_sort(L, key, cx, rx)
    merge(L, lx, cx, rx)

    # n = len(L)
    # complessità temporale: O(n log n), sempre
    # complessità spaziale: O(n) per la lista in merge + O(log n) per lo stack delle chiamate. In totale O(n)

a = ["zero", "uno", "due", "tre", "quattro", "cinque"]

merge_sort(a, key=lambda x: (len(x), x) )

print(a)


#La funzione sort ordina una sequenza ritornando una nuova lista ordinata. Il parametro key ha lo stesso significato di quello in merge_sort.

a = ["zero", "uno", "due", "tre", "quattro", "cinque"]
b = sorted(a, key=lambda x: (len(x), x))
print(a)
print(b)

['zero', 'uno', 'due', 'tre', 'quattro', 'cinque']
['due', 'tre', 'uno', 'zero', 'cinque', 'quattro']