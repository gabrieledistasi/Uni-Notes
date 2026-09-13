Questi soluzioni fanno riferimento alle slide SOR2025-2026_Reti_12_Esercizi_Checksum_Internet.pdf

--- 
# Come si risolvono questi esercizi?
Partiamo dal presupposto che il checksum è un algoritmo che dobbiamo dare in pasto ad una macchina, quindi è una sequenza di passaggi da seguire: 

- Dividiamo in blocchi da 16 bit
- Facciamo la somma (2 blocchi alla volta)
- riporto? Si $\rightarrow$ end-around-carry
- complemento a 1
- fine esercizio
Questo è l'algoritmo per il checksum, ora facciamo qualche esercizio.

# Esercizio 1 

Si considerino i dati forniti di seguito in formato binario

`1101 1010 1001 0110 1011 1100 0011 0101 1011 1100 0011 0101`

Si calcolino i bit di controllo di errore secondo la checksum di
Internet.

### 1. Dividiamo in gruppi da 16 bit
partendo da sinistra:
```
1101 1010 1001 0110 
1011 1100 0011 0101
1011 1100 0011 0101 
```

Ora sommiamo i primi due gruppi: 
```
1101 1010 1001 0110+
1011 1100 0011 0101=
___________________
1001 0110 1100 1100 con il riporto di 1
```
Nel checkusm di internet i bit oltre il 16esimo non vengono ignorati ma lo aggiungiamo al risultato: 
```
1001 0110 1100 1011+
0000 0000 0000 0001=
___________________
1001 0110 1100 1100
```
Adesso dobbiamo sommare il terzo gruppo di 16 bit al nostro risultato: 

```
1001 0110 1100 1100+
1011 1100 0011 0101=
___________________
0101 0011 0000 0001 con il riporto di 1
```
Aggiungiamo anche qui il riporto: 
```
0101 0011 0000 0001+
0000 0000 0000 0001=
___________________
0101 0011 0000 0010
```

### 2. Complemento a 1
Adesso dobbiamo prendere la cifra: 
$$0101 \ 0011 \ 0000 \ 0010$$ E fare il complemento a 1, ovvero invertiamo tutti i bit.
Quindi il nostro **checksum** è: 
$$
1010 \ 1100 \ 1111 \ 1101
$$
E abbiamo finito. 


# Esercizio 1b
Si considerino i dati (identici a quelli dell'esercizio precedente) forniti di seguito in
formato esadecimale
DA 96 BC 35 BC 35
Si calcolino i bit di controllo di errore secondo la checksum di
Internet.

### 1. Conversione
L'esercizio segue la stessa logica del precedente, dobbiamo solo ricordarci come tradurre i dati che abbiamo in binario: 
`D = 1101, A = 1010, 9 = 1001, 6=0110, B=1011, C=1100, 3=0011, 5=0101`
Quindi la nostra sequenza diventa: 
`1101 1010 1001 0110 1011 1100 0011 0101 1011 1100 0011 0101`

Ora possiamo iniziare a separare in gruppi di 16 bit: 
```
1101 1010 1001 0110
1011 1100 0011 0101
1011 1100 0011 0101
```

Sommiamo i primi due: 
```
1101 1010 1001 0110 +
1011 1100 0011 0101
____________________
1001 0110 1100 1011 -> con il riporto di 1
```
Quindi aggiungiamo al risultato il riporto di 1: 
```
1001 0110 1100 1011 +
0000 0000 0000 0001
___________________
1001 0110 1100 1100

```
Ora sommiamo il terzo gruppo di bit: 
```
1001 0110 1100 1100 +
1011 1100 0011 0101
_____________________
0101 0011 0000 0001 -> con il riporto di 1
```
Di nuovo, aggiungiamo il riporto al risultato: 
```
0101 0011 0000 0001 +
0000 0000 0000 0001
___________________
0101 0011 0000 0010
```
Adesso facciamo il complemento a 1: 
```
1010 1100 1111 1101
```

--- 
# Esercizio 2

Si supponga di aver ricevuto i dati seguenti, comprensivi
dell’Internet Checksum, rapprensentati in formato esadecimale.
12 34 56 78 97 53
Il destinatario rileva un errore?

### Come sappiamo se il destinatario rileva un errore?
Se la somma del checksum restituisce tutti bit a 1, non sono presenti errori. 
Quindi possiamo fare così: 
```
0001 0010 0011 0100 + (1 2 3 4)
0101 0110 0111 1000   (5 6 7 8)
____________________
0110 1000 1010 1100 +
1001 0111 0101 0011 
____________________
1111 1111 1111 1111

```

>**Il destinatario non rileva alcun errore**, perché la somma in complemento a 1 dei dati ricevuti e dell'Internet Checksum produce `1111 1111 1111 1111` (tutti bit a 1).

