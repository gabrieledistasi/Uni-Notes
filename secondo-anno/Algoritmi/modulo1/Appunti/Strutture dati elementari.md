![[download 2 1.svg|700]]
Introduciamo una distinzione tra due concetti: **Tipo di dato** e **Struttura dati**
Un tipo di dato specifica: 
- Una collezione di oggetti.
- Le operazioni che possiamo eseguire su quella collezione.
Ad esempio possiamo gestire una collezione di studenti con operazioni come inserire uno studente, cancellarlo o cercarlo.

Il tipo di dato descrive cosa possiamo fare, senza imporre come i dati siano memorizzati. 

## Struttura dati
Una struttura dati è invece l'organizzazione concreta utilizzata per memorizzare gli oggetti e supportare le operazioni, cercando di usare meno risorse di calcolo possibile. 

# Tipo di dato: dizionario
Il dizionario memorizza un insieme S di coppie: 
$$(elem, chiave)$$
Ogni elemento è associato a una chiave, che permette di identificarlo. 
Le operazioni definite su un dizionario sono 3: 
- **Insert**: `insert(elem, k)` aggiunge a $S$ una nuova coppia $(e, k)$
- **delete:** `delete(k)` cancella da $S$ la coppia con chiave k 
- **search**: `search(k)` restituisce l'elemento associato alla chiave k
Ma il dizionario è *un tipo di dato* ciò vuol dire che può essere organizzato in maniera diversa, con costi per ogni operazione differenti. 

# Tipo di dato: pila
Una pila (stack) contiene una sequenza di elementi e segue la regola LIFO (Last In First Out): l'ultimo elemento inserito è il primo ad essere rimosso. 
Le operazioni definite per questo tipo di dato sono: 
- `IsEmpty()`: verifica se la pila è vuota. 
- `push(e)`: aggiunge e come ultimo elemento, cioè in cima alla pila.
- `pop()`: rimuove e restituisce l'elemento in cima alla pila. 
- `top()`: restituisce l'ultimo elemento senza rimuoverlo. 

# Tipo di dato: Coda
La coda è una collezione di elementi che segue la regola FIFO (First In First Out): Il primo elemento inserito è il primo elemento a essere rimosso. 

Definiamo tre operazioni principali, oltre a `IsEmpty()`: 
- `isEmpty()`: restituisce true se la coda è vuota, false altrimenti. 
- `enqueue(e)`: aggiunge l'elemento $e$ in fondo alla coda. 
- `dequeue():` rimuove e restituisce il primo elemento della coda. 
- `first()`: restituisce il primo elemento senza rimuoverlo.

## Tecniche di rappresentazione dei dati
Abbiamo visto *che cosa fa* una struttura dati, ora passiamo a *come rappresentare una struttura dati in memoria*. 
Introduciamo due famiglie: 
- **rappresentazioni indicizzate:** i dati sono contenuti principalmente in array.
- **rappresentazioni collegate:** i dati sono contenuti in record collegati tra loro mediante puntatori (es. linked list). 

### Rappresentazione indicizzata
Gli elementi sono memorizzati in un array e raggiungibili tramite un indice. 
Il **vantaggio** è che l'accesso diretto a una posizione è in tempo $O(1)$. 
Lo **svantaggio** è che inserire o eliminare un elemento in mezzo, comporta lo spostamento di altri elementi. 

### Rappresentazione collegata
Gli elementi sono memorizzati in nodi, ciascuno dei quali contiene un dato e uno o più riferimenti ad altri nodi. 
Ogni nodo punta al successivo; 

**Vantaggio:** possiamo inserire o eliminare nodi modificando i collegamenti, senza dover spostare tutti gli elementi successivi. 
**Svantaggio:** per raggiungere un elemento non abbiamo un indice per arrivarci direttamente, ma dobbiamo attraversare i nodi precedenti. 

## Rappresentazioni indicizzate: proprietà
Un array è una collezione di celle numerate, ognuna delle quali contiene un elemento di un tipo prestabilito. 

