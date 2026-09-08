
# Rendere l'instradamento scalabile
**Il routing che abbiamo studiato finore funziona bene su una rete piccola, ma internet è enorme.**

In [[Funzioni del livello di rete | funzioni del livello di rete]] abbiamo visto due algoritmi di instradamento, ma applicarli ad internet sarebbe particolarmente ostico. 
In internet abbiamo miliardi di destinazioni, è impossibile mettere tutte le destinazioni nelle tabelle di ogni router.
Nel link state, diffondere continuamente informazioni sulla topologia di tutta Internet sarebbe enorme.
Nel distance vector la convergenza potrebbe diventare lentissima.
Inoltre internet non è amministrata da una sola organizzazione, perciò Internet viene divisa in **Sistemi Autonomi.**

## #🔑 Cos'è un AS?
Un autonomous system è **una rete, o un'insieme di reti, gestita dalla stess amministrazione e che applica una propria politica di routing.**
Ogni AS ha un identificatore chiamato **ASN (Autonomous system number).**
All'interno di ogni AS possiamo usare un protocollo di routing **intra-AS.**
Tra AS diversi usiamo invece il routing **inter-AS.**
### Router gateway?
Un router gateway è un router che si trova sul bordo dell'AS e che è collegato a uno o più router appartenenti ad altri AS. 
Quindi è il punto attraverso il traffico può uscire dal proprio AS o entrarvi. 

# Come si costruisce la tabella di inoltro 
Intra AS e inter AS routing servono per costruire la tabella di inoltro del router. 
Abbiamo un router dentro AS1, arriva un `pacchetto destinazione = X`. Come fa il router a sapere **su quale interfaccia mandarlo?**
La risposta è che dipende da dove si trova X.

### #📦 Destinazione dentro lo stesso AS
Se X si trova all'interno di AS1, basta il routing intra-AS. Il protocollo routing calcola il percorso e permette di sapere: 
	"Per raggiungere X, devo usare questa interfaccia."
Questa informazione finisce **nella tabella di inoltro.**

### #🌐 Destinazione fuori dall'AS
Supponiamo che AS1 sia collegato ad AS2 e AS3, il router dentro AS1 deve prima sapere: 
	**Attraverso quale AS posso raggiungere X?**
Questa informazione viene ottenuta tramite **inter-AS routing**. 
Se, ad esempio, X è raggiungibile tramite AS2, a questo punto il router deve ancora sapere: 
	**"Quale router gateway di AS1 devo usare per arrivare ad AS2?"**
E a questo punto entra in gioco l'**intra-AS routing.**

## #📌 L'inter-AS influenza anche l'inoltro intra-AS
Un router dentro `AS1` riceve un datagramma destinato fuori da `AS1`: **a quale gateway deve mandarlo?**. 
Supponiamo questo collegamento: 
                 AS3
                  │
                gateway
                  │
AS1 ──────────────┼──────── AS2
                  │
                gateway

Supponiamo che `AS1` abbia due possibilità: 
X $\rightarrow$ AS2
X $\rightarrow$ AS3

Il router interno deve sapere **quale gateway utilizzare.**
Per questo l'instradamento **inter-AS in AS1** deve fare due cose: 

### 1. Imparare le destinazioni raggiungibili
Deve sapere che, se vuole raggiungere una certa destinazione, deve passare per un certo AS
### 2. Diffondere questa informazione nell'AS
Non basta che lo sappia solamente il router gateway. 
L'informazione deve essere propagata agli altri router di `AS1`. 
Così un router interno può costruire la propria tabella di inoltro. 


# #🌐 Instradamento inter-AS
I protocolli di instradamento inter-AS sono: 
- **RIP: Routing Information Protocol**
		DV classico: DV scambiati ogni 30 secondi
- **EIGRP: Enhanced Interior Gateway Routing Protocol**
		basato su DV
		precedentemente di proprietà di Cisco per decenni
- **OSPF: Open Shortest Path First**
		Instradamento link-state
			Protocollo IS-IS(ISO standard, non standard RFC) essenzialmente identico a OSPF

# #📌 OSPF(Open shortest Path first)
"aperto": disponibile pubblicamente 
classico link-state: 
	ciascun router utilizza il *flooding* per inviare in broadcast le informazioni circa lo stato dei collegamenti a tutti gli altri router nell'intero AS. 
	Costo dei collegamenti: inversamente proporzionale alla larghezza di banda.
	Ogni router dispone di una topologia completa e utilizza Dijkstra per calcolare la tabella di inoltro. 

