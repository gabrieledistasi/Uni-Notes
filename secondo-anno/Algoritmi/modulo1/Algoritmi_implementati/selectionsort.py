def selectionsort(a):
    for k in range(len(a) - 1):  #itera tutti gli elementi eccetto l'ultimo
        m = k  # il minimo è nella posizione corrente
        for j in range(k + 1, len(a)):  # cerca il minimo
            if a[j] < a[m]:
                m = j  # trova il nuovo minimo
        # scambia a[k] e a[m]
        a[k], a[m] = a[m], a[k]
    return a

print(selectionsort([1, 3, 4, 6, 2, 7, 10, 9, 8]))


        