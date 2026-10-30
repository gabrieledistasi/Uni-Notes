Per prima cosa, **upper e lower bound** sono, rispettivamente, i limiti **superiori e inferiori** della complessità di algoritmi e problemi. 
Ad esempio, per il problema dell'ordinamento di n elementi, esiste un lower bound, ossia, un limite teorico sotto il quale non possiamo scendere?
Per dimostrare questi limiti verranno utilizzati gli alberi di decisione. 

# Upper Bound e Lower Bound di un algoritmo

### Upper bound: definizione
Un algoritmo A ha come complessità $O(f(n))$ se, nel caso peggiore, la quantità di risorse utilizzate dall'algoritmo è asintoticamente limitata da $f(n)$. 

### Lower Bound: definizione
Un algoritmo A ha come complessità $\Omega(n)$, se nel caso peggiore, il costo è limitato inferiormente da $f(n)$. 

Se un algoritmo ha un upper bound coincidente con il lower bound, allora possiamo dire che $\Theta(f(n))$. 

# Upper Bound e Lower Bound di un problema
- Un problema $P$ ha complessità $O(f(n))$ se esiste almeno un algoritmo che lo risolve con costo $O(f(n))$. 
- Un problema $P$ ha complessità $\Omega(f(n))$ se esiste almeno un algoritmo che lo risolve e ha costo, nel caso peggiore, almeno $\Omega(f(n))$. 

## Ottimalità di un algoritmo
Riprendendo la definizione data qui sopra, vediamo cosa significa. 

### 1. Lower bound del problema 
Supponiamo di sapere che per risolvere un problema servono almeno $\Omega(nlogn)$ operazioni. 
Questo significa che nessun algoritmo può risolverlo, nel caso peggiore, con un costo asintoticamente inferiore a quel limite. 

### 2. Troviamo un algoritmo che raggiunga quel limite
Supponiamo di avere un algoritmo con costo $O(nlogn)$. 
Abbiamo quindi: 
- Lower bound del problema: $\Omega(nlogn)$ 
- Costo dell'algoritmo: $O(nlogn)$ 
L'algoritmo raggiunge asintoticamente il limite inferiore del problema. Per questo viene definito **asintoticamente ottimo**. 
C'è da dire però che essere asintoticamente ottimo non implica essere il più veloce su ogni input, significa invece, **raggiungere il limite inferiore** dimostrato per il problema, rispetto alla risorsa considerata. 

## Complessità temporale del problema dell'ordinamento

| limite               | complessità | esempi o motivazione                                |
| -------------------- | ----------- | --------------------------------------------------- |
| Upper bound iniziale | $O(n^2)$    | InsertionSort, SelectionSort, QuickSort, BubbleSort |
| Upper bound migliore | $O(nlogn)$  | MergeSort e HeapSort                                |
| Lower bound banale   | $O(n)$      | Bisogna almeno leggere tutti gli n elementi         |
Il limite superiore migliore è **nlogn** mentre il lower bound è **n**. 

### Perché il lower bound è almeno $\Omega(n)$?
Immaginiamo un array di $n$ elementi. Se un algoritmo non esamina nemmeno uno degli elementi non può sapere se quell'elemento sia più piccolo o più grande degli altri e in generale, non può garantire di ordinare correttamente l'array. 

Ma esistono algoritmi che ordinano in tempo minore rispetto a $nlogn$? 

### Ordinamento per confronti 
dati due elementi $a_i \ e \ a_j$, possiamo confrontarli usando le operazioni di >, <, =, $\geq, \leq$. 
L'idea fondamentale è che non possiamo esaminare direttamente i valori per ricavare altre informazioni sul loro ordine: l'algoritmo deve basarsi sul risultato dei confronti. 

## Teorema fondamentale
>*Ogni algoritmo basato su confronti che ordina n elementi deve fare, nel caso peggiore, $\Omega(nlogn)$ confronti*. 