### Proprietà forte
La proprietà forte è che non ci sono buchi nella numerazione dell'array. 

### Proprietà debole
La dimensione dell'array è fissata al momento della sua creazione. Se si vuole più spazio generalmente bisogna creare un array più grande 

## Rappresentazioni collegate: proprietà
I costituenti fondamentali sono i record, cioè unità che contengono informazioni. I record possono essere creati o distrutti individualmente e dinamicamente, e vengono collegati tra loro tramite **puntatori**. 

### Proprietà forte
È possibile aggiungere o rimuovere record dalla struttura collegata. 

### Proprietà debole
Gli indirizzi di memoria dei record non devono essere necessariamente consecutivi. 

# Realizzazione di un dizionario
Ora applichiamo le rappresentazioni viste a un problema concreto: **implementare il tipo di dato dizionario**. 

#### Array non ordinato 
Immaginiamo un array in cui gli elementi sono memorizzati senza un ordine particolare. 
$$[23, 7, 41, 12, 5]$$
La complessità delle operazioni del tipo di dato per questo dizionario sono: 

| operazione | complessità | perché                                                        |
| ---------- | ----------- | ------------------------------------------------------------- |
| Insert     | $O(1)$      | Si inserisce l'elemento dopo l'ultimo elemento presente       |
| Search     | $O(n)$      | Bisogna scorrere l'array per cercare la chiave                |
| Delete     | $O(n)$      | Bisogna trovare l'elemento; la cancellazione segue la ricerca |
#### Array ordinato
In questo caso gli elementi sono mantenuti in ordine crescente: 
$$[5, 7, 12, 23, 41]$$

| operazione | complessità | perché                                                                               |
| ---------- | ----------- | ------------------------------------------------------------------------------------ |
| Search     | $O(logn)$   | si può utilizzare la ricerca binaria                                                 |
| Insert     | $O(n)$      | Bisogna trovare la posizione corretta e spostare gli elementi per mantenere l'ordine |
| Delete     | $O(n)$      | La cancellazione può richiedere lo spostamento degli elementi successivi.            |

### Perché l'inserimento costa $O(n)$?
Ci sono due passaggi: 
- Trovare la posizione corretta richiede $O(logn)$ confronti usando la ricerca binaria. 
- Spostare gli elementi per liberare la posizione può richiedere $O(n)$ trasferimenti. 

Combinando i costi: 
$$O(logn)+O(n)=O(n)$$ Il costo dominante è quello dei trasferimenti. 

## Realizzazione di un dizionario con le liste
Con le liste, quali sono i costi delle operazioni?

#### Lista non ordinata

| Operazione | Complessità |
| ---------- | ----------- |
| `Search`   | $O(n)$      |
| `Insert`   | $O(1)$      |
| `Delete`   | $O(n)$      |
Il ragionamento è simile a quello dell'array non ordinato: 
- **Ricerca:** nel caso peggiore, devi attraversare tutti i nodi. 
- **Inserimento:** se inserisci direttamente in testa, basta aggiornare un puntatore. 
- **Cancellazione:** devi prima trovare il nodo da eliminare, quindi il costo complessivo è $O(n)$. 

#### Lista ordinata

| Operazione | complessità |
| ---------- | ----------- |
| `Search`   | $O(n)$      |
| `Insert`   | $O(n)$      |
| `Delete`   | $O(n)$      |
La particolarità in questo caso è la ricerca: **anche se la lista è ordinata, non si può usare la ricerca binaria in modo efficiente.** 
Perché? In un array puoi aggiungere direttamente la cella centrale tramite indice. Una lista collegata invece, per raggiungere un nodo devi seguire i puntatori dalla testa. 

# Esercizi
Progettare una struttura dati che implementino pila e coda, garantendo che le operazioni abbiano complessità temporale costante, cioè $O(1)$. 
I due esercizi sono: 
**ESERCIZIO 1: con una rappresentazione indicizzata**
Per una pila, possiamo usare un array e un indice `top` che indica la posizione dell'ultimo elemento inserito. 
`push(e)`: inserisce l'elemento in cima
`pop()`:  rimuove l'elemento in cima 
Se l'array ha spazio disponibile, **entrambe le operazioni possono richiedere $O(1)$**

