![[download 1 1.svg]]>Dato un insieme S di n oggetti preso da un dominio completamente disordinato, ordinare S

Nel problema dell'ordinamento abbiamo in input una sequenza di *n* numeri $<a_1, a_2, \dots,a_n>$
e in output una permutazione della sequenza di input tale che $a_1 \leq a_2 \leq a_3 \leq \dots \leq a_n$

Per ordinare una sequenza di numeri partiamo da algoritmi che operano in tempo quadratico

# Ordinamento in tempo quadratico

## Selection Sort
Questo algoritmo estende l'ordinamento da k a k+1 elementi, scegliendo il minimo degli n-k elementi non ancora ordinati e mettendolo in posizione k+1. 

#pseudocodice
```
SelectionSort(A)
1.	for k=0 to n-2 do
2.		m = k+1
3.		for j=k+2 to n do
4.			if(A[j]<A[m]) then m = j
5.		scambia A[m] con A[k+1]
```

- Al passo k, A[1], ...,A[k] sono già ordinati
- Linee 2-4: ricerca del minimo fra gli elementi A[k+1],...,A[n]
- m è l'indice dell'array in cui si trova il minimo.
- Il minimo è messo in posizione k+1

È facile convincersi che l'algoritmo mantiene le seguenti invarianti: dopo la generica fase k (k=0,..., n-2) abbiamo che: 
- i primi k+1 elementi sono ordinati e 
- sono i k+1 elementi più piccoli dell'array

### Analisi complessità temporale
T(n) = numero di operazioni elementari sul modello RAM a costi uniformi eseguite dall'algoritmo nel caso peggiore su istanze di dimensione n

In effetti le righe 3-4-5 sono eseguite al più *n* volte per ogni ciclo esterno mentre il ciclo esterno viene eseguito *n* volte. 
Ogni linea di codice costa tempo O(1)

$$
T(n) \leq 5n^2O(1) = \Theta(n^2) \rightarrow T(n) = \Theta(n^2)
$$
Per il lowerbound conto solo i confronti fra elementi.
Righe 3 e 4 hanno n-k-1 confronti.

$$
T(n) \geq \sum_{k=0}^{n-2}(n-k-1)=\sum_{k-1}^{n-1}k=\frac{n(n-1)}{2} = \Theta(n^2) \\
\\
T(n) = \Omega(n^2) \rightarrow T(n) = \Theta(n^2)
$$

## Insertion sort
Approccio incrementale: estende l'ordinamento da k a k+1 elementi posizionando l'elemento k-1esimo nella posizione corretta rispetto ai primi k elementi.
#pseudocodice
```
InsertionSort(A): 

for k=2 to n do
	while(k>1)
		if A[i]>A[i+1]
			A[i], A[i+1] = A[i+1], A[i]
			decrementa k
		

```

Complessità $T(n)=\Theta(n^2)$ 
## Bubble sort 
Approccio incrementale: esegue n-1 scansioni. Ad ogni scansione guarda coppie di elementi adiacenti e li scambia se non sono nell'ordine corretto. 
```
BubbleSort(arr)
    for k = 1 to n-2 do 
        for j = 1 to n-1-k do 
            if(arr[j] > arr[j+1]) then
                scambia arr[j] con arr[j+1]


```

Complessità $T(n) = \Theta(n^2)$ 
# Ordinare in tempo minore che quadratico

## MergeSort
Usa la tecnica del divide et impera 
- Divide: divide l'array a metà 
- Risolve i due sottoproblemi ricorsivamente 
- Impera: fondi le due sottosequenze ordinate 
#pseudocodice
```
MergeSort(A, i, f)
if i < f then 
	m = floor((i+f))/2
	MergeSort(A, i, m)
	MergeSort(A, m+1, f)
	Merge(A, i, m, f)
	
```
La funzione merge fonde A[i:m] e A[m+1:f] output in A[i:f]. 
Notazione: dato un array A e due indici x < y, denotiamo con A[x:y] la porzione di A costituita da A[x], A[x+1], ...,A[y]. 

