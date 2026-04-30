import random

def bucketSort(X, k): 

    Y = [0 for _ in range(k)]

    for i in range(k): 
        Y[i]=[]
    
    for i in range(len(X)): 
        Y[X[i]].append(X[i])

    index = 0
    for i in range(k): 
        for val in Y[i]: 
            X[index] = val
            index += 1

k = 50
X = [random.randint(0, k-1) for _ in range(20)]
print(X)
bucketSort(X, k)    
print(X)