**ESERCIZIO 2: con una rappresentazione collegata**
- **Pila**: inseriamo e rimuoviamo i nodi in testa
- **Coda:** manteniamo un puntatore alla testa e uno alla coda, insieriamo in fondo e rimuoviamo in testa.
In entrambi i casi, le operazioni possono essere eseguite in $O(1)$, se i puntatori necessari sono mantenuti correttamente. 


# Alberi: organizzazione gerarchica dei dati
Abbiamo visto nelle precedenti lezioni, che un albero possiede: 
- **Nodi**: che contengono i dati
- **Archi**: che collegano i nodi e definiscono le relazioni gerarchiche. 

Introduciamo adesso il concetto di **grado** di un nodo: per **grado di un nodo** intendiamo il numero di figli di quel nodo, se un nodo ha grado 0, esso è una foglia. 

[[Algoritmi di ordinamento|Albero d-ario]], come abbiamo già visto, è un albero in cui ogni nodo può avere al massimo $d$ figli. 

**Antenato e discendente**
- Un nodo $u$ è antenato di un nodo $v$ se si può raggiungere $u$ partendo da $v$ e risalendo di padre in padre. 
- $v$ è discendente di $u$ se $u$ è suo antenato. 

## Rappresentazioni indicizzate di alberi
Ora vediamo come rappresentare un albero in un array, invece di collegare direttamente i nodi con i puntatori. 

### Vettore dei padri
L'idea è memorizzare ogni nodo in una cella dell'array, insieme all'indice del proprio padre. 
Ogni cella $P[i]$ contiene una coppia: 
$$P[i]=(info, parent)$$
- `info`: il contenuto del nodo. 
- `parent`: l'indice nell'array del nodo padre. 

Per la radice che non ha un padre si usa `null`.

## Vettore dei padri: esempio

Abbiamo un albero con le lettere che formano la parola **ALBERO**. 


![[download 4.svg|612]]
La numerazione delle celle, come mostrato nella slide, è questa: 

| indice | info | parent |
| ------ | ---- | ------ |
| 1      | L    | 3      |
| 2      | B    | 3      |
| 3      | A    | `null` |
| 4      | O    | 2      |
| 5      | E    | 1      |
| 6      | R    | 1      |

La cosa importante è capire che **l'indice** del padre non coincide necessariamente con l'indice presente nell'array. 
In altre parole: la disposizione delle celle nell'array è indipendente dalla posizione grafica dei nodi nell'albero. 

### Tre proprietà importanti 
- **Numero arbitrario di figli**: un nodo può avere quanti figli servono, perché ogni nodo memorizza soltanto l'indice del proprio padre. 
- **Individuare il padre:** richiede $O(1)$ perché basta leggere il campo parent dalla cella
- **Individuare i figli:** richiede $O(n)$ nel caso generale, perché bisogna scorrere il vettore e cercare tutti i nodi il cui campo parent corrisponde all'indice del nodo cercato. 

## Vettore posizionale 
Il **vettore posizionale** memorizza i nodi nell'array seguendo il loro ordine per livelli. È adatto soprattutto agli albero d-ari completi o quasi completi. 

### Come si dispongono i nodi
Consideriamo un albero binario, quindi $d=2$: 
![[download 1 2.svg|700]]
Con indici che partono da 0, l'array contiene: 

*Indice*:  0    1     2      3     4    5    6
*Nodo:*   A    B    C      D    E    F    G

La posizione nell'array permette di calcolare direttamente quella dei figli e del padre, senza memorizzare puntatori espliciti. 

### Formule con indici da 0
Per un albero d-ario, se un nodo si trova all'indice $i$, il suo $j-esimo$ figlio si trova all'indice 
$$
di+j
$$
dove $j$ varia da 1 a $d$. 
Il padre del nodo in posizione $i$ si trova invece in: 
$$\lfloor\frac{i-1}{d}\rfloor$$
Per un albero binario, $d=2$, quindi: 
- figlio sinistro: $2i+1$
- figlio destro: $2i+2$
- padre: $\lfloor\frac{i-1}{2}\rfloor$

