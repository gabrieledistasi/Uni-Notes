#scrivere un programma che acquisisce un intero in input e stampa la somma delle cifre che lo compongono


n = input("digita un numero: ")

somma = 0
for x in n: 
    somma+= int(x)
print(somma)

#scrivere un programma che acquisice due stringhe in input e le stampa allineandole al centro. 

b = "0123456789"
a = "abc"

spazi = (len(a)-len(b))//2

if spazi >= 0: 
    print(a)
    print(' '*spazi+b)

if spazi < 0: 
    print(-spazi*" "+a)
    print(b)


##############

a = "ProGrammAzione Dei calc0lat0r1"
minuscole = 0
for x in a:
    if x >= "a" and x <= "z":
        minuscole += 1

print(minuscole)

#############

a = "ProGrammAzione Dei calc0lat0r1"

vocali_minuscole = 0

for x in a:
    if x in "aeiou":
        vocali_minuscole += 1

print(vocali_minuscole)


##################

