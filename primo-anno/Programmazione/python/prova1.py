def f(a): 
    d = {}
    c = 0
    for x in a: 
        if x in d: 
            c+=1 
        else: 
            d[x] = None

        print(d)

    return c

a = [2, 3, 1, 4, 334, 2321 ,43343,4 ]
print(f(a))