#### Osservazioni: 
**Numero di figli:** ogni nodo deve avere esattamente $d$ posizioni potenziali per i figli; per questo la rappresentazione è adatta agli alberi completi o quasi completi. 
**Trovare il padre**: costa $O(1)$, perché la posizione si calcola direttamente con la formula. 
**Trovare uno specifico figlio:** costa $O(1)$, perché anche la posizione del figlio si calcola direttamente. 

## Rappresentazioni collegate di alberi 
Ogni nodo contiene le informazioni e uno o più puntatori ai propri figli. 
Questa soluzione è adatta quando il numero di figli è limitato e definito, come negli alberi binari, in cui ogni nodo può avere al massimo due figli. 

## Rappresentazione con liste di puntatori ai figli 
Se un nodo può avere un numero arbitrario di figli, possiamo memorizzare una lista di puntatori ai suoi figli. 
Per esempio, se il nodo `A` ha cinque figli, la sua lista conterrà cinque puntatori, uno per ciascun figlio. 
Questa rappresentazione è più flessibile perché non impone un numero massimo fisso di figli per nodo. 

### Rappresentazione primo figlio-fratello successivo
L'idea è semplice: invece di memorizzare un puntatore a ogni figlio, ogni nodo contiene due puntatori:
- **Primo figlio**: punta al primo figlio del nodo
- **Fratello successivo:** punta al fratello immediatamente successivo. 
Consideriamo un nodo con `A` con tre figli: `B`, `C` e `D`.

### Perché è utile?
Ogni nodo deve mantenere soltanto due puntatori, indipendentemente dal numero di figli. È quindi una rappresentazione flessibile anche quando alcuni nodi hanno molti figli e altri ne hanno pochi. 

---
## Visite di alberi 
A questo punto introduciamo gli *algoritmi di visita degli alberi*. 
Una visita è un algoritmo che permette di accedere sistematicamente ai nodi e agli archi di un albero. 
L'idea fondamentale è che non basta sapere quali nodi esistono: dobbiamo stabilire in quale ordine visitarli. 

Consideriamo questo albero: 
![[download 3.svg|700]]
Possiamo visitare questi nodi in ordini diversi, pur partendo dallo stesso albero. 
- **Visita in profondità** (DFS): Esplora un ramo fino in fondo prima di passare agli altri. 
- **Visita in ampiezza (BFS)**: Esplora l'albero per livelli, partendo dalla radice. 

#importante
# Algoritmo di visita in profondità (DFS)
La DFS parte dalla radice r e procede da un nodo a uno dei suoi figli fino a raggiungere una foglia. A quel punto retrocede al primo antenato che ha ancora figli non visitati e ripete il procedimento. 
Consideriamo l'albero: ![[download 1 3.svg|695]]
Supponiamo di visitare prima il figlio sinistro quando sono disponibili più figli. 
1. Partiamo da A 
2. Scendiamo a L
3. scendiamo a E che è una foglia
4. Saliamo di nuovo a L e visitiamo R
5. Torniamo ad A e visitiamo B
6. Scendiamo a O. 

L'ordine risultante è 
$$[A, L, E, R, B, O]$$
Il concetto è che quando raggiungi una foglia, non ricomincia dalla radice. Risali fino al primo antenato che ha ancora un figlio da visitare. 

#pseudocodice 
```
Algoritmo VisitaDFS(nodo r)
	Pila S
	S.push(r)
	while (not S.isEmpty()) do
	u <- S.pop() 
	if(u \= null) then
		visita il nodo u
		S.push(figlio destro di u)
		S.push(figlio sinistro di u)
		
```
Il procedimento è dunque: 
- Inserisci la radice nella pila 
- Estrai un nodo e visitalo. 
- Inserisci nella pila i figli che devi ancora visitare, nell'ordine appropriato
- Continua finché la pila è vuota. 
L'ordine in cui inseriamo i figli è importante: se vogliamo visitare prima il figlio sinistro, normalmente inseriamo prima il destro e poi il sinistro, così il sinistro viene estratto per primo. 

