

**Che cosa fa il livello di rete?**
Il livello di rete ha il compito di portare un pacchetto dall'host mittente all'host destinatario, attraversando eventualmente diversi router. 
Il livello di trasporto, studiato precedentemente, si occupa della comunicazione tra processi.

# Funzioni del livello di rete

1. **Inoltro**
	E' un'operazione locale al singolo router, il router riceve un pacchetto e deve decidere da quale porta di uscita mandarlo. 
2. **Instradamento**
	L'instradamento è il problema più generale: 
		**Quale percorso deve seguire il pacchetto dalla sorgente alla destinazione?**
	Il routing sceglie quale percorso utilizzare, e per farlo, vengono utilizzati degli **algoritmi di instradamento**
## Piano dei dati e piano di controllo 

### Piano dei dati
Si occupa dell'inoltro. E' una funzione locale del router: 

pacchetto in ingresso
        │
        ▼
    tabella 
        │
        ▼
porta di uscita

Deve essere estremamente veloce, perché deve essere eseguita per ogni pacchetto. 

### Piano di controllo
Si occupa dell'instradamento. Deve determinare come i pacchetti dovranno essere instradati attraverso i vari router. Opera su una scala temporale più lenta rispetto al forwarding, occupandosi di determinare e aggiornare le informazioni necessarie all'instradamento.

#remember 
## Forwarding e Routing

Il **forwarding (inoltro)** è una funzione locale del router: quando un
pacchetto arriva, il router determina **da quale porta di uscita deve
essere inoltrato**.

Il **routing (instradamento)** riguarda invece la scelta del **percorso
complessivo** che i pacchetti devono seguire dall'host sorgente all'host
destinatario.

Possiamo quindi distinguere:

- **Piano dei dati → Forwarding** → fa avanzare concretamente i pacchetti.
- **Piano di controllo → Routing** → determina il percorso che i pacchetti
  devono seguire.

> **Routing = quale percorso?**
>
> **Forwarding = quale uscita del router?**


## Routing tradizionale vs SDN 

1. **Routing tradizionale**
Nel modello tradizionale, ogni router partecipa al processo di routing. In pratica, i router comunicano tra loro e utilizzano degli algoritmi/protocolli di instradamento per determinare i percorsi. Ogni router contribuisce quindi a costruire le informazioni necessarie per sapere dove inoltrare i pacchetti. Il risultato del routing  viene utilizzato sul piano dei dati, che poi effettua concretamente il forwarding 

2. **SDN Software Defined Networking**
Con SDN cambia l'organizzazione del piano di controllo. Invece di avere il controllo dell'instradamento distribuito nei singoli router, viene introdotto un controllore separato. Il controller ha una visione della rete e può determinare le regole di inoltro da installare nei dispositivi. 
SDN separa il piano di controllo dal piano dei dati. 
Il controller determina le **regole di inoltro**, mentre i dispositivi del piano dei dati le applicano per effettuare concretamente il forwarding.

# Architettura del router 
![[Pasted image 20260901232504.png]]

1. Porte di ingresso 
	Il pacchetto arriva al router tramite una porta di ingresso. La porta di ingresso si occupa di ricevere il pacchetto dal collegamento fisico e di elaborarlo al livello di collegamento e al livello di rete. 
	
	Pacchetto
	   ↓
	porta di ingresso
	   ↓
	controllo / elaborazione
	
	Il router utilizza principalmente l'**indirizzo IP di destinazione** e la propria tabella di forwarding per determinare la porta di uscita.

2. Switching fabric
	Una volta che il router ha deciso la porta di uscita, il pacchetto deve essere trasferito fisicamente/logicamente dall'ingresso all'uscita corretta. 
	Qui entra in gioco lo switching fabric. Quest'ultimo è il meccanismo interno che collega la porta di ingresso alla porta di uscita. Si può vedere lo switching fabric come la rete interna del router, che permette di spostare il pacchetto dalla porta da cui è entrato alla porta da cui dovrà uscire. 
	
