def cifrario_di_cesare(word, key): 

    lower_word = word.lower()

    encrypted_word = []
    n = len(lower_word)

    for i in range(n): 

        ascii_num = 97 + ((ord(word[i])-97)+key) % 26
        encrypted_char = chr(ascii_num)
        encrypted_word.append(encrypted_char)
        
    
    new_word = ''.join(encrypted_word)
    print(new_word)

    return new_word


word = input("inserisci una parola da crittare: \n")
key = 1
cifrario_di_cesare(word, key)





