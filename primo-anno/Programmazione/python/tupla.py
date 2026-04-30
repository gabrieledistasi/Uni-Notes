a = [0, 1 , 2]
a.append([30,40,50,60])

if len(a[3])>len(a): 
    print("ciao")
elif id(a[3]) != id(a): 
    print("andrea")
elif type(a[3])== type(a): 
    print("termosifone")