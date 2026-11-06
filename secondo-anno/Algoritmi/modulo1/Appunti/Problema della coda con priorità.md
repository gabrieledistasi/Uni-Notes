Una coda con priorità è un tipo di dato che memorizza un insieme $S$ di $n$ elementi, ciascuno associato a una chiave appartenente a un dominio totalmente ordinato. 
Le operazioni principali sono: 

| Operazione     | significato                              |
| -------------- | ---------------------------------------- |
| `findMin()`    | Restituisce l'elemento con chiave minima |
| `insert(e, k)` | Inserisce un elemento con chiave `k`     |
| `delete(e)`    | Cancella un elemento specifico           |
| `deleteMin()`  | Cancella l'elemento con chiave minima    |
Esistono anche operazioni aggiuntive: 
`increaseKey(e, d)`: incrementa la chiave di un elemento $d$. 
`decreaseKey(e, d)`: decrementa la chiave di un elemento $d$. 
`merge(c1, c2)`: unisce due code con priorità. 

abbiamo quattro implementazioni: 
1. Array non ordinato
2. Array ordinato
3. Lista non ordinata 
4. Lista ordinata

L'obiettivo delle quattro implementazioni è capire come cambiano i costi a seconda della struttura scelta. 
Partiamo dall'array non ordinato. 

### Array non ordinato

`findMin()`: $\Theta(n)$, perché dobbiamo esaminare tutti gli elementi
`insert(e, k)`: $O(1)$ perché inseriamo in fondo
`delete(e)`: $O(1)$ grazie al riferimento diretto all'elemento e alla sovrascrittura con l'ultimo elemento. 
`deleteMin()`: $\Theta(n)$ perché prima dobbiamo cercare il minimo

### Array ordinato

`findMin()`: $O(1)$ perché il minimo si trova in testa alla lista
`insert(e, k)`: $O(n)$, nel caso peggiore, bisogna spostare n elementi di un posto. 
`delete(e)`: $O(n)$, nel caso peggiore, l'elemento da eliminare è il più grande dell'array.
`deleteMin()`: $O(1)$, sapendo che il minimo si trova in testa e che l'eliminazione è in tempo costante. 

### Lista non ordinata
Utilizziamo una lista bidirezionale. 
I costi sono: 
`findMin()`: $\Theta(n)$
`insert()`: $O(1)$
`delete()`: $O(1)$
`deleteMin()`: $\Theta(n)$

Una lista bidirezionale ha due puntatori per ogni nodo: 
- `prev`: punta al nodo precedente 
- `next`: punta al nodo successivo
Per eliminare un elemento abbiamo già il riferimento a quell'elemento. 
Ci basta modificare due collegamenti: 
- Il `next` dell'elemento precedente deve puntare all'elemento successivo all'elemento che vogliamo eliminare. 
- Il `prev` dell'elemento successivo all'elemento da eliminare, deve puntare al precedente dell'elemento eliminato. 
### Lista ordinata
La lista è bidirezionale ed è ordinata in modo crescente. 
`findMin()`: $O(1)$
`insert()`: $O(n)$
`delete()`: $O(n)$
`deleteMin()`: $O(1)$

# D-heap: definizione
Un d-heap è un albero radicato d-ario che rispetta tre proprietà: 
1. **Struttura**: è completo almeno fino al penultimo livello e le foglie dell'ultimo livello sono compattate verso sinistra. 
2. **Contenuto informativo**: ogni nodo contiene un elemento e una chiave appartenente a un dominio totalmente ordinato. 
3. **Ordinamento parziale**: ogni nodo ha una chiave maggiore o uguale a quella del padre. 

## Proprietà degli heap 
1. Un d-heap con $n$ nodi ha altezza $\Theta(log_dn)$ 
2. La radice contiene l'elemento con chiave minima 
3. Può essere rappresentato implicitamente tramite un vettore posizionale.

### Rappresentazione tramite vettore
Il fatto che l'albero sia completo ci permette di rappresentarlo tramite un vettore posizionale, ma perché?
Immaginiamo un heap binario completo: 
```
          2
        /   \
       5     7
      / \   /
     9  11 13
```
Possiamo memorizzarlo in un vettore seguendo l'ordine per livelli: 
```
[2, 5, 7, 9, 11, 13]
```
La cosa interessante è che **la posizione di ogni nodo ci permette di ricavare la posizione dei propri figli.**
Dunque non è necessario utilizzare i puntatori, la struttura stessa garantisce l'assenza di buchi nelle posizioni. 

## Altezza del d-heap 
$$h = \Theta(log_dn)$$
Significa che l'altezza cresce in modo logaritmico rispetto al numero di nodi con base $d$.
**NB**: se aumentiamo $d$ a parità di nodi $n$ il nostro albero risulterà più basso. 

## Procedure ausiliarie

- `muoviAlto()`: ripristina la proprietà di un heap quando un nodo ha una chiave troppo piccola rispetto al padre. 
- `muoviBasso()`: ripristina la proprietà di un heap quando un nodo ha una chiave troppo grande rispetto ai figli. 

