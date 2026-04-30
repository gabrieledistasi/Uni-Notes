#scrivere una funzione che abbia questo prototipo: 
#def snake_to_camel (s: str)->str
#riceve una stringa in snake_case
#restituisce la stringa convertita in camel

def snake_to_camel(s): 
    
    camel = []
    i = 0

    while i < len(s): 
        
        if s[i] == '_': 
            i+= 1
            if i < len(s): 

                camel.append(s[i].upper())
            
        else: 
        
            camel.append(s[i])
        i+=1


    return "".join(camel)



s = "ciao_sono_gabriele"
print(snake_to_camel(s))