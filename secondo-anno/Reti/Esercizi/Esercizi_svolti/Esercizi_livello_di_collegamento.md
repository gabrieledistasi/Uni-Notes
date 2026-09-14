
Questi esercizi fanno riferimento alle slide: SOR2025-2026_Reti_28_esercitazione_esercitazione livello collegamento.pdf
# Esercizio 1

Si vuole inviare la seguente sequenza di bit proteggendola
attraverso l'aggiunta di un bit di parità (pari), posto alla fine della
sequenza.
1101 1010 1001 0110
Quali bit saranno effettivamente trasmessi?

### Soluzione 
Nello schema di controllo di parità pari, si aggiunge ai dati un solo bit, detto bit di parità, dobbiamo fare in modo che **il numero complessivo di bit a 1 risulti pari.**
Vediamo la sequenza originale: 
$$
1101 \ 1010 \ 1001 \ 0110
$$
Abbiamo 9 bit a 1, quindi per ottenere un numero pari di bit a 1, il bit di parità deve essere 1. 
$$
1101 \ 1010 \ 1001 \ 0110 \ 1
$$
Pertanto questa sarà la sequenza da trasmettere. 

--- 
# Esercizio 2

Si supponga di aver ricevuto il seguente frame protetto da singolo
bit di parità (pari):
1101 1010 1001 0110
Rispondere alle seguenti domande:
1. Il ricevente rileva un errore?
2. In caso affermativo, il ricevente può correggere l'errore?


### Soluzione 
Il ricevente ottiene la sequenza: 
$$
1101 \ 1010 \ 1001 \ 0110
$$
Che ha 9 bit a 1, il controllo del bit di parità però richiede un numero **pari** di bit a 1. 
Dunque il  ricevente rileva un errore che **non può correggere**, poiché il bit di parità non fornisce informazioni sulla posizione dei bit invertiti. 

---
# Esercizio 3
si considerino i dati forniti di seguito in formato binario
1101 1010 1001 0110
Si calcolino i bit di EDC (error detection and correction) secondo lo
schema di controllo di parità (pari) bidimensionale.
Quali sono i bit EDC da aggiungere (fornire la soluzione minima)?

### Soluzione 
Per trovare il numero minimo di bit EDC dispongo i 16 bit in una matrice 4x4, quindi calcolo i bit di parità per ciascuna riga, colonna e per l'angolo in basso a destra, cioè per tutti i bit:
```
1101|1
1010|0
1001|0
0110|0
------
1000|1
```

**Bit EDC = 1001 1000 1**

---

# Esercizio 4

Sono stati ricevuti i seguenti dati
10110010 01101100 11001110
I dati sono stati trasmessi in modo tale che:
• Il bit più significativo (il primo a sinistra) di ciascuno dei primi due byte è un
bit di parità pari calcolato sui restanti 7 bit dello stesso byte.
• Il terzo byte contiene, in ciascuna posizione, la parità pari dei bit nella stessa
posizione dei primi due byte
Rispondere alle seguenti domande:
1. Il ricevente rileva un errore?
2. In caso affermativo, può correggerlo?
```

1|0110010
0|1101100
----------
1|1001110
```

In questo caso il ricevente rileva un errore, il bit di parità della quarta riga è errato. 
Il ricevente può correggere l'errore perché conosce la posizione (basta mettere il bit a 1). 
```
1|0110010
0|1101100
---------
1|1011110
```

la sequenza corretta diventa:
`10110010 01101100 11011110`

---

# Esercizio 5
Data la sequenza D di bit fornita di seguito in formato binario
1101 1010 1001 0110
Si calcolino i bit di EDC (error detection and correction) secondo lo
schema di CRC usando il generatore CRC-8-CCITT (1 0000 0111).
Quali sono i bit EDC da aggiungere?

### Soluzione
abbiamo: 
`1101 1010 1001 0110` e il generatore è G = `1 0000 0111`

Ricordiamo che il generatore è lungo `n+1`, noi avremo n bit da utilizzare. 
In questo caso il generatore è lungo 9 bit. 

Quello che dobbiamo fare è la divisione binaria, che non è altro che uno XOR: 

```

             _____________________________
1 0000 0111 |1101 1010 1001 0110 0000 0000
			 1000 0011 1
			 -----------
			 0101 1001 0
```

A questo punto, possiamo fare la divisione? Si, abbassando uno 0: 
```

             __________1__________________
1 0000 0111 |1101 1010 1001 0110 0000 0000
			 1000 0011 1
			 -----------
			 0101 1001 00
			  100 0001 11
			  ------------
			  001 1000 11
```

Posso fare la divisione abbassando uno zero? Non ancora, quindi il quoziente avrà uno zero: 
```

             __________110__________________
1 0000 0111 |1101 1010 1001 0110 0000 0000
			 1000 0011 1
			 -----------
			 0101 1001 00
			  100 0001 11
			  ------------
			  001 1000 1101
			    1 0000 0111
			    -----------
			    0 1000 1010
```

Ci chiediamo di nuovo se possiamo fare la divisione, abbassando lo zero, si
```

             __________1101 1_________________
1 0000 0111 |1101 1010 1001 0110 0000 0000
			 1000 0011 1
			 -----------
			 0101 1001 00
			  100 0001 11
			  ------------
			  001 1000 1101
			    1 0000 0111
			    -----------
			    0 1000 10100
			      1000 00111
			      ----------
			      0000 10011
			      
			      
```
E continuiamo così, fin quando non arriviamo alla fine e otteniamo l'EDC = 11010011. 


