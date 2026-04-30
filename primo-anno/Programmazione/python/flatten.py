#scrivere una funzione che, data una lista in input con all'interno altre liste,
#appiattisca la lista 
# [1, [2, 3], 4]


def flatten(a): 
    tmp = []

    for e in a: 
        if type(e) != list: 
            tmp.append(e)
        else: 
            for e1 in e: 
                tmp.append(flatten(e1))
    
    i = 0

    while i < len(tmp): 
        if i < len(a): 
            a[i] = tmp[i]
        else: 
            a.append(tmp[i])
        i+=1 


    while i < len(a): 
        del a[-1]

    return tmp


a = [1, 2, 3, 4, [6,[9], 10]]

print(flatten(a))