Abbiamo un problema con infinite istanze e vogliamo risolvere il problema in maniera automatica tramite un algoritmo. Quest'ultimo verrà eseguito su un modello di calcolo e deve descrivere in modo non ambiguo la sequenza di operazioni sul modello di calcolo che risolvono una generica istanza. 
Analizzare la complessità computazionale di un algoritmo vuol dire stimare il tempo di esecuzione dell'algoritmo nel caso peggiore in funzione della dimensione dell'istanza. 

## Criteri di costo: quanto mi costa

### Criteri di costo uniforme 
- Tutte le operazioni hanno lo stesso costo
- Complessità temporale misurata come il numero di passi elementari eseguiti

### Criteri di costo logaritmico 
- Il costo di un'operazione dipende dalla dimensione degli operandi dell'istruzione
- Un'operazione su un operando di valore x ha costo $logx$ 
- È un criteri di costo che modella meglio la complessità di algoritmi numerici. 


## Caso peggiore e caso medio
Misureremo il tempo di esecuzione di un algoritmo in funzione della dimensione n delle istanze. 
Istanze diverse, di pari dimensioni, potrebbero richiedere tempo diverso. 
Distinguiamo quindi tra **caso peggiore e caso medio**. 

# Caso peggiore 
Sia **Tempo(I)** il tempo di esecuzione di un algoritmo I. 
$$
T_{worst}(n) = max_{istanze\ I\ di\ dimensione \ n} \{tempo(I)\}
$$
- Intuitivamente $T_{worst}(n)$ è il tempo di esecuzione sulle istanze di ingresso che comportano più lavoro per l'algoritmo. 
- Rappresenta una garanzia sul tempo di esecuzione di ogni istanza. 

# Caso medio
Sia P(I) la probabilità dell'occorrenza dell'istanza I 
$$
T_{avg}(n) = \sum_{istanze \ di \ dimensione \ n}\{P(I)\ tempo(I)\}
$$
Intuitivamente, $T_{avg}(n)$ è il tempo di esecuzione nel caso medio, ovvero sulle istanze di ingresso tipiche del problema. 
Conoscere la distribuzione di probabilità sulle istanze non mi è possibile, dunque faccio un'assunzione. 

# Notazione asintotica 
Complessità computazionale di un algoritmo espressa con una funzione T(n): 
- T(n) è il numero di passi elementari eseguiti su una RAM (*random access machine*) nel caso peggiore su un'istanza di dimensione n.
- *idea:* descrivere T(n) in modo qualitativo, perdiamo un po' di precisione per guadagnare in semplicità. 

# Notazione asintotica: intuizioni 
Facciamo un esempio di quanto scritto sopra: 
$$
T(n) =\left\{ \begin{array}{rcrcr} 71n^2 & + & 100\lfloor n/4 \rfloor &+& 7 \ se \ n \ è \ pari  \\ 70n^2 &+ &150\lceil(n+1)/4\rceil&+5 \ se \ n \ è \ dispari \end{array}\right.
$$
Scriveremo T(n) = $\theta(n^2)$ 
Questa scrittura vuol dire che T(n) è proporzionale a $n^2$. 
Ignoriamo le costanti moltiplicativi e i termini di ordine inferiore, l'assunzione implicita è che consideriamo come si comporta l'algoritmo su grandi istanze. 

## Notazione asintotica O
$$
f(n) = O(g(n)) \ se \ \exists \ due \ costanti \ c \gt 0 \ n_0 \geq 0 \ tali \ che \\ 0 \leq f(n) \leq cg(n) 
$$
Ad esempio: 
Sia f(n) = $2n^2+3n$, allora: 
f(n) = $O(n^3) \ per \ c=1, n_0=3$
f(n) = $O(n^2) \ per \ c=3, n_0=3$
f(n) $\neq O(n)$

### Nota: 
$$
lim_{n \rightarrow \infty} \frac{f(n)}{g(n)} = 0 \rightarrow f(n) = O(g(n))

$$

## Notazione asintotica $\Omega$
$$
f(n) = \Omega(g(n)) \ se \ \exists \ due \ costanti \ c \gt 0 \ e \ n_0 \geq tali \ che \ f(n) \geq cg(n) \geq 0 \ per \ ogni \ n \geq n_0
$$

### Nota: 
$$
lim_{n \rightarrow \infty} \frac{f(n)}{g(n)}=\infty \rightarrow f(n) = \Omega(g(n))
$$
## Notazione asintotica $\Theta$ 
$f(n)=\Theta (g(n)) \ se \ \exists \ tre \ costanti \ c_1,c_2 \gt 0 \ e \ n \geq 0 \ tali \ che \\ c_1g(n) \leq f(n) \leq c_2g(n) \\ per \ ogni  \ n \geq n_0$ 

### Nota: 
f(n) = $\Theta(g(n)) \rightarrow f(n) = O(g(n))$

$f(n) = \Theta(g(n)) \longleftrightarrow f(n) = \Omega(g(n)) \ e \ f(n)=O(g(n))$

## Notazione asintotica o
Data una funzione g(n): N -> R, si denota con o(g(n)) l'insieme delle funzioni f(n): N -> R
$$
o(g(n)) = f(n):\forall c>0, \exists n_0 \ tale \ che \ \forall \ n \geq n_0 \\ 0\leq f(n) \leq cg(n)
$$
### Nota: 
$$
o(g(n)) \subset O(g(n))
\\
f(n)=o(g(n)) \leftrightarrow lim_{n\rightarrow \infty}\frac{f(n)}{g(n)}=0
$$
## Notazione asintotica $\omega$
Data una funzione $g(n):N \rightarrow R$, si denota con $\omega(g(n))$ l'insieme delle funzioni f(n): 
$$
\omega(g(n)) = \{f(n): \forall c > 0, \exists n_0 \ tale \ che \ \forall n \geq n_0 \\ 0\leq cg(n) < f(n)\}
$$
### Nota: 
$$
\omega(g(n)) = \Omega(g(n))

\\

f(n) = \omega(g(n)) \leftrightarrow lim_{n \rightarrow \infty} \frac{f(n)}{g(n)}=\infty
$$
# Analisi complessità fibonacci3: Upperbound

```
algoritmo fibonacci3(intero n) --> intero
	sia Fib un array di n interi 
	Fib[1] <-- 1; Fib[2] <-- 1
	
	for i = 3 to n do: 
		Fib[i] = Fib[i-1] + Fib[i-2]
	
	return Fib[n]
```

T(n): complessità computazionale nel caso peggiore con input n
$c_j:$ numero di passi eseguiti su una RAM quando è eseguita la linea di codice j
$$
T(n) \leq c_1+c_2+c_5+(c_3+c_4)\cdot n = \Theta(n) \\
T(n) = O(n)
$$
Perché le righe 1, 2 e 5 vengono eseguite una sola volta, le righe 3,4 vengono invece iterate n volte. 

La notazione asintotica è un modo eccellente per misurare l'efficienza di un algoritmo in quanto è indipendente dalla macchina su cui è eseguito. 
I dettagli nascosti sono poco rilevanti quando n è grande abbastanza per funzioni asintoticamente diverse. 
L'analisi dettagliata dei passi eseguiti da un algoritmo diventerebbe complicata e noiosa, la notazione asintotica è invece in grado di descrivere bene la complessità degli algoritmi. 

[[Ricorsione ed equazioni di ricorrenza|equazioni di ricorrenza]]
