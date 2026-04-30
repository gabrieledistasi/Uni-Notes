#scrivere una funzione che calcola esattamente che giorno sarà in un determinato anno
from datetime import datetime

giorno_corrente = datetime.now()

def zeller(giorno, mese, anno): 
    anno_originale = anno  # per stampare correttamente
    mese_originale = mese
    if mese < 3: 
        mese += 12
        anno -= 1
    
    k = anno % 100
    j = anno // 100

    h = (giorno + 13*(mese+1)//5 + k + k//4 + j//4 + 5*j) % 7

    giorni_settimana = ["Sabato", "Domenica", "Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì"]

    if anno > 2026: 
        print(f'Il giorno {giorno}/{mese_originale}/{anno_originale} sarà {giorni_settimana[h]}')
    else: 
        print(f'Il giorno {giorno}/{mese_originale}/{anno_originale} era {giorni_settimana[h]}')
         
    

    return h


giorno = int(input('Inserisci il giorno: '))
mese = int(input('Inserisci il mese: '))
anno = int(input('Inserisci l\'anno: '))

zeller(giorno, mese, anno)
