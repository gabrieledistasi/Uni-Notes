## Panoramica di TCP
Abbiamo già accennato a TCP negli appunti precedenti, ma per rinferscarci un po' la memoria ricordiamo che cos'è: 
***TCP è un protocollo di trasporto orientato alla connessione che offre un flusso di byte affidabile e ordinato tra un processo mittente e un processo destinatario.***

I punti principali di TCP sono: 
1. **Trasferimento affidabile e in sequenza**
	TCP garantisce che i dati consegnati all'applicazione siano: 
	- Affidabili -> i dati persi vengono recuperati tramite ritrasmissioni.
	- In ordine -> i byte vengono consegnati all'applicazione nell'ordine corretto. 
2. **ACK cumulativi**
	TCP utilizza degli ACK cumulativi. 
	L'ACK indica **il numero di sequenza del prossimo byte che il destinatario si aspetta di ricevere.**
3. **Pipelining** 
	TCP non aspetta di ricevere un ACK dopo ogni singolo segmento. 
	Può avere contemporaneamente diversi dati in volo. 
	La quantità di dati che TCP può avere in volo dipende dalla larghezza della finestra, questa dimensione dipende a sua volta da: 
	- controllo di flusso.
	- controllo della congestione. 
4. **Orientamento alla connessione** 
	Prima di scambiare i dati, client e server devono stabilire una connessione, ciò avviene mediante l'**handshake** (che vedremo più avanti).
5. **Controllo di flusso**
	TCP deve evitare che il mittente mandi dati più velocemente di quanto il destinatario possa gestire. Quindi il ricevente comunica al mittente quanti dati è in grado di accettare ancora. 
6. **Controllo della congestione**
	Simile al controllo di flusso, ma riguardante la rete: se la rete è sovraccarica, TCP deve ridurre la velocità di trasmissione. 
7. **TCP è point-to-point**
	Una connessione TCP coinvolge un solo mittente e un solo destinatario.
8. **Full duplex**
	TCP permette di trasmettere dati in entrambe le direzioni contemporaneamente. I dati possono viaggiare contemporaneamente da A verso B e da B verso A sulla stessa connessione TCP. 


## TCP: MSS

L'MSS (Maximum Segment Size) indica la quantità massima di **dati applicativi** che TCP può inserire in un segmento. Non comprende l'header TCP.

La dimensione del segmento TCP deve essere scelta in modo che, una volta aggiunto l'header IP, il pacchetto risultante non superi la MTU del collegamento:

$$
lunghezza(dati)+lunghezza(H_t)+lunghezza(H_n)\leq MTU
$$

Di conseguenza, assumendo header standard:

$$
MSS=MTU-H_{IP}-H_{TCP}
$$

Ad esempio, con MTU di 1500 B, header IPv4 di 20 B e header TCP di 20 B:

$$
MSS=1500-20-20=1460\ B
$$

La slide riporta inoltre le MTU minime di IPv4 e IPv6:
- IPv4: MTU minima 576 B → MSS 536 B
- IPv6: MTU minima 1280 B → MSS 1220 B

Un MSS più piccolo comporta un **maggiore overhead**, perché per trasmettere la stessa quantità di dati è necessario utilizzare più segmenti e quindi aggiungere più intestazioni. Questo riduce il rapporto tra dati utili e intestazioni e può ridurre il throughput end-to-end visto dall'applicazione.

![[Pasted image 20260829191919.png]]
# Struttura dei segmenti TCP

Un segmento TCP è formato da una **intestazione TCP** e dai **dati dell'applicazione**.

L'intestazione ha una lunghezza variabile, ma normalmente è di **20 byte** quando non sono presenti opzioni. I dati dell'applicazione hanno invece lunghezza variabile e possono essere suddivisi in più segmenti TCP.

La struttura generale è:

```text
┌─────────────────────────────────────┐
│        Intestazione TCP             │
├─────────────────────────────────────┤
│        Dati applicativi             │
└─────────────────────────────────────┘
```

## Porte di origine e destinazione

Il segmento contiene:

- **numero di porta di origine**
    
- **numero di porta di destinazione**
    

Questi campi permettono al livello di trasporto di individuare le **socket** coinvolte nella comunicazione e quindi di effettuare il demultiplexing.

## Numero di sequenza

Il **numero di sequenza** identifica la posizione dei dati contenuti nel segmento all'interno del **flusso di byte** TCP.

È importante ricordare che TCP conta i **byte e non i segmenti**.

Ad esempio, se il primo segmento contiene 1000 byte e il secondo contiene altri 1000 byte, i numeri di sequenza fanno riferimento alla posizione dei byte nel flusso, non semplicemente al numero del segmento.

## Numero di acknowledgement

Il campo **acknowledgement** contiene il numero di sequenza del **prossimo byte che il destinatario si aspetta di ricevere**.

Quindi, se:

```text
ACK = 1001
```

