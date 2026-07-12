'''siano date due liste di interi a e t, a rappresenta una lista di codici numerici, t una lista con codici target
di cui si vuole verificare la presenza e l'ordine in a. Scrivere una funzione python chiamata verifica_sequenza(a, t)
che nel caso in cui la lista a contenga tutti gli elementi di t nell'esatto ordine in cui compaiono in t, 
restituisca una lista p dove p[i] indica la posizione in a in cui compare t[i]
altrimenti restituisca la lista vuota '''

def verifica_sequenziale(a, t):

    p = []
    j = 0
    n = len(t)
    

    for i in range(len(a)):

        if  j < n and a[i] == t[j]: 
            p.append(i)
            j += 1
        
    if len(p) != len(t): 
        return []

    

    return p
         
    





a =[33, 43, 35, 31, 50, 49, 35, 37, 50, 100]
t = [43, 35, 31, 49, 35, 50]


print(verifica_sequenziale(a, t))

#complessità spaziale 