# #🧠 ECMP (Equal-Cost Multi-Path) routing
L'instradamento ECMP consente di instradare pacchetti ad una stessa destinazione mediante diversi percorsi di costo uguale, *aumentando la larghezza di banda.*
Un pacchetto che deve inoltrare un pacchetto fa load balancing tra i possibili next-hop:
- **Per flusso:** il router utilizza una funzione di hash sui campi che identificano il flusso, da quei valori calcola l'hash e decide quale next-hop utilizzare. 
- **Per destinazione:** la funzione di hash in questo caso, utilizza come unico input *l'indirizzo IP di destinazione*, tutti i pacchetti diretti verso `X` avranno lo stesso percorso, anche se provengono da host differenti. 
- **Per pacchetto:** qui il router può scegliere un percorso diverso per ogni singolo pacchetto, questo può creare problemi per TCP: 
	- Consegna fuori ordine 
	- Variabilità del ritardo 
	- Variabilità della MTU minima

## #📌 OSPF gerarchico 
Finora abbiamo visto OSPF dove tutti i router conoscono la topologia e usano dijkstra. 
Il problema è che, se l'AS diventasse enorme, far conoscere a tutti i router tutta la topologia sarebbe poco scalabile. 
La gerarchia è a due livelli: 
- **area locale $\rightarrow$** una parte dell'AS
- **backbone $\rightarrow$** la dorsale che collega le varie aree
Gli annunci link-state vengono inondati soltanto nella propria area locale o della dorsale, invece che in tutto l'AS. 

## #🔑 Instradamento Internet inter-AS: BGP 
 **BGP (Border Gateway Protocol):** è il protocollo per l'instradamento inter-domain. Permette alla sottorete di pubblicizzare la sua esistenza e le destinazioni che può raggiungere al resto di internet. 
 BGP fornisce a ciascun AS un mezzo per: 
 - Ottenere informazioni sulla raggiungibilità dei prefissi di sottorete da parte dei sistemi confinanti. 
 - Determinare le rotte verso altre reti in base alle informazioni di raggiungibilità e di politiche. 
 - Propagare le informazioni di raggiungibilità a tutti i router interni all'AS. 
 - Annunciare le informazioni sulla raggiungibilità delle destinazioni. 
## Nozioni di base su BGP 
**Sessione BGP:** due router BGP si scambiano messaggi BGP attraverso una connessione TCP semi-permanente. 
- Annunciare percorsi verso diversi prefissi di rete 
- Quando il gateway 3a di AS3 annuncia il percorsa AS3,X al gateway 2c di AS2: 
![[Pasted image 20260908134606.png]]

### #🔑 Messaggi del protocollo BGP
- I messaggi BGP sono scambiati tra peer su connessioni TCP 
- Messaggi BGP: 
	- **OPEN:** apre la connessione TCP al peer BGP remoto e autentica il peer BGP mittente 
	- **UPDATE:** annuncia un nuovo percorso
	- **KEEPALIVE:** mantiene in vita la connessoine in assenza di update; inoltre ACK della richiesta OPEN. 
	- **NOTIFICATION:** viene utilizzato per chiudere la connessione, ma anche per segnalare errori nel messaggio precedente.

## Attributi dei percorsi e rotte BGP 
**Rotta annunciata da BGP:** prefisso+attributi
- prefisso: la destinazione che viene annunciata. 
- due attributi importanti: 
	- *AS-PATH* elenco degli AS attraverso i quali è passato l'annuncio del prefisso. 
	- *NEXT-HOP:* Indirizzo IP dell'interfaccia del router che inizia l'AS-PATH. 

**Instadamento basato su politiche:** 
- Un gateway che riceve un annuncio usa una import policy per accettare/declinare il percorso.
- Le politiche dell'AS determinano anche se annunciare un percorso ad altri AS vicini. 

### Instradamento a patata bollente
Sceglie la rotta con router NEXT-HOP che ha il minimo costo *intra-AS* e non si preoccupa del costo complessivo del percorso. 

## Selezione delle rotte BGP
Un router può conoscere più di un percorso verso l'AS di destinazione, seleziona il percorso in base a: 
- Valore dell'attributo di preferenza locale (policy)
- AS-PATH più breve 
- Router NEXT-HOP più breve
- Identificatori BGP 

### Implementare BGP attraverso gli annunci
L'ISP vuole instradare il traffico solo verso/da le reti di propria di competenza. 
![[Pasted image 20260908140420.png]]

- A annuncia il percorso Aw a B e C 
- B sceglie di non annunciare BAw a C
- C instraderà CAw per raggiungere w non conoscendo il percorso CBAw

# #🌐 Perché diversi instradamenti Intra e Inter-AS?

**Politiche:**
- Inter-AS: l'amministratore vuole avere il controllo sul modo in cui viene instradato il traffico e su chi passa attraverso la sua rete.  
- Intra-AS: singolo amministratore, quindi le politiche meno rilevanti. 

**Scalabilità:**
- Routing gerarchico: limita l'ambito delle informazioni dettagliate al singolo AS. 
- Instradamento BGP verso prefissi per supportare un gran numero di destinazioni

**Prestazioni:**
- Intra-AS: può concentrarsi sulle prestazioni
- Inter-AS: le politiche sono dominanti rispetto alle prestazioni

---

# #🔑 SDN (Software Defined Network)

