
### Inoltro: 
Spostare i pacchetti dall'ingresso del router, all'uscita appropriata del router. 

### Instradamento: 
Determinare il percorso seguito dai pacchetti dalla sorgente alla destinazione. 

Il piano di controllo **si occupa dell'instradamento dei dati**.
Ci sono poi due metodi di approccio alla strutturazione del piano di controllo della rete: 
- controllo per router
- controllo logicamente centralizzato

## #🌐 Piano di controllo per router
I router possiedono, ciascuno, una parte dell'algoritmo di instradamento. I router comunicano tra loro e, grazie alle informazioni che vengono scambiate, costruiscono le proprie informazioni di routing. Il piano di controllo sono dunque i router che eseguono l'algoritmo di instradamento, mentre nel piano dei dati abbiamo i pacchetti che vengono effettivamente inoltrati. 

## #🌐 SDN (software defined networking)

Qui invece compare un **remote controller**.
Il controller calcola le tabelle di inoltro e le installa nei dispositivi della rete. 

Quindi la differenza fondamentale è: 
**Tradizionale:** i router partecipano direttamente al calcolo del routing.
**SDN:** il calcolo viene effettuato da un controller logicamente centralizzato.

Anche in SDN, quando arriva un pacchetto, il dispositivo deve comunque inoltrarlo nel piano dei dati. Cambia soprattutto **chi calcola le regole** che il dispositivo utilizzerà. 

# #📌 Algoritmo di instradamento
**Obiettivo degli algoritmi di instradamento:** determinare percorsi o cammini "buoni" tra le sorgenti e i destinatari attraverso la rete di router. 
**Percorso:** sequenza di router che i pacchetti attraversano dall'host di origine all'host di destinazione. 
**"buono":** "costo" minimo. 

## Consideriamo il grafo:

![[Pasted image 20260905173923.png]]

definito come: 
$G = (N, E)$, dove: 
N = insieme di nodi/router. 
E = insieme di collegamenti. 
Ogni collegamento ha un costo, questo può rappresentare: 
-  distanza fisica;
- ritardo;
- larghezza di banda;
- congestione;
- oppure semplicemente essere impostato a 1; 
Il costo di un percorso è la somma dei costi dei collegamenti attraversati. 
Ad esempio il percorso $C_{w,x}$ avrà costo 3. 

## #📌 Classificazione degli algoritmi di instradamento

### Statici: 
I percorsi cambiano lentamente nel tempo. 

### Globali: 
Calcolo logicamente centralizzato o replicato su tutti i router, basato sulla conoscenza completa della topologia e del costo dei collegamenti. 

### Decentralizzati:
Processo di calcolo iterativo, basato sullo scambibo di informazioni tra vicini. 
Inizialmente i router conoscono solo il costo dei collegamenti ai loro vicini. 

### Dinamici: 
I percorsi cambiano velocemente, per via di aggiornamenti periodici o in risposta a cambiamenti del costo dei collegamenti. 

### Sensibili al carico: 
Il costo dei collegamenti riflette il livello corrente di congestione. 

### Insensibili al carico: 
Il costo dei collegamenti non riflette il livello corrente di congestione. 

 #esercizi
# #🔑 Algoritmo "Link state"

Nel link state, ogni router conosce la topologia della rete, quindi può calcolare autonomamente i percorsi minimi. Questo algoritmo è **iterativo**, ovvero, dopo `k` iterazioni conoscerà il cammino minimo verso `k` destinazioni. 
Definiamo:
- $C_{x, y}$: come il costo del collegamento **diretto** dal nodo x al nodo y.
- $D(v)$: stima corrente del costo minimo del percorso dalla destinazione sorgente alla destinazione v.
- $p(v)$: immediato predecessore di v lungo il percorso minimo dall'origine a v.
- $N'$: sottoinsieme di nodi contenente tutti i nodi v per cui il percorso a costo minimo dall'origine a v è definitivamente noto. 

