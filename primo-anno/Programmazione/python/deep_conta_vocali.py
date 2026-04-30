#scrivere una funzione con il seguente prototipo: 
# def deep_conta_vocali(s)
#la funzione conta quante vocali sono presenti in una stringa 


def deep_conta_vocali(s): 

    
    if s == "": 
        return 0
    prima = 1 if s[0] in 'aeiou' else 0
    return prima + deep_conta_vocali(s[1:])

s = "gabriele"
print(deep_conta_vocali(s)) 