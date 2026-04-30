#scrivere una funzione in python 
#che riceve una stringa commands composta solo da LRDU
#partendo dalla posizione (0,0)
#restituisce la posizione finale (x, y)


def final_position(commands): 

    position = (0,0)
    tmp_list = list(position)



    for i in commands: 

        if i == "U" : 
            tmp_list[1] += 1
        
        elif i == "D": 
            tmp_list[1] -= 1

        elif i == "L": 
            tmp_list[0] -= 1

        elif i == "R": 
            tmp_list[0] += 1

    posizioni = tuple(tmp_list)
    
    return posizioni


commands = "UURDDL"
print(final_position(commands))