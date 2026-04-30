parole = input("Inserisci una frase: ").lower()

def clearstr(parole):
    new_parole = ""
    for i in parole:
        if i in "?!/.,:;{}[]()\"'":
            continue
        else:
            new_parole += i
    return new_parole

# 1. pulizia
pulito = clearstr(parole)

# 2. conteggio parole
lista_parole = pulito.split()
frequenze = {}

for parola in lista_parole:
    frequenze[parola] = frequenze.get(parola, 0) + 1

# 3. ordinamento: -frequenza e poi alfabetico
ordinato = sorted(frequenze.items(), key=lambda x: (-x[1], x[0]))

# stampa
for parola, freq in ordinato:
    print(parola, freq)

    

        


print(clearstr(parole))