### Esempio: 

![[download 1 3.svg|684]]

Nella DFS visitiamo dapprima il nodo radice, nel nostro caso A, perciò la nostra pila ha come elementi al suo interno: $$\lfloor{A}\rfloor$$
## Gestione dei nodi da visitare
Oltre all'ordine di visita, introduciamo anche la **pila dei nodi ancora da visitare**. 
Dopo aver visitato `A`, i suoi figli `L` e `B` devono essere gestiti in modo da proseguire prima nel ramo sinistro. La pila serve a ricordare quali nodi dobbiamo ancora visitare e a quale tornare quando abbiamo terminato un ramo. 

## Visita in profondità
L'ordine di visita riportato è `A, L`: sono stati visitati la radice `A` e il figlio sinistro. 
Nella pila è rappresentato `B`, che rimane in attesa di essere visitato. 
La visita in profondità continua esplorando il sottoalbero di `L` prima di tornare a `B`. 

### Stato della pila
**Ordine di visita:** `A`, `L`
**Contenuto della pila:** `E, R, B`

La pila contiene ancora i nodi da visitare. L'ordine di estrazione sarà: 
1. `E`
2. `R`
3. `B`
Questo permette di completare prima il sottoalbero di L e poi passare al sottoalbero di `B`

### Prosecuzione della visita
Ora viene estratto `E`, che è una foglia: non ha figli da inserire nella pila. 
L'ordine di visita diventa quindi: 
`A->L->E`
Nella pila rimangono `R` e `B`, in questo ordine di estrazione. 

**Dopo aver visitato `E`**, che è una foglia, non inseriamo altri nodi nella pila. Viene quindi estratto `R`. 
L'ordine di visita diventerà: `A->L->E->R`

### Aggiornamento della pila 
Dopo aver visitato `R`, anche questo nodo risulta essere una foglia. 
La pila contiene soltanto `B`, che sarà il prossimo nodo da visitare. 

Adesso nella pila compare `null`, seguito da `R` e `B`. Il valore `null` rappresenta un figlio inesistente: in questa rappresentazione anche i riferimenti nulli possono comparire nella pila. 
Ora viene rimosso il riferimento a `null` e nella pila rimangono `R, B`
`R` è in cima e sarà il prossimo nodo visitato. 

Abbiamo completato il sottoalbero sinistro di `A`: sia `E` sia `R` sono stati visitati. Ora possiamo passare al nodo `B`, che è il figlio destro della radice. 

**Ordine di visita:** `A->L->E->R`
**Pila:** `null`, `null`, `B`
I due riferimenti a `null` rappresentano i figli inesistenti del nodo `R`. Il nodo `B` rimane in attesa della pila. 

Adesso abbiamo: 
**Ordine di visita:** `A -> L -> E -> R`
**Pila:** `null, B`
È stato eliminato uno dei riferimenti `null` presenti prima. Rimane ancora un riferimento nullo prima di `B`. 

Dopo aver rimosso l'ultimo riferimento `null`. `B` è in cima alla pila.
**Ordine di visita:** `A->L->E->R`
**Pila:** `B`
Quindi il prossimo nodo da visitare sarà B. 
Il nodo B ha soltanto un figlio `O` e nessun figlio sinistro, quindi nella pila inseriremo `null` e `O`, figlio sinistro e O che è il figlio destro. 
Dopo aver visitato `O` la pila è vuota e quindi l'ordine della visita sarà: 
`A->L->E->R->B->O`

## Gestione dei riferimenti null
La visita è terminata: tutti i nodi effettivi sono stati visitati. 
Nella pila compaiono ancora due riferimenti a `null`, relativi ai figli inesistenti dell'ultimo nodo visitato, questi **non rappresentano nodi dell'albero e non aggiungono elementi all'ordine di visita.**

