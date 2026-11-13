## Cammini minimi in grafi pesati
Consideriamo un grafo:
$$G=(V, E, w)$$
Dove: 
- $V$ è l'insieme dei vertici
- $E$ è l'insieme degli archi
- $w$ è la funzione che associa un peso ad ogni arco

Consideriamo un cammino: 
$$\pi = <v_0, v_1, \dots, v_k>$$
Il suo costo è la somma dei pesi di tutti gli archi attraversati: 
$$w(\pi)=\sum_{i=1}^kw(v_{i-1}, v_i)$$
Un cammino minimo tra due vertici $x$ e $y$ è un cammino il cui costo è minore o uguale a quello di qualsiasi altro cammino con gli stessi vertici. **Il cammino minimo non è necessariamente unico**. Possono esistere più cammini con lo stesso costo minimo. 

### Esempio di cammino minimo
Supponiamo un grafo pesato con due vertici, $u$ e $v$, e diversi percorsi possibili. 
Vengono confrontati alcuni cammini: 
Uno con costo 43; 
Uno con costo 35; 
Il cammino minimo ha costo 17. 
La distanza tra due vertici viene indicata con $d_G(u, v)$ e rappresenta il costo di un qualsiasi cammino minimo da $u$ a $v$. 

### Esiste sempre un cammino?
In breve la risposta è no, e si possono verificare due casi: 

#### Caso 1 - Non esiste alcun cammino da $u$ a $v$
$$d_G(u, v)= +\infty$$
#### Caso 2 - Esiste un cammino che contiene un ciclo negativo raggiungibile 
$$d_G(u, v)= -\infty$$
Perché? Possiamo percorrere il ciclo negativo un numero arbitrario di volte, diminuendo il costo del cammino. 

> **Osservazione:** se il grafo non contiene cicli negativi, esistono cammini minimi che sono cammini semplici, cioè non contengono nodi ripetuti. 

Vediamo bene questa osservazione, immaginiamo il percorso: 
$$A \rightarrow B \rightarrow C \rightarrow D$$
Supponiamo che ci sia un arco da C a B, formando un ciclo: 
$$B \rightarrow C \rightarrow B$$
Se il ciclo ha un costo positivo, percorrerlo aumenta il costo totale. Se ha costo zero non lo diminuisce. 
Se eliminiamo un ciclo con costo positivo o nullo, eliminarlo non aumenta il costo. 

## Sottostruttura ottima
**Ogni sottocammino di un cammino minimo è a sua volta un cammino minimo**. 
Immaginiamo di avere: 
$$A \rightarrow B \rightarrow C \rightarrow D$$
Secondo questa proprietà il sottocammino: 
$$B \rightarrow C \rightarrow D$$
Deve essere necessariamente un cammino tra B e D. 

## Disuguaglianza triangolare
Introduciamo una proprietà fondamentale: 
$$d(u, v)\leq d(u, x)+d(x, v)$$
**Il cammino minimo da $(u, v)$ non può avere costo maggiore o uguale del percorso che passa per un nodo intermedio $x$**. 

### Cammini minimi a singola sorgente
Il problema consiste nel constatare i cammini minimi partendo da un unico nodo sorgente $s$. 
Per tutti gli altri nodi dobbiamo calcolare il costo del cammino minimo da $s$ verso ogni altro nodo. 
**Un albero dei cammini minimi**, rispetto al semplice insieme delle distanze, è che **conosciamo anche gli archi che compongono i cammini minimi** dalla sorgente, in questo modo possiamo costruire il percorso da $s$ a qualsiasi destinazione. 

## Formalizzazione SPT 
Un albero $T$ è un albero dei cammini minimi radicato in $s$ se: 
- $T$ è un albero radicato in $s$. 
- Per ogni nodo $v$ vale: 
$$d_T(s, v)=d_G(s, v)$$
La seconda condizione significa che il cammino da $s$ a $v$ nell'albero deve avere lo stesso costo del cammino minimo del grafo originale.

