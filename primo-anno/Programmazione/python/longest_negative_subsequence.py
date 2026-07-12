'''scrivere una funzione 
def longest_negative_subsequence
che restituisce una tupla (start, end) contenente gli indici della sottosequenza più lunga
composta eslcusivamente da numeri negativi'''

def longest_negative_subsequence(nums): 

    if nums == []: 
        return None

    best_start = 0
    best_len = 0

    curr_start = 0
    curr_len= 0

    n = len(nums)

    for i in range(n): 
        if nums[i] < 0: 

            if curr_len == 0 : 
                curr_start = i
                
            curr_len += 1
            

            
        else: 
            if curr_len > best_len: 
                best_start = curr_start
                best_len = curr_len
            curr_start = i
            curr_len = 0
    
    if curr_len > best_len: 
        best_len = curr_len
        best_start = curr_start
    
    return (best_start, (best_len+best_start)-1)




nums = [1,-2,-3,-4,5,-1,-2,6]
print(longest_negative_subsequence(nums))
