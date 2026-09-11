Ormai la tecnologia si è sviluppata orientandosi maggiormente al wireless, ovvero comunicando tramite **onde radio**, mentre **mobilità** significa gestire un dispositivo che cambia il suo punto di collegamento alla rete. 
Un dispositivo potrebbe essere wireless ma non mobile.

#  #🌐 Componenti di una rete wireless

## Host wireless 
Sono i dispositivi che eseguono le applicazioni: 
- smartphone;
- laptop;
- dispositivi IoT.
Possono essere **fissi oppure mobili.**

## Collegamento wireless
E' il collegamento radio che permette di comunicare: 

`Host ───── ~~~radio~~~ ───── Host/AP`

Può avere: 
- diversi tassi trasmissivi; 
- Diverse distanze massime; 
- Diverse bande di frequenza; 
Inoltre serve un protocollo ad **accesso multiplo,** perché più dispositivi possono voler utilizzare contemporaneamente lo stesso canale. 

### Stazione base
E' l'elemento centrale dell'infrastruttura.
In genere è collegata a una rete cablata e funziona come un **relay a livello di collegamento** tra la rete cablata e gli host wireless nella sua area. 

## Modalità infrastruttura
Nella **modalità infrastruttura**, gli host wireless comunicano attraverso una stazione base. 
La stazione base permette agli host di usufruire dei servizi della rete più ampia, come: 
- Indirizzamento
- Instradamento
Quando un dispositivo si sposta dalla copertura di una stazione base a quella di un'altra, cambia il proprio punto di collegamento ad una rete. 
Questo passaggio si chiama **handoff**. 

## Reti ad hoc
Nelle reti ad hoc **non ci sono stazioni base.** Gli host comunicano direttamente tra loro e possono anche occuparsi dei servizi normalmente offerti dall'infrastruttura: 
- Instradamento; 
- Assegnazione degli indirizzi; 
- Traduzione dei nomi; 

# #📌 Caratteristiche delle reti wireless: attenuazione
Un segnale wireless **si indebolisce mentre viaggia.**
I motivi principali sono due: 
- Ostacoli $\rightarrow$ assorbimento/diffusione; 
- Distanza $\rightarrow$ **free space path loss**

$$
attenuazione \sim (fd)^2 
$$
Dove: 
$f=frequenza$
$d=distanza$

Quindi: 
**Più aumenta la frequenza o la distanza, maggiore è l'attenuazione.**

## Propagazione su più cammini
Il segnale non necessariamente arriva al destinatario attraverso un unico percorso. 
Può succedere: 
```
             /──── riflesso ────\
A ─────────/                     \──→ B
            \──── riflesso ─────/
```

Una parte del segnale arriva direttamente, altre parti vengono riflesse da oggetti o terreno. 
Poiché i percorsi hanno lunghezze diverse, i segnali arrivano in momenti leggermente differenti. 
Questo fenomento è chiamato **multipath propagation.**

## #🧠 SNR e BER 

### SNR 
**Signal-to-Noise Ratio**
Indica quanto il segnale è forte rispetto al rumore. 
>	**SNR alto $\rightarrow$ più facile distinguere il segnale dal rumore**

### BER
**Bit Error Rate**

E' la probabilità che un bit venga ricevuto erroneamente. 

### Bilanciamento di SNR e BER
Per un dato schema di modulazione: aumenta la potenza $\rightarrow$ aumentare lo SRN $\rightarrow$ diminuisce il BER. 
Trasmissioni a potenza maggiore implicano un maggiore consumo di energia e possono andare a interferire con altre trasmissioni. 
Per un dato SNR, una tecnica di modulazione con più elevato tasso di trasmissione dei bit avrà un BER più alto. 
Lo SNR può cambiare con la mobilità: adattare dinamicamente il livello fisico. 