Per i grafi non pesati, abbiamo già visto la [[Strutture dati elementari|BFS]] che costruisce un albero dei cammini minimi radicato nella sorgente. Perché BFS riesce a farlo? perché trova i nodi in ordine di distanza dalla sorgente, contando il numero di archi attraversati. 

## Le due varianti del problema
Le due varianti sono essenzialmente equivalenti: 
- Calcolare tutte le distanze minime dalla sorgente. 
- Costruire l'albero dei cammini minimi. 
Conoscendo L'SPT possiamo ricavare le distanze sommando i pesi degli archi. Viceversa, dalle distanze possiamo ricavare un SPT. 

# Algoritmo di Dijkstra

Introduciamo un'assunzione fondamentale: 
$$w(u, v) \geq 0 \ \ \ \ \ \ \ \ \forall(u, v) \in E$$
Ovvero, **tutti gli archi devono avere peso non negativo**. 
L'algoritmo mantiene tre elementi fondamentali:
- $D_{sv}$: una stima per eccesso della distanza minima dalla sorgente $s$ al nodo $v$
- $X$: l'insieme dei nodi per i quali abbiamo già determinato la distanza minima esatta
- $T$: l'albero dei cammini minimi, che contiene i percorsi verso i nodi già inseriti in $X$.

## Inizializzazione
All'inizio: 
- $X=\{s\}$: conosciamo già la distanza minima dalla sorgente $s$ al nodo $v$
- $D_{ss}=0$
- Per tutti gli altri nodi, $D_{sv} = +\infty$
- $T$ non contiene archi

### Come procede?
A ogni iterazione, Dijkstra: 
1. Seleziona un nodo $u$ fuori da $X$ con la stima $D_{su}$ più piccola. 
2. Aggiunge $u$ a $X$ e il relativo arco a $T$. 
3. Aggiorna le stime dei nodi adiacenti a $u$
Dijkstra sceglie il nodo con la stima minima perché, dato che tutti i pesi sono non negativi, non possiamo trovare successivamente un percorso che raggiunga quel nodo con un costo inferiore. 
Per questo motivo, quando selezioniamo un nodo, possiamo considerare definitiva la sua distanza minima e inserirlo in $X$.
### Aggiornamento delle stime
Quando aggiungiamo un nodo $u$ a $X$, controlliamo i suoi archi uscenti verso i nodi non ancora definitivi. 
La formula è: 
$$D_sy=min_{(x, y)\in E,\ \ x \in X}\{D_{sx}+w(x, y)\}$$

Facciamo un esempio: 
Supponiamo che
- $D_{su}=5$
- Esiste un arco $u \rightarrow y$ di peso 3
- Attualmente $D_{sy}=10$

La nuova stima di y sarà $D_{sy}=(10, 5+3)=8$
Questa operazione si chiama **rilassamento dell'arco** (relaxation), se invece la nuova stima è maggiore rispetto alla precedente, non aggiorniamo l'arco. 

# Pseudocodice 
Prima di analizzare lo pseudocodice di Dijkstra, ricordiamo che **la coda con priorità** contiene i nodi non ancora definitivi, organizzati in base alla stima di $D_{sv}$ .

#pseudocodice 
```
algoritmo Dijkstra(grafo G, vertice s) -> albero
	for each (vertice u in G) do D_su <- +infinito
	T^<--albero formato dal solo nodo s. 
	X <- insieme vuoto 
	CodaPriorità S
	D_ss <-- 0
	S.insert(s, 0)
	while (not S.isEmpty()) do
		u <- S.deleteMin; X <- X U {u}
		for each(arco(u, v) in G ) do
			if(D_sv=+infinito) then
				S.insert(v, D_su +w(u, v))
				D_sv <- D_su + w(u, v)
				rendi u padre di v in 
			else if(D_su+w(u, v)<D_sv) then
				S.decreaseKey(v, D_sv-D_su-w(u, v))
				D_sv <- D_su+w(u, v)
				rendi u nuovo padre di v in T^
				
	return T^
```

