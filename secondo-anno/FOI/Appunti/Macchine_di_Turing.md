La macchina di Turing può essere definita così: 
- Una unità di controllo che, ad ogni istante, può trovarsi in uno stato interno appartenente ad un certo insieme Q che contiene lo stato $q_0$ che fa partire la computazione e un sottoinsieme $Q_f$ di stati che fanno terminare la computazione. 
- Un nastro suddiviso in un numero infinito di celle, ciascuna delle quali, ad ogni istante può essere vuota o contenere un simbolo appartenente ad un alfabeto $\sum$, e sul quale nastro si muove una testina in lettura/scrittura.
- Ad ogni istante, dipendentemente dallo stato interno e da ciò che è letto dalla testina, viene eseguita una quintupla scelta in un insieme P di quintuple. 

## Come funziona una macchina di Turing?
All'inizio, quando l'unità si trova nello stato $q_0$ la testina legge il simbolo contenuto all'interno della cella, la macchina cerca una quintupla che inizia con $q_0$ e il simbolo letto dalla testina e, se trova una quintupla, la esegue.
Se non trova la quintupla, l'unità non fa nulla e termina la computazione. 

Eseguire una quintupla significa eseguire le tre azioni in essa indicate: 
- Sovrascrivere il simbolo nella cella scandita. 
- Cambiare stato interno
- Muovere la testina

Eseguita la prima quintupla si cerca un'altra quintupla da eseguire e così via fino a quando nessuna quintupla può più essere eseguita. 

## Esempio
Consideriamo la macchina di Turing ad un nastro, $T_{parità}$, definita sull'alfabeto: 
$\sum = \{0,1,p,d\}$ e sull'insieme degli stati $Q = \{q_0, q_p, q_d, q_f\}$ 
Con stato iniziale $q_0$ e stato finale $q_f$ il cui insieme delle quintuple è: 
$$
Q = <q_0, 0, \square, q_p, destra> \ , \ <q_0, 1, \square, q_d, destra> \newline
<q_p, 0, \square, q_p, destra> \ , \ <q_p, 1, \square, q_d, destra> \newline
<q_d, 0, \square, q_d, destra> \ , \ <q_d, 1, \square, q_p, destra> \newline
<q_p, \square, p, q_f, fermo> \ , \ <q_d, \square, d, q_f, fermo> 
$$
Questa macchina verifica se una parola, con ogni carattere in una cella, è pari o dispari, le quintuple indicano cosa fare in ogni singolo caso in cui si trovi la macchina. Per ogni carattere che viene letto la macchina cancella il carattere appena letto e controlla se il numero di '1' è pari, in questo caso stampa **p**, stampa **d** altrimenti.

Ma se sul nastro scriviamo un carattere diverso da 0 e 1 ma compreso nell'alfabeto, come ad esempio p o d?
In quel caso la macchina non avrebbe nessuna quintupla che indichi cosa fare in quel caso, dunque la computazione, se p è il primo carattere, non parte o termina quando viene letta dalla testina. 

### Definizione macchina di Turing
Una macchina di Turing è completamente caratterizzata da: 
- $\sum$, ossia, un insieme finito di caratteri che prende il nome di *alfabeto*
- Q, un insieme di stati interni
- Uno stato iniziale, solitamente identificato come $q_0$
- Un sottoinsieme di stati finali $Q_f$ tale che $Q_f \subset Q$
- Un insieme di quintuple $P \subseteq Q \times \sum \times \sum \times Q \times \{sinistra, destra, fermo\}$ 

Questo è valido per le macchine di Turing a un nastro, per quelle con più nastri la differenza è che vanno inseriti i caratteri che devono essere scritti per ciascun nastro, i caratteri che devono essere sovrascritti per ciascun nastro e i movimenti che le testine (una testina per ogni nastro), devono eseguire.


### Esercizio 
Progettare una macchina di Turing a due nastri, che, avendo sul primo nastro, due numeri interi della stessa lunghezza, calcola il valore della loro somma scrivendo il risultato sul secondo nastro. 

Per prima cosa, dobbiamo considerare da dove inizierà il primo numero che incontreremo e dove inizia l'altro: in questo caso, siccome stiamo facendo la somma di due numeri sulla stessa riga, dunque è facile intuire che è necessario un carattere separatore '+' che indica la separazione tra i due numeri. 

L'idea della soluzione è quella posizionare la testina sulle unità del primo numero, ricordiamo la cifra letta, la cancelliamo inserendo un '+' e ci spostiamo sulle unità del secondo numero con la testina. 
poi, eseguiamo la somma fra la cifra del primo numero che ci stiamo ricordando e quello che stiamo leggendo: cancelliamo la cifra che stiamo leggendo sul primo nastro sostituendola con un $\square$ e scriviamo sul secondo nastro la cifra appena calcolata muovendo, in seguito, la sua testina a sinistra e ricordando il nuovo.

