#scrivere una funzione in python che date in input due stringhe restituisce 
#true se le due stringhe sono anagrammi, false altrimenti 

def anagrammi(p1, p2):
    # Rimuove spazi e mette tutto in minuscolo
    p1 = p1.replace(" ", "").lower()
    p2 = p2.replace(" ", "").lower()

    # Se hanno lunghezze diverse, non possono essere anagrammi
    if len(p1) != len(p2):
        return False

    # Controlla se le lettere sono le stesse (ordinandole)
    return sorted(p1) == sorted(p2)

# Programma principale
p1 = input("Inserisci una parola: ")
p2 = input("Inserisci un'altra parola: ")

if anagrammi(p1, p2):
    print("Le parole sono anagrammi!")
else:
    print("Le parole NON sono anagrammi.")
