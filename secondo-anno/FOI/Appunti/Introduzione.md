In questo corso considereremo problemi di calcolabilità, ossia capire quali problemi possono essere risolti automaticamente e capire quali problemi non possono essere in nessun modo risolti. Nella seconda parte ci occuperemo invece della complessità, ossia capire quali dei problemi che possono essere risolti possono essere risolti per davvero.

## Notazioni
Siano: 
- $\sum$ un insieme finito-
- $\sum^*$ l'insieme di tutte le sequenze di 0 o più caratteri di $\sum$, dette parole. 
- $\epsilon$ la parola vuota all'interno di $\sum^*$ 
- Date due parole in x e y in $\sum^*$, indichiamo con xy la concatenazione di x e y, ossia se x = $x_1x_2...x_n$ e y = $y_1 y_2 ... y_n$ allora xy diventa xy= $x_1 x_2...x_n y_1 y_2 ... y_n$. 
- Data $x=x_1 x_2...x_n \in \sum^*$, la parola inversa di x è $x^{-1}=x_n,x_n-1...x_1$.
- Data $x=x_1x_2 ...x_n \in \{0,1\}^*$ , la parola complemento di x è $x^c=y_1y2 ...y_n$ tale che, per i = 1, ...,n, $y_i=0$ se $x_i=1$ e $y_i=1$ se $x_i=0$. 

# Che cos'è un problema?
*Un problema è la descrizione di un insieme di parametri, che chiameremo **dati**, collegati da un certo insieme di relazioni, associata alla richiesta di derivare da essi un altro insieme di parametri, che costituiscono la soluzione.* 

*Un'istanza di un problema è un particolare insieme di valori associati ai dati.*
Quando l'istanza di un problema non ha soluzione, essa viene detta **istanza negativa**.

# Cosa vuol dire risolvere un problema?
Risolvere un problema significa trovare un metodo che sappia trovare la soluzione di qualunque istanza positiva del problema e che sappia riconoscere un'istanza negativa. Quindi risolvere un problema significa **trovare un procedimento che, per ogni istanza del problema, indichi la sequenza di azioni che deve essere eseguita per trovare la soluzione di quell'istanza**. 

*Un procedimento è la descrizione delle azioni che devono essere compiute, aggiungendo inoltre l'ordine in cui deve essere fatto ciò.* 
In un procedimento, le istruzioni eseguite devono essere **elementari.** 

### Cosa intendiamo per istruzione elementare?
Secondo Turing, un'istruzione, per poter essere definita elementare, ha bisogno di rispettare queste caratteristiche: 
- Deve essere scelta in un insieme di poche istruzioni.
- Deve scegliere l'azione da eseguire all'interno di un insieme di poche azioni possibili. 
- Deve poter essere eseguita ricordando una quantità limitata di dati, ossia usando una quantità di memoria limitata. 

Per verificare la seconda caratteristica pensiamo alla somma di due numeri naturali, per sommare qualunque coppia di interi sono necessarie *242 istruzioni*, che eseguono tre azioni ciascuna, fra le quali scegliere e che utilizzano una memoria di 3 cifre. 
Quindi possiamo concludere che, **il numero di istruzioni, azioni e la quantità di memoria necessaria sono costanti e non dipendono dall' input.**
Inoltre, le istruzioni dicono, per ogni azione possibile, esattamente quali azioni devi eseguire in quelle condizioni. Dunque consideriamo l'insieme di istruzioni come *non ambiguo*.
L'ordine in cui eseguire le istruzioni è indicato implicitamente dal meccanismo "se...allora..." .

Dunque, risolvere automaticamente un problema significa (informalmente) progettare un procedimento che risolve tutte le istanze di quel problema e che può essere eseguito da un automa. 

# Nuovo linguaggio
Prendiamo come esempio la somma di due numeri naturali, possiamo scrivere il procedimento in una forma più compatta, senza l'utilizzo continuo di "se...allora...", scrivendo le due condizioni seguite dalle tre istruzioni. 
Se r = 0 (riporto) e le due cifre sono 4 e 6, allora scrivi 0, poni r = 1 e spostati di una cifra a sinistra.
Compattando tutto diventa: 
$$
<q_0, (4,6), 0, q_1, sinistra>
$$


Dove $q_0 \ e \ q_1$ sono due simboli che indicano rispettivamente r=0 e r = 1. 
E l'istruzione *se r=1 e l'unica cifra è 5, allora scrivi 6, poni r = 0 e spostati a sinistra di una cifra*, in cui le cifre di uno degli operandi sono terminate, diventa la coppia di istruzioni: 
$$
<q_0 \ , (5, \square), \ 6 \ , q_0, sinistra> 
$$
e 
$$
<q_1 \ , \ (\square, 5), 6, q_0, sinistra> 
$$
Dove $\square$ indica che non viene letto nulla o che non deve essere scritto nulla.
E abbiamo due diverse istruzioni perché l'operando le cui cifre sono terminate può essere il primo o il secondo. 

Le istruzioni: 
- Se r = 1 e le cifre di entrambi i numeri sono terminate, allora scrivi 1 e termina.
- Se r = 0 e le cifre di entrambi i numeri sono terminate, allora termina.

Diventano rispettivamente: 
$$
<q_1,(\square, \square), 1, q_f, fermo>
$$
e: 
$$
	<q_0, \ (\square, \square),\ \square, \ q_f, \ fermo>
$$
Dove $q_f$ è lo stato interiore, che permette all'esecutore di capire che non ci sono altre istruzioni da eseguire.

### Possiamo far capire questo linguaggio ad una macchina
Immaginiamo una macchina, per la somma dei numeri naturali, che può trovarsi in uno dei tre stati: $q_0 \ , \ q_1 \ , \ q_f$. 
Che utilizza, per leggere e scrivere, tre nastri. 
- Suddivisi ciascuno in un numero infinito di celle
- Tali che ciascuna cella, in ogni istante, può contenere o una cifra, oppure può essere vuota. 
Tre testine di lettura/scrittura. 

Questa è **quasi** una macchina di Turing, quasi perché abbiamo utilizzato tre nastri, e in una macchina di Turing occorre descrivere cosa viene letto e cosa viene scritto su ogni nastro. 
Così, l'istruzione, **se r = 0, e le due cifre sono 4 e 6, allora scrivi 0 e poni r = 1 e spostati a sinistra di una posizione**, diventa: 
$$
< q_0, \ ,(4,6,\square), \ (4,6,0), q_1, sinistra> 
$$
Poiché specifica due condizioni e 3 azioni,  questa prende il nome di **quintupla.**
E quelli che abbiamo chiamato "stati interiori" sono detti propriamente **stati interni**. 
E l'esecuzione delle quintuple su un insieme fissato di dati si chiama **computazione**. 

--- 

#### Attenzione!!!
Fondamentale distinguere la *macchina di Turing*, cioè la descrizione di un procedimento di risoluzione di un problema espresso nel linguaggio definito da Alan Turing. 
Il linguaggio che costituisce il modello di calcolo: il modello *Macchina di Turing*. (Con la M maiuscola).
