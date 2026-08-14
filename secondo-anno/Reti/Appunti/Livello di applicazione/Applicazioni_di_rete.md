Il livello di applicazione è il livello più alto del modello OSI, esso rappresenta l'interfaccia diretta tra i programmi utente e la rete, gestendo i protocolli che permettono alle applicazioni lo scambio dei messaggi. 

# Creazione di un'applicazione di rete 
Creare un'applicazione di rete significa scrivere programmi che girano su sistemi periferici differenti e comunicano attraverso la rete. I dispositivi del nucleo non eseguono applicazioni utente, l'isolamento delle applicazioni nei sistemi periferici ha facilitato lo sviluppo di una vasta gamma di applicazioni per internet.

### Architettura peer-to-peer
Nell'architettura peer-to-peer non c'è un host sempre attivo e le coppie di host comunicano direttamente tra di loro. L'idea di questa architettura è che un host (H1) che ha bisogno di un servizio lo richiede ad un host (H2) in grado di fornirlo, l'host H1 offre invece altri servizi. Questa architettura ha un'ottima scalabilità in quanto nuovi host aggiungono nuovi servizi al sistema anche aumentando il carico di lavoro. 
### Processi comunicanti 
*Processo: programma in esecuzione su un host.*
All'interno dello stesso host, due processi comunicano tra di loro e si coordinano mediante IPC (Inter-Process Communication). 
Processi che si trovano su host diversi comunicano tramite messaggi, lo scambio avviene mediante il servizio del livello di trasporto. 

#### Processi client e server
I processi possono essere client, ovvero quelli che richiedono il servizio, sia server ovvero quelli che attendono di essere contattati. Nelle applicazioni P2P un processo può essere sia client che server, ma durante una sessione di comunicazione, il processo è o client o server, nella sessione successiva potrà cambiare il proprio ruolo. 

### Socket 
Un processo invia/riceve messaggi a/dalla socket, una socket è simile ad una porta, una struttura che viene utilizzata per le comunicazioni: 
- Il processo mittente fa uscire il messaggio fuori dalla propria socket. 
- Il processo che ha inviato il messaggio, suppone che ci sia una struttura in grado di trasportare il proprio messaggio fino alla destinazione. 
#### Indirizzamento
Per ricevere messaggi, un processo deve possedere un identificatore, un host ha un indirizzo IP univoco a 32 bit o 128 bit. 
L'identificatore del processo deve contenere sia l'indirizzo IP che i numeri di porta associati al processo in esecuzione sull'host. 

Alcuni numeri di porta assegnati dallo IANA (Internet Assigned Names Authority): 
Porta HTTP : 80
Mail server : 25
Se volessimo inviare un messaggio HTTP al server gaia.cs.umass.edu:
Indirizzo IP: 128.119.245.12
Numero di porta:  80

## Protocollo a livello di applicazione

Un protocollo nel livello di applicazione definisce: 
- Tipi di messaggi scambiati 
- sintassi dei messaggi 
- semantica dei messaggi 
- regole per determinare quando e come un processo invia e risponde ai messaggi
- protocolli di pubblico dominio 

## Servizi di trasporto 

Qui ci chiediamo "Se sto progettando un'applicazione di rete, cosa mi interessa che la rete faccia per me?"
La prima cosa fondamentale da capire è se possiamo permetterci perdite, questo dipende molto dall'applicazione, alcune richiedono un trasferimento affidabile al massimo, altre possono tollerare qualche perdita. 
E' anche importante la questione della sensibilità al tempo, in giochi interattivi ad esempio, i ritardi dovrebbero essere più bassi possibile per evitare di compromettere l'utillizzo dell'applicazione. 
In fine è fondamentale l'aspetto della sicurezza, riservatezza, integrità dei dati, autenticazione. 

#### Throughput 
Alcune applicazioni, come quelle multimediali, sono dette sensibili alla banda, implicano una larghezza di banda minima. Altre applicazioni utilizzano l'ampiezza di banda che si rende disponibile. 

# Servizi dei protocolli di trasporto di internet

## [[TCP | TCP]]
Il trasporto TCP è affidabile fra i processi di invio e ricezione, i dati vengono consegnati senza errori e perdite e nell'ordine di arrivo. 
**Controllo di flusso**: il mittente non vuole sovraccaricare il destinatario 
**Controllo di congestione**: "Strozza" il processo di invio quando la rete è sovraccarica 
**Orientato alla connessione**: è richiesto un setup fra i processi client e server
**NON offre**: tempo di consegna garantito, garanzie su ampiezza di banda minima, sicurezza

## [[UDP|UDP]]
**Trasferimento dati inaffidabile** fra i processi di invio e ricezione
NON offre: affidabilità, controllo di flusso, controllo della congestione, temporizzazione, ampiezza di banda minima, sicurezza, né setup della connessione. 

## Rendere sicuro TCP 
### Socket TCP e UDP 
Nessuna cifratura, le password vengono mandate senza cifratura. 
### Transport Layer security
Offre connessioni TCP cifrate
Controllo di integrità dei dati
autenticazione end-to-end

### Implementazione di TLS a livello di applicazione
Le applicazioni usano librerie TLS che a loro volta utilizzano TCP 
Dapprima il cleartext viene inviato alla socket TLS e lì viene cifrato prima di entrare nella socket TCP. I dati consegnati dalla socket TCP vengono di nuovo messi in chiaro (decifrati) prima di venire restituiti dalla socket TLS. 

$Applicazione -> TLS -> TCP -> Rete$

TLS si mette sopra TCP e si occupa della sicurezza, TCP continua intanto a fornire i suoi servizi di trasporto affidabile. 

## Web e HTTP 
Una pagina Web è costituita da oggetti, ciascuno memorizzato su un server web differente, si considera oggetto un codice HTML, un'immagine JPEG, fogli stile css ecc.
Una pagina web contiene un file HTML di base che include diversi oggetti referenziati, ciascuno referenziato da un URL, ad esempio: 
				http://www.someschool.edu/someDept/pic.gif
- http indica lo **schema**
- www.someschool.edu indica l'hostname
- someDept/pic.gif indica il percorso 

[[HTTP | HTTP]]