Chiamiamo $q_i$ lo stato iniziale e indichiamo con **s** sinistra, **d** destra e **f** per fermo. 
Utilizziamo le quintuple
$<q_i, (0, \square), (0, \square), q_i, (d, f)>, \dots, <q_i, (9, \square), (9, \square), q_i, (d, f)>$ 
Che abbrevieremo con $\forall x \in \{0, \dots, 9\}$. 
Lo stato $q_i$ corrisponde all'azione "vai a destra finché trovi +" e quando incontriamo `+` smettiamo di muoverci a destra sul primo nastro e tornare indietro di una posizione, dobbiamo eseguire un'azione diversa da quella regolata con $q_i$. 
Per questo, quando leggiamo `+` entriamo nello stato $q_{is}$ al quale corrisponde l'azione muoviti a sinistra sul primo nastro. 
A questo punto eseguiamo la somma delle cifre e scriviamo sul secondo nastro il risultato, utilizzando le quintuple: 
$$
<q_{0s}^0, (0,\square), (\square, 0),q^0, (f,s)> \ , \ <q_{0s}^1, (0, \square), (\square, 1), q^0, (f, s)> \newline
<q_{1s}^0, (0, \square), (\square, 1), q^0, (f, s)> \ , \ <q_{1s}^1, (0, \square), (\square, 2), q^0, (f, s)> \dots
$$
dove $q^0$ e $q^1$ sono gli stati che corrispondono a "torno a sinistra a cercare la nuova cifra del primo addendo ricordando il riporto"
Questa macchina funziona soltanto se i due numeri da sommare hanno la stessa lunghezza, ossia, lo stesso numero di cifre. 

Il modello di calcolo della Macchina di Turing richiede che in ogni macchina, l'insieme degli stati e l'alfabeto abbiano cardinalità finita e lo stesso vale per il numero di nastri. 
Una macchina con infiniti stati interni e alfabeto infinito renderebbe le costruzioni delle quintuple troppo semplici, ma la semplicità non permetterebbe il corretto funzionamento: ciò implicherebbe predisporre infiniti stati e infiniti caratteri ma noi non abbiamo tempo infinito. 
Dunque, *è necessario che, numero di nastri, numeri di caratteri dell'alfabeto e numero di stati e quintuple siano **costanti***. 

### Definizione di parola
Dato un alfabeto finito $\sum$, una parola su $\sum$ è una sequenza finita di elementi di $\sum$.
L'insieme di parole nell'alfabeto $\sum$ si indica con $\sum^*$. 

### Stati globali
Uno stato globale SG di una macchina di Turing è una fotografia della macchina ad un certo istante. 
Formalmente: 
*Uno stato globale di una macchina ad un nastro T ad un certo istante, contiene una descrizione della porzione non blank del nastro di T, della posizione della testina e dello stato interno.* 
*Ed è rappresentato mediante la sequenza di caratteri contenuti sul nastro in cui il carattere letto dalla testina è premesso lo stato interno.*

### Transizioni
Una transizione dallo stato globale $SG_1$ allo stato globale $SG_2$ avviene quando viene eseguita una quintupla che trasforma $SG_1$ in $SG_2$ . 
Formalmente, se $T=<\sum, Q, q_0, Q_f, P>$ è una macchina di Turing ad un nastro, esiste una transizione da $SG_1 \ a \ SG_2$ se esiste una quintupla $<q, x, x', q', m> \ \in P$ tale che: 
- In SG1 T si trova nello stato interno $q \in Q$
- In SG1 la testina di T sta scandendo una cella che contiene il carattere $x \in \sum$
- In SG2 la cella che in SG1 conteneva il carattere x contiene il carattere $x' \in \sum$
- In SG2, T si trova nello stato interno $q' \in Q$
- In SG2, la testina di T sta scandendo la cella che si trova in posizione m rispetto a quella che stava scandendo in SG1. 

### Computazione
Una computazione di una macchina di Turing deterministica a un nastro $T = <\sum, Q, q_0 Q-f, P>$ è l'esecuzione di quintuple di T su una sequenza di caratteri scritti sul nastro. 
Formalmente: 
*Una computazione di una macchina di Turing T è una sequenza SG_0, SG_1, SG_2, ..., SG_h* di stati globali tali che: 
SG_0 è uno stato globale iniziale, ossia, uno stato globale nel quale lo stato interno è $q_0$ e la testina è posizionata sul carattere più a sinistra scritto sul nastro. 
Se esiste un indice h tale che $SG_h$ è uno stato globale dal quale non può avvenire alcuna transizione, allora la computazione termina. 

## Trasduttori e riconoscitori
Le macchine di tipo **trasduttore** sanno calcolare il valore di una funzione qualsiasi. 
Assumiamo che le macchine di Turing di tipo **trasduttore** dispongano sempre di un nastro di output sul quale scrivono il valore della funzione che hanno calcolato. 
Un trasduttore ha un solo stato finale con il quale terminare la computazione: lo stato $q_f$. 

Le macchine di tipo **riconoscitore**, invece, sanno calcolare solo il valore di funzioni booleane e non dispongono di un nastro di output. 
Il valore calcolato da un riconoscitore viene memorizzato nello stato interno con il quale la macchina termina la computazione: $q_a$ se il valore della funzione è 1, $q_r$ se il valore della funzione è 0. 
Diciamo che un riconoscitore T accetta x se la computazione T(x) termina in $q_a$ e che la macchina T rigetta x se la computazione T(x) termina in $q_r$

### Esito di una computazione
Data una macchina di Turing T ed un suo input x, l'esito della computazione T(X) è indicato con $o_t(x)$, ovvero il risultato. 
Se T è una macchina di tipo **trasduttore** allora $o_T(x)$ è la parola scritta da T sul nastro di output al termine della computazione T(x).
Se T è una macchina di tipo **riconoscitore** allora $o_T(x)$ è lo stato interno con il quale la macchina termina la computazione T(x). 
