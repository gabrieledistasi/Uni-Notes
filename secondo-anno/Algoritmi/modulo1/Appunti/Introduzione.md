
## I numeri di Fibonacci
Il problema di FIbonacci tratta questa domanda:

>"**Quanto velocemente si espanderebbe una popolazione di conigli sotto appropriate condizioni?"**

Supponiamo di partire con una sola coppia di conigli, quante coppie si avrebbero nell'anno n?
Le regole sono che **ogni coppia di conigli concepisce due coniglietti di sesso diverso** i quali formeranno le nuove coppie. 
La gestazione dura un anno. 
I conigli cominciano a riprodursi soltanto al secondo anno dopo la nascita. 
I conigli sono immortali. 

Nell'anno n ci saranno dunque tutte le coppie dell'anno precedente e una coppia per ogni coppia presente due anni prima. 
Indicando con $F_n$ il numero di coppie dell'anno n, abbiamo la seguente relazione di ricorrenza: 
$$
\left\{ \begin{array}{rcrcr} F_{n-1} & + & F_{n-2} & se & n \geq3 \\ 1 & se & n =1, 2 \end{array}\right.
$$
**Come calcoliamo $F_n$?** 
Come prima cosa, possiamo pensare di calcolare $F_n$ attraverso la seguente funzione matematica: 
$$
 F_n = \frac{1}{\sqrt5} \cdot (\phi^n-\widehat{\phi}^n)
$$
Dove $\phi \approx = 1.1618...$ e $\widehat{\phi}\approx-0.618...$

# Algoritmo 1


```
algoritmo fibonacci1(intero n) -> intero
	return 1/sqrt(5)(phi^n-phi^^n)
```

Il problema di questo algoritmo è scegliere un giusto compromesso per quanto riguarda l'arrotondamento. 

# Algoritmo 2
Un altro modo è quello di utilizzare la ricorsione: 

```
algoritmo fibonacci2(intero n) -> intero
if (n<=2) then return 1
else return fibonacci2(n-1)+fibonacci2(n-2)
```

Ogni riga di questo codice ovviamente costa un'unità di tempo al calcolatore. 
Vediamo quante righe vengono eseguite: 
- Se n <= 2, una sola linea di codice
- Se n = 3, quattro linee di codice , due per la chiamata fibonacci(3), una per la chiamata fibonacci(2) e uno per la chiamata fibonacci(1)

# Relazione di ricorrenza 

Sia T(N) il numero di linee di codice eseguite, nel caso peggiore, dall'algoritmo su input n. 
In ogni chiamata si eseguono due linee di codice, oltre a quelle eseguite nelle chiamate ricorsive: 
$$
T(n)=2+T(n-1)+T(n-1) \rightarrow T(1)=T(2)=1
$$
Il tempo richiesto da un algoritmo ricorsivo è pari al tempo speso all'interno della chiamata più il tempo nelle chiamate ricorsive. 


### Lemma 1
*Il numero di foglie dell'albero della ricorsione  di fibonacci2(n) è pari a $F_n$* 

### Lemma 2
Il numero di nodi interni di un albero in cui ogni nodo interno ha due figli è pari al numero di foglie -1. 

In totale, le linee di codice eseguite sono: 
$$
F_n+2(F_{n-1})
$$
Ma **fibonacci2 è un algoritmo lento:**
$$
T(n) \approx F_n \approx \phi^n
$$
# Algoritmo 3
Fibonacci2 è lento perché ricalcola continuamente la soluzione dello stesso sottoproblema. 
Idea: memorizzare in un array le soluzioni dei sottoproblemi?

```
algoritmo fibonacci3(intero n) --> intero
	sia Fib un array di n interi 
	Fib[1] <-- 1; Fib[2] <-- 1
	
	for i = 3 to n do: 
		Fib[i] = Fib[i-1] + Fib[i-2]
	
	return Fib[n]
```

## Calcoliamo il tempo di esecuzione
Linee 1, 2 e 5 vengono eseguite una sola volta. 
Linea 3 viene eseguita <= n volte.
Linea 4 viene eseguita <= n volte.

T(n): numero di linee di codice mandate in esecuzione da fibonacci3. 
T(n) <= n + n + 3 = 2n + 3

Questo algoritmo, rispetto al precedente, impiega tempo lineare O(n) invece che esponenziale in n  come fibonacci2. 

Il tempo di esecuzione non è la sola risorsa che ci interessa, anche la memoria richiesta può essere fondamentale, infatti, se un algoritmo è lento basta aspettare, ma se un algoritmo richiede una memoria maggiore di quella a disposizione, non otterremo mai la soluzione. 

# Algoritmo 4
Rispetto a Fibonacci3 questo algoritmo non salva in un array tutti i numeri fino ad n, si limita a tenere gli ultimi due: 

```
algoritmo fibonacci4(int n) --> intero
a <-- 1, b <--1
for i=3 to n do: 

	c = a+b
	a = b
	b = c
	
return c
```

T(n) <= 4n+2

## Notazione asintotica
L'idea è di valutare T(n) in maniera qualitativa, ovvero, vogliamo vedere come T(n) cresce al crescere di n. In soldoni, si ignorano le costanti moltiplicative e i termini di ordine inferiore. 

Diciamo che $f(n) = O(g(n)) se f(n) \le c\cdot g(n)$ per qualche costante c ed n abbastanza grande. 
Quindi possiamo sostituire: 
- $T(n)=3F_n \ con T(n)=O(F_n)$
- $T(n)=2n \ e \ T(n)=4n \ con \ T(n)=O(n)$
- $T(n) = F_n con T(n) = O(\phi(n))$


>**Siamo sicuri di aver fatto il meglio possibile?**

### È possibile mostrare per induzione la seguente proprietà di matrici
$$
\begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} ^n = \begin{pmatrix} F_{+1} & F_n \\ F_n & F_{n-1} \end{pmatrix}
$$
$$
(AB)_{i,j} = \sum^n_{k=1}a_{i,k}b_{k, j} 
$$
# Algoritmo 5
```
algoritmo fibonacci5(intero n) --> intero
	M <-- (1 0)
		  (0 1)
	
	for i = 1 to n-1 do 
	M <-- M*(1 1)
			(1 0)
			
	return M[0][0]
```