## #🌐 Terminali nascosti
```
A          B          C
 \          ↑        /
  \         │       /
   \        │      /
```
A riesce a comunicare con B. 
B riesce a comunicare con C. 
Ma **A e C non riescono a sentirsi tra di loro.** 
Ora supponiamo che A inizi a trasmettere a B, C ascolta e pensa che il canale è libero. 
Quindi anche C trasmette verso B. 
Il risultato è una collisione, data dal fatto che A e C non si sono accorti l'uno dell'altro, ma interferiscono presso B. 

## IEEE 802.11: WLAN

La Wireless LAN è una connessione LAN **realizzata tramite collegamenti wireless** invece che tramite cavi. 
L'esempio più comune è il **Wi-Fi**. 

## BSS 
**BSS= Basic Service Set**

In modalità infrastruttura, un BSS contiene: 
- Gli host wireless; 
- un Access point. 

## I canali Wi-Fi
Lo spettro radio viene suddiviso in **canali**, ciascuno associato a una determinata frequenza. 
L'amministratore dell'AP sceglie il canale da utilizzare. 
Problema: 
> Se due AP vicini usano lo stesso canale, possono interferire. 

## Associazione
Una volta scelto l'AP:
```
Host
  │
  │ Association Request
  ↓
 AP
  │
  │ Association Response
  ↓
Host
```
A questo punto può esserci l'autenticazione. Successivamente il dispositivo normalmente invia una richiesta **DHCP** attraverso l'AP per ottenere un indirizzo IP della sottorete. 
Quindi il flusso generale è: 
```
SCANSIONE
   ↓
scelgo AP
   ↓
ASSOCIAZIONE
   ↓
autenticazione
   ↓
DHCP
   ↓
ottengo IP
```

## WLAN ad hoc 
Non tutte le WLAN utilizzano un AP. 802.11 può funzionare anche in modalità ad hoc. 
Gli host comunicano *direttamente tra di loro.*
**802.11 può funzionare sia in modalità infrastruttura sia in modalità ad hoc.**

# Protocollo MAC 802.11 CSMA/CA

L’802.11 adotta CSMA/CA (Carrier Sense Multiple Access con Collision Avoidance). Non utilizza la Collision
**Detection** (CD) poiché l’hardware per trasmettere e ricevere contemporaneamente è costoso e non rileverebbe
i terminali nascosti.
Flusso del CSMA/CA
1. Se l’host rileva il canale libero, attende un tempo breve denominato DIFS (Distributed Inter-frame
Space) e trasmette l’intero frame.
2. Se il canale è occupato, l’host seleziona un valore casuale di backoff (tramite binary exponential backoff )
e avvia un conto alla rovescia solo quando il canale è libero. Se il canale torna occupato, il contatore
viene congelato.
3. Raggiunto lo 0, l’host trasmette il frame.
4. Se il destinatario riceve il frame correttamente, attende un tempo SIFS (Short Inter-frame Spacing) e
trasmette un frame ACK. Se il mittente non riceve l’ACK, incrementa la finestra di backoff e riavvia il
conto alla rovescia.
• DIFS (Distributed Inter-frame Space): È il tempo di attesa minimo che una stazione deve osservare
quando il canale è rilevato come libero prima di poter tentare la trasmissione di un nuovo frame. Funziona
come una sorta di “periodo di cortesia” che garantisce che il canale sia veramente inattivo.
• SIFS (Short Inter-frame Spacing): È un intervallo molto più breve del DIFS, utilizzato per
trasmissioni che hanno priorità assoluta, come il frame di ACK.
Collisioni
Le collisioni possono avvenire se:
• Sono presenti terminali nascosti.
• Tempi di backoff troppo ravvicinati.
Soluzione ai Terminali Nascosti: RTS e CTS Per prenotare il canale e mitigare le collisioni dei
terminali nascosti, l’802.11 utilizza frame di controllo brevi:
5. Il mittente invia un frame RTS (Request To Send) indicando la durata totale della trasmissione.
6. L’AP risponde con un frame CTS (Clear To Send) in broadcast, autorizzando il mittente e imponendo
il silenzio agli altri nodi nel suo raggio di copertura per la durata dichiarata.

