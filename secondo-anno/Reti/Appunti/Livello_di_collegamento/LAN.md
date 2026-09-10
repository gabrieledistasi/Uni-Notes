# #🌐 LAN (Local Area Network)
Copre un'area limitata come un'abitazione, una scuola, un ufficio o un edificio. 
Le tecnologie principali delle reti LAN sono: 
- Ethernet: IEEE 802.3
- Wi-Fi: IEEE 802.11

## Indirizzi MAC 
### IP vs MAC

Un **indirizzo IP**:

- appartiene al livello di rete;
- è usato per l'inoltro dei **datagrammi IP**;
- è gerarchico;
- dipende dalla sottorete.

Un **indirizzo MAC**:

- appartiene al livello di collegamento;
- identifica un'interfaccia di rete;
- viene utilizzato per consegnare un **frame** all'interfaccia collegata localmente;
- è lungo normalmente **48 bit**;
- viene rappresentato in esadecimale.

Ciascuna interfaccia in una LAN 
- Ha un indirizzo MAC univoco
- Ha un indirizzo IP univoco

Allocazione degli indirizzi MAC gestita dall'IEEE, i produttori comprano porzioni dello spazio degli indirizzi MAC. 
#remember 
> Possiamo immaginare gli indirizzi MAC come il codice fiscale mentre gli indirizzi IP come il codice postale. 

Indirizzo MAC: portabilità
- è possibile spostare un'interfaccia da una LAN a un'altra. 
- Indirizzo IP non portabile: dipende dalla sottorete IP alla quale il nodo è connesso

# Protocollo per la risoluzione degli indirizzi (ARP)
Come possiamo determinare l'indirizzo MAC di un'interfaccia conoscendo il suo IP?
Qui viene utilizzato ARP: 
**La tabella ARP** è una tabella presente in ogni router/host per ciascuna interfaccia. 
Una voce di questa tabella è, ad esempio: 
`< IP address ; MAC address ; TTL >`
Il TTL indica per quanto tempo la corrispondenza viene mantenuta. 
Dopo la scadenza: 

> La voce viene modificata

**La tabella ARP non contiene necessariamente tutti i dispositivi della LAN.**
Una corrispondenza può:
- Non essere mai stata inserita.
- Essere stata rimossa perché è scaduto il TTL

## ARP in azione
Immaginiamo che A voglia mandare il datagramma a B. 

#### 1. A non conosce l'indirizzo MAC di B
A invia una **ARP request in broadcast**. 
Destinazione Ethernet: 
`FF-FF-FF-FF-FF-FF`
Quindi tutti i dispositivi della LAN ricevono la richiesta. 
La richiesta contiene: 
```
Sender IP  = IP_A
Sender MAC = MAC_A

Target IP  = IP_B
Target MAC = 00-00-00-00-00-00
```

La domanda implicita è: 
**Chi possiede IP_B? Mi dica il proprio MAC**

#### 2. B riconosce il proprio IP
B risponde con una **ARP reply.**
Questa volta non in broadcast ma destinata solo ad A.
```
Sender IP  = IP_B
Sender MAC = MAC_B

Target IP  = IP_A
Target MAC = MAC_A
```

#### 3. A aggiorna la tabella ARP 
A riceve la risposta e memorizza: 
`IP_B → MAC_B`
Da questo momento può costruire il frame ethernet destinato a B. 

# ARP spoofing
**ARP è stateless.**
Significa che un host può aggiornare la propria tabella ARP anche quando riceve una risposta che non aveva richiesto. 
Un attaccante può quindi inviare una risposta ARP falsa: 
`IP_B → MAC_attaccante`
facendo credere agli altri dispositivi che il suo MAC corrisponde all'IP di B. 

# #🌐 Come inviare un datagramma a un nodo esterno alla sottorete
A vuole mandare un datagramma a B. 
### 1. A capisce che B è in un'altra sottorete
A conosce: 
```
IP_A = 111.111.111.111
IP_B = 222.222.222.222
```
e sa di appartenere a: 
```
111.111.111.0/24
```
Confrontando i **24 bit della rete**, vede che: 
```
111.111.111.xxx
222.222.222.xxx
```
sono diversi. 

Quindi B non è nella stessa sottorete di A. 
A non deve cercare il MAC di B. 
Deve invece mandare il frame al router R, che è il default [[Autonomous_system|gateway]].

