>Dato un insieme S di n oggetti preso da un dominio completamente disordinato, ordinare S

Nel problema dell'ordinamento abbiamo in input una sequenza di *n* numeri $<a_1, a_2, \dots,a_n>$
e in output una permutazione della sequenza di input tale che $a_1 \leq a_2 \leq a_3 \leq \dots \leq a_n$

Per ordinare una sequenza di numeri partiamo da algoritmi che operano in tempo quadratico

# Ordinamento in tempo quadratico

## Selection Sort
Questo algoritmo estende l'ordinamento da k a k+1 elementi, scegliendo il minimo degli n-k elementi non ancora ordinati e mettendolo in posizione k+1. 

**Pseudocodice**
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

## Bubble sort 
Approccio incrementale: esegue n-1 scansioni. Ad ogni scansione guarda coppie di elementi adiacenti e li scambia se non sono nell'ordine corretto. 

# Ordinare in tempo minore che quadratico

## MergeSort
Usa la tecnica del divide et impera 
- Divide: divide l'array a metà 
- Risolve i due sottoproblemi ricorsivamente 
- Impera: fondi le due sottosequenze ordinate 

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
