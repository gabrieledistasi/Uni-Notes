import math
import numpy as np


# utilizziamo la formula per calcolare l'n-esimo numero di fibonacci 
# scegliamo circa 1*10^-3 come arrotondamento di phi
def fibonacci1(n): 
    phi = 1.618
    phi_cap= -0.618
    return round(1/math.sqrt(5)*((phi**n)-(phi_cap**n)))

# per questo algoritmo utilizziamo invece la ricorsione

def fibonacci2(n): 
    if n <= 2: 
        return 1 
    else: 
        return fibonacci2(n-1)+fibonacci2(n-2)


# nel terzo algoritmo vogliamo invece salvare i numeri calcolati in una struttura dati
# inizializziamo un array Fib in cui saranno contenuti tutti i valori

def fibonacci3(n): 


    Fib = [0 for i in range(n)]

    Fib[0] = 1
    Fib[1] = 1

    for i in range(2, n): 
        Fib[i] = Fib[i-1] + Fib[i-2]

    return Fib




# Usare un array per ricordare tutti i numeri fino all'n-simo può risultare inutile
# salviamo soltanto gli ultimi due numeri, questo permette di utilizzare solo due variabili e non un array
def fibonacci4(n): 

    a = 1 
    b = 1 

    for i in range(2, n): 

        c = a+b
        a = b
        b = c

    return c

#introduciamo il calcolo del numero di fibonacci attraverso il prodotto matriciale

def fibonacci5(n): 

    M = np.array([[1, 0], [0, 1]])
    A = np.array([[1, 1], [1, 0]])

    i = 1

    while i < n:

        M = M @ A
        i += 1

    return M[0][0]

# portiamo il calcolo attraverso il prodotto tra matrici ad un altro livello
def fibonacci6(n):
    A = np.array([[1, 1], [1, 0]])
    M = potenzaDiMatrice(A, n-1)

    return M[0][0]



def potenzaDiMatrice(A, k):

    if k == 0:
        return np.array([[1, 0], [0, 1]])

    else: 
        M = potenzaDiMatrice(A, math.floor(k/2))
        M = M @ M

    if k%2!=0: 
        M = M @ A


    return M 


print(fibonacci6(9))

 
