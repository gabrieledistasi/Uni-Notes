## Che cos'è il problema del dizionario?
Come visto precedentemente ([[strutture dati elementari | strutture dati elementari]] ) il dizionario è *un tipo di dato che memorizza un insieme S di coppie*: 
$$(elem, chiave)$$
Ogni elemento è associato a una chiave che permette di identificarlo. 
Il dizionario mette a disposizione tre operazioni, `insert`, `delete`, `search`. 

Il problema del dizionario è: come implementare in modo efficiente questo tipo di dato?

## Come implementare efficientemente un dizionario?
Introduciamo due strutture dati importanti: 
1. **Alberi binari di ricerca (BST):** organizzare gli elementi in un albero in modo che ogni operazione richieda tempo $O(h)$, dove $h$ è l'altezza dell'albero. 
2. **Alberi AVL**: mantenere l'altezza dell'albero sempre $O(logn)$


L'obiettivo è garantire che tutte le operazioni abbiano costo: 
$$O(logn)$$

# Definizione di BST 
Un albero binario di ricerca deve rispettare due proprietà per ogni nodo $v$: 
- Tutte le chiavi del sottoalbero sinistro sono minori o uguali alla chiave di $v$. 
- Tutte le chiavi del sottoalbero destro sono strettamente maggiori della chiave di $v$
Queste proprietà **devono essere rispettate da tutti i nodi** non solo dai figli diretti. 
### Proprietà dei BST 
- Seguendo l'ordine dei collegamenti verso sinistra troviamo valori progressivamente più piccoli
- Seguendo l'ordine dei collegamenti verso destra troviamo valori progressivamente più grandi 

## Visita simmetrica di un BST
**Visitando un albero binario di ricerca in ordine simmetrico, otteniamo le chiavi in ordine crescente.** 
Ricordando l'ordine della visita simmetrica: *Visita sottoalbero sinistro*, *visita la radice*, *visita sottoalbero destro*. 

## Correttezza 
**Caso base:** altezza $h=1$. La proprietà è vera poiché tutti i valori a sinistra sono minori o uguali alla radice e quelli a destra sono maggiori. 
**Passo induttivo:** Supponiamo che la visita simmetrica funzioni correttamente per alberi di altezza minore di $h$. Dobbiamo dimostrare che funziona anche per un albero di altezza h.
Perché: 
- Nel sottoalbero sinistro restituisce una sequenza ordinata di valori minori o uguali alla radice. 
- Visitiamo la radice. 
- Il sottoalbero destro restituisce una sequenza di valori maggiori alla radice. 

### Implementazione delle operazioni nel dizionario
Adesso passiamo alla parte algoritmica: implementare su un BST le tre operazioni fondamentali: 
1. `search`
2. `insert`
3. `delete`

# Ricerca in un BST 
L'obiettivo è trovare un elemento associato alla chiave `k`. 
La slide descrive un algoritmo basato su un cammino nell'albero che parte dalla radice. 
In ogni nodo confrontiamo la chiave cercata con quella del nodo corrente. 
Abbiamo tre possibilità: 
1. k = $chiave(v)$: abbiamo trovato l'elemento e terminiamo
2. $k > chiave(v)$: proseguiamo nel sottoalbero sinistro
3. $k \leq chiave(v)$: proseguiamo nel sottoalbero destro

Se arriviamo a un riferimento `NIL` senza trovare la chiave, l'elemento non esiste nel dizionario.

![[Pasted image 20261103124051.png]]

Prendiamo ad esempio questo albero: **quale sarà il percorso per trovare `19` partendo dalla radice?**
La radice è 15 e iniziamo i confronti: 
- 15 > 19? No, proseguo nel sottoalbero di destra. 
- 20 > 19? Si, proseguo nel sottoalbero sinistro. 
- 17 > 19? No, proseguo nel sottoalbero destro. 
- Alla fine 19 = 19 quindi abbiamo trovato l'elemento.
# Inserimento
L'inserimento aggiunge un nuovo nodo al BST, sempre come nodo foglia. 
La procedura segue tre passaggi: 
- Crea un nuovo nodo `u` contenente l'elemento `e` e la chiave `k`
- Cerca la chiave `k` nell'albero, individuiamo il nodo `V` che diventerà padre di `u`. 
- Collega `u` come figlio sinistro o destro di `V`, rispettando la proprietà del BST. 

# Ricerca del minimo e del massimo
Prima di vedere la cancellazione, dobbiamo conoscere due operazioni ausiliarie. 
In un BST: 
- **minimo**: è il nodo più a sinistra dell'albero 
- **Massimo**: è il nodo più a destra dell'albero
Per trovare il minimo partiamo dalla radice e continuiamo a seguire i puntatori sinistri finché troviamo un nodo senza figlio sinistro. 
Per trovare il massimo, logicamente, eseguiremo il procedimento al contrario. 