L'operazione fondamentale è `deleteMin` che estrae dalla coda con priorità il nodo con la stima minima. 
Quando un nodo viene estratto dalla coda con `deleteMin` la sua distanza diventa definitiva e il nodo viene aggiunto all'insieme X, non dovremo più aggiornare la sua distanza. 
Per capire meglio, vediamo un esempio di **iterazione**.

### Esempio di iterazione dell'algoritmo di Dijkstra
![[Pasted image 20261113113732.png|582]]

Il grafo ha cinque nodi $(A, B, C, D, E)$ e la sorgente è A. 
Archi diretti e pesi sono: 

| Archi diretti     | Pesi |
| ----------------- | ---- |
| $A \rightarrow B$ | 10   |
| $A \rightarrow C$ | 3    |
| $B \rightarrow C$ | 1    |
| $C \rightarrow B$ | 4    |
| $B \rightarrow D$ | 2    |
| $C \rightarrow D$ | 8    |
| $C \rightarrow E$ | 2    |
| $D \rightarrow E$ | 7    |
| $E \rightarrow D$ | 9    |

#### Iterazione 0 - impostiamo le distanze
| Nodo | stima      |
| ---- | ---------- |
| A    | 0          |
| B    | $+ \infty$ |
| C    | $+ \infty$ |
| D    | $+ \infty$ |
| E    | $+ \infty$ |
Abbiamo: 
$$X=\{A\}$$
Ora analizziamo gli archi uscenti da A: 
- $A \rightarrow B$ possiamo aggiornare B a 10
- $A \rightarrow C$ possiamo aggiornare C a 3

Quindi otteniamo

| nodo | stima      |
| ---- | ---------- |
| A    | 0          |
| B    | 10         |
| C    | 3          |
| D    | $+ \infty$ |
| E    | $+ \infty$ |
Ora dobbiamo eseguire `deleteMin` per scegliere il prossimo nodo da rendere definitivo, scegliamo di estrarre C perché **è il nodo con la stima più piccola**. 
Quindi: 
$$deleteMin()=C$$
La distanza di C diventa definitiva: $D_{sC}=3$
Inseriamo: 
$$X=\{A, C\}$$

Ora guardiamo gli archi uscenti da C: 
$C \rightarrow B$: aggiorniamo a 4 
$C \rightarrow E$: scopriamo un cammino per E, il costo dell'arco è 2
$C\rightarrow D$ scopriamo un cammino per D, con costo 8

Aggiorniamo la tabella: 

| Nodo | Stima |
| ---- | ----- |
| A    | 0     |
| B    | 7     |
| C    | 3     |
| D    | 11    |
| E    | 5     |
Ricordiamo che dobbiamo sommare alle nuove stime trovate, il peso dell'arco da A a C. 
Ora con `deleteMin` estraiamo il nodo E perché è il minimo
Quindi la stima definitiva diventa $D_sE=5$
Aggiorniamo $X$ che diventa: 
$$X=\{A, C, E\}$$

Ora guardiamo gli archi uscenti da E: 
L'unico arco è $E \rightarrow D$ con peso 9. 
Il costo del nuovo percorso è: 
$$D_sE+w(E, D)= 5+9=14$$
La nostra stima precedente era 11, dunque non aggiorniamo la tabella. 

Adesso tra $B(7) \ e \ D(11)$ estraiamo il nodo con stima minima, quindi B la cui stima definitiva diventa: 
$$D_{sB}=7$$
Quindi aggiornando $X$: 
$$X=\{A, C, E, B\}$$
vediamo gli archi uscenti da B: 
- $B \rightarrow C$ con costo 1
- $B\rightarrow D$ con costo 2

La nostra stima precedente di C era 3, questo nuovo cammino ha $D_{sB}+w(B, C)=7+1=8$, quindi non aggiorniamo la stima (Inoltre C aveva già una distanza definitiva).

Per D invece abbiamo $D_sB+w(B, D)=7+2=9$, la nostra stima precedente era 11, dunque aggiorniamo la tabella:

