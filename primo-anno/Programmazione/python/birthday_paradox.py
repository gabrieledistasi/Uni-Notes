import random 

def birthday_paradox(n, experiments): 
    count = 0

    for _ in range(experiments): 

        compleanni = [random.randint(1, 365) for _ in range(n)] 

        if len(compleanni) != len(set(compleanni)): 
            count += 1

    return count/experiments

print(birthday_paradox(400, 100000))


    
