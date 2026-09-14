
# Domanda 1

Si consideri una coppia di processi che comunicano tramite una connessione TCP che attraversa un unico collegamento punto-a-punto full-duplex, senza altro traffico. Il collegamento ha velocità di 100 Mbps e un ritardo di propagazione di 60 μs.

All’istante t = 0 il mittente inizia a trasmettere, sottostando ai vincoli del protocollo di trasferimento dati affidabile, 5 segmenti da 1 MSS ciascuno.

Si assuma che:

- MSS = 250 byte
- finestra del mittente di dimensione costante = 4 MSS
- numero di sequenza iniziale = 0
- invio immediato degli ACK
- il ricevente memorizzi in un buffer i segmenti fuori ordine
- il mittente utilizzi il fast retransmit (ritrasmissione rapida)
- il timeout di ritrasmissione sia fisso a 1 s: il timer parte con l’invio del primo segmento e viene riavviato a ogni nuovo ACK finché restano dati non riscontrati

Si trascuri l’overhead delle intestazioni e dei protocolli sottostanti, tutti i ritardi diversi da quelli di trasmissione e propagazione e, per gli ACK, il ritardo di trasmissione.

Si assuma inoltre che solo il **secondo segmento** venga inizialmente perso.

Si richiede di descrivere in maniera ragionata e introducendo le necessarie definizioni, la sequenza degli eventi, evidenziando i) i numeri di sequenza e acknowledgment, ii) gli istanti di invio e ricezione dei segmenti, iii) il recupero della perdita, iv) gestione del buffer nel ricevente e disponibilità dei dati al processo destinatario.

Si discuta inoltre come viene regolata in realtà la dimensione (variabile) della finestra del mittente in scenari con più collegamenti attraversati.

## Soluzione 
Calcoliamo i dati fisici: 

$$MSS = 250byte$$

Ogni segmento contiene quindi $250 \times 8 = 2000bit$ 
Il link ha velocità: 
$$
R = 100Mbps
$$
E, ricordando la formula per il ritardo di trasmissione: 
$$
d_{trasm}=\frac{L}{R}
$$
Quindi calcoliamo il ritardo di trasmissione: 
$$
d_{trasm} = \frac{2\cdot10^3}{1\cdot10^8}=2\cdot10^{-5}=0.00002s=20\mu s
$$
Per un segmento che attraversa il link abbiamo: 
$$
d_{segmento} = d_{trasm}+d_{prop}=20+60=80 \mu s
$$
### Numeri di sequenza

```
|Segmento|Primo byte|Ultimo byte| Seq |
|---     |--       :|--        :| --: |
|S1      |     0    |    249    |  0  |
|S2      |   250    |    499    | 250 |
|S3      |   500    |    749    | 500 |
|S4      |   750    |    999    | 750 |
|S5      |  1000    |    1249   |1000 |
```

Questa tabella serve a tenere traccia dei numeri di sequenza dei segmenti.
In questo esercizio, ogni segmento trasporta 250 byte, TCP assegna a ogni segmento come `seq` il **numero del primo byte contenuto**, con questa tabella possiamo capire **quali byte sono arrivati e quali mancano**. 

### ACK 
Sappiamo che i due processi hanno una connessione TCP, sappiamo che TCP utilizza **ACK cumulativi**, quindi, se arriva correttamente S1:
`S1 = byte 0-249` e il ricevente si aspetta il byte `250`, quindi invia
$$ACK = 250$$

Così anche per S2: 
`S2 = byte 250-499` 
e il prossimo byte sarebbe `500`, ma sappiamo che S2 viene inizialmente perso, come scritto nella traccia. 
Quello che succede, quando si verifica la perdita del secondo segmento è che i successivi arrivano, ma gli ACK vengono ripetuti.
S2 è perso, e nel mentre arriva S3, ma l'ACK di TCP è cumulativo, non può andare avanti perché non ha ricevuto i byte da 250-499, quindi rinvia
$$
ACK = 250
$$
Stessa cosa per S4, che una volta trasmesso fa inviare 
$$
ACK = 250
$$
Sappiamo che il mittente usa fast retransmit, ma questo scatta solo quando abbiamo $3 \ ACK \ Duplicati$ e noi per ora ne abbiamo solo 2. 
La finestra è di 4 MSS, all'inizio abbiamo: 
`S1, S2, S3, S4`
Quando S1 arriva al destinatario, viene inviato: 
$$
ACK = 250
$$
e così S1 non è più un segmento non riscontrato, questo vuol dire che la nostra nuova finestra non è più
`S1 S2 S3 S4` ma diventa `S2 S3 S4 S5` dopo l' ACK di S1. 
S5 ha `seq = 1000` e arriva al ricevente, ma il ricevente sta ancora aspettando `250`. 
Quindi S5 è fuori ordine e non può essere consegnato al processo destinatario, per questo viene messo in un buffer e il destinatario invia ancora: 
$$
ACK = 250
$$
Ora è il terzo ACK ripetuto, quindi scatta *fast retransmit*.
A questo punto il mittente ritrasmette S2, non aspettando il timeout di 1s perché viene recuperato molto prima del timeout.
Quindi ora il ricevente possiede tutti i segmenti e può ricostruire tutto il flusso, facendo avanzare l'ACK finale. 
#### Ordine degli eventi: 
Trasmettiamo all'istante t = 0, quindi il primo segmento arriva al ricevente in tempo: 
```
t = 0 inizio trasmissione
t = 80μs arriva al ricevente

```
A questo punto il ricevente deve inviare l'ACK per la conferma di ricezione del segmento, il ritardo generato dall'ACK è solo quello di propagazione, ovvero 60μs: 
$$
80+60=140\mu s
$$
Gli altri segmenti non aspettano che S1 arrivi al destinatario, essi partono dopo la trasmissione di S1: 
```
t = 0 S1 viene trasmesso
t = 20μs S2 viene trasmesso
t = 40μs S3 viene trasmesso
t = 60μs S4 viene trasmesso
```
S2 viene perso, lo vediamo dopo. 
S3 termina la trasmissione a `60μs` e arriva al ricevente in `60+60=120μs`
S4 termina la trasmissione a `80μs` e arriva al ricevente in `80+60=140μs
`
A `140μs S1 arriva l'ACK di S1` quindi la finestra può avanzare e il mittente può inviare S5. 
`t=140μs` il mittente invia S5 che finisce la trasmissione a `t = 160μs` e arriva al destinatario in `t=220μs` a questo istante sono arrivati S1, S3, S4, S5 ma manca ancora S2. 
Quindi il destinatario manda anche per S5 ACK = 250 che si propaga in `60μs` e quindi a tempo: 
`t=280μs` viene ricevuto l'ack dal mittente. 
A tempo `t=280μs` il mittente riceve il terzo ACK duplicato. A questo punto avviene il **fast retransmit**. S2 viene ritrasmesso a `t=280μs` e termina la ritrasmissione a `t=300μs`, arriva al ricevente all'istante `t=360μs` , a questo punto viene inviato l'ultimo ACK: 
$$
ACK = 1250
$$
Che si propaga all'istante `t=420μs`. 