```
1 Inizializzazione:
2 N' = {u}
/* calcola il percorso di minor costo da u a tutti gli altri nodi
*/
3 per tutti i nodi v
4 se v è adiacente a u
/* inizialmente conosce il costo del percorso diretto solo per i vicini diretti */
5
allora D(v) = cu,v
/* ma potrebbe non essere di costo minimo
*/
6 altrimenti D(v) = ∞
7
8 Ciclo
9 determina un w non in N' tale che D(w) sia minimo
10 aggiungi w a N'
11 aggiorna D(v) per ciascun nodo v adiacente a w e non in N' :
D(v) = min ( D(v), D(w) + cw,v )
12
13 /* il nuovo costo verso v è il vecchio costo verso v oppure il costo del percorso minimo
noto verso w più il costo da w a v */
14
15 Ripeti il ciclo finché non si verifica che N' = N
```

#### Complessità algoritmica: n nodi
- ciascuna delle n iterazioni deve controllare tutti i nodi, w, non in N' per determinare quello avente il costo minimo. 
- complessità $O(n^{2})$
- sono possibili implementazioni più efficienti: $O(nlogn)$ usando un heap. 

#### Complessità dei messaggi: n nodi
- Ogni router deve trasmettere in broadcast le proprie informazioni sullo stato dei collegamenti agli altri n router. 
- algoritmi di broadcasting efficienti: $O(n)$ attraversamenti dei collegamenti per diffondere un messaggio di broadcasting da una sorgente. 
- Il messaggio di ogni router attraversa $O(n)$ collegamenti: complessità dei messaggi complessiva $O(n^2)$
### Possibili oscillazioni
Quando il costo dei collegamenti dipende dal volume del traffico possono verificarsi oscillazioni dei percorsi. 

# #🔑 Distance Vector 

Questo algoritmo si basa sull'equazione di Bellman-Ford: 
>Sia $d_{x}(y)$: il costo del percorso di costo minimo da x a y. Allora: 
>$d_{x}(y) = min_{v}\{_{c_{x,v}+d_{v}(y)}\}$

- min calcolato su tutti ii vicini di v di x
- $c_{x, v}$ costo diretto del collegamento da x a v
- $d_{v}(y)$ costo del cammino minimo da v a y

Il secondo nodo lungo qualsiasi cammino da x a y è necessariamente un vicino $v_{i}$ di x. 
Il costo del primo arco è $c_{x, v_{i}}$, mentre la parte restante del cammino non può costare meno di $d_{v_{i}}$ cioè il costo del cammino minimo da $v_{i}$ a y, per un totale di $c_{x, v_{i}}$ + $d_{v_{i}}$. Per trovare il cammino di costo minimo da x a y, è quindi sufficiente trovare il vicino di x che minimizza questa quantità. 

**Idea chiave:**
di tanto in tanto, ogni nodo invia ai vicini il proprio vettore delle distanze, per l'appunto, *distance vector*. 
Quando x riceve un DV da un qualsiasi vicino, aggiorna la propria DV utilizzando l'equazione di Bellman-Ford. 
Sotto certe condizioni minori e naturali, la stima $D_{x}(y)$ converge verso l'effettivo costo minimo $d_{x}(y)$

Nell'algoritmo Distance vector, ciascun nodo: 
- attende un cambiamento del costo di un collegamento o un messaggio da un vicino. 
- ricalcola il DV usando il DV appena ricevuto dal vicino. 
- se il DV verso qualsiasi destinazione è cambiato, notifica i vicini. 
Questo algoritmo è **iterativo asincrono**: ciascuna iterazione locale causata: 
- cambiamento del costo del collegamento del locale
- messaggio di aggiornamento del DV da un vicino. 

