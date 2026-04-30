def binarysearch(A, x, left, right): 
    if left > right: 
        return -1
    
    mid = (right+left)//2

    if A[mid] == x: 
        return mid
    if A[mid] < x: 
        return binarysearch(A, x, mid+1, right)
    else: 
        return binarysearch(A, x, left, mid-1)
    

A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

x = 6

print(binarysearch(A, x, 0, len(A)-1))
