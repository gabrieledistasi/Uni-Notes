def collatz(n): 

    i = 0

    c = []

    while n!= 1: 

        if n%2 == 0: 
            n = n//2

        else: 
            n = n*3 + 1
        i+=1
        c.append(n)

    return i, c


print(collatz(100))