## Svuotamento della pila
L'albero di visita rimane: 
`A->L->E->R->B->O`

Nella pila è rimasto un solo riferimento a `null`, che viene eliminato sensza visitare alcun nodo. 

## Conclusione della visita in profondità 
**Ordine di visita:** `A->L->E->R->B->O`
**Pila vuota.**
L'algoritmo ha terminato la visita dell'albero. 

#importante 
# Complessità della visita in profondità 
Consideriamo i passaggi principali: 
1. Ogni nodo viene inserito nella pila una sola volta
2. Ogni nodo viene eliminato dalla pila una sola volta. 
3. Se possiamo individuare i figli di un nodo in tempo $O(1)$, il costo per ogni nodo è costante. 
4. Anche i riferimenti `null` vengono inseriti ed estratti, ma il loro numero è proporzionale al numero di nodi. 
Di conseguenza, se l'albero contiene $n$ nodi: 
$$T(n)=O(n)$$
La visita in profondità richiede quindi tempo lineare rispetto al numero di nodi. 

# DFS: versione ricorsiva
La DFS vista fin'ora è **iterativa**, utilizzando una pila esplicita. 
Adesso introduciamo la versione ricorsiva per gli alberi binari. 
L'algoritmo è composto da quattro passaggi: 
#pseudocodice 

```
algoritmo visitaDFSricorsiva(nodo r)
if (r!= null) then 
	visita il nodo r
	visitadfsricorsiva(figlio sinistro di r)
	visitadfsricorsiva(figlio destro di r)
```
Vediamo cosa succede: 
1. Se il nodo `null`, non facciamo nulla
2. visitiamo il nodo corrente.
3. Richiamiamo ricorsivamente l'algoritmo sul figlio sinistro. 
4. Richiamiamo ricorsivamente l'algoritmo sul figlio destro. 

Esistono tre metodi per ordinare queste operazioni: 

| Tipo       | Ordine                                            |
| ---------- | ------------------------------------------------- |
| Preordine  | Radice $\rightarrow$ Sinsitro$\rightarrow$ Destro |
| Simmetrica | Sinistro$\rightarrow$Radice$\rightarrow$Destro    |
| Postordine | Sinistro$\rightarrow$Destro$\rightarrow$Radice    |


#importante 
# Algoritmo di visita in ampiezza (BFS)
Adesso introduciamo un nuovo algoritmo: **Breadth-First Search**, ovvero la visita in ampiezza. 
A differenza della DFS, che procede in profondità lungo un ramo prima di passare agli altri, la BFS visita i nodi **per livelli successivi**. 

>Un nodo sul livello $i$ può essere visitato soltanto se tutti i nodi sul livello $i-1$ sono stati visitati. 

Consideriamo l'albero: 
```
          A          Livello 0
        /   \
       L     B       Livello 1
      / \     \
     E   R     O     Livello 2
```
L'ordine di visita sarà: 
$$A \rightarrow L \rightarrow B \rightarrow E \rightarrow R \rightarrow O$$
Prima visitiamo la radice, poi tutti i figli e infine i nodi del livello successivo. 

**Differenza fondamentale**
- **DFS:** visita in profondità, completando un ramo prima degli altri. 
- **BFS:** visita in ampiezza, completando un livello prima di passare al successivo. 

# BFS: versione iterativa
La BFS, a differenza della visita DFS che utilizzava una **pila**, utilizza una **coda**. 

#pseudocodice 
```
algoritmo visitaBFSiterativa(nodo r)
	coda C
	C.enqueue(r)
	
	while (not C.isEmpty()) do
	 u ← C.dequeue()
	 
	 if (u!=null) then
		 visita il nodo u
		 C.enqueue(figlio sinistro di u)
		 C.enqueue(figlio destro di u)

```

1. **Creazione della coda:** inizializziamo una coda vuota `C`. 
2. **Inserimento nella radice:** inseriamo `r` nella coda con `enqueue`
3. **Condizione del ciclo:** continuiamo finché la coda non è vuota
4. **Estrazione:** estraiamo il primo elemento con `dequeue()` e lo assegniamo a `u`
5. **Controllo:** se `u` non è `null`, visitiamo il nodo. 
6. **Inserimento dei figli:** inseriamo prima il figlio sinistro e poi quello destro. 

