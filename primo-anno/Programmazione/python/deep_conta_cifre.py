def deep_conta_cifre(n): 
    if n == 0: 
        return 0
    else: 
        return 1+deep_conta_cifre(n//10)

n =100500

print(deep_conta_cifre(n))