# Evitare le collisioni
*idea*: consentire al mittente di "prenotare" il canale: si evitano così le collisioni anche durante l'invio di lunghi pacchetti di dati. 
- Il mittente invia prima un piccolo pacchetto $request-to-send$  all'AP usando CSMA. 
- Possono verificarsi collisioni tra i pacchetti RTS 
- AP risponde diffondendo in broadcast il pacchetto clear-to-send CTS in risposta al pacchetto ricevuto. 
- Il pacchetto CTS è ricevuto da tutti i nodi
- Il mittente invierà il pacchetto. 
- Gli altri nodi rimanderanno eventuali trasmissioni.

## Il frame 802.11

Struttura peculiare con **quattro campi per indirizzi MAC**:
• **Address 2**: Indirizzo MAC della stazione che trasmette il frame sul link wireless (mittente fisico).
• **Address 1**: Indirizzo MAC della stazione che riceve il frame sul link wireless (ricevitore fisico).
• **Address 3**: Indirizzo MAC dell’interfaccia del router che connette il BSS alla rete cablata o del nodo
destinazione finale.
• **Address 4**: Utilizzato solo in modalità ad hoc (BSS-to-BSS).
• Altri campi: Duration (prenota il canale), Sequence Control (per scartare duplicati o riordinare), Frame
Control (Type, Subtype, WEP).

# #🌐 Mobilità all'interno della stessa sottorete
Siccome i due AP sono connessi da uno switch, H1 rimane nella stessa sottorete: l'indirizzo IP può rimanere lo stesso. 
Switch: con quale AP è associato con H1? 
- Autoapprendimento: lo switch vedrà frame da H1 e "ricorderà" quale porta può essere usata per raggiungere H1. 
- Il nuovo AP può inviare un frame Ethernet broadcast con mittente H1, affinché lo switch apprenda la nuova porta per raggiungere H1. 
- Lo standard 802.11f definisce un protocollo inter-AP che affronta questo e altri problemi.
Siccome i due AP sono connessi da un router, H1 cambia sottorete: deve cambiare indirizzo IP, magari usando DHCP. 

## 802.11: Funzionalità avanzate
**Adattamento dello stato trasmissivo:**
La stazione base e la stazione mobile cambiano dinamicamente il tasso trasmissivo come la stazione mobile si sposta e di conseguenza cambia l'SNR. 
1.  SNR cala BER aumenta quando il nodo si allontana dalla stazione di base. 
2. Quando il BER diventa troppo alto, passa un tasso trasmissivo inferiore ma con BER inferiore. 
---
**Gestione dell'energia:**
- Nodo ad AP: "divento inattivo fino al prossimo frame beacon"
	- AP sa che non deve trasmettere frame a questo modo. 
	- Il nodo si riattiva prima del successivo frame beacon.
- *Frame beacon:* contiene la lista dei nodi che devono ricevere frame in attesa sull'AP
	- Il nodo rimane sveglio se devono essere inviati frame da AP a mobile; altrimenti dorme di nuovo fino al prossimo frame beacon. 

# Reti cellulari 4G/5G
Il wi-fi funziona bene su distanze relativamente brevi. 
Le reti cellulari servono invece **a fornire un accesso mobile a internet su una distanza molto più ampia.** L'idea è di dividere il territorio in celle, dove ogni cella ha una **base station** che gestisce i dispositivi presenti nella propria area. 

### Similarità e differenze con internet cablato
**Similarità:**
- Distinzione tra periferia e nucleo, ma entrambi appartengono allo stesso carrier
- Rete cellulare globale: una rete di reti. 
- Interconnessione a internet cablato
**Differenze:**
- Differenti protocolli livello di collegamento wireless
- Mobilità come servizio di prima classe
- Identità dell'utente attraverso la SIM

## Elementi dell'architettura 4G

La rete 4G può essere vista così: 
```
📱
UE
 │
 ▼
📡 eNode-B
Base Station
 │
 ▼
S-GW
 │
 ▼
P-GW
 │
 ▼
Internet
```
Parallelamente abbiamo alcuni elementi che si occupano principalmente del controllo e della mobilità: 
```
       HSS
        │
        ↕
       MME
        │
        ↕
    eNode-B / S-GW / P-GW
```