3. Porte di uscita
	Il pacchetto arriva quindi alla porta di uscita. Qui viene preparato per essere trasmesso sul collegamento successivo.
	
	Pacchetto
	   ↓
	porta di ingresso
	   ↓
	controllo / elaborazione

	Ma qui si presenta un problema: **la coda**.
	Se arrivano pacchetti più velocemente di quanto la porta di uscita riesca a trasmetterli, i pacchetti devono aspettare in un buffer/coda.
	Se la coda diventa troppo lunga, il router può arrivare a scartare pacchetti.
	IP non garantisce che il pacchetto arrivi a destinazione; se un router è congestionato e non ha più spazio nel buffer, può scartarlo. 

4. Processore di instradamento
C'è poi il routing processor, cioè il processore di instradamento. Questo appartiene principalmente al piano di controllo. Si occupa delle funzioni necessarie per determinare le informazioni di routing, mentre le porte e la switching fabric partecipano al lavoro del piano dei dati. 
Il routing processor contribuisce a determinare le informazioni necessarie al forwarding; le porte e la switching fabric permettono poi di inoltrare concretamente i pacchetti. 

# Commutazione attraverso rete di interconnessione

- rete crossbar, reti clos e altre, sono reti di interconnessione sviluppate originariamente per architetture multiprocessore. Multistage switch: switch nxn da più stadi di switch più piccoli. 
- sfruttare il parallelismo: 
	- frammenta il datagramma in celle di lunghezza fissa all'ingresso. 
	- commutare le celle attraverso la rete di commutazione, riassemblare il datagramma in uscita. 
- Scalare utilizzando molteplici piani di commutazione in parallelo
	- speedup, scaleup grazie al parallelismo

- CISCO CSR Router: 
	- unità di base: 8 switching plane 
	- ogni plane: rete di interconnessione a 3 stadi 
	- capacità di commutazione, fino a centinaia di Tbps

## Accodamento sulle porte di ingresso
Quando i pacchetti arrivano alle porte di ingresso di un router, devono essere trasferiti attraverso la **switching fabric** verso la corretta porta di uscita. Se la switching fabric non è immediatamente disponibile o se più pacchetti devono essere trasferiti verso la stessa porta di uscita, alcuni pacchetti possono dover **attendere in una coda sulla porta di ingresso.**
Un problema importante è il **Head-of-the-Line (HOL) blocking**. 
Questo fenomeno si verifica quando il primo pacchetto di una coda è bloccato, in quanto la porta a cui deve essere inoltrato è bloccata, ciò causa un problema perché nella coda possono essere presenti pacchetti che devono essere inoltrati su altre porte che potrebbero essere libere. 

## Accodamento in uscita 
Quando un pacchetto attraversa la switching fabric, viene portato verso la porta di uscita corretta. Il problema nasce quando più pacchetti vengono portati alla stessa porta di uscita. La porta di uscita può trasmettere un solo pacchetto alla volta sul link. 

Quindi: 
1. P1 arriva alla porta di uscita; 
2. P2 arriva mentre P1 sta ancora venendo trasmesso; 
3. P3 arriva subito dopo; 
4. P2 e P3 devono aspettare in coda. 
Questa è l'**output queuing** e può essere un problema quando i pacchetti arrivano più velocemente di quanto la porta riesca effettivamente a trasmetterli; in quanto la coda è limitata, se arrivasse un altro pacchetto mentre questa è piena, il router sarebbe costretto a scartarlo. 
Proprio per questo motivo IP service è **Best effort:** se i buffer sono pieni, alcuni pacchetti possono essere persi.

La differenza importante è questa:

>**Input queuing** → il pacchetto aspetta **prima della switching fabric**.
  **Output queuing** → il pacchetto ha già attraversato la switching fabric e aspetta **prima di essere trasmesso sul link di uscita**.

