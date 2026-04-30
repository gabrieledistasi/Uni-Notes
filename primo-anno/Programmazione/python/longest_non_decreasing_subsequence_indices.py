#scrivere una funzione  che riceve una lista di numeri lst 
#restituisce una coppia (start, end)
#tale che lst[start:end] sia la più lunga sottosequenza contigua non decrescente 
#in caso di parità restituisce la prima trovata 


def longest_non_decreasing_subsequence_indices(lst):
    if not lst:
        return (0, 0)

    best_start = 0
    best_len = 1

    curr_start = 0
    curr_len = 1

    for i in range(1, len(lst)):
        if lst[i] >= lst[i-1]:          # non decrescente
            curr_len += 1
        else:
            if curr_len > best_len:
                best_len = curr_len
                best_start = curr_start
            curr_start = i
            curr_len = 1

    # controllo finale (se la sequenza migliore arriva alla fine)
    if curr_len > best_len:
        best_len = curr_len
        best_start = curr_start

    return (best_start, best_start + best_len)


lst = [1, 2, 3, 2, 5, 12, 6, 7, 8, 4]
print(longest_non_decreasing_subsequence_indices(lst))
