'''si scriva una funzione chiamata word_frequency_map che prenda come argomento una stringa testo 
e un intero k. La funzione deve: 
1.  contare le occorrenze di ogni parola (ignorando la distinzione tra maiuscole e minuscole)
2.  restituire un dizionario dove le chiavi sono le frequenze riscontrate e i valori sono liste di parole
    che compaiono esattamente quel numero di volte
3.  nel dizionario finale devono essere incluse solo le frequenze maggiori o uguali a k'''

def frequency_map(testo, k): 

    d = {}
    

    lower_testo = testo.lower()
    parole = lower_testo.split()

    for i in range(len(parole)):

        if parole[i] not in d: 
            d[parole[i]] = 1 
        else: 
            d[parole[i]] += 1
    

    for i in list(d.keys()):  
        if d[i] < k: 
            del d[i]


    ris = {}
    for i in d: 
        frequenza = d[i]

        if frequenza not in ris: 
            ris[frequenza] = []
        
        ris[frequenza].append(i)
    


    return ris


testo = "ciao ciao come stai io tutto bene"
print(frequency_map(testo, 1))


#complessità temporale: sia n la lunghezza della variabile test, il ciclo esegue n iterazioni, l'operatore in per il controllo
#ha complessità O(1), supponiamo n parole e dunque n chiavi, anche il secondo for ha complessità O(n), dunque O(n+n)--> O(n)
#complessità spaziale: sia n il numero di parole, la funzione split ha costo O(n) e il dizionario al termine del programma
#nel caso in cui tutte le parole siano diverse, avrà complessità O(n), dunque complessità spaziale O(n)