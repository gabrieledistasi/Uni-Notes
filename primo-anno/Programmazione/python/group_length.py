#scrivere una funzione group_lengths(lst) che, data una lista di stringhe lst, restituisca un dizionario in cui 
#le chiavi sono le lunghezze delle stringhe 
#i valori sono il numero di stringhe di quella lunghezza


def group_lengths(lst): 

    d = {

    }

    for i in lst: 
        if len(i) not in d: 
            d[len(i)] = 1 
        else: 
            d[len(i)] += 1 

    return d


lst = ["ciao", "gatto", "aragosta", "aeroplano", "oro"]
print(group_lengths(lst))

#complessità temporale O(n)
#complessità dizionario O(n)





