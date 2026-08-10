#introduzione

**Il Core della rete è l'insieme dei router interconnessi che trasportano i pacchetti dalla sorgente alla destinazione.**

Quando un'applicazione vuole mandare un messaggio, esso viene diviso in pacchetti. Ogni pacchetto contiene un'intestazione (Header), quest'ultimo è importante perché con esso la rete riesce a gestire il pacchetto. 
I router che ricevono il pacchetto decidono a quale router successivo inviarlo a seconda della route/path, fino alla destinazione. 

Nella commutazione di pacchetto, le risorse non vengono prenotate in anticipo. 
Il pacchetto viene semplicemente immesso nella rete e i router lo inoltrano.

# Funzioni fondamentali del CORE 

Le due funzioni fondamentali del core della rete sono due: 
- Forwarding (Inoltro)
- Routing (Instradamento)

### Forwarding
Il router riceve su una porta di ingresso un pacchetto e deve decidere su quale porta di uscita inoltrarlo. Per fare ciò il router guarda l'indirizzo contenuto nell'header del pacchetto e successivamente consulta la tabella di inoltro. 

Forwarding = "Da quale porta faccio uscire il pacchetto?". 
### Routing 
Il routing è un'azione globale, serve a determinare quale percorso devono seguire i pacchetti dalla sorgente alla destinazione. Per fare ciò vengono implementati degli algoritmi di instradamento. 

Routing = "Qual è il percorso da sorgente a destinazione?".

Il routing si occupa di inserire e gestire le informazioni che permettono al router di avere la tabella di inoltro. Il forwarding si occupa di consultarla ogni volta che arriva un pacchetto. 

### Store and Forward
Nello store and forward il router deve aver ricevuto l'intero pacchetto prima di poter iniziare la trasmissione sul collegamento di uscita. 

#### Esempio numerico "One-Hop"

$L = 10Kbit$ 
$R = 100Mbps$

Ritardo di trasmissione "One-Hop" = $\frac{10*10^3 bit}{100*10^6 bit/s} = 0.1*10^{-3} = 0.1 ms$

# Commutazione di Pacchetto

Nella commutazione di pacchetto, il messaggio viene suddiviso in pacchetti e successivamente inoltrato da un router al successivo. 
I pacchetti vengono inoltrati indipendentemente. 
Questo però comporta un problema: se arrivano troppi pacchetti si forma una coda. 
L'idea è che se si crea una coda, i pacchetti in attesa dell'invio vengono inseriti in un buffer, aspettando il proprio turno. 
Ma cosa succede se la coda diventasse troppo lunga? 
Il buffer è si grande, ma non infinito, quindi se arriva un pacchetto quando il buffer è pieno, cosa succede?
L'ultimo pacchetto in arrivo verrà perso. 


# Commutazione di circuito

La commutazione di circuito funziona in modo diverso dalla commutazione di pacchetto. 

L'idea della commutazione di circuito è: 
	Prima di iniziare la commutazione viene stabilito un circuito dedicato tra sorgente e destinazione. Questo modello è quello utilizzato nella rete telefonica tradizionale. 

#remember 
Packet switching --> le risorse vengono condivise tra più utenti. 
Circuit Switching --> Le risorse vengono riservate per quella comunicazione. 

**Esempio di chat: 
## Un esempio intuitivo

Immagina un'autostrada.

### Circuit switching

È come **riservare una corsia esclusivamente per te**:

```
════════════════════════════
       🚗 TU
════════════════════════════
```

Anche se non stai utilizzando tutta la corsia, nessun altro può utilizzarla.

### Packet switching

È come avere una strada normale:

```
🚗 🚙 🚕 🚗 🚌 🚙
```

Tutti condividono la strada.

È molto più efficiente quando gli utenti **non trasmettono continuamente**.
	

# FDM & TDM

Nella commutazione di circuito le risorse possono essere divise mediante due diverse tecniche. 
### FDM (Frequency Division Multiplexing)
La banda viene divisa in frequenze, le bande adiacenti sono separate da piccoli intervalli detti *guard* i quali non vengono utilizzati. 
Ogni circuito ha la propria banda e può trasmettere al massimo della velocità di quella banda ristretta. 
L'FDM si basa su questa intuizione: 
La luce visibile corrisponde ad una porzione dello spettro elettromagnetico. 
Una luce di un solo colore viene chiamata **Luce Monocromatica** , immaginiamo ora tre sorgenti luminose (rosso, verde, blu) che inviano impulsi contemporaneamente alla stessa fibra ottica, ma così staremmo mandando tre segnali contemporaneamente sullo stesso mezzo fisico: Come facciamo a inviarli insieme senza confonderci? Li distringuiamo in base alla loro frequenza. 
All'altra estremità arriva un segnale composto dai tre segnali, anche se i segnali sono stati combinati, possiamo comunque separarli perché hanno frequenze diverse (Principio del multiplexing). 
Quindi, invece di dare ad ogni utente tutto il collegamento, assegnamo a ciascuno una banda di frequenze diversa, in questo modo tutti possono trasmettere contemporaneamente, perché stanno utilizzando porzioni diverse dello spettro. 

