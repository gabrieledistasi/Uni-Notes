import random 



def guess_num(): 

    secret_num = random.randint(1,100)
    attempts = 0

    while True:
        
        attempts += 1

        guess = int(input("inserisci un numero da 1 a 100: \n"))

            
        if guess > secret_num:
            print("più basso\n")
        elif guess < secret_num: 
            print("più alto\n")
        else: 
            print(f"{secret_num} è il numero a cui stavo pensando!!!!\nnumero indovinato in {attempts} tentativi \n")
            
            break
    return "fine del gioco"




print(guess_num())
