'''scrivere una funzione 
def longest_positive_subsequence(nums)
che restituisce una tupla contenente gli indici della più lunga sottosequenza composta esclusivamente da numeri
strettamente positivi'''

def longest_positive_subsequence(nums): 

    if not nums:
        return None

    best_start = 0
    best_len = 0

    curr_start = 0
    curr_len = 0

    for i in range(len(nums)):
        if nums[i] > 0:          # numero pari
            curr_len += 1
        else:
            if curr_len > best_len:
                best_len = curr_len
                best_start = curr_start
            curr_start = i + 1
            curr_len = 0

    # controllo finale (se la sequenza migliore arriva alla fine)
    if curr_len > best_len:
        best_len = curr_len
        best_start = curr_start

    return (best_start, (best_start + best_len)-1)

nums = [0, 2, 4, 1, -3, 5, 7, 9, -1]
print(longest_positive_subsequence(nums))