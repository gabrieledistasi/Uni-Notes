
## Che cos'è internet?
Internet è una "rete di reti", essa è costituita da moltissime reti gestite da diverse organizzazioni, le ISP, tra loro interconnesse. 
Internet possiede diversi elementi, tra questi, i principali sono: 
- Gli host 
		sistemi periferici della rete (PC, smartphone, tablet, ecc.). 
- Packet Switch
		Dispositivi che inoltrano i pacchetti attraverso la rete, i principali sono i router e gli switch. 
- Communication Link
		Sono i collegamenti che permettono ai dispositivi di comunicare, utilizzano rame, fibra ottica, radio, satellite. La velocità di trasmissione è detta trasmission rate, normalmente espressa in bit/s. 

## Internet come infrastruttura

Internet non è solo un modo per connettere i computer tra di loro, è un'infrastruttura che permette alle applicazioni di comunicare: 
- Web
- Streaming
- Email 
- Dispositivi interconnessi
- ecc. 
	Inoltre fornisce un'interfaccia alle applicazioni distribuite attraverso cui possono utilizzare i servizi di trasporto della rete 

## Protocolli di internet 

Un protocollo stabilisce: 
- Quali messaggi devono essere inviati
- In quale ordine devono essere inviati
- Quali azioni devono essere eseguite quando si riceve un messaggio o si verifica un evento 

Un protocollo è un insieme di regole che governa la comunicazione tra due entità. 

## Struttura di internet 

Possiamo dividere internet in 3 parti: EDGE, Reti di accesso,  CORE

- EDGE: 
		La periferia di internet contiene gli host, ovvero i client e i server. 

- RETI DI ACCESSO: 
		Collegano gli host al resto di internet 

- CORE: 
		è formato principalmente da router interconnessi, il core costituisce la parte centrale della "rete di reti". 

### Edge Router 

Quando un pacchetto viene inviato, al di fuori della propria rete di accesso, incontra per primo l'edge router 

### Cloud Computing

Il Cloud Computing consiste nell'utilizzare risorse informatiche tramite internet invece di possederle fisicamente, le risorse vengono generalmente fornite on-demand e pagate in base al consumo. 

### Reti di accesso 

Ma come colleghiamo un host al primo router della rete? 
Bisogna considerare quale tra questi:  l'accesso residenziale, accesso aziendale e accesso mobile. 
E bisogna considerare inoltre: 
- Velocità di trasmissione. 
- accesso dedicato o condiviso. 

### DSL 

La DSL (Digital Subscriber Line) sfrutta il normale doppino telefonico in rame. 
La cosa interessante è che voce e dati utilizzano frequenze diverse, infatti per la voce si va da 0-4 kHz, per l'upstream 4-50kHz, 50kHz-1MHz per il downstream. 
Il dispositivo centrale è il DSLAM (DSL Access Multiplexer).

### FFTX 

Con FFT indichiamo "Fiber To The": più la fibra è vicina all'utente, maggiore sarà la velocità dell'ultimo tratto. 

### FFTH VS PON 

Con FFTH la fibra arriva direttamente all'abitazione 

Esistono due architetture: 

#### AON (Active Optical Network)
Utilizza apparati attivi, come switch ottici. 

#### PON (Passive Optical Network)
Utilizza splitter ottici passivi che dividono il segnale tra più utenti. 

### FWA (FIxed Wireless Access)
è una rete mista, la quale può utilizzare diverse tecnologie radio, compreso il 5G

### Rete domestica
Una tipica rete domestica contiene: 
- modem 
- router
- firewall
- NAT 
- Access point 

### Reti wireless
Una rete wireless permette di collegare gli host al router attraverso una base station o access point. 

###### Wlan/Wi-Fi 
Tipicamente: 
- circa 1000m
- all''interno delle vicinanze degli edifici

###### Reti cellulari
- copertura molto maggiore 
- decine di km 
- 4G/5G

# Pacchetti e transmission rate

Quando un'applicazione deve inviare un messaggio, l'host: 
1. prende il messaggio
2. lo divide in pezzi più piccoli 
3. questi pezzi vengono chiamati pacchetti
4. trasmette i pacchetti attraverso la rete

Se un pacchetto ha: 
- lunghezza L bit 
- collegamento con velocità R bit/s
Il ritardo di trasmissione è: 
			dtrans = L/R 

## Mezzi trasmissivi

Si dividono in: 

**Guided media**
Il segnale viaggia all'interno di un mezzo fisico. 
- doppino in rame
- cavo coassiale 
- fibra ottica

**Unguided media**
Il segnale si propaga liberamente 
- radio
- wireless
- satellite

## Canali radio 
Trasportano segnali nello spettro elettromagnetico senza bisogno di cavi. 
Problemi principali: 
- riflessione 
- ostacoli
- interferenze 
Sono generalmente broadcast e half-duplex. 

### Satelliti GEO VS LEO 

Geostazionari:
- Segue la rotazione terrestre 
- Appare fermo nel cielo 
- Grande copertura 
- Elevata latenza 
- Sono sufficienti circa 3 satelliti per una copertura quasi globale

Low Earth Orbit: 
- Orbita più bassa 
- Si sposta rapidamente rispetto alla superficie 
- Servono costellazioni di satelliti per garantire copertura continua
- Latenza molto più bassa

[[Nucleo della rete|Nucleo della rete]]