### Procedura del merge
- Due array ordinati A e B possono essere fusi rapidamente: 
	- Estrai ripetutamente il minimo di A e B e copialo nell'array di output, finché A oppure B non diventa vuoto
	- Copia gli elementi dell'array non vuoto alla fine dell'array di output
#pseudocodice
```
Merge(A, i, f1, f2)
1. Sia X un array ausiliario di lunghezza f2-i1+1
2. i = 1; k1 = i1
3. k2 = f1+1
4. while (k1 <= f1 e k2 <= f2) do 
5.	   if(A[k1] <= A[k2])
6.		   incrementa i e k 
7.		else X[i]=A[k2]
8.			incrementa i e k2
9.	if(k1<=f1) then copia A[k1:f1] alla fine di X
10.	else copia A[k2:f2] alla fine di X
11.	Copia X in A[i1:f2]
```

### Lemma
La procedura del merge fonde due sequenze ordinate di lunghezze $n1$ e $n2$ in un'unica sequenza in tempo $\Theta(n_1+n_2)$ 

#### Dim. 
Ogni confronto consuma un elemento di una delle due sequenze. Ogni posizione di X è riempita in tempo costante. Il numero totale di elementi è n1+n2. Anche la linea 12 costa $\Theta(n_1+n_2) \ \square$ 

### È corretto?
Si, le due chiamate ricorsive ordinano le due metà e il merge le fonde correttamente. 
### Complessità? 
La complessità del mergesort è data da: 
$$T(n) = 2 T(\frac{n}{2}) + O(n)$$
Applichiamo il teorema master: 
a = 2
b = 2

confronto $n^{log_22} \ vs \ n \rightarrow \Theta(n)$ dunque per il secondo caso del teorema master $\Theta(nlogn)$

## Quanta memoria (ausiliaria) usiamo?
Ogni chiamata ricorsiva sta usando memoria ausiliara costante per ogni chiamata ricorsiva, queste chiamate ricorsive utilizzano O(logn) memoria ausiliara, da sommare a O(n), dove n è la memoria necessaria per l'ultimo merge. 
Il merge sort non ordina *in loco*, questo è un difetto del mergesort. 

# QuickSort
Usa la tecnica del divide et impera: 
1. Divide:  scegli un elemento x della sequenza e partiziona la sequenza in elementi $\leq$ x ed elementi > x
2. Risolvi i due sottoproblemi ricorsivamente 
3. Impera: restituisci la concatenazione delle due sottosequenze ordinate 

## Partizione 
- Scegli il perno
- scorri l'array in parallelo da sinistra verso destra e da destra verso sinistra
	- da sinistra verso destra, ci si ferma su un elemento maggiore del perno
	- da destra verso sinistra, ci si ferma su un elemento maggiore del perno
- Scambia gli elementi e riprende la scansione 
- Fermati quando i due indici si sono incrociati

#pseudocodice
```
Partition(A, i, f)
x = A[i]
inf = i
sup = f+1
while(true) do
	do(inf = inf+1) while (inf<=f e A[inf]<=x)
	do(sup=sup-1) while (A[sup]>x)
	if(inf<sup) then scambia A[inf] e A[sup]
	else break 
Scambia A[i] e A[sup]
return sup
```
Partiziona A[i:f] rispetto ad A[i]
Tempo di esecuzione: **O(n)**
Proprietà invariante: In ogni istante, gli elementi A[i], ..., A[inf-1] sono <= del perno, mentre gli elementi A[sup+1], ..., A[f] sono > del perno. 

#pseudocodice
```
QuickSort(A, i, f)
if(i < f) then 
	m = Partition(A, i, f)
	QuickSort(A, i, m-1)
	QuickSort(A, m+1, f)
	
```