### 2. A deve conoscere il MAC di R
A conosce l'IP dell'interfaccia di R nella propria sottorete: 
`IP_R = 111.111.111.110`
Questo può essere ottenuto tramite [[DHCP|DHCP]]. 
Ma per creare il frame Ethernet A deve conoscere anche: 
`MAC_R = E6-E9-00-17-BB-4B`. 
Se non lo conosce, utilizza ARP. 

**Per una destinazione esterna alla sottorete, ARP viene utilizzato per trovare il MAC del router, non il MAC della destinazione finale.**

### 3. A crea il datagramma IP 
A crea il normale datagramma IP: 
```
IP sorgente      = 111.111.111.111  (A)
IP destinazione  = 222.222.222.222  (B)
```
**Gli indirizzi IP sono quelli di A e B e rimangono gli stessi durante questo tratto del percorso.**

### 4. A incapsula il datagramma in un frame Ethernet
Il frame Ethernet ha: 
```
MAC sorgente      = MAC_A
MAC destinazione  = MAC_R
```
Quindi: 
```
FRAME ETHERNET
┌───────────────────────────────┐
│ MAC A → MAC R                 │
│                               │
│   DATAGRAMMA IP               │
│   IP A → IP B                 │
└───────────────────────────────┘
```

### 5. R riceve il frame
Il router R riceve il frame Ethernet perché il MAC di destinazione è il suo: 
`MAC_dest = MAC_R`
R rimuove l'incapsulamento Ethernet e passa il datagramma IP al livello IP. 
Il datagramma è ancora: 
```
IP src = 111.111.111.111
IP dest = 222.222.222.222
```
**Il frame cambia, il datagramma no.**

### 6. R decide dove inoltrare il datagramma
Il router guarda l'indirizzo: 
`222.222.222.222`
e consulta la propria tabella di inoltro. 
Determina l'interfaccia di uscita verso la rete di B. 
Poi passa nuovamente il datagramma al livello di collegamento. 

### 7. R crea un NUOVO frame Ethernet 
Questa volta il frame deve viaggiare da R a B. 
Quindi: 
```
MAC sorgente      = MAC_R
MAC destinazione  = MAC_B
```
Mentre dentro rimane: 
```
IP sorgente       = IP_A
IP destinazione   = IP_B
```

Quindi abbiamo: 
```
PRIMO COLLEGAMENTO

MAC_A → MAC_R
IP_A  → IP_B


SECONDO COLLEGAMENTO

MAC_R → MAC_B
IP_A  → IP_B
```

# #🌐 Ethernet
Ethernet è la tecnologia dominante per le reti cablate: 
- Prima tecnologia LAN ampiamente utilizzata. 
- Semplice, economica. 
- Ha tenuto il passo sulla velocità: 10Mbps-400Gbps
- Singolo chip, più velocità. 

## Ethernet: topologia fisica

- **BUS:** popolare fino alla metà degli anni '90. 
	- Tutti i nodi sono nello stesso dominio di collisione
- **Topologia a stella con hub:** Popolare fino agli anni 2000
	- I nodi sono interconnessi da un hub, pertanto tutti i nodi sono nello stesso dominio di collisione. 
- **Commutata (switched):** oggi prevalente
	- *switch* di livello 2 attivo al centro
	- ogni "spoke" esegue un protocollo Ethernet

## Struttura del frame Ethernet 
L'interfaccia trasmittente incapsula il datagramma IP in frame Ethernet. 
![[Pasted image 20260910155938.png]]

*Preambolo*: 
- Usato per risvegliare le schede di rete dei riceventi e sincronizzare i loro clock con quello del trasmittente. 
- 7 byte di 10101010 seguiti da un byte di 10101011, questi ultimi due 1 segnalano al ricevente l'inizio del vero e proprio frame.

