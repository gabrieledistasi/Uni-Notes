import random

def integerSort(X, k): 
    Y = [0 for _ in range(k)]
    
    for i in range(k):
        Y[i]=0
    for i in range(len(X)): 
        Y[X[i]]+=1
    j = 0

    for i in range(k): 
        while Y[i] > 0: 
            X[j]=i
            j+=1
            Y[i]-=1

k = 30
X = [random.randint(0, k-1) for _ in range(10)]

print(X)
integerSort(X, k)
print(X)