### Corretto?
Si, dopo partition A[i:m-1] contiene elem <= del perno, A[m] il perno, A[m+1:f] elementi > del perno 
Le chiamate ricorsive ordinano A[i:f]

### Complessità?
Ogni invocazione di Partition posizione almeno un elemento in modo corretto (il perno) 
Quindi dopo n invocazioni di Partition, ognuna di costo O(n) ho il vettore ordinato. Il costo complessivo è quindi O(n^2). 
Il caso peggiore si verifica quando il perno scelto ad ogni passo è il minimo o il massimo degli elementi nell'array. 
La complessità in questo caso è: 
$$T(n)=T(n-1)+T(0)+O(n) \\ =T(n-1)+O(1)+O(n) \\ =T(n-1)+O(n) \\= T(n) = O(n^2)$$
Complessità nel caso migliore?
Caso migliore O(nlogn), partizionamento sempre bilanciato

**Caso medio**
Si può dimostrare che: 

**Teorema:**
Assumendo la distribuzione di probabilità uniforme sulle istanze, l'algoritmo quickSort ha complessità nel caso medio di O(nlogn)

### Intuizioni sul caso medio
- Problema: la partizione può essere sbilanciata 
- La probabilità che ad ogni passo si presenti la partizione peggiore è molto bassa 
- Per partizioni che non sono "troppo sbilanciate", l'algoritmo è veloce 
- **domanda:** Qual è la velocità dell'algoritmo supponendo che l'algoritmo di parizionamento produca sempre una partizione proporzionale 9-a-1?
- E se la partizione fosse sempre proporzionale a 99-a-1?
- Nota: sembrano partizioni piuttosto sbilanciate

Se le istanze non sono equiparabili?
versione randomizzata: scegli il perno x a caso fra gli elementi da ordinare 

**Teorema**
L'algoritmo quickSort randomizzato ordina in loco un array di lunghezza n in tempo O(n^2) nel caso peggiore e O(nlogn) tempo atteso


# HeapSort
L'HeapSort utilizza lo stesso approccio incrementale del selectionSort, selezionando gli elementi dal più grande al più piccolo. 
L'idea dell'HeapSort è quella di cambiare, rispetto al SelectionSort, il modo in cui cerchiamo il massimo. 
Invece di cercare ogni volta il massimo partendo da zero, utilizziamo una struttura dati chiamata **heap** che è progettata per estrarre velocemente il massimo: **Heap ha costo O(logn)**. 
Il punto fondamentale in questo caso è che non cambiamo l'algoritmo, ma cambiamo la struttura dati per renderlo più efficiente. 

*Tipi di dato:* 
Specifica una collezione di oggetti e delle operazioni di interesse su tale collezione 
*Struttura dati:*
Organizzazione dei dati che permette di memorizzare la collezione e supportare le operazioni di un tipo di dato usando meno risorse di calcolo possibile. 

---
# Alberi 
Un albero è una struttura dati composta da **nodi** collegati tra loro tramite **archi**. A differenza di un array, i dati non sono organizzati semplicemente in una sequenza, ma hanno una gerarchia 

## Alcune definizioni
- **Radice**: è il nodo da cui parte l'albero, questo nodo **non ha un padre.**
- **Padre e figlio**: se una arco collega due nodi $u, v$ scendendo dall'alto verso il basso, u è il padre di v e v è un figlio di u. 
- **Fratelli**: Sono nodi che hanno lo stesso padre, questi vengono detti fratelli.
- **Nodo interno e foglia**: Un nodo interno ha almeno un figlio 
- **Arco**: un arco è il collegamento tra due nodi, viene indicato come (u,v)

## Livelli e altezza dell'albero
- *livello 0:* contiene la radice
- *livello 1:* contiene i figli della radice
- *livello 2:* contiene i figli dei nodi del livello 1 
- ...
- *livello n:* contiene i figli dei nodi del livello n-1

