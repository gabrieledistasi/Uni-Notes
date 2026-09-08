'''Sia logs una lista di sessioni di accesso, ciascuna delle quali identificata da una 
sequenza di identificativi utente (stringhe), 
eventualmente ripetuti all'interno della stessa sessione. 
Si scriva un programma che stampi, per ogni identificativo utente, 
il numero di sessioni distinte a cui ha partecipato e il numero totale di accessi 
(ovvero le occorrenze totali su tutte le sessioni).

Esempio. Se
logs = [["alice", "bob", "alice", "charlie"], ["bob", "david", "bob"], ["alice", "charlie"]]
il programma deve stampare la seguente informazione:
alice in 2 sessione/i (3 accessi totali)
bob in 2 sessione/i (3 accessi totali)
charlie in 2 sessione/i (2 accessi totali)
david in 1 sessione/i (1 accessi totali)'''

def conta_accessi(logs):
    sessioni_distinte = {}
    accessi_totali = {}

    for sessione in logs:
        # Convertendo in set eliminiamo i duplicati all'interno della singola sessione
        utenti_unici_sessione = set(sessione)
        for utente in utenti_unici_sessione:
            sessioni_distinte[utente] = sessioni_distinte.get(utente, 0) + 1

        # Contiamo tutti gli accessi individuali
        for utente in sessione:
            accessi_totali[utente] = accessi_totali.get(utente, 0) + 1

    # Stampa formattata
    for utente in accessi_totali:
        print(f"{utente} in {sessioni_distinte[utente]} sessione/i ({accessi_totali[utente]} accessi totali)")

# Esecuzione
logs = [["alice", "bob", "alice", "charlie"], ["bob", "david", "bob"], ["alice", "charlie"]]
conta_accessi(logs)

"""
Complessità Temporale: O(N)
Dove N è il numero totale di elementi presenti in tutte le sotto-liste di logs.
La conversione a set della singola sessione richiede tempo proporzionale alla sua lunghezza.
Le operazioni di inserimento e aggiornamento nei dizionari e set avvengono in tempo medio O(1).

Complessità Spaziale: O(U)
Dove U è il numero di utenti unici registrati. I dizionari memorizzano 
una chiave per ciascun utente distinto. Nel caso peggiore O(N).
"""

              

