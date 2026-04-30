#scrivere una funzione con il seguente prototipo: 
#def deep_reverse_string(s)
#la funzione deve restituire la stringa s al contrario

def deep_reverse_string(s):

    if s == "": 
        
        return ""
    else: 
        return deep_reverse_string(s[1:])+s[0]
        
    
s = "ciaomondo"
print(deep_reverse_string(s))