significa che il destinatario ha ricevuto correttamente tutti i byte precedenti e ora si aspetta il **byte 1001**.

Gli ACK TCP sono quindi **cumulativi**.

Il campo ACK è considerato valido quando è attivo il relativo **flag ACK**.

## Lunghezza dell'intestazione

Il campo **lunghezza dell'intestazione TCP** indica quanto è lunga l'intestazione.

La lunghezza è espressa in multipli di **32 bit**.

L'intestazione normalmente è di:

```text
20 byte
```

ma può diventare più grande se vengono utilizzate le **opzioni TCP**.

## Flag TCP

Nell'intestazione sono presenti diversi **flag**, che servono a indicare particolari condizioni o a gestire la connessione.

Tra quelli evidenziati troviamo:

- **SYN** → utilizzato nella gestione dell'instaurazione della connessione;
    
- **FIN** → utilizzato nella chiusura della connessione;
    
- **RST** → utilizzato per il reset della connessione;
    
- **ACK** → indica che il campo acknowledgement è valido;
    
- **CRW ed ECE** → utilizzati per il controllo esplicito della congestione.
    

## Finestra di ricezione

Il campo **finestra di ricezione** (`rwnd`) indica quanti **byte** il destinatario è ancora disposto ad accettare.

È utilizzato per il **controllo di flusso**.

In pratica il destinatario comunica al mittente:

> "Questo è lo spazio che ho ancora disponibile per ricevere dati."

Il mittente quindi non deve inviare una quantità di dati superiore a quella che il ricevente è in grado di gestire.

```text
Mittente ───────────────► Ricevente
             dati
                 ◄────── rwnd
```

Anche in questo caso si parla di **byte**, non di segmenti.

## Checksum

Il campo **checksum** viene utilizzato per il **rilevamento degli errori** nel segmento.

È basato sul **checksum Internet**, lo stesso meccanismo già visto per UDP.

Il checksum permette quindi di rilevare eventuali alterazioni dei dati durante la trasmissione, ma non costituisce da solo un meccanismo di correzione.

## Opzioni TCP

L'intestazione può contenere delle **opzioni di lunghezza variabile**.

Le opzioni permettono di aggiungere informazioni e funzionalità al protocollo TCP.

La loro presenza fa sì che l'intestazione TCP possa essere **più grande dei 20 byte tipici**.

## Dati dell'applicazione

Alla fine del segmento troviamo i **dati dell'applicazione**, cioè i dati che l'applicazione ha consegnato alla socket TCP.

La loro lunghezza è variabile.

TCP considera i dati come un **flusso di byte** e non conserva i confini dei messaggi dell'applicazione.

Per esempio, se l'applicazione produce:

```text
10000 byte
```

TCP può suddividerli in più segmenti:

```text
TCP
│
├── segmento → dati 1
├── segmento → dati 2
├── segmento → dati 3
└── ...
```

## Schema generale

Per ricordare la struttura dell'header TCP possiamo dividerla in gruppi:

```text
HEADER TCP
│
├── Identificazione
│     ├── porta sorgente
│     └── porta destinazione
│
├── Affidabilità
│     ├── numero di sequenza
│     └── acknowledgement
│
├── Controllo
│     ├── finestra di ricezione
│     └── checksum
│
├── Gestione connessione
│     └── flag SYN, FIN, RST, ACK...
│
└── Opzioni
```

Infine:

```text
HEADER TCP
     +
DATI APPLICAZIONE
     ↓
SEGMENTO TCP
```


## Numeri di sequenza e ACK di TCP
*Numeri di sequenza:*
"numero" del primo byte nel segmento nel flusso di byte. 

*ACK:*
- Numero di sequenza del prossimo byte atteso dall'altro lato.
- ACK cumulativo. 
![[Pasted image 20260829192738.png]]
## TCP: tempo di andata e ritorno (round trip time) e timeout
Il round trip time è fondamentale per capire come TCP determina dopo quanto tempo un pacchetto è considerato perso. 

### TCP: RTT 
Il RTT è il tempo necessario affinché un segmento vada: 
	**dal mittente al destinatario e torni indietro sottoforma di ACK**
Ad esempio: 
	segmento inviato:  t = 0 ms
	ACK ricevuto:      t = 100 ms
allora: 
		RTT = 100ms

**Perché TCP deve conoscere RTT?**
TCP deve utilizzare un timer per capire se il segmento è stato perso. 
TCP deve decidere: 
	"Quanto tempo devo aspettare prima di considerare perso un segmento?"
Se il timeout fosse troppo breve, TCP potrebbe ritrasmettere inutilmente un segmento che in realtà non era perso, ma semplicemente stava impiegando più tempo ad arrivare. 
Se invece fosse troppo lungo, TCP impiegherebbe troppo tempo a rilevare una perdita. 

#### RTT non è sempre uguale!
Se la rete si congestiona, i pacchetti possono metterci più tempo ad arrivare, quindi TCP non utilizza un RTT fisso, effettua delle misurazioni e calcola una stima dell'RTT. 

