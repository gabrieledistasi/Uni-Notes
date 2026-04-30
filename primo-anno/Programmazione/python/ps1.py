#abbiamo n cassetti, in L cassetti sono presenti gli addobbi di natale ma non sappiamo quali e quanti sono
#l'unico modo per scoprirlo è aprendo i cassetti. In che ordine? 



#supponiamo che i cassetti siano 10
# n = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] e che l sia 3, allora divido a metà i cassetti e cerco nella prima metà la prima occorrenza di l
# supponendo che troviamo n[l] controllo n[l-1], finché non trovo più occorrenze, poi controllo a destra fino alla fine della prima metà

import random
from ricerca_binaria import binarysearch


def trovaaddobbi(n): 

    l = random.randint(0, n)

    binarysearch(n, n//2, 0, n-1) #divido in due metà i cassetti 





print(trovaaddobbi(10))