*Indirizzi:* Indirizzi sorgente e destinazione a 6 byte. 
- se l'adattatore riceve un frame con un indirizzo di destinazione corrispondente o con un indirizzo di broadcast, passa i dati nel frame al protocollo di livello superiore. 
*Tipo:* Indica un protocollo di livello superiore 
- **Principalmente IP**, ma sono possibili anche altri protocolli a livello di rete
- Utilizzato per demultiplexare sul ricevitore. 
*CRC:* controllo di ridondanza ciclica presso il ricevitore. 
- errore rilevato: il frame viene scartato. 
*Payload:* dati passati al protocollo di livello superiore 
- minimo 46 byte: se più piccolo deve essere aggiunto del padding; perciò è importante che il protocollo di livello superiore preveda un meccanismo per stabilire la reale dimensione dei dati. 
- La fine del frame è determinata a livello fisico dall'assenza di transizioni sulla linea.
- Escludendo il preambolo, la dimensione di un frame è compresa tra *64 bye e 1518 byte*. In Gigabit Ethernet lo slot time è in realtà di 4096 bit: frame più piccoli richiedono l'aggiunta di padding. 

## Ethernet: non affidabile, senza connessione
*Serve connessione:* nessun handshake tra le NIC mittente e ricevente
*Non affidabile:* la NIC ricevente non invia ACK o NAK alla NIC mittente
- I dati nei frame scartati vengono recuperati solo se il mittente iniziale utilizza un trasferimento dati affidabile di livello superiore, altrimenti i dati scartati vanno persi. 
*Protocollo MAC di ethernet:* Unslotted CSMA/CD con binary backoff. 

# #🌐 802.3 Ethernet standard: livelli di collegamento e fisico
Lo standard IEEE definisce caratteristiche sia del: 
- Livello di collegamento
- Livello fisico
La distinzione è importante perché i due livelli si occupano di cose diverse. 

## Livello di collegamento
Qui ethernet definisce principalmente il formato del frame e il funzionamento del protocollo Ethernet. 
Il frame contiene, tra le altre cose: 
```
MAC destinazione
MAC sorgente
dati
CRC
```
Quindi qui siamo nel mondo degli **indirizzi MAC e dei frame.**

## Livello fisico
Qui invece si parla di come i bit vengono effettivamente trasmessi sul mezzo fisico. 
Per esempio:

- tipo di cavo;
- fibra ottica;
- segnali elettrici/ottici;
- velocità di trasmissione.

Quindi:

> **livello di collegamento → cosa contiene e come funziona il frame**

> **livello fisico → come quei bit vengono trasmessi fisicamente**

Perché esistono tanti standard ethernet?
Perché nel corso degli anni sono stati implementati diversi mezzi fisici per Ethernet, il che implica una continua evoluzione. **Sebbene Ethernet rimanga sempre concettualmente lo stesso** il livello fisico utilizzato può cambiare. 

# #🌐 Switch
Uno switch Ethernet è un dispositivo del livello di collegamento che collega più dispositivi all'interno di una **LAN**. 
Lo switch riceve un frame Ethernet su una porta e decide su quale porta inoltrarlo. 
Supponiamo: 
`A → B`
Il frame arriva allo switch: 
```
MAC sorgente      = MAC_A
MAC destinazione  = MAC_B
```
Lo switch deve capire: 
**Su quale porta trovo MAC_B?**
Per farlo utilizza una **switch table**

## Come impara la tabella?
Lo switch utilizza un meccanismo di autoapprendimento, **self-learning**
Quando riceve un frame guarda il **MAC address sorgente.**
E registra:
```
MAC sorgente      = MAC_A
MAC destinazione  = MAC_B
```
Non serve quindi configurare manualmente ogni associazione. 

## E se non conosce la destinazione?
Supponiamo che arrivi: 
`MAC destinazione = MAC_X`
Ma nella switch table non c'è `MAC_X`
Lo switch non sa su quale porta, quindi effettua il **flooding.**
Il frame viene inoltrato sulle altre porte, esclusa quello da cui è arrivato. 
Quando il dispositivo destinatario risponde, lo switch può imparare anche la sua posizione. 

# Switch: filtraggio e inoltro dei frame
Quando uno switch riceve un frame, segue una procedura precisa. 
Supponiamo: 
`A ──(porta 1)── Switch ──(porta 4)── B`
A manda un frame a B. Lo switch riceve il frame dalla porta 1.

### 1. Impara il mittente
Per prima cosa guarda il **MAC sorgente** del frame: 

`MAC sorgente = MAC_A`

e il frame è arrivato dalla porta `1`, registra: 

`MAC_A → porta 1`

nella **switch-table**. 

### 2. Cerca il destinatario
Poi guarda il: 
`MAC destinazione = MAC_B`

