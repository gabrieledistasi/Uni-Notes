'''scrivere una funzione 
def first_duplicate(lst)

che restituisca il primo elemento duplicato presente almeno due volte
'''

def first_duplicate(lst): 

    visti = []

    for x in lst: 

        if x in visti:
            return x
        
    
        visti.append(x)
    
    return None



lst = [1, 2, 3, 4, 1, 5, 6, 7, 8, 9, 10]
print(first_duplicate(lst))