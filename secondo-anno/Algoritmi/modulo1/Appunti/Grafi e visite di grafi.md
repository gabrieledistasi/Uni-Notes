### Perché studiamo i grafi?
Nel 1736, il matematico Eulero affrontò un problema famoso: è possibile partire da un qualsiasi punto della città di Königsberg e attraversare ciascuno dei sette ponti **soltanto una volta?**
Eulero ebbe l'intuizione di **eliminare i dettagli geografici e rappresentare il problema attraverso un modello matematico**. 
Trasformò: 
- Le quattro zone della città in 4 **vertici**. 
- I sette ponti in 7 archi. 
Trasformando così un problema geografico in un problema sui grafi. 
L'idea della modellazione su grafi è la **rappresentazione delle relazioni tra oggetti senza preoccuparsi dei dettagli non necessari**. 

--- 
# Grafi: alcune definizioni
## Definizione di grafo non orientato
Un grafo è definito come: 
$$G=(V, E)$$
Dove: 
- $V$ è l'insieme dei vertici o **nodi**.
- $E$ è un insieme di **coppie non ordinate di vertici**, chiamate archi. 

Una coppia non ordinata significa che non esiste una direzione privilegiata tra i due vertici. 
Per esempio: 
$$V=\{A, B, C\} \\ \\ E=\{(A, B), (B, C)\}$$
Significa che A è collegato a C da B. 
In un grafo non orientato, come quello dell'esempio, è possibile percorrere l'arco (A, B) in entrambe le direzioni: da A a B e viceversa, questa è la differenza rispetto ad un grafo diretto.

### Multigrafo
Nel grafo dei sette ponti di Königsberg, abbiamo: 
$$V=\{A, B, C, D\} \\ \\ E=\{(A, B),(A, B), (A, D),(B, C), (B, C), (B, D), (B, D), (C,D)\} $$
Notiamo che ci sono due archi tra A e B e due tra B e C. Un grafo che contiene archi paralleli viene chiamato più propriamente multigrafo. 

## Grafo diretto
Introduciamo il grafo diretto: 
$$D=(V, A)$$
È composto da: 
- $V$ insieme di vertici; 
- $A$ insieme di coppie ordinate di vertici, chiamate archi diretti. 
La differenza è che una coppia ordinata distingue il punto di partenza da quello di arrivo. 
Per esempio: 
$$(A,B) \neq (B, A)$$
 L'arco $(A, B)$ va da A verso B, mentre $(B,A)$ va da B verso A. 
 Dunque in un grafo diretto, se esiste l'arco $(A,B)$ questo ci permette di andare da A a B, ma non necessariamente da B verso A. Per poter tornare da B ad A deve esistere anche l'arco $(B, A)$. 

### Terminologia dei grafi
Consideriamo un grafo non orientato $G = (V, E)$
E introduciamo queste definizioni: 
- $n$  = $|V|$: numero di vertici. 
- $m$ = $|E|$ numero di archi. 
- Due vertici sono **adiacenti** se sono collegati da un arco. 
- Un arco $(u, v)$ è **incidente** a entrambi i suoi estremi. 
- $\delta(u)$: grado di $u$, cioè numero di archi incidenti a $u$. 
- Il grado di un grafo è il massimo grado tra tutti i suoi vertici. 

### Terminologia dei grafi diretti
In un grafo diretto, un arco $(u, v)$ parte da $u$ e arriva a $v$
Definiamo quindi: 
- $\delta_{out}(u)$: numero di archi **uscenti da $u$**
- $\delta_{in}(u)$: numero di archi **entranti in $u$**. 

--- 
# Proprietà dei grafi non diretti
In un grafo non diretto, se sommiamo i gradi di tutti i vertici contiamo **due volte** lo stesso arco, una volta per un estremo, la seconda per l'altro estremo. 
Da qui ricaviamo la proprietà: 
$$\sum_{v \in V}\delta(v)=2m$$
dove $m$ è il numero totale di archi. 

>In un grafo non diretto, il numero di vertici con grado dispari è sempre pari. 

# Proprietà dei grafi diretti
Per i grafi diretti vale una proprietà analoga:
$$\sum_{v\in V}\delta_{out}(v)=m$$
e
$$\sum_{v\in V}\delta_{in}(v)=m$$
Questo perché ogni arco viene contato: 
- una volta tra gli archi uscenti dal suo vertice di partenza; 
- una volta tra gli archi entranti nel suo vertice di arrivo. 

## Cammini e distanze
- **Cammino:** sequenza di nodi collegati da archi. 
- **Lunghezza di un cammino:** numero di archi attraversati. 
- **Distanza tra due nodi:** lunghezza del cammino più corto che li lega. 
Nei grafi diretti, per percorrere un cammino bisogna rispettare il verso degli archi. 

Un grafo è **connesso** se esiste un cammino tra ogni coppia di vertici. 
Un **ciclo** è invece un cammino che termina nel nodo da cui è partito.
Il **Diametro** è la massima distanza tra tutte le coppie di vertici. 
Se il grafo non è connesso, il suo diametro è **infinito**. 

## Grafi pesati
Un grafo pesato è un grafo in cui a ogni arco è associato un valore, chiamato peso, tramite una funzione $w$. 
Per esempio, il peso può rappresentare la distanza tra due città. 