Per **altezza** di un albero si intende il livello massimo raggiunto da un nodo. 

## Alberi d-ari e alberi binari
Un albero **d-ario** è un albero in cui ogni nodo ha al massimo *d-figli* 
Ad esempio: 
- d = 2, albero binario con al massimo due figli per nodo
- d = 3, albero ternario con al massimo tre figli per nodo
- d = 4, albero con al massimo quattro figli per nodo

Non è obbligatorio per un nodo avere d figli: un nodo può averne meno di d ma mai di più. 

### Albero binario completo
Un albero binario si dice completo quando: 
- Tutti i nodi interni hanno esattamente due figli
- Tutte le foglie si trovano allo stesso livello

Tutti gli alberi a cui manca **una delle due**, o tutt'e due le proprietà, allora è detto **albero binario non completo.**

# Che cos'è un Heap?
Un heap è un albero binario radicato che soddisfa tre proprietà: 
Le prime due riguardano la struttura e la memorizzazione; la terza riguarda l'ordinamento dei valori. 
## Proprietà 1 
L'heap deve essere un albero binario: 
- completo fino al penultimo livello 
- con le foglie dell'ultimo livello tutte compattate a sinistra ![[albero_binario_heap.svg]]
In questo esempio, l'ultimo livello contiene D, E e F nelle prime tre posizioni disponibili da sinistra. La posizione successiva è vuota: questo è consentito. 
Questa proprietà ci serve perché garantisce che l'albero abbia un'altezza contenuta, pari a $O(logn)$, e che possa essere rappresentato comodamente in un array, come vedremo nelle slide successive. 

## Proprietà 2
Ogni nodo contiene esattamente un elemento, indicato come $chiave(v)$. 
Per esempio, un nodo può contenere il numero 16, un altro numero 14 e un altro ancora il numero 10. 
La chiave è semplicemente il valore memorizzato nel nodo. 
Questa proprietà ci dice come vengono collocati i dati nell'albero, ma non dice ancora nulla sull'ordine dei valori. È proprio la terza proprietà a stabilirlo. 

## Proprietà 3
Questa è la proprietà decisiva dell'heap: 
$$chiave(padre(v)) \geq chiave(v)$$
Per ogni nodo $v$ diverso della radice. 
**Il valore di ogni padre deve essere maggiore o uguale al valore di ciascuno dei suoi figli**. 
Questa struttura si chiama **max-heap**, perché il valore massimo si trova sempre nella radice. 

In un'heap non è necessario che i valori siano ordinati da sinistra a destra. È sufficiente che ogni padre sia maggiore o uguale ai propri figli. 

Il costo per trovare il massimo: 
$$
T(n) = O(1)
$$
**Perché?**
Non dobbiamo cercare in tutto l'albero, sappiamo già dove si trova il massimo. 

### Proprietà degli heap 
**L'altezza è log(n)**
Questa è la proprietà più importante per capire la complessità di `fixheap` e HeapSort. 
Consideriamo un albero binario con livelli numerati a partire da 0. 
- livello 0 massimo 1 nodo
- livello 1 massimo 2 nodi 
- livello 2 massimo 4 nodi
- livello 3 massimo 8 nodi
In generale, il livello i può contenere al massimo $2^i$ nodi. 
Se l'altezza è h, un albero completo fino al livello h-1 contiene: 
$$1+2+4+\dots+2^{h-1}=2^h-1$$
Per un heap di n nodi ricaviamo dalla struttura dell'albero: 
$$n\geq 2^k$$
Da cui: 
$$h \leq log_2n$$ Quindi: 
$$
h = O(logn) 
$$
Il significato intuitivo è che, quando il numero di nodi raddoppia, l'altezza cresce soltanto di circa un livello. 
Questo spiega perché possiamo scendere lungo l'albero, confrontando e spostando gli elementi, in tempo logaritmico. 

