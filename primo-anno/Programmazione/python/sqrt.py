#crea una funzione che restituisca la radice quadrata di un numero 

def sqrt(x): 

    if x == 0: 
        return 0

    g = x/2

    while abs(g*g -x) > 1e-6: 

        g = 0.5*(g + x/g)



    return int(g)

print(sqrt(25))