## Complessità temporale della `BFS`
I punti fondamentali sono: 
1. Ogni nodo viene inserito ed estratto dalla coda una sola volta
2. Il tempo speso per ogni nodo è $O(1)$, se sappiamo individuare i figli in tempo costante. 
3. Il numero di nodi `null` inseriti ed estratti è $O(n)$ 

Di conseguenza: 
$$T(n)=O(n)$$ La visita in ampiezza ha quindi complessità temporale lineare rispetto al numero di nodi dell'albero. 

### Utilizzo degli algoritmi di visita: calcolo dell'altezza
Ora introduciamo un'applicazione degli algoritmi di visita: calcolare l'altezza di un albero. 
- `r`: la radice dell'albero. 
- `h`: l'altezza dell'albero

### Calcolo dell'altezza 
Per calcolare l'altezza di un albero binario, consideriamo: 
- $h_s$: altezza del sottoalbero sinistro
- $h_d$: altezza del sottoalbero destro
La formula riportata è: 
$$h=1+max\{h_s, h_d\}$$
## Algoritmo ricorsivo per calcolare l'altezza
```
CalcoloAltezza(nodo r)
if(r = null) then return -1 

sin = CalcoloAltezza(figlio sinistro di r)

des = CalcoloAltezza(figlio destro di r)

return 1+max{sin, des}
```

Perché in questa convenzione il caso base restituisce -1?
Perché una foglia ha altezza 0, per una foglia entrambi i figli sono null: 
$$1+max{-1, -1}=0$$
La complessità temporale di questo algoritmo è $O(n)$

### Esempio di calcolo dell'altezza 
Il risultato riportato è 
$$h=3$$
Vediamo come interpretare i valori mostrati: 
- I nodi foglia hanno altezza `0`. 
- I nodi `null` hanno altezza `-1`
- Risalendo nell'albero, ogni nodo calcola la propria altezza usando: 
$$h=1+max\{h_s, h_d\}$$
Per esempio, se un nodo ha sottoalbero sinistro di altezza 2 e sottoalbero destro di altezza 1: 
$$h = 1+max{2, 1}=3$$

#pseudocodice 
```
CalcolaNumeroFoglie(r)

if(r=null) then 
	return 0

if(r è una foglia) then 
	return 1

sin = CalcolaNumFoglie(figlio sinistro di r)
des = CalcolaNumFoglie(figlio destro di r)
```

La formula fondamentale: 
$$Foglie(r)=Foglie(sin)+Foglie(des)$$ La complessità indicata è $O(n)$, perché ogni nodo viene elaborato una volta. 

#pseudocodice 
## calcola grado medio
```
CalcolaGradoMedio(nodo r)
n = numero nodi dell'albero
nfoglie = CalcolaGradoMedio(r)
if(r!=null)
	return SommaGradir(r)/(n-foglie)
```

## Calcola il numero di foglie 
#pseudocodice
```
CalcolaNumFoglie(r)
if (r=null) then 
	return 0
	
if (r è una foglia) then 
	return 1

sin = CalcolaNumFoglie(figlio sinistro di r)
des = CalcolaNumFoglie(figlio destro di r)

return sin + des
```

## Somma gradi 
#pseudocodice
```
SommaGradi(nodo r)

1. if (r = null) return 0
2. if (r è una foglia) return 0
3. S = numero figli di r
       + SommaGradi(figlio sinistro di r)
       + SommaGradi(figlio destro di r)
4. return S
```

# Ricerca di un elemento in un albero

```
CercaElemento(nodo r, chiave k)
if (r = null) then 
	return null
	
if (chiave(r)=k) then return r

sin = CercaElemento(figlio sinistro di r)

if(sin!=null) then return sin 

return CercaElemento(figlio destro di r, k)
```
La complessità indicata è: 
$$O(n)$$
