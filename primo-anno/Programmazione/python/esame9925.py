'''siano date 
    - una stringa a composta da parole formate solo da caratteri alfabetici e separati da spazi e senza spazi iniziali o finali
    - sia un intero n

si scriva una funzione chiamata longes_prefix_with_words, che ritorna la stringa prefissa più lunga i a
tale che: 
    -la sua lunghezza è esattamente n
    contiene solo parole intere(nessuna parola deve essere troncata)
    -le parole sono separate da spazi singoli
    -se necessario, aggiungere spazi finali per raggiungere la lunghezza n
se la prima parola è più lunga di n, la funzione deve ritornare una stringa con n spazi'''

def longes_prefix_with_words(s, n):
    words = s.split()
    prefix = ""
    
    for word in words:
        if len(prefix) + len(word) + (1 if prefix else 0) > n:
            break
        if prefix:
            prefix += " "
        prefix += word
    
    # Add spaces to reach length n
    if len(prefix) < n:
        prefix += " " * (n - len(prefix))
    
    return prefix[:n]  # Ensure the result is exactly n characters long