La prima costa $O(log_dn)$, la seconda costa $O(dlog_dn)$ 

#pseudocodice

```
procedura muoviAlto(v):
	while(v!=radice(T) and chiave(v)<chiave(padre(v))) do
		scambia di posto v e padre(v) in T
		

procedura muoviBasso(v): 
	repeat
		sia u il figlio di v con la minima chiave(u), se esiste 
		if(v non ha figli o chiave(v)<=chiave(u)) break
		scambia di posto v e u in T

```

La procedura `findMin()` ha costo $T(n) = O(1)$ questo perché il minimo si trova sempre nella radice, dunque basta restituire quell'elemento. 

### Insert
`insert(elem e, chiave k)` è la procedura che permette l'inserimento all'interno di un d-heap. 
Questa procedura prevede due fasi: 
1. **Inserimento strutturale**: inseriamo il nuovo nodo nella prima posizione libera, mantenendo la proprietà di struttura. ù
2. **Ripristino dell'ordinamento**: eseguiamo `muoviAlto` sul nuovo nodo, se necessario. 
Il costo dell'operazione è: 
$$T(n)=O(log_dn)$$
perché `muoviAlto` percorre al massimo l'altezza dell'albero. 

### Delete 
La cancellazione utilizza una strategia simile: 
1. individuiamo il nodo da eliminare (per `delete(e)` abbiamo già il riferimento diretto). 
2. Lo sostituiamo con l'ultimo nodo dell'heap 
3. Rimuoviamo l'ultima posizione, mantenendo la proprietà della struttura. 
4. Ripristiniamo la proprietà di ordinamento con `muoviAlto` oppure `muoviBasso`, a seconda della situazione. 
Per `deleteMin` il procedimento parte dalla radice, che contiene il minimo. 
Il costo è $O(nlog_dn)$ nel caso generale.

### DecreaseKey
Questa operazione diminuisce la chiave di un nodo già presente nell'heap. 
Questa operazione può violare la proprietà **rispetto al padre**, violando la proprietà del min-heap. 
Per ripristinarla, utilizziamo `muoviAlto`, facendo risalire il nodo finché necessario. 
Il costo di questa operazione è:
$$T(n)=O(log_dn)$$
### IncreaseKey
Questa operazione aumenta la chiave di un nodo già presente nell'albero, questo potrebbe non far rispettare la proprietà del min-heap rispetto ai figli. 
Per ripristinare la proprietà del min-heap utilizziamo `muoviBasso`, facendo scendere il nodo. 
$$T(n)=O(dlog_dn)$$
### Merge
Questa operazione ci permette di unire due code con priorità `c1` e `c2`
Abbiamo due strategie: 
1. Costruire un nuovo heap da zero contenente tutti gli elementi 
2. Inserire ripetutamente gli elementi della coda più piccola in quella più grande. 

**Esempio**: 
Se abbiamo una coda con molti elementi e un'altra con pochi, la seconda strategia è più efficiente, indichiamo: 
- $k = min(|c1|, |c2|)$ 
- $n = |c1| + |c2|$
Effettuiamo $k$ inserimenti, ciascuno con costo $O(logn)$
Quindi:
$$T(n)=O(klogn)$$

La prima strategia, invece costruisce un heap da zero con costo $\Theta(n)$, per $d$ costante. 
La seconda conviene quando: 
$$klogn=o(n)$$
ovvero: 
$$k = o(\frac{n}{logn})$$
Se le due code hanno circa lo stesso numero di elementi, a quel punto è più conveniente utilizzare il primo metodo. 
Se le due code hanno dimensioni simili, k è circa $n/2$. Quindi gli inserimenti ripetuti costano: 
$$O(\frac{n}{2}logn)=O(nlogn)$$
Mentre costruire da zero costa:
$$\Theta(n)$$
Quindi la prima strategia è asintoticamente più efficiente. 

---
# Heap binomiali
Abbiamo concluso la parte sui d-heap. Ora iniziamo una nuova struttura dati: **gli heap binomiali.**
Prima di studiarne le operazioni dobbiamo capire che cosa sono.

#definizione
## Definizione Heap Binomiali
Un albero binomiale $B_i$ è definito ricorsivamente: 
- $B_0$ è formato da un unico nodo
- $B_{i+1}$ di ottiene fondendo due alberi $B_i$, ponendo la radice di uno come figlia dell'altro. 

Sapendo che $B_0$ contiene un solo nodo, possiamo dedurre che $B_1$ sarà l'unione di due alberi $B_0$ e dunque avrà 2 nodi. L'albero $B_2$ si ottiene fondendo due alberi $B_1$, dunque avrà 4 nodi, di conseguenza un albero $B_4$ avrà 16 nodi.
Da questo possiamo ricavare la formula generale: 
$$|B_i|=2^i$$
## Proprietà strutturali
>Un albero binomiale $B_h$ gode delle seguenti proprietà: 