Questo significa che, per questa classe di algoritmi (a questa classe appartengono tutti gli algoritmi che abbiamo visto fino ad ora), non possiamo ottenere un ordinamento con costo temporale asintoticamente inferiore a nlogn, perché già il numero di confronti richiesti ha quel limite inferiore. 

### Corollario: MergeSort e Heap sono ottimi
Poiché: 
- Il lower bound per gli algoritmi basati su confronti è $\Omega(nlogn)$
- MergeSort e HeapSort hanno costo $O(nlogn)$ nel caso peggiore. 
Entrambi sono algoritmi asintoticamente ottimi, almeno, nella classe degli algoritmi basati su confronti. 

Non significa che siano sempre i più veloci, ma che non si può migliorare il loro ordine di crescita asintotico nel caso peggiore restando in questa classe. 

# Alberi di decisione

>*Un albero di decisione descrive astrattamente i confronti che un algoritmo può eseguire su input di una determinata dimensione*. 

L'idea è: 
- Ogni nodo interno rappresenta un confronto. 
- Ogni risultato possibile del confronto determina un ramo. 
- Ogni **foglia** rappresenta un possibile output dell'algoritmo, cioè una permutazione degli elementi 

Ad esempio, se confrontiamo due elementi $a_1 \ e \ a_2$, possiamo ottenere due risultati principali: 
- $a_1 \leq a_2$
- $a_1 > a_2$ 
A seconda del risultato, l'algoritmo prosegue la propria esecuzione lungo un ramo diverso. 
Questo permette di studiare la struttura dei confronti senza preoccuparci degli altri dettagli dell'algoritmo, come gli spostamenti dei dati. 

## Albero di decisione per 3 elementi 
Consideriamo tre elementi in ingresso: 
$$
a_1, a_2, a_3
$$
L'algoritmo deve capire in quale ordine disporli. Ci sono $3!=6$ possibili ordinamenti: 
$$
a_1, a_2, a_3 \\
a_1, a_3, a_2 \\
a_2, a_1, a_3 \\
a_2, a_3, a_1 \\
a_3, a_2, a_1 \\
a_3, a_1, a_2
$$
Come fa l'algoritmo a scegliere qual è l'ordinamento corretto? Attraverso una serie di confronti.
L'idea è che ogni risultato di un confronto determina quale confronto eseguire dopo. 

### A cosa è associato un albero di decisione?
Un albero di decisione è associato a: 
- Un algoritmo
- Una dimensione dell'istanza
Non è quindi associato soltanto al problema in generale. 
Per esempio, l'albero InsertionSort per input di dimensione 3 può essere diverso da quello di un altro algoritmo, anche se entrambi risolvono il problema dell'ordinamento. 
Inoltre, aumentando la dimensione dell'input cambiano i confronti che possono essere eseguiti e cambia la struttura dell'albero. 
Per esempio, con InsertionSort per n = 3. Per tre elementi, il primo passo confronta $a_1$, $a_2$. Nel secondo passo, il terzo elemento viene confrontato con quelli precedenti, secondo l'ordine stabilito dal primo passaggio. 
**Attenzione:** l'albero non rappresenta ogni assegnamento o spostamento dell'algoritmo. Rappresenta soltanto i confronti e le decisioni che ne derivano. 

## Proprietà fondamentali

### 1. Ogni input determina un cammino radice-foglia
I confronti effettuati su una determinata istanza rappresentano un percorso nell'albero, dalla radice fino alla foglia. 

### 2. Input diversi possono seguire cammini diversi 
I risultati dei confronti dipendono dai valori presenti nell'array. Di conseguenza, può seguire percorsi differenti. 

### 3. Il caso peggiore corrisponde al cammino più lungo
Il numero massimo di confronti eseguiti dall'algoritmo è pari all'altezza dell'albero. 