# Domanda 2
Considerando router e link-layer switch impiegati per la commutazione di pacchetto, affrontare i seguenti punti:

**1.** Si descriva il funzionamento dei router e degli switch, evidenziando le principali differenze tra i due dispositivi.

**2.** Si descriva il funzionamento del piano di forwarding di un router e di uno switch.

**3.** Si descriva come uno switch costruisce la propria tabella di inoltro tramite il meccanismo di autoapprendimento.

**4.** Si discuta come router e switch contribuiscono all'isolamento del traffico e alla scalabilità della rete.

**5.** Si introduca infine il paradigma **SDN (Software-Defined Networking)**, evidenziandone le principali caratteristiche e differenze rispetto all'architettura tradizionale.

## Risposta
Il router è un dispositivo che opera nel layer 3 della pila di internet, che interconnette reti differenti e inoltra pacchetti verso la destinazione. 
Un router possiede delle porte di ingresso, che servono per ricevere i pacchetti in entrata, il router utilizza poi l'IP destinazione per determinare su quale porta di uscita inoltrare il pacchetto. 
Il trasporto del pacchetto dalla porta di ingresso alla porta di uscita è compito dello **switching fabric**. La porta di uscita è dove il pacchetto viene preparato per essere trasmesso sul collegamento successivo. 
Uno Switch svolge la stessa funzione del router ma opera al layer 2,  lo switch inoltra i frame sulla base di indirizzi MAC. 
Un'altra differenza è che i router selezionano i percorsi per il transito dei pacchetti nelle reti e raggiungere le loro destinazioni. Per questo i router si connettono con reti diverse e inoltrano i dati da una rete all'altra. 
Il router esegue il forwarding, una funzione locale:  quando arriva un pacchetto, il router determina da quale porta di uscita deve essere inoltrato, la scelta della porta non è casuale ma  consultando la tabella di inoltro che ogni router possiede. 
Il forwarding in uno switch è il processo in cui uno switch riceve un frame ethernet su un'interfaccia di ingresso e decide dove inviarlo, lo switch è un dispositivo *store-and-forward* e trasparente agli host, l'inoltro si basa sull'analisi dell'indirizzo MAC di destinazione contenuto nell'intestazione del frame e sulla consultazione della tabella di commutazione. 
Lo switch costruisce la propria tabella di inoltro utilizzando *l'auto-apprendimento* , ovvero,
quando un frame giunge su un'interfaccia dello switch, questo analizza l'indirizzo MAC sorgente e associa quell'indirizzo MAC al numero di porta a cui è stato inviato il frame. 
Per inoltrarlo al destinatario controlla la propria tabella di inoltro, se il destinatario è presente, invia il frame sulla porta corrispondente nella tabella, altrimenti esegue il flooding. 
Il flooding consiste nell'inviare quel frame a tutte le porte appropriate ad eccezione della porta da cui il frame è arrivato, in seguito, lo switch aggiungerà una nuova voce alla tabella di inoltro. Se il nodo destinatario si trova sullo stesso segmento fisico condiviso da cui è arrivato, lo switch scarterà il frame, questo è il *filtraggio*. 
Uno switch inoltra un frame sulla porta appropriata quando conosce il MAC di destinazione, invece di inviarlo a tutte le porte. Questo limita il traffico inutile sugli altri segmenti. 
Un router, invece, costruisce un confine tra reti differenti e impedisce che il traffico di una rete venga automaticamente propagato alle altre reti.
Nel modello tradizionale, ogni router ha il proprio piano di controllo, ovvero il sistema che decide come e dove inviare i dati. 
Ogni router esegue protocolli come OSPF, RIP, BGP e comunica con gli altri router per condividere le proprie informazioni di routing. Con Software-defined-network il piano di controllo viene separato dal piano dei dati, abbiamo un controller SDN che controlla gli switch della rete.SDN separa il piano di controllo dal piano dei dati, permettendo di programmare e modificare il comportamento della rete tramite software. 
Il controller SDN può decidere: 
- Quali percorsi utilizzare 
- Quali pacchetti bloccare 
- Come bilanciare il traffico
- Quali regole installare nella flow table
Gli elementi fondamentali nell'architettura SDN sono sicuramente lo switch sul piano dei dati e il controller SDN, il quale mantiene informazioni di stato sulla rete, comunica con gli switch e permette alle applicazioni di controllo di interagire la rete. 
