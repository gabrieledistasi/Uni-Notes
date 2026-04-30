#scrivere una funzione ricorsiva 
#def media_aritmetica(lista): 
#che restituisce la media aritmetica degli elementi nella lista     


def deep_media_aritmetica(lista):
    if lista == []:
        return 0, 0

    somma_restante, conteggio_restante = deep_media_aritmetica(lista[1:])
    somma = lista[0] + somma_restante
    conteggio = 1 + conteggio_restante

    return somma, conteggio



somma, conteggio = deep_media_aritmetica([2,4,6,8])
media = somma / conteggio
print(media)   # 5.0





    
    