Anche questo algoritmo è in O(n), ma cosa ci abbiamo guadagnato allora?

Possiamo calcolare l'n-sima potenza elevando al quadrato la $\lfloor \frac{n}{2} \rfloor$. 
Se n è dispari eseguiamo un'ulteriore moltiplicazione. 

# Algoritmo 6
```
algoritmo fibonacci6(intero n) --> intero
	A <-- (1, 1)
	  (1, 0)
	M <-- potenzaDiMatrice(A, n-1)
	return M[0]

funzione potenzaDiMatrice(matrice A, intero k) --> matrice
	if k = 0 return (1 0)
					(0 1)

	else M <-- potenzaDiMatrice(A, ⌊k/2⌋)
		M <-- M * M

	if k è dispari then M <-- M * A
return M
```

Il tempo di esecuzione è speso nella procedura  *PotenzaDiMatrice*
- All'interno della procedura si spende tempo costante 
- Si esegue una chiamata ricorsiva con input ⌊n/2⌋
- L'equazione di ricorrenza è pertanto: 
$$
T(n) \leq T(\lfloor \frac{n}{2} \rfloor)+c
$$
e dunque: 
$$
T(n) <= c + \leq T(\lfloor \frac{n}{2}\rfloor) \\
\\
\leq 2c + T(\lfloor \frac{n}{4}\rfloor \\
\\
\leq 3c + T(\lfloor \frac{n}{8}\rfloor
$$
Per i otteniamo: $\lfloor log_2 n \rfloor$
E dunque l'algoritmo ha costo: 
$$
T(n) \leq c \cdot \lfloor log_2 n \rfloorù + T(1) = O(log_2n)
$$

## Quanta memoria usa un algoritmo?
**Algoritmo non ricorsivo:** Dipende dalla memoria allocata; es. variabili, array, matrici, strutture dati ecc. 

**Algoritmo ricorsivo:** dipende dalla memoria allocata ad ogni chiamata e dal numero di chiamate che sono contemporaneamente attive. 

**Nota:** Una chiamata usa sempre almeno memoria costante, anche se non utilizza variabili ausiliarie. 
Analizzare l'albero della ricorsione aiuta a capire quali chiamate possono essere attive nello stesso momento. 