#remember 
Nell'accodamento in uscita, più pacchetti destinati alla stessa porta di uscita competono per lo stesso link; quelli che non possono essere trasmessi immediatamente vengono messi in coda e, se il buffer si riempie, possono essere scartati.

### Quanta memoria buffer è necessaria?
RFC 3439 Rule of thumb: buffering medio uguale al prodotto del RTT "tipico", diciamo 250 ms per la capacità del collegamento C. 
- Raccomandazione più recente: con N flussi, dimensione del buffer: 
	$$
	\frac{{RTT}*C}{\sqrt{N}}
	$$
Troppo buffering può, però, **aumentare i ritardi** 
RTT elevato: prestazioni scarse delle applicazioni real-time, mittenti TCP meno reattivi alla congestione e alla perdita dei pacchetti. 
#remember 
*"mantenere il collegamento collo di bottiglia sufficientemente pieno ma non più pieno"*

# Gestione del buffer
Come gestisce il router il buffer? Sopra abbiamo accennato a qualcosa, vediamo più nel dettaglio.

### Quando il buffer è pieno

Se il buffer è pieno e arriva un nuovo datagramma, il router deve decidere: 
	**Quale pacchetto elimino?**
Questa è la **drop policy**, politica di scarto. 

#### Tail drop
La politica più semplice è il tail drop: 

>Se il buffer è pieno, **scarto il pacchetto appena arrivato.**

**Priorità**
Un'altra possibilità è utilizzare una politica basata sulla priorità. I pacchetti possono essere trattati secondo classi di priorità; quando è necessario liberare spazio, la politica di gestione può favorire alcune classi rispetto ad altre.

# Schedulazione dei pacchetti
## FCFS 
First come first served, i pacchetti vengono trasmessi in ordine di arrivo alla porta di uscita. 

## Priority
Traffico in arrivo classificato e accodato per classi. **Qualsiasi campo di intestazione può essere usato per la classificazione**. Invia il pacchetto dalla coda non vuota con priorità più alta, dentro ogni classe viene utilizzato **FCFS**.  Il rischio di questo meccanismo di schedulazione è la *starvation*, un pacchetto può attendere indefinitamente se continuano ad arrivare pacchetti con priorità maggiore. 

## Round Robin 
Il traffico in arrivo viene, anche qui, accodato per classi. Il server esegue ciclicamente e ripetutamente la scansione delle code di classe, inviando a turno un pacchetto completo di ogni classe. 

## Weighted fair queuing (WFQ)
E' una generalizzazione del round robin. Ciascuna classe, i, ha un peso, $w_{i}$ e riceve una quantità ponderata di servizio in ogni ciclo:
$$
\frac{w_{i}}{\sum_{j}{w_{j}}}
$$
Se una classe ha peso maggiore, riceve una quota maggiore della capacità disponibile.
Questo algoritmo garantisce a ciascuna classe una **quota minima di servizio proporzionale al proprio peso**, quando la classe ha traffico da trasmettere.


## Barra laterale: Neutralità della rete
Che cos'è la neutralità della rete?
>è il principio secondo cui il provider internet dovrebbe trattare i dati degli utenti senza discriminazioni basate sul contenuto, sull'applicazione, sul servizio o sul mittente/destinatario. 

**Nel 2015 la FCC introdusse tre regole fondamentali nell'Open Internet Order:**
- no blocking … “non bloccherà i contenuti, le applicazioni, i servizi o i dispositivi
	non dannosi leciti, fatta salva una ragionevole gestione della rete.”
	
- no throttling … “non devono pregiudicare o degradare il traffico Internet lecito
	sulla base del contenuto, dell'applicazione o del servizio Internet o dell'uso di un
	dispositivo non dannoso, fatta salva una ragionevole gestione della rete.”
	
-  no paid prioritization. … “non deve impegnarsi nella prioritizzazione a
	pagamento". 
	
Nel 2017 la *restoring internet freedom order* ha annullato questi divieti, concentrandosi maggiormente sulla trasparenza degli ISP. 


[[IP_Protocol | IP]]
