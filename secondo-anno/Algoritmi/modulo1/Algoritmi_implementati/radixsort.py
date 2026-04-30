
def bucketsort(X, exp): 
    k = 10
    buckets = [[] for _ in range(k)]

    for num in X: 
        digit = (num//exp) % 10
        buckets[digit].append(num)
    
    index = 0

    for b in buckets: 
        for num in b:
            X[index] = num
            index += 1


def radixSort(X): 
    max_val = max(X)
    exp = 1
    while max_val// exp > 0: 

        bucketsort(X, exp)
        exp *= 10

X = [170, 45, 75, 90, 802, 24, 2, 66]
radixSort(X)
print(X)  # [2, 24, 45, 66, 75, 90, 170, 802]