### 4. L'albero deve avere almeno n! foglie
Per ordinare correttamente n elementi distinti, deve poter distinguere tutti i possibili ordinamento. Il loro numero è: 
$$n!=(n-1)\cdot(n-2)\cdot ... \cdot 1$$

## Lemma 
>Un albero binario $T$ con $k$ foglie ha altezza almeno $log_2k$ . 

In soldoni, se un albero **ha molte foglie**, non può essere **troppo basso**. La dimostrazione usa l'induzione su $k$. 

### Dimostrazione
Vogliamo dimostrare che, per un albero binario $T$ con $k$ foglie, la sua altezza $h(T)$ soddisfa: 
$$
h(T) \geq log_2k
$$
L'idea è che un albero binario può avere al massimo $2^h$ foglie se la sua altezza è $h$. Quindi se vogliamo almeno $k$ foglie, l'altezza deve essere almeno $log_2k$. 

**Caso base:**
Se un albero ha una sola foglia, l'altezza può essere 0. 

**Passo induttivo:** 
Supponiamo che il lemma sia vero per tutti gli alberi con meno di $k$ foglie. 
Consideriamo il nodo interno, chiamato $v$, più vicino alla radice che ha due figli. Uno dei due figli, indicato con $u$ è la radice di un sottoalbero che contiene **almeno** $\frac{k}{2}$ **foglie**, ma meno di $k$. 
Per ipotesi induttiva, l'altezza di quel sottoalbero è almeno: 
$$
h(u) \geq log_2\frac{k}{2}
$$
Poiché per arrivare a quel sottoalbero dobbiamo percorrere almeno un arco in più, otteniamo: 
$$h(T) \geq 1+log_2k/2 \\
= 1 +log_2k-log_22 \\
= 1+log_2k-1 \\
= log_2k$$
Dunque il lemma è dimostrato. 

## Limite inferiore $\Omega(nlogn)$
Ciò che sappiamo finora è che:
- *un algoritmo di ordinamento corretto*, rappresentato da un albero di decisione, deve avere almeno $n!$ foglie, perché esistono $n!$ possibili ordinamenti degli elementi distinti. 
- Un albero binario con $k$ foglie ha altezza almeno $log_2k$ 

### Applichiamo il lemma 
Dato che l'albero ha almeno $n!$ foglie, la sua altezza h deve soddisfare: 
$$h \geq log_2(n!)$$
### Usiamo la formula di Stirling
$$n! \approx \sqrt{2\pi n}\cdot (\frac{n}{e})^n$$
Per ottenere un limite inferiore, utilizziamo la disuguaglianza: 
$$
n! \gt (\frac{n}{e})^n 
$$
Applicando $log_2$ a entrambi i membri otteniamo: 
$$
log_2n! \gt log_2(\frac{n}{e})^n
$$
Usiamo la proprietà dei logaritmi: 
$$log_2n! \gt nlog_2(\frac{n}{e})$$
Ora separiamo il rapporto: 
$$log_2n!\gt nlog_2n-nlog_2e $$
Poiché $log_2e$ è una costante, il termine dominante è $nlog_2n$ pertanto: 
$$h = \Omega(nlogn)$$
Ciò significa che **nessun algoritmo di ordinamento basato sui confronti** può, nel caso peggiore, avere costo inferiore a $\Omega(nlogn)$. 

## Esercizio
Verificare l'ottimalità di un algoritmo per pesare delle monete: come per l'ordinamento, dobbiamo distinguere tra diverse possibilità e possiamo rappresentare le decisioni attraverso un albero. 

>Dimostrare, usando la tecnica dell'albero di decisione, che l'algoritmo di pesatura che esegue, nel caso peggiore $\lceil log_3n \rceil$ pesate per trovare la moneta falsa tra n monete è ottimo. 
>

