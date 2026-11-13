Ora che abbiamo visto cos'è un grafo, dobbiamo capire come rappresentarlo in memoria.
Per fare ciò introduciamo due strutture dati: 
1. **Matrice di adiacenza**
2. **Liste di adiacenza**

# Matrice di adiacenza 
La matrice di adiacenza è una matrice $n \times n$ dove $n$ è il numero di vertici. 
Ogni elemento $M[i][j]$ indica se esiste un arco tra il vertice $i$ e il vertice $j$: 
- `1` se esiste un arco
- `0` se non esiste
Per esempio, se abbiamo un arco tra A e B, nella matrice non diretta avremo sia $M[A][B]=1$ sia $M[B][A]=1$ 

## Matrice di adiacenza - spazio occupato 
La matrice contiene sempre $n \times n$ celle, indipendentemente dal numero di archi. 
Per questo motivo, lo spazio richiesto è: 
$$O(n^2)$$
Anche se il grafo ha pochissimi archi, dobbiamo comunque allocare tutta la matrice. 

# Liste di adiacenza
L'idea è semplice: invece di utilizzare una matrice, manteniamo per ogni vertice una lista contenente tutti i suoi vertici adiacenti. 
Per esempio, se abbiamo: 
A collegato a B, C e D
B collegato ad A e C
C collegato ad A, B e D
D collegato ad A e C

*Le liste saranno:* 
```
A → B → C → D
B → A → C
C → A → B → D
D → A → C
```

Lo spazio occupato è: 
$$O(m+n)$$
Dove: 
- $n$ è il numero di vertici; 
- $m$ è il numero di archi; 
Dobbiamo considerare anche il numero di vertici perché **ogni vertice deve avere una propria lista di adiacenza**, anche quando non ha archi. 
Per questo lo spazio totale è: 
$$O(m+n)$$
## Confronto tra le rappresentazioni
Confrontiamo alcune operazioni:

| Operazione                    | Matrice | Liste                           |
| ----------------------------- | ------- | ------------------------------- |
| Elencare gli archi incidenti  | $O(n)$  | $O(\delta(v))$                  |
| Verificare se esiste $(u, v)$ | $O(1)$  | $O(min\{\delta(u),\delta(v)\})$ |
Con le liste di adiacenza, per elencare i vicini di un vertice $v$, dobbiamo semplicemente scorrere la sua lista.
Se $v$ ha grado 3, dobbiamo esaminare 3 elementi. 

Ora vediamo la seconda operazione: verificare se esiste un arco $(u, v)$
- Con la matrice di adiacenza basta accedere direttamente a `M[u][v]`, quindi $O(1)$.
- Con le liste dobbiamo cercare il vertice nella lista di adiacenza di $u$ oppure di $v$, scegliendo quella più corta. 

# Algoritmi di visita 
Una visita di un grafo permette di esaminare sistematicamente i suoi nodi e archi e genera **un albero di visita**. 
Abbiamo due tipi di visita: 
- **BFS**: visita in ampiezza. 
- **DFS**: visita in profondità. 

## Struttura dati utilizzata dalla BFS
La BFS utilizza una coda (FIFO): 
- Inseriamo in fondo i nodi da visitare; 
- Estraiamo dalla testa il prossimo nodo da elaborare. 
Questo garantisce che i nodi vengano visitati per livelli


#pseudocodice 
```
Algoritmo visitaBFS(vertice s) -> albero 
	rendi tutti i vertici non marcati 
	T <- albero formato da un solo nodo s
	coda F
	marca il vertice s; dist(s) <- 0
	F.enqueue(s)
	
	while(not F.isEmpty()) do 
	u <- F.dequeue()
	for each(arco(u,v) in G) do 
		if(v non è ancora marcato ) then 
			F.enqueue(v)
			marca il vertice; dist(v)<- dist(u)+1
			rendi u padre di v in T 
			
	return T
```

Il tempo di esecuzione dipende dalla struttura dati che scegliamo per rappresentare il grafo. 
**Osservazioni:**
1. Si noti che se il grafo è connesso, allora $m \geq n-1$ e quindi $O(m+n)=O(m)$
2. Ricordando che $m \leq n(n-1)/2$, si ha $O(m+n)=O(n^2)$

## Teorema
> Per ogni nodo v, il livello di v dell'albero BFS è pari alla distanza di v dalla sorgente s (sia per grafi orientati e non orientati )

### Dimostrazione informale
- All'inizio inserisco s in F che è a distanza 0 da sé stesso e gli assegno livello 0. Chiaramente s è l'unico nodo a distanza 0. 
- Estraggo s e guardo tutti i suoi vicini; questi sono tutti i nodi a distanza 1 da s; li inserisco in F e assegno loro livello 1. Ora in F ho tutti i nodi a distanza 1. 
- estraggo uno a uno tutti i nodi di distanza 1 e per ognuno guardo tutti i suoi vicini; i vicini non marcati sono a distanza 2 da s. Li inserisco in F e assegno loro livello 2; quando ho estratto e visitato tutti i nodi di livello 1, in F ho tutti i nodi a distanza 2 da s. 
- Estraggo uno a uno tutti nodi di livello/distanza 2 e per ognuno guardo tutti i suoi vicini; i vicini sono a distanza 3 da s. 

# Visita in profondità

La DFS genera anch'essa un albero di visita, radicato nel nodo sorgente s, ma la sua struttura dipende dall'ordine con cui vengono esplorati i vicini. 
## costo della visita in profondità
anche qui il costo è $O(m+n)$ per le liste di adiacenza e $O(n^2)$ per la matrice di adiacenza. 

# Proprietà dell'albero DFS radicato in s
Se il grafo è non orientato per ogni arco $(u, v)$ si ha:
- (u, v) è un arco dell'albero DFS, oppure
- I nodi u e v sono l'uno antenato/discendente dell'altro. 

Se il grafo è orientato, per ogni arco $(u, v)$ si ha: 
- $(u, v)$ è una arco dell'albero DFS, oppure 
- I nodi u e v sono l'uno l'antenato/discendente dell'altro, oppure 
- $(u, v)$ è un arco trasversale a sinistra, ovvero il vertice v è un sottoalbero visitato precedentemente da u. 