e cerca `MAC_B` nella switch table. 
A questo punto abbiamo due possibilità. 

#### Caso 1: conosce il destinatario
Supponiamo che la tabella dica:
```
MAC_A → porta 1
MAC_B → porta 4
```
Quindi: 
```
A
│
│ porta 1
↓
SW
│
│ porta 4
↓
B
```
**Inoltra il frame solo sulla porta 4**, non lo manda sulle altre porte. 

#### Caso 2: non consce il destinatario
```
Supponiamo invece: 
MAC_A → porta 1
MAC_B → ?
```
Lo switch non sa dove si trovi B.
Quindi fa il **flooding**: 
```
             ┌── C
             │
A ─────── SW ├── B
             │
             └── D
```
Il frame viene inviato su **tutte le interfacce tranne quella da cui è arrivato.** 

>**Fare flooding non significa modificare il MAC di destinazione in broadcast**

#### Caso 3: il destinatario è sullo stesso argomento
C'è anche un terzo caso. 
Supponiamo che lo switch sappia: 
`MAC_B → porta 1`
e il frame destinato a B sia arrivato proprio dalla porta 1. 
Significa che sorgente e destinazione sono sullo stesso segmento.
Quindi lo switch **scarta il frame**. 
Non avrebbe senso rimandarlo sullo stesso segmento. 

# #📌 Autoapprendimento dello switch
Lo switch inizialmente non sa dove si trovino i dispositivi. 
**Arriva un frame da A**, A manda un frame verso, per esempio C. Lo switch riceve il frame sulla porta 1. 
La prima cosa che fa è guardare il MAC sorgente: 
```
MAC sorgente = MAC_A
porta di ingresso = 1
```
Quindi impara 
`MAC_A → porta 1`
L'autoapprendimento è quando il router impara la posizione di un host osservando i frame che riceve. 

## Dove si trova C?
Lo switch guarda il MAC di destinazione: 
`MAC destinazione = MAC_C`
Se **non è ancora nella tabella**, lo switch non sa su quale porta mandarlo. 
Quindi fa il **flooding**. 
**C risponde ad A** e il frame arriva allo switch dalla porta 3. 

---
# Switch VS Router

## Switch
- Lo switch lavora al livello di collegamento.
- Guarda il **MAC Address** contenuto nel frame Ethernet
```
Frame Ethernet
┌──────────────┬──────────────┬─────────┐
│ MAC dest.    │ MAC sorgente │  dati   │
└──────────────┴──────────────┴─────────┘
       ↑
    SWITCH
```

La sua tabella contiene: 
`MAC → porta`
e viene costruita tramite **autoapprendimento.**

## Router
- Il router lavora al livello di rete 
- Guarda **l'IP destinazione** del datagramma. 
```
Datagramma IP
┌──────────────┬──────────────┬─────────┐
│ IP sorgente  │ IP destinaz. │  dati   │
└──────────────┴──────────────┴─────────┘
                       ↑
                    ROUTER
```
Il router utilizza una **tabella di inoltro IP**, costruita tramite i meccanismi di routing. 

## 4. Una differenza: i loop

Questa è una cosa che può essere chiesta all'esame.

### Router

Il router può gestire i loop grazie a meccanismi come il **TTL dell'IP**.

Ogni volta che un datagramma attraversa un router:

```
TTL ↓
```

Quando arriva a 0, il datagramma viene eliminato.
### Switch

Un frame Ethernet **non ha un TTL**.

Quindi, se avessimo un loop:

```
       ┌── Switch 2 ──┐
       ↓              ↑
Switch 1              Switch 3
       ↑              ↓
       └──────────────┘
```

un frame potrebbe continuare a circolare.

Questo è particolarmente pericoloso con i **broadcast**, perché il traffico può moltiplicarsi e creare una **broadcast storm**.

Per questo le reti Ethernet con switch devono essere organizzate logicamente senza loop, ad esempio tramite **Spanning Tree Protocol (STP)**.

# #🌐 VLAN: Virtual LAN
Cosa succede quando le dimensioni della LAN aumentano e gli utenti cambiano il punto di attacco?
*Singolo dominio di broadcast:*
- *Scalabilità:* tutto il traffico broadcast di livello 2 deve attraversare l'intera LAN.
- problemi di efficienza, sicurezza, privacy

