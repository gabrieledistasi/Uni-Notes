#bubblesort

a = [3,12,1,7,4,2,6,7,2,1]
n = len(a)

for c in range(n-1): # per n-1 volte
    for i in range(n-1-c): # per n-1 volte, non è necessario considerare gli ultimi c elementi
        if a[i] > a[i+1]:
            a[i], a[i+1] = a[i+1], a[i]

print(a)

# complessità temporale O(n**2)
# complessità spaziale O(1)