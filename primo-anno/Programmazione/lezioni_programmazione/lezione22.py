#soluzioni esercizi fine settimana
#Implementare la seguente funzione

def lower(a):
        """
        Parametro: a, una stringa
        Ritorna una nuova stringa identica ad a, tranne per il fatto
            che tutte le lettere minuscole sono sostituite dalle
            corrispondenti lettere maiuscole
        """

'''Per risolvere il problema si utilizzino le funzioni ord e chr (vedere la documentazione) e si consideri il metodo delle stringhe join per limitare i costi computazionali.

Non sono ammesse altre funzioni o metodi non trattati a lezione.

Soluzione'''

def lower(a):
        """
        Parametro: a, una stringa
        Ritorna una nuova stringa identica ad a, tranne per il fatto
            che tutte le lettere minuscole sono sostituite dalle
            corrispondenti lettere maiuscole
        """

        # n = len(a)

        lower_a = ""
        for c in a: # per n volte
            if c >= "A" and c <= "Z":
                 nuovo_c = chr(ord("a")+ord(c)-ord("A"))
            else:
                 nuovo_c = c
            lower_a += nuovo_c   # complessità temporale, O( len(lower_a) ); complessità spaziale, O( len(lower_a) )
        return lower_a

        # complessità temporale O(n**2); complessità spaziale O(n)

testo = "PrograMMazioNe"
print( lower(testo) )

def lower(a):
        """
        Parametro: a, una stringa
        Ritorna una nuova stringa identica ad a, tranne per il fatto
            che tutte le lettere minuscole sono sostituite dalle
            corrispondenti lettere maiuscole
        """

        # n = len(a)

        lower_a = []
        for c in a: # per n volte
            if c >= "A" and c <= "Z":
                 nuovo_c = chr(ord("a")+ord(c)-ord("A"))
            else:
                 nuovo_c = c
            lower_a.append(nuovo_c)   # complessità temporale, O( 1 ); complessità spaziale, O( 1 )
        return "".join(lower_a)

        # complessità temporale O(n); complessità spaziale O(n)

testo = "PrograMMazioNe"
print( lower(testo) )


#Implementare la seguente funzione
def moda(L):
        """
        Parametro: L, una lista di interi
        Ritorna l'elemento più fraquente in L
        """


def moda(L):
    """
    Parametro: L, una lista di interi
    Ritorna l'elemento più fraquente in L
    """

    occ = {}
    for e in L: # per n=len(L) volte
        occ[e] = occ.get(e, 0)+1
        # Equivalente a ...
        #if e in occ:
        #    occ[e] += 1
        #else:
        #    occ[e] = 1
        
        
    return max(occ.items(), key=lambda t: t[1])[0]

    # Equinvalente a...
    #k_max = None
    #for k in occ: # al massimo n volte
    #    if k_max == None or occ[k] > occ[k_max]:
    #        k_max = k

    #return k_max

    

    # complessità temporale: O(n) sempre; complessità spaziale O(n) nel caso peggiore

a = [1, 4, 4, 100000, 6]
moda(a)

#Consultando la documentazione dire quali dei seguenti dati possono essere utilizzati come chievi in un dizionario: str, list, tuple, dict, set.
#Soluzione: i tipi immotabili possono essere usati come chiavi, gli altri no.



