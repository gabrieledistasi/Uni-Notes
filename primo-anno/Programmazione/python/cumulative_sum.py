#creare una funzione che fa una somma cumulativa dei numeri in input fin quando l'utente non digita 0

somma = 0


while True: 
    
    try:    
        addendo = int(input("inserisci un numero: "))

    except ValueError: 
        print("mongoloide ho detto numero, NUMERO, N-U-M-E-R-O, sai leggere o sei semplicemente ritardato?")



    if addendo != 0: 
        somma += addendo
    else: 
        break


print(somma)


