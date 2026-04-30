

def compress_list(lst): 

    current_value = lst[0]
    c = 1
    new_list = []

    for i in range(1, len(lst)): 

        if lst[i] == current_value: 

            c += 1 
            
            

        else: 
            new_list.append((current_value, c))
            current_value = lst[i]
            c = 1

    new_list.append((current_value, c))

    return new_list







lst = [1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1]

print(compress_list(lst))

#complessità O(n) sia temporale che spaziale 
