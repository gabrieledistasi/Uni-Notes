#bubble_sort
#scorri l'array più volte
#confronta elementi adiacenti
#scambiali se in ordine sbagliato


def bubble_sort(a):

    n = len(a); 

    for i in range(n): 
        for j in range(0, n-i-1): 
            if a[j] > a[j+1]: 
                a[j], a[j+1] = a[j+1], a[j]







a = [467, 71, 624, 3, 684, 179, 942, 883]
bubble_sort(a)
print(a)