### Proprietà 2 - L'heap si rappresenta come un array di dimensione n
Normalmente, un albero potrebbe essere rappresentato con nodi collegati tramite puntatori ai figli. 
Ma un heap ha una struttura più particolare: i livelli sono pieni fino al penultimo e l'ultimo è compatto a sinistra. 
Questo ci permette di memorizzare i valori direttamente in un array, seguendo l'ordine per livelli: prima la radice, poi i suoi figli, poi i nodi del livello successivo, da sinistra verso destra. 
Per un heap di n elementi basta quindi un array di dimensione n, senza bisogno di creare un oggetto separato per ogni nodo o memorizzare i collegamenti tra padre e figli. 
Questo è particolarmente utile per HeapSort, perché permette di riutilizzare lo stesso array da ordinare. 

## Come passiamo da albero ad array?
Prendiamo questo Heap: 
![[download 1.svg]]
L'array risultante è: [37, 22, 31, 13, 15, 25, 14], per passare dall'albero all'array guardiamo quindi la radice, questo sarà il primo elemento contenuto nell'array. Scendendo al livello 1 e, leggendo da sinistra a destra, otteniamo il secondo valore, in questo caso 22, e spostandoci a destra abbiamo 31 sullo stesso livello, il procedimento continua fino a quando non abbiamo inserito tutti i nodi. 

### Tre formule da ricordare
Per un nodo che si trova nella posizione i: 
$$
sin(i) = 2i
$$
$$des(i)=2i+1$$
$$
padre(i) = \lfloor \frac{i}{2} \rfloor
$$
`sin(i)` restituisce l'indice del figlio sinistro.
`des(i)` restituisce l'indice del figlio destro. 
`padre(i)` restituisce l'indice del padre. 

## FixHeap

Ricordiamo la proprietà di MaxHeap: 
$$chiave(padre(v))>padre(v)$$
Ogni padre dovrà essere maggiore o uguale ai suoi figli. 

![[download 1.svg|613]]
Vedendo quest'albero notiamo che la radice è < rispetto ai figli, tuttavia, i sottoalberi sono già heap validi, dobbiamo quindi risolvere questo problema utilizzando `fixheap`.
L'idea del `FixHeap` è quella di **far scendere il valore sbagliato**.
La procedura funziona così: 
- Guarda i figli nel nodo da sistemare.
- Individua il figlio con la chiave maggiore.
- Se il figlio maggiore è più grande del nodo corrente, scambia i due valori. 
- Continua sul figlio su cui è finito il valore più piccolo. 

Quindi facciamo scendere nell'albero un valore, fin quando la proprietà di ordinamento non viene ripristinata. 
![[download 2.svg|700]]
Trasformiamo da albero ad array: $[4, 16, 10, 14, 7, 9, 3, 2, 8, 1]$  
Confrontiamo la radice con i suoi figli: 
- figlio sinistro 16
- figlio destro 10

Scegliamo il figlio con la chiave massima: 
	$max(16, 10)=16$
	
Ora confrontiamo la radice con il figlio: 
	$4 < 16$
	
Dobbiamo scambiarli, otteniamo come risultato: 
	$[16, 4, 10, 14, 7, 9, 3, 2, 8, 1]$

Ora possiamo notare che il nodo contenente 4 ha come figli $14 \ e \ 7$, maggiori rispetto a lui. Prendiamo i due figli e prendiamo il massimo, 14 in questo caso, il vettore risultante sarà: 

$A = [16, 14, 10, 4, 7, 9, 3, 2, 8, 1]$ 

Il valore 4 si trova, adesso in posizione 4, i suoi figli sono 2 e 8, quindi effettuiamo nuovamente il confronto tra i figli $max(8, 2)=8$ e dunque il vettore risultante a questo punto sarà 

$A = [16, 14, 10, 8, 7, 9, 3, 2, 4, 1]$ 