- Numero di nodi: $(|B_h|):n=2^h$
- Grado della radice: $D(n) = log_2n$
- Altezza: $H(n)=h=log_2n$
- Figli della radice: i sottoalberi radicati della radice di $B_h$ sono $B_0, B_1, B_2, \dots$

## Definizione di Heap Binomiale
Un heap binomiale è una foresta di alberi binomiali che gode delle seguenti proprietà: 
- **Unicità**: per ogni intero $i\geq0$, esiste al più un $B_i$ nella foresta. 
- **Contenuto informativo:** ogni nodo v contiene un elemento *elem(v)* ed una chiave *chiave(v)* presa da un dominio totalmente ordinato 
- **Ordinamento a heap:** chiave(v) $\geq$ chiave(parent(v)) per ogni nodo v diverso da una delle radici. 

## Proprietà topologiche
Il numero di alberi binomiali presenti in un heap **dipende dalla rappresentazione binaria del numero di nodi**. 
**Esempio:**
$$13 = 8+4+1 = 2^3+2^2+2^0$$
Quindi: 
$$13=1101_2$$
L'heap binomiale con 13 nodi contiene: 
$$B_0, B_2, B_3$$
Quindi se un albero binomiale ha 11 nodi, allora: 
$$11_{10}=8+2+1 = 2^3+2^1+2^0$$
Quindi l'heap binomiale con 11 nodi contiene: 
$$B_0, B_1, B_3$$
Un'altra conseguenza importante è che **un heap binomiale con $n$ nodi contiene al massimo $\lceil log_2n \rceil$ alberi binomiali.** 

### Rappresentazione collegata e ristrutturazione
La procedura ausiliaria `ristruttura` è utile per ripristinare la proprietà di unicità dell'heap binomiale 

#pseudocodice 
```
procedura ristruttura(): 
	i = 0
	while(esistono ancora due Bi) do
		si fondono i due Bi per formare un albero Bi+1, ponendo la radice con
		
		chiave più piccola come genitore della radice con chiave più grande
		i+=1
```

$T(n)=lineare \ nel \ numero \ di \ alberi \ binomiali \ in \ input$
Ogni fusione diminuisce di uno il numero di alberi binomiali in input. 

# Realizzazione di una coda con priorità usando Heap Binomiali

### Step 1

```
classe HeapBinomiale implementa CodaconPriorità: 
dati: 
	una foresta H con n nodi, ciascuno contenente un elemento di tipo elem e una
	chiave di tipo chiave presa da un universo totalmente ordinato
	
operazioni: 
	findMin()->elem
		scorre le radici in H e restituisce l'elemento a chiave minima
		
	insert(elem e, chiave k)
		aggiunge ad H un nuovo B0 con dati e e k. Ripristina poi 
		le proprietà di
		unicità in H mediante fusioni successive dei doppioni Bi. 
```

### Step 2
```
deleteMin(): 
	Trova l'albero Th con radice a chiave minima. Togliendo la radice a Th, esso 
	si spezza in h alberi binomiali che vengono aggiunti ad H. Ripristina poi la 
	proprietà di unicità in H mediante fusioni successive dei doppioni Bi. 

decreaseKey(elem e, chiave d):
	decrementa di d la chiave nel nodo v contenente l'elemento e. Ripristina poi 
	la proprietà dell'ordinamento a heap spingendo il nodo v verso l'alto
	tramite ripetuti scambi di nodi. 

delete(elem e)
	richiama decreaseKey(e, -infinito) e poi deleteMin() 
```

### Step 3
```
increaseKey(elem e, chiave d)
	richiama delete(e) e poi insert(elem, k+d), dove k è la chiave associata
	all'elemento e. 
Merge(codaPri.c1, CodaPri.c2)-> CodaPri
	unisce gli alberi in c1 e c2 in un nuovo heap binomiale c3. 
	Ripristina poi la proprietà di unicità nell'heap binomiale c3 mediante 
	fusioni successive dei doppioni Bi.  
```

Tutte le operazioni richiedono tempo $T(n)=O(logn)$
Durante l'esecuzione della procedura ristruttura esistono infatti al più tre $B_i$, per ogni $i\geq0$

# Heap di Fibonacci
Gli heap di Fibonacci sono una versione ancora più "rilassata" degli heap binomiali. 
L'idea è rendere alcune operazioni più efficienti, rimandando parte del lavoro di organizzazione a un momento successivo. 
Partiamo dal confronto: 
1. **Heap binomiale**: rispetta la proprietà di unicità degli alberi $B_i$.
2. **Heap binomiale rilassato**: elimina la proprietà di unicità e adotta un comportamento più pigro durante `insert`. 
3. **Heap di Fibonacci**: indebolisce ulteriormente la proprietà di struttura degli alberi binomiali, che non devono più essere necessariamente alberi binomiali. 

## Analisi ammortizzata
Introduciamo il concetto di **Costo ammortizzato**. 
Il costo ammortizzato di un'operazione è il costo medio rispetto a una sequenza qualsiasi di operazioni. Può succedere che una singola operazione sia costosa, ma che il costo complessivo di tutta la sequenza rimanga contenuto. 