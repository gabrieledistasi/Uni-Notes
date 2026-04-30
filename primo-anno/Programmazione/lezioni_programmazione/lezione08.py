#operatori bit-a-bit

n = 7

print(n>>1) # shift a sx
print(n<<1) # shift a dx

a = 6
b = 3

print(a&b) # and bit-a-bit
print(a|b) # or bit-a-bit


#usare gli operatori bit-a-bit per calcolare il logaritmo intero in base 2 di n
n = 13

n_copia = n # preserviamo il valore originale di n operando su una sua copia
k = 0

while n_copia >= 2:
    print("n_copia = ", n_copia, "type(n_copia) = ", type(n_copia))
    n_copia = n_copia>>1 # equivale alla divisione intera per 2
    k += 1

print("Logaritmo intero in base 2 di", n, "=", k)



#Problema: data una stringa a, stampare True se la stringa è palindroma 
pal = "itopinonavevanonipoti"
a = "0123456789"

print(a[3])

# a[0] = "I" NO, le stringhe sono immutabili

# slicing
print( a[1:6] ) # nuova stringa
print( a[:6]) 
b = a[:]
print(b)
print(a[2:8:2]) # slicing con  step
print(a[8:2:-1])
print(a[::-1])
print(a[-1]) # ultimo carattere
print(a[-2])
print(a[-len(a)]) # primo carattere


#altro modo per risolvere lo stesso problema: 
a = "itopinonavevanonipoti"
#a = "kayak"

i, n = 0, len(a)
sembra_palindroma = True

while i < n/2 and sembra_palindroma:
    if a[i] != a[-i-1]: # coppia di caratteri simmetrici
        sembra_palindroma = False
    else:
        i += 1

print(sembra_palindroma)