import random


num_digits = 3 
max_guess = 10
num_guesses = 0

def mastermind(): 

    print("\nSto pensando ad un numero a tre cifre \nProva ad indovinarlo\n ")
    print("quando dico:     significa:\nPico             Una cifra è corretta ma nella posizione errata \nFermi            Una cifra è corretta e nella giusta posizione")
    print("Bagels           Nessuna cifra è corretta\n")

    num_digits = 3 
    max_guess = 10
    num_guesses = 1

    
    while True: 

        secret_num = getSecretNum()

        print('Ho pensato ad un numero\n')
        print('Hai {} tentativi per indovinare'.format(max_guess))

        while num_guesses <= max_guess: 
            guess = ''
            while len(guess) != num_digits or not guess.isdecimal(): 
                print('\nTentativo #{}'.format(num_guesses))
                guess = input('>')

                num_guesses += 1
            
            clues = getClues(guess, secret_num)
            print(clues)
            

            if guess == secret_num: 
                break
            if num_guesses > max_guess: 
                print('Hai finito i tentativi...')
                print('La risposta era {}'.format(secret_num))
            
        print("vuoi giocare di nuovo? (si o no)")
        num_guesses = 1
        if not input('>').lower().startswith('s'): 
            break 
    return 'grazie per aver giocato!!'




    



def getClues(guess, secretNum):
    if guess == secretNum: 
        return "Hai indovinato !!!"
    
    clues = []
    
    for i in range(len(guess)): 
        if guess[i] == secretNum[i]: 
            clues.append("Fermi")
        elif guess[i] in secretNum: 
            clues.append("Pico")

    if len(clues)==0: 
        return 'Bagels'
    
    else: 
        clues.sort()
        
        return ' '.join(clues)




def getSecretNum(): 

    numbers = list('0123456789')
    random.shuffle(numbers)

    secretNum = ''

    for i in range(num_digits): 
        secretNum += str(numbers[i])
    return secretNum


print(mastermind())

