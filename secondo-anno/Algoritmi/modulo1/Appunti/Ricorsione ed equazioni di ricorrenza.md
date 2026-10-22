>Analizzare la complessità nel caso medio del primo algoritmo di pesatura Alg1 presentato nella prima lezione. Rispetto alla distribuzione di probabilità su istanze, si assuma che la moneta falsa possa trovarsi in modo equiprobabile in una qualsiasi delle n posizioni.

```
Alg1 (X={x1, ..., Xn})
for i = 2 to n do
	if peso(x1) > peso(x2) then return x1
	if peso(x1) < peso(xi) then return xi
```

$$
\sum_{I \ di \ dim \ n}{Pr(I)}\ {\# Pesate \ I}
$$
$$
\sum_{j=1}^n Pr("moneta \ falsa \ è \ in \ posizione \ j) \# \ numero \ di \ pesate(I) = \frac{1}{n}+\sum_{j=2}^n(j-1)=\\ \frac{1}{n}(1+\sum_{j=1}^nj)=(\frac{1}{n})+(1+(n-1)(\frac{n}{2}))=\frac{1}{n}+\frac{n-1}{2}
$$


## Ricerca di un elemento in una lista non ordinata
Questo algoritmo restituisce la posizione si x (elemento da cercare) in L (array) se presente, -1 se x non è presente nell'array
```
algoritmo RicercaSequenziale(array L, elem x): --> intero
n = lunghezza L
i = 1

for i = 1 to n do
	if (L[i]==x) then return i 
	
return -1
```

Sia T(n) il numero di elementi acceduti su un array di dimensione n
$T_{worst}(n)=O(n) \rightarrow x \notin L$ oppure ultima posizione
$T_{avg}(n)=\frac{(n+1)}{2}$ assumendo che $x \in L$ e che si trovi con la stessa probabilità in una qualsiasi posizione

Sia T(n) il numero di operazioni RAM su un array di dimensione n

$T_{worst}(n)=\Theta(n) \rightarrow x \notin L$ oppure ultima posizione
$T_avg(n) = \Theta(n)$ assumendo che $x \in L$ e che si trovi con la stessa probabilità in una qualsiasi posizione. 

# Algoritmo di ricerca binaria
In questo algoritmo utilizziamo due indici, i e j, che indicano la porzione di L in cui cercare l'elemento x. 
L'algoritmo torna in posizione di x in L, se x c'è, -1 altrimenti. 

```
algoritmo ricercabinaria(array L, elem x, int i, int j)
if(i>j)
	m = floor((i+j)/2)
if (L[m]=x) then return m
if (L[m]>x) then return ricercabinaria(L, x, i, m-1)
	else return ricercabinaria(L, x, m+1, j)
```

$T(n)=T(n/2)+O(1) \longrightarrow T(n)=O(logn)$ 

## Come analizzare gli algoritmi ricorsivi
$T(n)=T(n-1)+T(n-2)+O(1)$

### Equazioni di ricorrenza
La complessità computazionale di un algoritmo ricorsivo può essere espressa in modo naturale attraverso un'equazione di ricorrenza. 
Esempi: 
$$
T(n)=T(\frac{n}{3})+2T(\frac{n}{4})+O(nlogn)\\
\\
T(n) = T(n-1)+O(1)
\\ \\
T(n)=T(n/3)+2T(2n/3)+n
$$
## Metodo dell'iterazione
Idea: "srotolare" la ricorsione, ottenendo una sommatoria dipendente solo dalla dimensione **n** del problema iniziale
Ad esempio: 
$$T(n) = c+T(\frac{n}{2})\\
T(\frac{n}{2})=c+T(\frac{n}{4}) \dots$$
Ancora: 
$$T(n)=T(n-1)+1\\
=T(n-2)+2 \\
=T(n-3)+3\\
=T(n-4)+4 \dots \\
=T(n-i)+i$$

# Analisi dell'albero della ricorsione
**Idea:**
- Disegnare l'albero delle chiamate ricorsive indicando la dimensione di ogni nodo
- Stimare il tempo speso da ogni nodo dell'albero
- Stimare il tempo complessivo sommando il tempo speso da ogni nodo

Se il tempo speso dentro ogni nodo è costante, allora T(n) sarà costante. 
A volte conviene analizzare l'albero per livelli: 
- Analizzare il tempo speso su ogni livello
- Stimare il numero di livelli


#### NOTA: aggiungere slide mancanti

---


# Metodo della sostituzione
È un metodo potente e preciso, è fortemente legato a una dimostrazione per induzione. 
L'idea del metodo della sostituzione è quella di fare un'ipotesi su quale potrebbe essere la soluzione, una volta fatto ciò, si utilizza l'induzione matematica e si risolve per le costanti. 

ES. 
$T(n)=n+T(n/2), T(1)=1$

Vogliamo dimostrare che la soluzione sia $T(n) \leq cn$ per una costante c opportuna. 

Passo base: 
$T(1) = 1 \leq c1 \ \forall c \gt 1$ 

Passo induttivo: 
Assumiamo che $T(k) \leq c \cdot k \ \forall c \gt 1$


### Lemma 
$f(n)=n = O(1)$

**dim.**
$$
caso \ base:\\
n = 1 = O(1) \\
passo \ induttivo: \\
n = n-1+1 = O(1)+1


$$


#### Altro esempio
T(n) = 4T(n/2)+n, T(1) = 1

Assumiamo che $T(n) \leq c \cdot n^3$

$T(k)\leq c \cdot k^3 \ \forall k \leq n$

Allora:
$$T(n) = 4T(n/2)+n \leq 4c(n/2)^3+n \\
\\
\frac{1}{2}\cdot n^3-(\frac{1}{2}\cdot n^3 - n)$$
Ma se volessimo dimostrare che T(n) = O(n^2)?

Proviamo a dimostrare che $T(n) \leq c \cdot n^2$

Assumiamo $T(k) \leq c \cdot k^2$
$$T(n)= 4T($$

Questo non funziona, allora utilizziamo un altro claim: 
Proviamo a dimostrare che $T(n) \leq c_1n^2-c_2n$
assumiamo che $T(k) \leq c_1k^2-c_2k \ , \forall k < n$

$$T(n) = 4T(n/2)+n \leq 4(c_1(n/2)^2-c_2(n/2))+n$$
# Teorema Master 
Algoritmi basati sulla tecnica del divide et impera: 
- Dividi il problema in a sottoproblemi di dimensioen n/b
- Risolvi i sottoproblemi ricorsivamente
- ricombina le soluzioni
Sia f(n) il tempo per dividere e ricombinare istanze di dimensione n. La relazione di ricorrenza è data da:$$T(n)= \left\{ \begin{array}{rcrcr} aT(n/b)+f(n) \ se \ n\gt 1 \\ \Theta(1) \ se \ n = 1\end{array}\right.$$
Questa equazione dipende da a, b e f(n), per calcolarla dobbiamo confrontare $n^{log_ba}$ con f(n) se una delle due è polinomialmente più veloce T(n) ha l'ordine asintotico della più veloce. 
Formalmente.
Tale relazione di ricorrenza ha soluzione: 
$$
1. \ T(n)= \Theta(n^{log_ba}) \ se \ f(n) = O(n^{log_ba-\epsilon}) \ per \ \epsilon >0 \\
2. \ T(n)= \Theta(n^{log_ba}logn) \ se \ f(n) = \Theta(n^{log_ba}) \\
3. \ T(n) = \Theta(f(n)) \ se \ f(n) = \Omega(n^{log_ba+\epsilon}) \\ per \ \epsilon>0 \ e \ af(n/b) \leq cf(n)\ per \ c \leq \ e \ n \ sufficientemente \ grande
$$

## Applichiamo il teorema master

1) T(n) = n+2T(n/2)

 a = 2
 b = 2
 f(n) = n

Dobbiamo confrontare: 
$$
n^{log_2 2} \ vs \ n? \ n
$$
T(n) = $\Theta(n logn)$

2) T(n) = c + 3T(n/9)
a = 3
b = 9
f(n) = c

Dobbiamo confrontare: 
$$
n^{log_93} \ vs \ c? \ n^{1/2}
$$
Allora corrisponde al primo caso del teorema master, dunque:  $$T(n) = \Theta(n^{1/2})$$
3) $T(n)= nlogn + 2T(n/2)$
a = 2 
b = 2
f(n) = nlogn

Cosa confronto?

$n^{log_22} \ vs \ nlogn \ ? \ nlogn$  

E rientriamo nel terzo caso del teorema master ma: 
$$nlogn = \Omega(n^{1+\epsilon})?$$
In realtà: 
	$\frac{nlogn}{n\cdot n ^{\epsilon}}$ 

E semplificando: 
$$
\frac{logn}{n^\epsilon}
$$
Non ho un $\epsilon$ positivo per cui il limite a più infinito tenda ad infinito.

# Cambiamento di variabile
Serve per risolvere equazioni di ricorrenza un po' più "strane". 

Esempio: 
$T(n)=T(\sqrt n)+ O(1), T(1)$

Allora scriviamo: 
$T(n)=T(n^{1/2})+O(1)$

$n = 2^x \rightarrow x = log_2n$
$T(2^x)=T(2^{x/2}+O(1)$
$R(x) = R(x/2)+O(1) \rightarrow R(x) = O(logx)$
$T(n) = O(log log n)$

## Esercizi
Progettare due algoritmi ricorsivi per i seguenti due problemi. Se ne studi la complessità nel caso peggiore. 

### Esercizio 1
Siamo ad una festa con **n** persone tra esse c'è una celebrità. Quest'ultima non conosce nessuno ma tutti la conoscono. Il nostro obiettivo è capire chi è la celebrità facendo domande del tipo: conosci questa persona?

### Esercizio 2 
n dischi di diametro diverso e tre pali. 

Regole:
si può spostare un disco a scelta e non si può mettere un disco di diametro più grande sopra uno di diametro più piccolo

obiettivo: 
spostare i dischi dal palo A al palo c (facendo meno spostamenti possibile)


[[Algoritmi di ordinamento|ordinamento]]