Per prima cosa, abbiamo n monete, tra le quali una è falsa. Vogliamo individuarla usando una bilancia a due piatti. 
Ogni pesata può avere tre possibili esiti: 
- Il piatto sinistro pesa di meno
- Il piatto destro pesa di meno
- I piatti pesano uguale
Dunque avremo un albero di decisione **ternario**, a differenza di quello binario usato per l'ordinamento. 
### Quante monete possiamo distinguere?
Se eseguiamo una pesata, abbiamo al massimo 3 esiti. 
Con due pesate abbiamo al massimo $3^2=9$ sequenze di esiti. 
Con h pesate abbiamo $3^h$ possibili esiti. 
Per identificare una moneta falsa tra n possibilità, l'albero deve avere almeno n foglie. Quindi: 
$$3^h\geq n$$
Prendendo il logaritmo in base 3: 
$$h\geq log_3n$$
Poiché il numero di pesate è intero: 
$$h\geq \lceil log_3n \rceil$$ 
### Perché l'algoritmo è ottimo?
Abbiamo appena dimostrato che nessun algoritmo può garantire un numero  inferiore di pesate nel caso peggiore, perché deve distinguere almeno n possibilità. 
L'algoritmo raggiunge quindi il limite inferiore ed è ottimo. 

## Possiamo ordinare interi piccoli in meno di $nlogn$?
>Può un algoritmo basato su confronti ordinare $n$ interi piccoli, compresi tra 1 e k = $O(n)$, in un tempo asintoticamente inferiore a nlogn?

La risposta è **no**: anche in questo caso continua a valere il limite inferiore mostrato precedentemente. 
Se un algoritmo **usa solo confronti**, il fatto che i numeri siano piccoli non cambia il ragionamento degli alberi di decisione. 

# IntegerSort
Abbiamom visto finora algoritmi basati sui confronti, questi hanno limite inferiore $\Omega(nlogn)$, ma esistono altri modi per ordinare gli interi, un algoritmo che vediamo adesso è l'**integerSort**. 
L'idea è sfruttare il fatto che i valori appartengono all'intervallo $[1, k]$. 
Supponiamo di avere: 
$$X = [5, 1, 6, 8, 6]$$
Quindi $n=5$ elementi e valori compresi tra 1 e 8, per cui $k=8$. 

### Fase 1: contare le occorrenze
Creiamo un array ausiliario $Y$ di dimensione $k$, inizializzato a 0. 
Ogni posizione $Y[x]$ contiene il numero di volte in cui il valore $x$ compare in $X$: 
$$Y[x] = \# \{i:X[i]=x\}$$
Per il nostro esempio: 

| valore $x$ | $Y[x]$ |
| ---------- | ------ |
| 1          | 1      |
| 2          | 0      |
| 3          | 0      |
| 4          | 0      |
| 5          | 1      |
| 6          | 2      |
| 7          | 0      |
| 8          | 1      |
Qui non stiamo confrontando gli elementi tra di loro: leggiamo ogni valore $X[i]$ e incrementiamo direttamente il contatore $Y[X[i]]$. 

### Fase 2: costruire l'array ordinato 
Ora scorriamo $Y$ da sinistra verso destra, per ogni valore x, scriviamo x nell'array X tante volte quante indica l'array $Y[x]$

### Pseudocodice e complessità 
Questo algoritmo esegue quattro operazioni principali: 
1. Crea l'array $Y$ di dimensione $k$
2. Inizializza i contatori k a zero: $O(k)$
3. Scorre gli n elementi e aggiorna i contatori: $O(n)$
4. Scorre i contatori e ricostruisce $X$: $O(n+k)$

## Perché può essere lineare?
Se $k = O(n)$, allora: 
$$
T(n, k)=O(n+k)
$$
### E se k è molto grande?
Consideriamo il caso: 
$$
k = \Theta(n^c) \ \ \ c>1
$$
In questo caso, il termine dominante è $k$, quindi: 
$$
T(n) = \Theta(n^c)
$$
Questo costo è asintoticamente maggiore di **nlogn**. 

