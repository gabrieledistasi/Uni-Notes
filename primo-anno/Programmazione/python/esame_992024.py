#scrivere una funzione chiamata arg_sort che prenda in input una lista di numeri a e ritorni la lista degli indici
#che ordinano a.

def arg_sort(a):
    idx = list(range(len(a))) #genera [0, 1, 2]
    merge_sort_idx(a, idx, 0, len(idx)-1) #idx è la lista degli indici, ordiniamo idx e non a 
    return idx


def merge_sort_idx(a, idx, i, f):
    if i < f:
        m = (i + f) // 2
        merge_sort_idx(a, idx, i, m)
        merge_sort_idx(a, idx, m + 1, f)
        merge_idx(a, idx, i, m, f)





def merge_idx(a, idx, i, m, f):
    left = idx[i:m+1]
    right = idx[m+1:f+1]

    li = ri = 0
    k = i

    while li < len(left) and ri < len(right):
        if a[left[li]] <= a[right[ri]]:
            idx[k] = left[li]
            li += 1
        else:
            idx[k] = right[ri]
            ri += 1
        k += 1

    while li < len(left):
        idx[k] = left[li]
        li += 1
        k += 1

    while ri < len(right):
        idx[k] = right[ri]
        ri += 1
        k += 1

a= [1, 4, 23, 245, 556 ,23,42, 5]


print(arg_sort(a))


