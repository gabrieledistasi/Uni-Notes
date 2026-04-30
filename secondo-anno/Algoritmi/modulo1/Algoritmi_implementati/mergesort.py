def merge (A, i, m, f): 

    left = A[i:m+1]
    right = A[m+1:f+1]
    k = i
    li = 0
    ri = 0

    while li < len(left) and ri<len(right): 
        if left[li]<= right[ri]: 
            A[k] = left[li]
            li+=1

        else: 
            A[k] = right[ri]
            ri+=1
        k+=1

    while li<len(left): 
        A[k] = left[li]
        li += 1
        k+=1
    while ri<len(right): 
        A[k] = right[ri]
        ri+=1
        k+=1




def mergesort(A, i, f): 
    if i<f: 
        m = (i+f)//2
        mergesort(A, i, m)
        mergesort(A, m+1, f)
        merge(A, i, m, f)


A = [523, 12, 745, 289, 612, 7, 951, 33, 427, 801,
     99, 310, 456, 689, 208, 570, 84, 921, 65, 378,
     490, 734, 268, 852, 174, 392, 640, 5, 215, 704,
     858, 147, 925, 367, 993, 193, 422, 756, 601, 275,
     889, 450, 315, 249, 980, 75, 168, 477, 644, 723,
     916, 81, 630, 288, 314, 593, 422, 105, 715, 364,
     280, 819, 47, 562, 194, 937, 455, 667, 153, 772,
     886, 300, 476, 535, 640, 213, 744, 812, 964, 501,
     221, 115, 358, 744, 276, 881, 939, 622, 452, 759,
     284, 610, 222, 355, 141, 964, 677, 250, 193, 999]
x=len(A)-1

print(mergesort(A, 0, x
))
print(A)