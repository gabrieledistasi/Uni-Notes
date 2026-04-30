#complessità computazionale, tuple e liste 



# INPUT
a = "itopinonavevanonipoti"
n = len(a)

# Preambolo
i = 0
sembra_palindroma = True

# Parte centrale
while i < n/2 and sembra_palindroma:
    if a[i] != a[-i-1]: # coppia di caratteri simmetrici
        sembra_palindroma = False
    else:
        i += 1

# Conclusioni
print(sembra_palindroma)



'''Calcoliamo la complessità temporale del programma in funzione di n.

Assumiamo a palindroma

sia c0 il costo del preambolo
sia c1 il costo delle conclusioni
sia c il costo costo del corpo del while (solo il blocco di)
c0, c1 e c non dipendono da n: sono costanti.

Costo totale:

T(n)=c0+c1+c2⋅n/2

è una funzione lineare in n, diciamo che il tempo di calcolo cresce linearmente in n. 
Oppure, la complesità temporale del programma è lineare in n.

Per descrivere questo comportamento con n
che cresce asintoticamente, si usa la notazione O-grande che semplifica una funzione tenendo solo il termine che cresce più velocemente al crescere di 
n, ignorando costanti e termini più piccoli..

Quindi si dice che 
T(n) è O(n) (O-grande di n) per dire che la crescita di T(n) è al più lineare in n.

Se a non palindroma

T(n)≤c0+c1+c2⋅n/2

T(n) è O(n) nel caso peggiore.

Nell'analisi della complessità si considera solitamente il caso peggiore, talvolta il caso medio.

Complessità del caso medio: è la media dei costi di tutti i possibili casi, nel nostro caso

Tm(n)=1+2+…+n/2n/2

Poiché 1+2+...+(k−1)+k=(k+1)/2 allora

Tm(n)=(n2+1)n4n/2=(n2+1)12

che è 
O(n)

Altro esempio: se 
T(n)=c0+c1⋅n+c2⋅n2

allora la crescita di 
T(n) sarebbe O(n2)'''

#TUPLA

n, i = 10, 0

print(n, i)

# una tupla
t = 10, 0  #  # impacchettamento, unpacking

print(type(t))

print(t)

# per le tuple sono definite tutte le operazioni sulle stringhe, come le stringhe sono immutabili

n, i = t # spacchettamento, packing

print(n, i)

t = (0, 3.14, ('python', 0, 'stringa'), 9)

print(t[0]) # indicizzazione


#LISTA

a = [] # lista vuota
b = [0, 3.14, ('python', 0, 'stringa'), 9, [1,2,3] ]

print(b[2])

b[2] = 'nuovo valore'

print(b)

del(b[2])

print(b)

b.append('ultimo elemento')

print(b)