## Predecessore e successore
- **Predecessore** di un nodo $u$: nodo con la massima chiave minore o uguale alla chiave di $u$.
- **Successore** di un nodo $u$: nodo con la minima chiave maggiore alla chiave di $u$. 

### Come trovare il predecessore?
#### Caso 1 - il nodo ha un sottoalbero sinistro
Il predecessore è il massimo del sottoalbero sinistro

#### Caso 2 - il nodo non ha un sottoalbero sinistro
Bisogna risalire verso gli antenati e trovare il primo antenato per cui il nodo si trova nel suo sottoalbero destro. 

## Ricerca del predecessore
Il procedimento è simmetrico rispetto a quello del predecessore.
Abbiamo due casi: 
1. Se il nodo possiede un sottoalbero destro, cerchiamo **il minimo nel sottoalbero destro**. 
2. Se non possiede un sottoalbero destro, risaliamo verso gli antenati fino a trovare il primo antenato per cui il nodo si trova nel suo sottoalbero sinistro. 

# Cancellazione
Qui arriviamo ad una delle operazioni più importanti dei BST. La cancellazione presenta tre casi, a seconda del numero di figli del nodo da eliminare: 
1. Nodo foglia. 
2. Nodo con un solo figlio. 
3. Nodo con due figli. 

### Caso 1 - Il nodo è una foglia 
È il caso più semplice: basta rimuovere il nodo dall'albero, scollegandolo dal padre. 

### Caso 2 - Il nodo ha un solo figlio
Non possiamo semplicemente eliminarlo, perché rischieremmo di perdere il sottoalbero. 
Dobbiamo collegare direttamente il figlio del nodo da eliminare al suo padre, eliminando il nodo intermedio. 

### Caso 3 - Il nodo ha due figli 
Se il nodo ha due figli, non possiamo semplicemente collegare uno dei due al padre, perché ciò potrebbe causare la perdita del sottoalbero o violare la proprietà dei BST. 

La soluzione è: 
1. Trovare il predecessore del nodo da eliminare.
2. Sostituiamo il nodo da eliminare con il predecessore.
3. Rimuoviamo fisicamente il predecessore dalla sua posizione originale. 

# Complessità delle operazioni 
Possiamo riassumere il costo delle operazioni con: 
$$T(n) = O(h)$$
Dove $h$ è l'altezza dell'albero. 
Nel caso peggiore, quando l'albero è molto sbilanciato: 
$$h=O(n) \rightarrow T(n) = O(n)$$
Quindi anche un BST può avere prestazioni lineari.

Se invece il **BST è bilanciato e ha altezza $O(logn)$**, le operazioni di ricerca, inserimento e cancellazione hanno costo $O(logn)$

## Il problema dei BST sbilanciati

- **BST completo/bilanciato**: altezza $h$ = $\Theta(logn)$
- **BST linearizzato:** altezza $h$ = $\Theta(n)$
Entrambi rispettano la proprietà del BST, ma hanno prestazioni molto diverse. 
Il problema è che un BST normale non garantisce automaticamente il bilanciamento. 

Se supponiamo di inserire nell'ordine i valori: $1, 2, 3, 4, 5$ in un BST, l'inserimento avverrà in questo modo: 
- `1` diventa la radice
- `2 > 1` va a destra
- `3 > 2 e 3 > 1` va a destra
- `4>3, 4 > 2, 4>1` va a destra
- `5 > 4, 5 > 3, 5 > 2, 5 > 1` va a destra

Quindi l'albero sarà:
```
1
 \
  2
   \
    3
     \
      4
       \
        5
```

L'albero ha 5 nodi e altezza 4 quindi la sua altezza è lineare rispetto al numero dei nodi: 
$$h=\Theta(n)$$ Il problema è che inserire elementi già ordinati può trasformare un BST in una struttura simile a una lista concatenata. 

# Alberi AVL 
Un'altra possibile soluzione al problema del dizionario è usare **gli alberi AVL**
Sono alberi binari di ricerca che mantengono il bilanciamento attraverso opportune operazioni chiamate *rotazioni*. 
L'obiettivo è garantire un'altezza: 
$$O(logn)$$
## Definizione albero AVL 

Introduciamo il **fattore di bilanciamento** di un nodo $v$ e lo indichiamo con $\beta(v)$. 
Si calcola come $\beta(v) = h_{sinistro}-h_{destro}$
Dove: 
- $h_{sinistro}$ è l'altezza del sottoalbero sinistro.
- $h_{destro}$ è l'altezza del sottoalbero destro.
Un albero si dice **bilanciato in altezza se**, per ogni nodo $v$: 
$$|\beta(v)|\leq1$$
Gli alberi AVL sono quindi alberi binari bilanciati in altezza. Il fattore di bilanciamento viene generalmente mantenuto come informazione aggiuntiva nei record di ogni nodo. 

### Come interpretare il bilanciamento?