---
# BucketSort
Abbiamo visto che IntegerSort ordina gli interi contando le occorrenze. Adesso il professore introduce **BucketSort**, che permette di ordinare dei record in base a una chiave intera. 

## Che cos'è un record
Un record è un elemento composto da più informazioni, l'ideaè che vorremmo ordinare gli elementi in base ad una determinata chiave. 
- **Chiave:** il campo usato per ordinare, ad esempio la matricola. 
- **Informazione satellite:** gli altri dati associati al record. 
La cosa fondamentale è che non possiamo ordinare soltanto le chiavi e lasciare i dati associati nelle posizioni originali: dobbiamo spostare l'intero record. 

# Idea di BucketSort
BucketSort funziona in modo simile a IntegerSort, ma al posto di un array di contatori utilizza un array di liste. 
Supponiamo di avere questi record, con chiavi comprese da 1 a 8: 
$$
X = [[\alpha, 5], [\beta, 1], [\gamma, 6], [\eta, 8], [\beta, 6]]
$$
Creiamo un array $Y$ con $k=8$ liste, inizialmente vuota. La lista $Y[i]$ contiene tutti i record con chiave i. 
Scorriamo quindi $X$: 
- Il record con chiave 5 viene inserito in $Y[5]$. 
- Quello con chiave 1 viene inserito in $Y[1]$. 
- Il primo record con chiave 6 viene inserito in $Y[6]$. 
- Quello con chiave 8 viene inserito in $Y[8]$. 
- Il secondo record con chiave 6 viene aggiunto a $Y=6$. 
Alla fine, concatenando le liste in ordine crescente di indice, si ottiene l'array di liste ordinato. 

### Pseudocodice e complessità
Il procedimento completo è: 
- Crea un array di $k$ liste 
- Inizializziamo tutte le liste come liste vuote
- Scorrere gli n record e aggiungere in coda alla lista corrispondente alla sua chiave. 
- Scorrere le liste da 1 a $k$, copiando ordinatamente i record di X. 
Il costo è: 
$$T(n, k)=O(n+k)$$ Infatti, inizializzare la lista costa $O(k)$, distribuire i record costa $O(n)$ e ricopiarli nell'array costa $O(n+k)$. 

## Stabilità 
Questa proprietà è importante per gli algoritmi di ordinamento. 
Un algoritmo è stabile se mantiene l'ordine relativo iniziale degli elementi che hanno la stessa chiave. 

# RadixSort 
Ora vediamo un algoritmo che permette di ordinare interi anche quando il dominio dei valori è troppo grande per rendere conveniente IntegerSort. 
L'idea è quella di rappresentare i numeri in una base $b$ ed eseguire una serie di passate di BucketSort. 
**La regola fondamentale è: si parte dalla cifra meno significativa e si procede verso quella più significativa.**
Per esempio, consideriamo i numeri: 
$$2397, \ 4368, \ 5924$$
In base $10$, li ordiniamo prima in base alle unità, poi alle decine, poi alle centinaia, e infine alle migliaia. 
A ogni passata: 
- La cifra corrente diventa la chiave. 
- Le altre cifre costituiscono le informazioni del satellite.
- Usiamo BucketSort, che deve essere stabile. 

### Perché partiamo da destra?
Supponiamo di aver già ordinato correttamente i numeri in base alle unità. Nella passata successiva li ordiniamo per decine. 
Se due numeri hanno la stessa decina, BucketSort stabile conserva il loro ordine precedente, quindi anche l'ordine per unità. In questo modo l'ordinamento corretto si costruisce progressivamente. 

## Perché RadixSort funziona?
Abbiamo capito che radix parte dalle unità e arriva fino alle migliaia, ma come fanno i numeri a tornare in ordine?

### Caso 1: due numeri hanno cifre diverse nella posizione corrente. 
La passata di BucketSort li mette in ordine corretto rispetto a quella cifra.

