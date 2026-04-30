'''si scriva una funzione con i seguente prototipo: 
def valori_compresi(a, x, y)

a è una lista di interi 
la funzione deve restituire una nuova lista contenente tutti gli elementi di a compresi tra x e y inclusi 
l'ordine degli elementi deve essere lo stesso dell'array originale 
se non esistono elementi che soddisfano la condizione, la funzione deve restituire una nuova lista ([])
non usare una list comprehension(cioè niente [...for...in...])
'''

def valori_compresi(a, x, y):
    new_list = []
    n = len(a)

    for i in range(n): 
        if a[i] >= x and a[i] <= y:
            new_list.append(a[i])

    return new_list

a = [1, 4, 54, 4, 1, 5, 19914, 134, 35,52, 34, 23]
x = 10
y = 100

print(valori_compresi(a, x, y))