| Fattore       | Significato                      |
| ------------- | -------------------------------- |
| $\beta(v)=0$  | Sottoalberi della stessa altezza |
| $\beta(v)=+1$ | Sinistro più alto di uno         |
| $\beta(v)=-1$ | Destro più alto di uno           |
| $\beta(v)=+2$ | Nodo sbilanciato                 |
| $\beta(v)=-2$ | Nodo sbilanciato                 |

**Non basta controllare la radice**: dobbiamo verificare il fattore di bilanciamento di ogni nodo. 

# Altezza degli alberi AVL 
$$
h = O(logn)
$$
Possiamo dimostrare che un albero AVL con $n$ nodi ha altezza logaritmica. 
La dimostrazione introduce gli **alberi di Fibonacci**.
L'idea è che tra tutti gli alberi AVL di altezza $h$, consideriamo quello che contiene il numero minimo di nodi. 
Lo chiamiamo albero di fibonacci di altezza $h$. 
Ci interessa che anche l'albero AVL con il minor numero di nodi cresce esponenzialmente rispetto all'altezza, allora possiamo concludere che tutti gli AVL hanno altezza $O(logn)$. 

## Alberi di Fibonacci

Costruiamo gli alberi di Fibonacci partendo dalle altezze più piccole. 
Indichiamo con $T_i$ l'albero di Fibonacci con altezza $i$. 

La caratteristica fondamentale è che, per ottenere il minimo numero di nodi: 
- Un sottoalbero deve avere altezza $i-1$
- L'altro deve avere altezza $i-2$

In questo modo il fattore di bilanciamento del nodo è proprio $+1$ oppure $-1$. 

## Ricorrenza degli alberi di Fibonacci
Per costruire un albero di Fibonacci di altezza $h$, utilizziamo: 
- Un sottoalbero di altezza $h-1$
- Un sottoalbero di altezza $h-2$
- La radice 
Otteniamo quindi: 
$$n_h=1+n_{h-1}+n_{h-2}$$
I casi iniziali sono: 
$$n_0=1, n_1=2$$
## Lemma 
$$n_h=F_{h+3}-1$$
Dove $F_i$ è l'i-esimo numero della successione di Fibonacci. 
Possiamo utilizzare questo risultato per dimostrare che: 
$$n_h=\Theta(\phi^h)$$
**Nota Bene:**
La differenza tra un albero AVL e un BST è che il BST non garantisce il bilanciamento: può diventare una struttura **linearizzata** con altezza $O(n)$. 

# Come mantenere un AVL bilanciato?
Qui nasce un problema: cosa succede quando inseriamo o cancelliamo un nodo?
L'operazione potrebbe modificare le altezze dei sottoalberi e quindi violare la proprietà dell'AVL. 
La soluzione è utilizzare le **rotazioni**. 
`search`: procede esattamente come in un BST.
`insert` e `delete`: potrebbero sbilanciare l'albero. 
Per mantenere il bilanciamento utilizziamo opportune rotazioni. 

## Rotazioni semplici
Una rotazione è un'operazione che modifica la struttura dell'albero per ripristinare il bilanciamento. 
Le rotazioni hanno due proprietà fondamentali: 
- Mantengono la proprietà di ricerca del BST 
- Richiedono tempo $O(1)$
Esistono due rotazioni di base: 
- Rotazione verso destra
- Rotazione verso sinistra
L'idea è spostare un nodo verso l'alto e il suo genitore verso il basso, riorganizzando i sottoalberi senza violare l'ordinamento delle chiavi. 

## Inserimento in un albero AVL 
1. Inseriamo il nuovo nodo come in un normale BST 
2. Ricalcoliamo i fattori di bilanciamento lungo il cammino dal nodo inserito verso la radice 
3. Individuiamo il nodo più profondo v come fattore di bilanciamento $+2$ o $-2$
4. Eseguiamo la rotazione opportuna per riequilibrare l'albero. 

## Cancellazione AVL
La cancellazione è diversa dall'inserimento: 
- Si cancella il nodo come in un normale BST 
- Si ricalcolano i fattori di bilanciamento risalendo verso la radice
- Se necessario, si eseguono le rotazioni 
- Si continua a risalire se l'altezza del sottoalbero ribilanciato è diminuita

Durante la cancellazione, l'altezza di un sottoalbero può diminuire anche dopo una rotazione. 
Immagina: 
1. Cancelliamo un nodo
2. Il suo sottoalbero diventa più basso 
3. Un antenato perde altezza in uno dei suoi due sottoalberi e può diventare sbilanciato. 
4. Eseguiamo una rotazione per riequilibrarlo
5. Se dopo la rotazione l'altezza è ulteriormente diminuita, anche il suo antenato potrebbe diventare sbilanciato. 

Questo processo può ripetersi fino alla radice. 

## Costo delle operazioni AVL
Tutte le operazioni principali hanno costo: 
$$O(logn)$$
Questo perché: 
- L'altezza dell'AVL è $O(logn)$
- Ogni rotazioni costa $O(1)$
- Durante la cancellazione possiamo effettuare al massimo $O(logn)$ rotazioni. 