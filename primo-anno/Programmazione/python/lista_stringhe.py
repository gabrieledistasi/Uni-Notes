'''
Si scriva una funzione Python chiamata raggruppa_per_lunghezza(lista_stringhe) 
che prende in input una lista di stringhe. La funzione deve restituire un dizionario in cui:

Le chiavi sono interi che rappresentano le lunghezze delle stringhe trovate nella lista.

I valori associati a ciascuna chiave sono liste contenenti tutte le stringhe di quella specifica lunghezza, mantenendo l'esatto ordine con cui compaiono nella lista originale.

Esempio:
Se lista_stringhe = ["mela", "pera", "kiwi", "banana", "uva", "fico"]
La funzione deve restituire:
{4: ['mela', 'pera', 'kiwi', 'fico'], 6: ['banana'], 3: ['uva']}'''


def raggruppa_per_lunghezza(lista_stringhe): 

    d = {}
    elements = []

    for i in lista_stringhe:
        if len(i) not in d: 
            d[len(i)] = []

        
        d[len(i)].append(i)


    return d


lista_stringhe = ["mela", "pera", "kiwi", "banana", "uva", "fico"]
print(raggruppa_per_lunghezza(lista_stringhe))