# TDM (Time Division Multiplexing)
Tempo suddiviso *frame* di durata fissa ripartiti in un numero fisso di slot. 
Ciascun circuito riceve slot periodici, può trasmettere alla massima velocità della banda di frequenza, solo nei propri slot temporali. 

#remember 
**Circuit switching: "ti riservo la banda, che tu la usi o no".**  
**Packet switching: "la banda la usi quando ti serve".**


# Struttura di Internet

Come funzionano i pacchetti dentro la rete? Internet è una "rete di reti", gli host sono collegati tutti direttamente tra loro. Gli utenti accedono tramite un ISP di accesso, anche gli ISP di accesso devono essere interconnessi a loro volta, altrimenti due host appartenenti a reti diverse non potrebbero comunicare. 
Il problema diventa quindi: 
**Come collegare tutti gli ISP tra di loro?**
Si potrebbe pensare di collegare ogni ISP a tutti gli altri, una soluzione semplice apparentemente, ma che porta problemi di scalabilità, con N ISP, ogni ISP dovrebbe essere collegato agli altri N-1 ISP, il numero totale dei collegamenti sarebbe $\frac{N(N-1)}{2}$ che cresce come $O(N^2)$ pertanto si opta per una struttura gerarchica. 

## ISP di transito/globali 

Una soluzione migliore potrebbe essere quella di collegare gli ISP di accesso ad un ISP globale di transito, gli ISP di accesso diventano così clienti dell'ISP di transito. Non esiste un solo ISP globale, ma diversi e come comunicano tra di loro? 
attraverso il concetto di **Peering**

### Peering
Un peering link è un collegamento diretto tra ISP di pari livello (Possono esistere a tutti i livelli). 
Lo scopo è permettere ai due ISP di scambiarsi traffico direttamente, evitando di dover passare attraverso un altro provider, i punti in cui gli ISP possono effettuare il peering sono gli IXP ovvero **internet exchange point** 

### ISP tier-1 
Questi ISP possiedono una rete globale e possono raggiungere ogni altra rete su internet esclusivamente tramite accordi di peering "settlement-free", ovvero senza scambi di denaro per il traffico. 

# Ritardi e perdite 

### Come si verificano ritardi e perdite? 

Come abbiamo detto precedentemente, un possibile modo in cui possono verificarsi le perdite è per via della differenza di velocità tra ricezione e uscita dei pacchetti su un router, la perdita si verifica quando la  memoria contenente la coda si riempie. 

### Possibili cause dei ritardi: 

**$d_{elab}$ : elaborazione di nodo**
causato dal controllo errori sui bit e dalladeterminazione del collegamento di uscita. 

**$d_{acc}$ : ritardo di accodamento**
causato dall'attesa di trasmissione oppure può dipendere dal livello di congestione del router. 

**$d_{trasm}$ : ritardo di trasmissione** 
- L : lunghezza del pacchetto in bit
- R: tasso di trasmissione del collegamento 
$d_{trasm} = \frac {L}{R}$

**$d_{prop}$ : ritardo di propagazione**
- d : lunghezza del collegamento fisico. 
- v : velocità di propagazione ($~2*10^8 m/s$)
- $d_{prop} = \frac{d}{v}$
### Altre cause dei ritardi

- Un host potrebbe ritardare l'invio del pacchetto perché deve rispettare le regole del protocollo di accesso al mezzo utilizzato da tutti i dispositivi. 
- Ritardo di pacchettizzazione nelle applicazioni multimediali in tempo reale. 

### Commutazione di pacchetto: Ritardo end-to-end

I ritardi totali di nodo cui è incorso un pacchetto lungo il suo percorso
dalla sorgente alla destinazione si accumulano, determinando un
ritardo end-to-end (o punto-punto) pari a:

$$
d_{end-to-end} = \sum_i \left(d_{elab,i} + d_{trasm,i} + d_{prop,i}\right)
$$


## Ritardo di accodamento dei pacchetti

- a: velocità media di arrivo dei pacchetti
- L: Lunghezza del pacchetto (in bit)
- R: velocità di trasmissione (in bit/s)
- $\frac {L*a}{R} : \frac{velocita' di arrivo dei bit}{velocita' di servizio dei bit}$
Se la formula sopra restituisce un valore vicino allo zero, il ritardo può essere considerato piccolo, se 1 il ritardo medio di accodamento si considera grande, > 1 più lavoro in arrivo di quanto possa essere servito. 


#esercizi
# Throughput
Il throughput è la velocità effettiva con cui i dati riescono arrivare dal mittente alla destinazione. 
Supponiamo di dover trasferire un file da 1GB, se il trasferimento richiede 10 secondi, il throughput medio sarà: 
$$
THROUGHPUT = \frac {dati \ trasferiti}{tempo}
$$
### Osservazioni 
Il throughput end-to-end non può superare la velocità di trasmissione dei collegamenti attraversati dal flusso di dati. 
Se il percorso non è attraversato da altro traffico: 
Throughput $≈ min{R_{i}}$ dove $R_{i}$ è la velocità di trasmissione dell'i-esimo collegamento.
In presenza di altro traffico invece, la banda viene divisa equamente, in base al numero di utenti attivi. 
#remember 
**Il throughput è limitato dal collegamento più lento e, se quel collegamento è condiviso, anche dalla quantità di traffico che lo attraversa.**