Ora il valore 4 è sceso nella posizione 9, questa posizione non ha figli in quanto il figlio sinistro si troverebbe in posizione *18* e il figlio destro in posizione *19*, ma l'heap è lungo 10. 
Dunque non ci sono altri confronti da fare, ora ogni padre è $\geq$ dei propri figli, in questa maniera abbiamo ripristinato la proprietà del max-heap. 

#pseudocodice
```
fixheap(i, A)
	s = sin(i)
	d = des(i)
	if (s <= heapsize[A] e A[s]>A[i]) then
		massimo = s
	else
		massimo = d
	
	if (d<=heapsize[A] e A[d]>A[massimo])
	then massimo = d
	
	if(massimo!=i)
		then scambia A[i] e A[massimo]
			fixheap(massimo, A)
```

Perché FixHeap costa $O(logn)?$ 
La procedura visita al massimo un nodo per livello e, a ogni scambio, scende di un livello. 
Ogni livello richiede un numero costante di confronti e operazioni, quindi: 
$$T(n)=O(logn)$$ Nel caso migliore, se il nodo è maggiore o uguale ai figli, la procedura si ferma subito e costa $O(1)$ . 


# L'idea di estrazione del massimo

Consideriamo questo albero:
![[download 2.svg|700]]
Ricordiamo che in un `maxHeap` il massimo si trova sempre nella radice. In quest'albero, vogliamo rimuovere il nodo contenente il valore 16, il problema è che se rimuoviamo questo nodo lasciamo un buco nell'albero e perdiamo la struttura richiesta dall'heap.
Per questo seguiamo tre passaggi: 
- Copiamo nella radice la chiave contenuta nella foglia più a destra dell'ultimo livello 
- Rimuoviamo quella foglia decrementando `HeapSize[A]` 
- Richiamiamo fixHeap sulla radice per ripristinare le proprietà di ordinamento

**Esempio:**
Prendiamo l'array $A = [16, 14, 10, 8, 7, 9, 3, 2, 4, 1]$, la dimensione iniziale è: 
$$heapsize[A]=10$$ Individuiamo il massimo e l'ultima foglia: il massimo è nella radice $A[1]=16$ e l'ultima foglia è $A[10]=1$
Copiamo il valore di 1 nella radice, sostituendo il valore 16, ma ora 1 è troppo piccolo rispetto ai figli della radice. 

### Passo 2 
Riduciamo la dimensione dell'heap: 
$$heapsize[A]=10-1=9$$
L'array ha ancora 10 posizioni, ma la posizione 10 non appartiene più all'heap attivo. Contiene il massimo estratto, cioè 16, che è ora nella sua posizione definitiva per l'ordinamento. 

### Passo 3
Chiamiamo `fixheap(1, A)`, i figli di 1 sono 14 e 10, quindi sostituiremo 14 con 1; 1 scende in posizione 2 e i suoi figli sono 8 e 7; 1 scende in posizione 4 e i suoi figli sono 2, 4, scambiamo 1 e 4; 1 ora si trova in posizione 9, è una foglia adesso. 
La struttura del nuovo array sarà: 
$$A = [14, 8, 10, 4, 7, 9, 3, 2, 1 | 16]$$

Questo procedimento  conserva la struttura dell'heap perché: 
- sostituiamo la radice con l'ultimo elemento
- rimuoviamo logicamente l'ultima foglia riducendo `heapsize[A]`
- la forma dell'albero rimane quella richiesta
- `fixheap` ripristina la proprietà di ordinamento.

## Complessità dell'estrazione del massimo
Analizziamo il costo dell'intera operazione 

| Operazioni                           | Complessità |
| ------------------------------------ | ----------- |
| Copiare l'ultima foglia nella radice | $O(1)$      |
| Decrementare `heapsize`              | $O(1)$      |
| Eseguire `fixHeap` sulla radice      | $O(logn)$   |
La complessità effettiva è quindi: 
$$
T(n) = O(1)+O(1)+O(logn)
$$
Eliminando i termini costanti: 
$$
T(n)=O(logn)
$$
Il motivo è che `fixheap` può scendere al massimo fino a una foglia, e l'altezza dell'heap è $O(logn)$.

