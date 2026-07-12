def longest_alternating_subsequence_indices(lst):   
    if not lst:
        return (0, 0)
    best_start = 0
    best_len = 1 

    curr_start = 0
    curr_len = 1

    for i in range(1, len(lst)): 
        if (lst[i] > 0 and lst[i-1] < 0) or (lst[i] < 0 and lst[i-1] > 0): 
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
    
    


lst = [1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 12, 42, 34]


print(longest_alternating_subsequence_indices(lst))

#complessità temporale O(n)
#complessità spaziale O(1)