def deep_conta_consonanti(s): 

    if s == "": 
        return 0
    
    c = s[0].lower()
    
    prima = 1 if c.isalpha() and c not in 'aeiou' else 0
    return prima + deep_conta_consonanti(s[1:])

s = 'otto'
print(deep_conta_consonanti(s))