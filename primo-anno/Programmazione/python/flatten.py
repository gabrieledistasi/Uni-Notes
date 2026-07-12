#scrivere una funzione che, data una lista in input con all'interno altre liste,
#appiattisca la lista 
# [1, [2, 3], 4]


def flatten(a):
    tmp = []

    for e in a:
        if type(e) != list:
            tmp.append(e)
        else:
            tmp.extend(flatten(e))

    i = 0

    while i < len(tmp):
        if i < len(a):
            a[i] = tmp[i]
        else:
            a.append(tmp[i])
        i += 1

    while len(a) > len(tmp):
        del a[-1]

    return tmp


a = ["ciao", ['c', 'i', 'a', ['o'], [1, 2, 3, 4]], 5, 6, 7, 8]

print(flatten(a))