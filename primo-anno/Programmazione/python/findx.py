def findx(A, x):
    i = 0
    j = len(A) - 1

    while i < j:
        s = A[i] + A[j]
        if s == x:
            return A[i], A[j]
        elif s < x:
            i += 1
        else:
            j -= 1
    return None

A = [2, 5, 9, 14, 20, 21, 25, 40]
x = 34
print(findx(A, x))
