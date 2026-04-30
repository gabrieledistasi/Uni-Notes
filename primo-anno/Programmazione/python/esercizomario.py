'''scrivere un programma che sommi un numero reale fornito in input per un certo numero di volte.
stampi il risultato e lo confronti con il valore atteso'''

try: 
    reale = float(input("inserisci un numero reale: \n"))
    ntimes = int(input("Per quante volte devo sommarlo? \n"))
    expected = float(input("Qual è il valore atteso? \n"))
except ValueError: 
    print("per favore inserisci solo numeri")
    exit(1)
res = 0 

for i in range(ntimes): 
    res += reale #res = real*ntimes
    

if abs(res-expected)<1e-9: 
    print(f"Il numero {res} è uguale a {expected}")
else: 
    print(f"il numero {res} non è uguale a {expected}")