| Nodo | Costo |
| ---- | ----- |
| A    | 0     |
| B    | 7     |
| C    | 3     |
| D    | 9     |
| E    | 11    |
A questo punto nella coda rimane soltanto D, che possiamo inserire in $X$: 
$$X=\{A, C, E, B, D\}$$
Tutti i nodi sono stati elaborati, dunque l'algoritmo termina. 
Ora l'albero dei cammini minimi contiene gli archi: 
- $A \rightarrow C$
- $C \rightarrow B$
- $C\rightarrow E$
- $B \rightarrow D$

## Correttezza di Dijkstra
Ora vogliamo capire **perché possiamo essere sempre sicuri che restituisca sempre le distanze minime corrette**. 

### Lemma
Quando un nodo $v$ viene estratto dalla coda con priorità, valgono due proprietà: 
1. La sua stima è esatta: 
$$D_{sv}=d(s, v)$$
2. Il cammino da $s$ a $v$ nell'albero corrente T ha costo minimo

In altre parole, quando `deleteMin` estrae un nodo, possiamo davvero considerare definitiva la sua distanza. 

#### Dimostrazione per assurdo
- Si suppone che il nodo $v$ venga estratto con una distanza non ottimale. 
- Si considera un cammino minimo da $s$ a $v$. 
- Si individua il primo arco $(x, y)$ di quel cammino con $x \in X \ e \ y \notin X$
- Si sfrutta il fatto che i pesi degli archi sono non negativi per arrivare a una contraddizione. 

## Complessità computazionale
Analizziamo la complessità computazionale in due casi: 
- Senza coda con priorità 
- Con coda con priorità 

### Senza coda con priorità 
Complessità: 
$$O(n+m)$$
dove: 
- $n = |V|$: numero di nodi
- $m =|E|$: numero di archi

### Coda con priorità
Ora consideriamo il caso in cui un grafo sia rappresentato tramite liste di adiacenza e tutti i nodi siano raggiungibili dalla sorgente. 
Dijkstra esegue: 

| Operazione    | Numero di esecuzioni |
| ------------- | -------------------- |
| `insert`      | $n$                  |
| `deleteMin`   | $n$                  |
| `decreaseKey` | al massimo $m$       |
`decreaseKey` viene eseguita al più $m$ volte perché ogni `decreaseKey` è associata all'esame di un arco. 
Quando elaboriamo un nodo $u$, esaminiamo i suoi archi uscenti. Per ciascun arco $(u, v)$, possiamo eventualmente migliorare la stima di $v$, eseguendo `decreaseKey`. 
Dato che il grafo contiene $m$ archi e ogni arco viene esaminato una sola volta, possiamo eseguire al massimo $m$ operazioni `decreaseKey`.

## Implementazione della coda
### Con un array non ordinato

| operazione    | complessità |
| ------------- | ----------- |
| `insert`      | $O(1)$      |
| `deleteMin`   | $O(n)$      |
| `decreaseKey` | $O(1)$      |
#### Complessità complessiva
Ricordiamo che abbiamo: 
- $n$ operazioni `insert`, ciascuna $O(1)$
- $n$ operazioni `deleteMin`, ciascuna $O(n)$
- al massimo $m$ operazioni `decreaseKey`, ciascuna $O(1)$

Quindi:
$$O(n)+O(n \cdot n)+O(m) \\ \\ O(n^2+m)$$
Nel caso in cui $m = O(n)$ avremo:
$$O(n^2)$$

### Con un array ordinato
| Operazione    | Costo  |
| ------------- | ------ |
| `insert`      | $O(n)$ |
| `deleteMin`   | $O(1)$ |
| `decreaseKey` | $O(n)$ |
La complessità diventa: 
$$O(n \cdot n)+O(n)+O(m \cdot n) \\ \\
O(mn)$$
**Se utilizzassimo un heap binario o binomiale** otteniamo una complessità complessiva: 
$$O(mlogn)$$
## Heap di Fibonacci
Con gli heap di fibonacci otteniamo una complessità complessiva: 
$$O(m+nlogn)$$