### Caso 2: due numeri hanno la stessa cifra nella posizione corrente. 
BucketSort è stabile, quindi conserva l'ordine che i due numeri avevano dopo le passate precedenti. 
Questo è fondamentale: l'ordinamento già ottenuto sulle cifre meno significative non viene perso. 

## Complessità RadixSort
Indichiamo con: 
- $n$ il numero di elementi da ordinare
- $k$: valore massimo rappresentabile
- $b$: base numerica utilizzata

Il numero di cifre necessarie per rappresentare $k$ in base $b$ è $O(log_bk)$
Ogni passata di BucketSort costa $O(n+b)$, perché bisogna distribuire gli $n$ elementi e gestire $b$ possibili valori della cifra. 
Quindi il costo complessivo è: 
$$O((n+b)log_nk$$
Se inoltre $k=O(n^c)$, dove C è una costante, il numero di passate è costante e il tempo diventa lineare, cioè $O(n)$. 

---
# Il problema dell'oracolo

**Problema:** dato un vettore $X$ di $n$ interi appartenenti a $[1, k]$, costruire in tempo $O(n+k)$ una struttura che risponda in tempo $O(1)$ alla domanda: 
**Quanti elementi di X appartengono all'intervallo $[a, b]$?**

## Come valutiamo un oracolo?
Prendiamo d'esempio il vettore: 
$$X=[1, 10, 4, 5, 5, 20, 3, 3]$$
Vogliamo rispondere a query come "quanti elementi appartengono all'intervallo $[a, b]$?"

Introduciamo due criteri per valutare una struttura dati: 
- **Tempo di costruzione**: quanto tempo serve per preparare l'oracolo
- **Tempo di query:** quanto tempo serve per rispondere a una domanda
L'obiettivo è trovare un compromesso che permetta di costruire l'oracolo in $O(n+k)$ e rispondere in $O(1)$. 
### Soluzione 1: rispondere al volo
La soluzione più semplice è non preparare alcuna struttura dati: quando arriva una query $[a, b]$, scorriamo il vettore e contiamo gli elementi compresi nell'intervallo. 

Per esempi, con la query $[5, 15]$, controlliamo uno per uno gli otto elementi e troviamo $10, 5, 5$ 
**Tempo di costruzione:** $O(1)$
**Tempo di query:** $\Theta(n)$ perché dobbiamo esaminare tutti gli elementi. 
È semplice, ma poco efficiente se riceviamo molte query. 

### Soluzione 2: precalcolare tutte le risposte
Possiamo anche memorizzare in anticipo le risposte ad ogni singola query. 
Dato che $[a, b]$ possono assumere valori da 1 a k, esistono $\Theta(k^2)$ coppie possibili. 
Il risultato sarebbe: 
**Tempo di costruzione:** almeno $\Omega(k^2)$ 
**Tempo di query:** O(1) perché basta recuperare la risposta memorizzata

### Soluzione 3: Array di prefissi
La più efficiente delle 3, costruiamo un array $Y$ tale che: 
$$Y[i]= numero \ di \ elementi \ di \ X \ minori \ o \ uguali \ a \ i$$
Per il nostro vettore, supponendo di considerare un dominio che arrivi fino a 20: 
$$X=[1,10,4,5,5,20,3,3] $$
- $Y[3]=3$ perché abbiamo tre elementi $\leq$ 3: $1 3, 3$

#### Come rispondiamo alla query?
Vogliamo sapere quanti elementi sono compresi in $[a, b]$ . 
Il numero di elementi minori o uguali a b è $Y[b]$. Quelli strettamente minori di a sono $Y[a-1]$. 
Quindi: 
$Query(a, b)=Y[b]-Y[a-1]$
Se $a \leq 1$ restituiamo semplicemente $Y[b]$. Se b > k limitiamo b a k. 
**Costi**:
- **costruzione**: $O(n+k)$
- **Query:**$O(1)$
