'''si scriva una funzione in python denominata is_matrix che riceva in input una lista di numeri 
e restituisca true se e solo se la lista può codificare una matrice quadrata'''

def is_matrix(a): 
    if not isinstance(a, list):
        return False
    n = len(a)
    for row in a:
        if not isinstance(row, list) or len(row) != n:
            return False
    return True











a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]