L'idea della VLAN è che abbiamo un solo switch, ma logicamente è come se avessimo due switch superati: 
```
        SWITCH FISICO
      ┌───────────────┐
      │               │
   VLAN 10          VLAN 20
   Studenti        Professori
   1 ─ 2 ─ 3       9 ─ 10 ─ 11
      │               │
      └───── X ───────┘
```

I frame della VLAN 10 **non vengono inoltrati** alle porte della VLAN 20. 
Quindi le VLAN creano **domini di broadcast separati.**

## VLAN basata sulla porta
La forma più semplice è associare una porta a una VLAN. 
```
Porta 1 → VLAN 10
Porta 2 → VLAN 10
Porta 3 → VLAN 10

Porta 4 → VLAN 20
Porta 5 → VLAN 20
Porta 6 → VLAN 20
```
Un host può anche essere associato alla VLAN in base al suo MAC, anziché semplicemente alla porta. La cosa interessante è che la VLAN è una separazione **logica**, non necessariamente fisica.

## Comunicazione tra VLAN
Una VLAN 10 e una VLAN 20 sono isolate a livello 2. 
Se vogliamo fare: 
`VLAN 10 → VLAN 20`
serve il **routing**, quindi interviene un router o uno switch Layer 3. 
Quindi: 
> **VLAN separa le reti a livello 2; il routing permette di comunicare tra VLAN diverse.**

*isolamento del traffico:* i frame verso/da le porte 1-8 possono raggiungere soltanto le porte 1-8. 
- Si possono definire anche le VLAN basate sugli indirizzi MAC degli endpoint, piuttosto che sulle porte. 
*appartenenza dinamica:* le porte possono essere assegnate dinamicamente tra le VLAN
*Inolttro tra VLAN:* fatto tramite routing. 

## VLAN su più switch 
Qui arriva il problema interessante. 
Supponiamo di avere: 
```
          SWITCH 1             SWITCH 2

VLAN 10 ── PC ──┐             ┌── PC
                │             │
                └─────────────┘
```
Vogliamo che la VLAN 10 possa attraversare entrambi gli switch. 
Potremmo dedicare un collegamento fisico per ogni VLAN: 
```
VLAN 10 ─────────────
VLAN 20 ─────────────
VLAN 30 ─────────────
```
Ma se abbiamo 100 VLAN, servirebbero **100 collegamenti.**

# 802.1Q

IEEE 802.1Q aggiunge al frame Ethernet un tag che contiene informazioni sulla VLAN.

**VLAN ID = identifica la VLAN a cui appartiene il frame.**

Nel tag troviamo:
- **TPID** → identifica un frame VLAN-tagged (81-00);
- **VLAN** ID → 12 bit;
- **Priority** → 3 bit;
- **Drop Eligible Indicator** → 1 bit.

Il frame viene quindi modificato quando attraversa il trunk e il **CRC viene ricalcolato**.

Schema semplificato:

Frame Ethernet

┌──────┬──────┬──────┬────────┬─────┐
│ MAC  │ MAC  │802.1Q│  DATA  │ CRC │
│ dest │ src  │ TAG   │        │     │
└──────┴──────┴──────┴────────┴─────┘
                 ↑
              VLAN ID

#🧠 

**Trunk = un collegamento che trasporta più VLAN.**

**802.1Q = aggiunge al frame il tag che identifica la VLAN.**

# EVPN 
Normalmente Ethernet è una tecnologia del livello di collegamento. 
EVPN Permette di collegare logicamente reti Ethernet anche quando in mezzo abbiamo una rete **IP layer 3.** 
```
LAN A                         LAN B

PC ── Switch ──┐          ┌── Switch ── PC
                │          │
                └── IP ────┘
                  UNDERLAY
```

Dal punto di vista dei PC possiamo far sembrare che le due LAN siano parte della stessa rete Ethernet. Per farlo **incapsula/trasporta** i frame ethernet attraverso la rete IP. 
Questa appena descritta è l'idea di **overlay:**
>L'obiettivo è quindi poter estendere una rete Layer 2 sopra un'infrastruttura layer 3. 

#🧠 
**EVPN permette di collegare logicamente reti Ethernet attraverso una rete IP, trasportando i frame Ethernet dentro datagrammi IP.**