### UE (user equipment)
E' semplicemente il **dispositivo mobile:**
- smartphone;
- tablet; 
- laptop;
- IoT. 
Nella terminologia LTE viene chiamato UE(User Equipment). 
La SIM contiene l'**IMSI (International Mobile Subscriber Identity)**, utilizzato per identificare l'utente/dispositivo nella rete dell'operatore. 

### Base station
E' l'equivalente, a grandi linee, dell'access point wi-fi.
Nel 4G si chiama **eNode-B**. 
```
📱 📱 📱
 \  |  /
  \ | /
  📡
eNode-B
```

Gestisce le risorse radio dei dispositivi presenti nella propria cella. 
Ma c'è una differenza importante rispetto a un AP Wi-fi:
> La base station 4G ha un ruolo molto più attivo nella **gestione della mobilità**. 

Le diverse base station si coordinano per gestire gli utenti che si spostano tra le celle. 

### HSS (Home Subscriber Server)
L'HSS contiene informazioni sugli utenti per i quali quella rete è Home-Network. 
In particolare collabora con l'MME per l'autenticazione dei dispositivi. 

--- 
## S-GW e P-GW
Questi sono lungo il percorso dei dati tra il dispositivo mobile e internet. 

**S-GW Serving Gateway**
E' un gateway interno alla rete dell'operatore che partecipa al trasporto dei dati dell'utente. 

**P-GW PDN Gateway**
E' il gateway che collega la rete mobile a Internet 

---
## MME (Mobility Management Entity)
L'MME gestisce principalmente il piano di controllo. 
Tra le sue funzioni troviamo: 
- Autenticazione dei dispositivi, coordinandosi con HSS
- gestione dell'handover tra celle. 
- Tracking/paging della posizione dei dispositivi. 
- setup dei percorsi tramite tunneling tra dispositivo e P-GW. 

### Piano di controllo vs Piano dei dati

**Piano di controllo**
Si occupa di gestire: 
- mobilità
- sicurezza
- autenticazione
- stato della connessione
Nel 4G troviamo soprattutto `MME e HSS`

**Piano dei dati**
Trasporta effettivamente i dati all'utente: 
```
UE
 ↓
eNode-B
 ↓
S-GW
 ↓
P-GW
 ↓
Internet
```

## #🧠 Tunneling
Supponiamo che il telefono voglia mandare un datagramma a Internet. 
Il datagramma originale viene **incapsulato** dentro un altro protocollo. 
Nel 4G viene utilizzato **GTP-U (GPRS Tunneling Protocol)**
La struttura diventa, semplificando: 
```
Datagramma IP originale
          ↓
       GTP-U
          ↓
         UDP
          ↓
          IP
          ↓
     rete del carrier
```

# 5G

Il passaggio al 5G nasce dall'esigenza di ottenere prestazioni molto superiori e supportare nuovi tipi di applicazioni.

Le slide indicano tre grandi obiettivi/categorie:

### Enhanced Mobile Broadband

👉 banda larga mobile molto più veloce.

### Massive Machine Type Communications

👉 enorme quantità di dispositivi/macchine connessi.

### Ultra-Reliable Low-Latency Communications

👉 comunicazioni con **latenza molto bassa e alta affidabilità**.

# Obiettivi numerici del 5G

Secondo le slide:

- **10×** bitrate di picco;
- **10×** riduzione della latenza;
- **100×** capacità di traffico rispetto al 4G.

Il 5G NR (**New Radio**) utilizza due intervalli di frequenza indicati nelle slide:

- **FR1:** 450 MHz – 6 GHz;
- **FR2:** 24 – 52 GHz.

Le frequenze più alte permettono velocità maggiori ma hanno **distanze di copertura più brevi**. Per questo il 5G può richiedere una distribuzione molto più densa delle stazioni base.