Nel modello tradizionale, ogni router ha il proprio piano di controllo.
Ogni router esegue protocolli come **OSPF, RIP, BGP**, comunica con gli altri router e calcola le proprie informazioni di routing, quindi il controllo è distribuito e per router. 
Con **Software-Defined Network**, il piano di controllo viene separato dal piano dei dati. 
Invece di avere un'intelligenza di routing dentro ogni switch/router, abbiamo un **controller SDN** che controlla gli switch della rete. Il controller controlla e installa le tabelle di inoltro negli switch. 
Si chiama *software redefined* perché il comportamento della rete viene ridefinito tramite software. Gli switch non devono necessariamente contenere tutta la logica necessaria per decidere autonomamente i percorsi. 
Il controller può decidere: 
- Quali percorsi utilizzare; 
- Quali pacchetti bloccare; 
- Come bilanciare il traffico; 
- Quali regole installare nelle flow table; 
Le applicazioni di controllo possono occuparsi, ad esempio, di routing, controllo degli accessi e bilanciamento del carico.

**Elementi fondamentali dell'architettura SDN**
1. Switch del piano dei dati 
	Sono switch veloci e semplici che effettuano l'inoltro in hardware. 
	Utilizzano una **flow table**, cioè una tabella di regole che dice cosa fare quando arriva un pacchetto. 
2. #🧠 **Controller SDN** 
	E' il componente centrale del piano di controllo.
	Il controller: 
	- Mantiene le informazioni sullo **stato della rete**
	- comunica con gli switch
	- riceve informazioni degli switch
	- permette alle applicazioni di controllo di interagire contro la rete. 

## Applicazioni di controllo di rete
Sopra il controller possiamo avere applicazioni che implementano le funzioni di controllo. Queste applicazioni sono una sorta di **"cervello"** della rete: utilizzano i servizi messi a disposizione dal controller tramite API.

### Northbound e Southbound API
Il controller ha due direzioni di comunicazione. 

**Northbound API**
Collega: 
*applicazioni $\rightarrow$ switch*
Le applicazioni richiedono al controller di realizzare determinati comportamenti. 

**Southbound API**
Collega: 
*controller $\rightarrow$ switch*

Il controller comunica agli switch le regole da installare.
Uno degli esempi principali è OpenFlow. 

# #🔑 Intent-based networking

1. L'utente esprime in forma dichiarativa un obiettivo di alto livello, ovvero **l'intento**. 
2. Il sistema determina come realizzare l'obiettivo richiesto, attraverso l'opportuna allocazione e configurazione delle risorse. 
3. Il sistema può garantire che l'obiettivo rimanga soddisfatto nel tempo, attraverso il monitoraggio della rete e interventi corretti automatici. 
## SDN: sfide selezionate
1. Hardening del piano di controllo
Il problema principale è: il controller SDN è fondamentale per la rete. Se il piano di controllo ha problemi, tutta la rete può risentirne. 
Per questo si vuole rendere il controller: 
	Scalabile $\rightarrow$ deve riuscire a gestire reti molto grandi
	robusto ai guasti $\rightarrow$ se qualcosa si rompe, la rete deve continuare a funzionare
	sicuro $\rightarrow$ deve essere protetto da attacchi e accessi indesiderati 

2. Dependability
	dependability = capacità di un sistema di fornire un servizio affidabile nel tempo
	viene considerata attraverso: 
	- availability $\rightarrow$ quanto tempo il sistema è operativo
	- reliability $\rightarrow$ quanto riesce a funzionare correttamente senza interruzioni
	- safety $\rightarrow$ posizione degli incidenti
	- security $\rightarrow$ protezione da intrusioni/accessi indesiderati

### 3. 🚀 Reti con requisiti particolari

L'SDN deve poter essere utilizzato anche in reti che hanno requisiti molto specifici, ad esempio:

- **tempo reale**;
    
- **ultra-affidabilità**;
    
- **ultra-sicurezza**. 
    

Quindi non basta avere un controller "comodo da programmare": deve essere abbastanza affidabile e veloce anche in situazioni dove un errore può essere molto grave.

---

### 4. 🌍 Andare oltre un singolo AS

Un'altra sfida è usare l'SDN **oltre i confini di un singolo Autonomous System**.

Finora abbiamo ragionato spesso così:

```
        AS 1
   ┌─────────────┐
   │ SDN         │
   │ Controller  │
   └─────────────┘
```

Ma Internet è composta da **tantissimi AS**, appartenenti ad amministratori diversi.

Quindi nasce il problema:

> **Come faccio a coordinare SDN appartenenti a domini amministrativi differenti?**

È molto più complicato perché entrano in gioco **autonomia amministrativa, sicurezza e policy**. La slide lo indica semplicemente come una delle sfide future.

### 5. 📱 SDN e 5G

Infine, la slide sottolinea che:

> **l'SDN è fondamentale per le reti cellulari 5G.**

Il motivo concettuale è che il 5G richiede una rete molto **programmabile, flessibile e dinamica**, caratteristiche che si sposano bene con l'approccio SDN.