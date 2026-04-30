#scrivere una funzione che riceve una stringa s 
#conta quante parole sono palindrome 
#le parole sono separate da spazi


def count_mirror_words(s): 

    words = s.lower().split()
    c = 0

    for i in words: 
        if len(i) < 2: 
            
            continue
        elif i[0] == i[-1]: 
            c+=1 
    



    return c


s = "radar mom anna erika"
print(count_mirror_words(s))


#radar 
