#ciao
#oca

def commonchar(s1, s2): 

    caratteri_comuni = []

    for i in range(len(s1)): 
        if s1[i] in s2: 
            caratteri_comuni.append(s1[i])

    return set(caratteri_comuni)


print(commonchar("aeroplano", "catena"))