## EstimatedRTT
TCP mantiene una stima chiamata: 
$EstimatedRTT$
che viene aggiornata utilizzando le misurazioni effettuate. 
L'idea è quella di non utilizzare soltanto l'ultima misura, ma fare una media pesata delle misure precedenti e di quella nuova. 
$$
EstimatedRTT = (1-α)EstimatedRTT + αSampleRTT
$$

dove: 
$SampleRTT$ = RTT misurato per un determinato segmento.
$EstimatedRTT$ = stima precedente.
$α$ = parametro che determina quanto peso dare alla nuova misura.

## Mittente TCP
Il mittente TCP riceve un flusso di byte dall'applicazione e lo trasforma in segmenti TCP. 
Supponiamo 4 eventi:
1. **Arrivano i dati all'applicazione**
	Quando l'applicazione consegna i dati a TCP: 
	- TCP crea un segmento
	- Assegna al segmento un numero di sequenza
	-  Il numero di sequenza è il numero del primo byte contenuto nel segmento
	- Se non c'è già un timer attivo, avvia il timer. 
2. **Il timer**
	Il timer serve per capire se un segmento è probabilmente andato perso. Il timer controlla il segmento con il numero di sequenza più piccolo tra quelli non ancora riscontrati. 
3. **Succede un timeout**
	Se il timer scade, il segmento che ha causato il timeout, cioè quello in attesa di ACK con il più piccolo numero di sequenza. 
4. **Arriva un ACK**
	Supponiamo che TCP riceve: 
		ACK(y) e che y > sendBase
	Significa che sono stati riscontrati segmenti che precedentemente non erano stati riscontrati, il mittente quindi aggiorna $SendBase = y$.
	
Poiché l'ACK TCP indica il **prossimo byte atteso**, `ACK(y)` significa che tutti i byte precedenti a `y` sono stati ricevuti correttamente. Dopo aver aggiornato `SendBase`, TCP controlla se ci sono ancora segmenti non riscontrati. Se ce ne sono, il timer rimane attivo e viene associato al segmento più vecchio ancora non riscontrato; se invece tutti i segmenti sono stati riscontrati, il timer viene fermato.

## Ritrasmissione rapida
Se il mittente riceve 3 ACK addizionali per gli stessi dati, rispedisce il segmento non riscontrato con il più piccolo numero di sequenza. 
è probabile che il segmento non riscontrato sia stato perso, quindi non aspettare il timeout. 

## Controllo di flusso 
*Cosa succede quando il livello di rete fornisce i dati più velocemente di quanto il livello applicativo prelevi i dati dai buffer delle socket?*
Un gran casino, e proprio per questo motivo tcp risolve questo problema utilizzando la **finestra di ricezione**, indicata con **RWND**. 
RWND è un valore che il ricevente comunica al mittente e che indica:
	Quanti byte il ricevente è ancora in grado di accettare nel proprio buffer. 

## Gestione della connessione TCP 
Prima di scambiare i dati, il mittente e il destinatario si "stringono la mano": 
- accettano di stabilire una connessione 
- concordare i parametri della connessione
- inizializzare variabili e buffer

## TCP 3-way handshake 
Questo è il meccanismo con cui client e server stabiliscono una connessione TCP prima di iniziare a scambiarsi i dati. 
Questo meccanismo si chiama così perché utilizza 3 segmenti TCP. 
1. **Client -> Server: SYN**
Il client vuole stabilire una connessione con il server, invia quindi un segmento con il flag: 
$SYN = 1$, il client inserisce anche il proprio numero di sequenza iniziale. 

2. **Server -> Client: SYN+ACK**
Il server riceve il SYN e risponde con un segmento che contiene due informazioni:
$SYN = 1$
$ACK = 1$
Il server comunica il proprio numero di sequenza iniziale e conferma di aver ricevuto il SYN dal client. 

3. **Client -> Server: ACK**
Il client riceve il SYN + ACK e risponde con: 
- ACK = 1

L'utilizzo di tre messaggi è fondamentale affinché entrambi possano verificare che l'altro sia raggiungibile e sincronizzare i propri numeri di sequenza. 

### ⚠️ Una cosa da non confondere

Il **3-way handshake serve per instaurare la connessione**, non per rendere TCP affidabile in generale.

L'affidabilità, invece, viene ottenuta attraverso meccanismi come:

- numeri di sequenza;
- ACK;
- timer;
- ritrasmissioni.

Il handshake serve principalmente a **inizializzare la connessione e sincronizzare i numeri di sequenza**.

## Chiusura di una connessione TCP
Client e server chiudono ciascuno il proprio lato della connessione, inviano il segmento TCP con il bit FIN = 1.
Rispondono entrambi al FIN ricevuto con un ACK. 
E' possibile gestire scambi FIN simultanei. 