def partition(A, i, f): 
    x=A[i]
    inf = i
    sup = f 
    while True: 

        

        while inf < f and A[inf] <= x: 
            inf += 1

        while A[sup] > x: 
            sup -= 1

        if inf < sup: 
            A[inf], A[sup] = A[sup], A[inf]

        else: 
            break
    A[i], A[sup] = A[sup], A[i]
    return sup

def quicksort(A, i, f): 
    if i >= f: 
        return
    m = partition(A, i, f)
    quicksort(A, i, m-1)
    quicksort(A, m+1, f)

import random

A = [random.randint(1, 10000) for _ in range(1000)]

quicksort(A, 0, len(A)-1)
print(A)
    