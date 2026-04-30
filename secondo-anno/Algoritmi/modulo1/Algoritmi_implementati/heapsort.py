def fixheap(i, A, n):
    largest = i
    left = 2*i + 1
    right = 2*i + 2

    #confronta con il figlio sinistro 
    if left < n and A[left] > A[largest]: 
        largest = left 

    #confronta con il figlio destro
    if right < n and A[right] > A[largest]: 
        largest = right 
    
    #se il massimo non è il nodo ricorrente, scambia e chiama ricorsivamente
    if largest != i: 
        A[i], A[largest] = A[largest], A[i]
        fixheap(largest, A, n)

def heapify(A, n): 

    #parte dai nodi non foglia fino alla radice
    for i in range(n//2 -1, -1, -1): 
        fixheap(i, A, n)


def heapsort(A): 
    n = len(A)
    heapify(A, n)
    for i in range(n-1, 0, -1): 
        A[0], A[i] = A[i], A[0]
        fixheap(0, A, i)

import random

A = [random.randint(1, 100) for _ in range(20)]
print(A)

heapsort(A)
print(A)