# Heapify
Fin'ora abbiamo visto `fixHeap` che ripristina la proprietà di ordinamento quando un nodo è fuori posto, assumendo che i suoi sottoalberi siano già heap. 
Ma cosa succede se partiamo da un array qualsiasi, nel quale non abbiamo ancora costruito un heap?
Per esempio: 
$$A = [4, 1, 3, 2, 16, 9, 10]$$
Questo array non è un max-heap perché la radice contiene 4, mentre uno dei suoi figli contiene 16. Ci serve quindi una procedura che trasformi l'intero albero in un heap valido. Questa procedura è `heapify` 

## L'idea: costruire dal basso verso l'alto 
Il ragionamento è: 
- costruisci un heap nel sottoalbero sinistro
- costruisci un heap nel sottoalbero destro
- chiama `fixHeap` sulla radice 

#pseudocodice 
```
heapify(heap H)
	if(H non è vuoto) then 
	heapify(sottoalbero sinistro di H)
	heapify(sottoalbero destro di H)
	fixHeap(radice di H, H)
```
La prima chiamata ricorsiva costruisce l'heap nel sottoalbero sinistro.
La seconda chiamata ricorsiva costruisce l'heap nel sottoalbero destro.
La chiamata fixHeap sistema la radice rispetto ai figli. 

**Esempio:**
Partiamo dall'array: 
$$A=[4,1,3,2,16,9,10,14,8,7] $$
Applicando `heapify`, i sottoalberi vengono costruiti prima dei nodi che li contengono. Il risultato finale è: 
$$A = [16, 14, 10, 8, 7, 9, 3, 2, 4, 1]$$
Questo array rappresenta un max-heap perché ogni padre è $\geq$ ai propri figli. 

## Perché Heapify costa $O(n)$?
Potremmo pensare che con n nodi, chiamiamo fixheap (costo $O(logn)$) per ogni nodo, il costo sia $O(logn)$, tuttavia **non tutti i nodi possono scendere di $logn$ livelli**. 
- I nodi vicino alla radice possono scendere di n livelli ma sono pochi. 
- I nodi vicino alle foglie sono molti, ma possono scendere solo di pochi livelli. 
- Le foglie non devono essere sistemate, sono già heap. 

Indichiamo con $T(n)$ il costo di `heapify`, consideriamo un albero con n' nodi scelto in modo da avere la stessa altezza e una forma completa. La ricorrenza riportata è: 
$$
T(n') = 2T(\frac{n'-1}{2})+O(logn')
$$
E quindi: 
$$T(n') \geq 2T(\frac{n'}{2})+O(logn')$$
Per il teorema master abbiamo: 
$a=2$
$b=2$
$f(n)=O(logn)$, per il costo di `fixheap`

Confrontiamo $f(n)$ con: 
$$n^{log_ba}=n^{log_22}=n$$
$log(n)$ cresce più lentamente di n, dunque il teorema porta a: 
$$
T(n') = \Theta(n') 
$$
## Max-Heap e Min-Heap
Esistono due tipi di Heap, nel Max-Heap vale: 
$$A[padre(i)] \geq A[i]$$
Nel min-Heap vale la relazione opposta: 
$$A[padre(i)] \leq A[i]$$
# Idea di Heapsort
L'algoritmo procede in due fasi: 
1. Costruzione: chiama `heapify(A)` per trasformare l'array in un max-heap
2. Ordinamento: estrae ripetutamente il massimo e lo colloca alla fine della parte ancora da ordinare

#pseudocodice
```
heapsort(A)
heapify(A)
heapsize[A]=n
for i = n down to 2 
	scambia A[1] e A[i]
	heapsize[A] = heapsize[A]-1
	fixheap(1, A)

```