## Cambiamento del costo dei collegamenti 
Un nodo rileva il cambiamento del costo del collegamento locale. Come abbiamo detto, ogni router conosce il costo verso i propri vicini e riceve da loro i loro distance vector, così, se cambia un collegamento locale: cambia il costo, ricalcola il proprio DV
Se il DV è cambiato, informa i vicini. 

### Problemi del distance vector e confronto con il link state
### 1. 
Supponiamo di avere: 
       1          1
   x ----- y -------- z

e supponiamo che y raggiunga x direttamente; 
z raggiunga x passando attraverso y. Poi però potrebbe verificarsi che il collegamento tra x e y diventi troppo costante. 

### 2. 
Uno dei principali problemi del **Distance Vector** è il **conteggio all'infinito** (*count-to-infinity*). Il problema nasce quando si verifica un **instradamento ciclico** tra due router.

### 3. Poisoned reverse
Per cercare di risolvere il problema viene utilizzata una tecnica chiamata: **Poisoned reverse.**
L'idea è che: se un router raggiunge una destinazione passando attraverso un vicino, comunica a quel vicino che la distanza verso quella destinazione è $∞$. 

Ma anche il poisoned reverse ha dei limit: 
Funziona quando il ciclo coinvolge due router adiacenti. Il poisoned reverse non è sufficiente a impedire necessariamente il conteggio all'infinito
Nella realtà non possiamo aspettarci che il conteggio duri indefinitamente.
Per questo motivo l'`∞` viene rappresentato attraverso un **valore finito scelto preventivamente**.

### RIP

Il protocollo **RIP**:

- usa costi unitari per i collegamenti;
- rappresenta l'infinito con il valore **16**.
- 
Quando il conteggio raggiunge `16`, il percorso viene considerato irraggiungibile.

### Perché scegliere proprio un valore piccolo?

Bisogna trovare un compromesso.

L'infinito deve essere:

- abbastanza grande da permettere i normali percorsi della rete;
- abbastanza piccolo da interrompere rapidamente il count-to-infinity.

Quindi:

infinito piccolo→convergenza piuˋ veloce\text{infinito piccolo} \rightarrow \text{convergenza più veloce}

ma

infinito troppo piccolo→limita la dimensione della rete\text{infinito troppo piccolo} \rightarrow \text{limita la dimensione della rete}

I progettisti di RIP ritenevano infatti che RIP non fosse pratico per reti con **diametro superiore a 15**.

## Complessità dei messaggi

### Link State

Ogni router comunica informazioni sullo stato dei propri collegamenti.

Secondo la slide:

O(n2)O(n^2)

messaggi inviati.

### Distance Vector

I router scambiano informazioni solamente con i **router adiacenti**.

Il tempo necessario alla convergenza è variabile e può essere molto elevato.

---

## Velocità di convergenza

### Link State

Utilizza l'algoritmo di **Dijkstra**.

La slide indica:

O(n2)O(n^2)

per l'algoritmo nella formulazione considerata.

Può comunque presentare **oscillazioni**.

### Distance Vector

Utilizza **Bellman-Ford**.

Può:

- convergere molto lentamente;
- creare instradamenti ciclici;
- soffrire del problema del conteggio all'infinito.

---

## Robustezza

La slide considera cosa succede se un router:

- si guasta;
- oppure viene compromesso.

### Link State

Un router compromesso può comunicare un costo sbagliato per uno dei propri collegamenti.

Tuttavia ogni router calcola **la propria tabella di routing**.

Quindi l'errore rimane maggiormente circoscritto.

### Distance Vector

Un router compromesso può comunicare agli altri router un percorso con un costo molto basso, ad esempio:

> "Ho un cammino di costo bassissimo verso qualsiasi destinazione."

Questo può creare un **buco nero** (_black hole_): il traffico viene indirizzato verso quel router anche se non esiste realmente un percorso valido.

Il problema è che:

> **il Distance Vector di ogni router viene utilizzato dagli altri router.**

Quindi un'informazione errata può **propagarsi attraverso la rete**.