Se abbiamo un grafo semplice non diretto con $n$ vertici, qual è il numero massimo di archi che può avere questo grafo?
Poiché stiamo considerando un grafo **non diretto**: 
- L'arco $(A, B)$ è uguale a $(B, A)$ 
- Semplice: non può avere cappi(archi da un vertice a sé stesso) né archi paralleli. 
Quindi tra due vertici distinti può esistere al massimo un arco. 
Per calcolare il numero massimo, dobbiamo collegare ogni vertice con tutti gli altri. 
Il numero di coppie di vertici distinti è: 
$$m_{max}=\binom{n}{2}=\frac{n\cdot(n-1)}{2}$$
Questo è il numero di archi di un grafo completo $K_n$. 

### Due definizioni importanti
- **Grafo totalmente sconnesso:** $V \neq \emptyset$ ed $E \neq \emptyset$, cioè non esiste alcun arco. 
- **Grafo completo:** ogni coppia di vertici è collegata da un arco. 
Il grafo completo con $n$ vertici si indica con $K_n$

## Com'è fatto un grafo connesso con il minimo numero di archi?
Per avere un grafo connesso con il minimo numero di archi, ci bastano $n-1$ archi. 
Immaginiamo di avere 4 vertici: 
$$A-B-C-D$$
Abbiamo 4 vertici e soltanto 3 archi, ma il grafo è comunque connesso. 
La struttura è quella di un albero: un grafo connesso e aciclico. 
La proprietà fondamentale è: 
$$|E|=|V|-1$$
Quindi un albero con $n$ vertici ha esattamente $n-1$ archi. 

#importante
### Dimostrazione per induzione sul teorema degli alberi
- **Caso base:** un albero con un solo vertice ha 0 archi. 
- **Passo induttivo:** rimuovendo una foglia (un vertice di grado 1), rimane ancora un albero
Togliendo la foglia eliminiamo un vertice e un arco, quindi la relazione rimane valida. 


Se un grafo è connesso con n nodi e m archi, vale: 
$$n-1\leq m \leq \frac{n(n-1)}{2}$$
Nota bene: se un grafo ha $m \geq n-1$ archi, non è detto che sia connesso. Quanti archi deve avere un grafo per essere sicuramente connesso?

Nota bene: un grafo contenente un ciclo **non è un albero**, poiché gli alberi per definizione, sono **aciclici**. 

### Proprietà
$$G \ è \ un \ albero \leftrightarrow G \ è \ connesso \ e \ |E|=|V|-1$$
Quindi se, ad esempio, un grafo ha 6 vertici e 5 archi: 
- Se è connesso, è sicuramente un albero; 
- Se non è connesso, non è un albero.

Non dobbiamo verificare separatamente che sia aciclico, perché è garantito dalle due condizioni. 

--- 
Vediamo questa equivalenza: 
$$G \ è \ aciclico \ \wedge |E| = |V|-1 \leftrightarrow G \ è \ un \ albero$$
Il punto interessante è che queste due condizioni sono sufficienti a garantire anche la connessione. 
Non serve quindi anche aggiungerla esplicitamente. 

## Cammini e cicli euleriani
- **Un cammino Euleriano**: cammino che attraversa tutti gli archi del grafo una sola volta. 
- **Un ciclo Euleriano:** cammino euleriano che termina nel vertice da cui è partito. 

Il teorema di eulero afferma: 
- Un grafo ammette un ciclo Euleriano se e solo se tutti i vertici hanno grado pari. 
- Un grafo ammette un cammino Euleriano se e solo se tutti i vertici sono di grado pari, tranne eventualmente due. 

Se ci sono due vertici di grado dispari, possiamo trovare un **cammino euleriano**, non un ciclo euleriano. Se un grafo ha esattamente due vertici dispari per avere un cammino Euleriano il cammino deve partire da uno dei due vertici *dispari* e terminare nell'altro vertice *dispari*. 

Nel caso del ponte di Königsberg non era possibile trovare un cammino Euleriano in quanto non erano presenti **esattamente due vertici dispari**, ma tutti e 4 lo erano.
Se il grafo fosse stato connesso e avesse avuto esattamente due vertici di grado dispari, sarebbe stato possibile attraversare tutti i ponti una sola volta, iniziando da uno o più vertici dispari e terminando nell'altro. 

---
# Applicazioni dei grafi
Possiamo applicare la teoria dei grafi, ad esempio alle reti stradali e di trasporto, considerando: 
- i vertici come i luoghi; 
- gli archi come i collegamenti; 
- i pesi possono rappresentare distanze o tempi di percorrenza. 

Ma possiamo anche utilizzare la teoria dei grafi anche per rappresentare le relazioni sociali.  

## Reti delle dipendenze
In questo tipo di grafo: 
- i vertici rappresentano compiti; 
- un arco diretto $(u, v)$ indica che il compito $u$ deve essere eseguito prima del compito $v$. 

## Grafi di incompatibilità
In questo caso: 
- I vertici rappresentano compiti; 
- Un arco tra due vertici indica che i rispettivi compiti non possono essere svolti contemporaneamente. 

# Colorazione dei grafi
L'obiettivo è assegnare un colore a ogni vertice rispettando questa regola: 

>due vertici adiacenti devono avere colori diversi.

Il numero minimo di colori necessari per colorare un grafo si chiama **numero cromatico** e si indica con $\chi(G)$   
