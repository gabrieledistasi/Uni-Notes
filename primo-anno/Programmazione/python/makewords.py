#Scrivere una funzione in Python che, data una lista words di parole e una stringa letters di caratteri, 
#stampa in output tutte e sole le parole in words che possono essere 
#ottenute usando un sottoinsieme delle lettere in letters.


words = ["cane", "gatto", "tartaruga", "canto" ]
letters = "anetougc"


def makewords(words, letters): 

    parole = []


    for word in words: 
        for letter in letters: 
            if letter in word : 
                parole.append(word)
                break


    return parole

print(makewords(words, letters))

