#Set
insieme_vuoto = set()
print(insieme_vuoto)

a = set([1,2,1,6,7,5,0,6])
print(a)
print(1 in a)
set()
{0, 1, 2, 5, 6, 7}
True
a.add(10)
print(a)
a.remove(5)
print(a)
print(len(a))
{0, 1, 2, 5, 6, 7, 10}
{0, 1, 2, 6, 7, 10}
6
n = 500000
m = 100
a = set(list(range(n)))
b = set(list(range(m)))

c = set()

if n < m:
    A, B = a, b
else:
    A, B = b, a

for k in A: # per al più O(n) volte 
    if k in B: # O(1)
        c.add(k) # O(1)

print(c)

# complessità temporale righe 7-9: O( min(n, m) )
{1, 3, 7}
c = a.intersection(b)
# complessità temporale è O( min(n, m) )

d = a.union(b)  # O(n+m)
e = a.difference(b) # ( min(n,m) )

print(c)
print(d)
print(e)
{1, 3, 7}
{0, 1, 2, 3, 4, 5, 6, 7, 8}
{8, 2, 6}


#invertire un dizionario 
d = {"zero":0, "uno":1, "Uno":1, "due":2, "DUE":2}
d_inv = {}

for k in d:
    if d[k] in d_inv:
        d_inv[d[k]].append(k) # inserire k nella lista della chiave d[k] in d_inv
    else:
        d_inv[d[k]] = [k]

print(d_inv)

d = {"zero":0, "uno":1, "Uno":1, "due":2, "DUE":2}
d_inv = {}

for k, v in d.items():
    if v in d_inv:
        d_inv[v].append(k) # inserire k nella lista della chiave v in d_inv
    else:
        d_inv[v] = [k]

print(d_inv)



#altri metodi per iterare sui dizionari 
for v in d.values():
    print(v)

for k in d.keys():
    print(k)    


d = {"zero":0, "uno":1, "Uno":1, "due":2, "DUE":2}
d_inv = {}

for k, v in d.items():
    L = d_inv.get(v,[])
    L.append(k)

    d_inv[v] = L

print(d_inv)
