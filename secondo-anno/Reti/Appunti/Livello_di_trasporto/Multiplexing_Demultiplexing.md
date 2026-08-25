Per visualizzare questo argomento immaginiamo sul nostro PC diverse applicazioni aperte, ad esempio: 
- Discord 
- Spotify
- Chrome
- Steam
Tutti questi processi vogliono utilizzare la rete, qui entra in gioco il livello di trasporto, che deve effettuare due operazioni. 
### Multiplexing
**Il multiplexing avviene lato mittente**.
Il livello di trasporto deve: 
- Raccogliere i dati provenienti da varie socket. 
- Aggiungere un'intestazione a ciascun dato. 
- Creare i segmenti. 
- Passarli al livello di rete.
In altre parole: **Il multiplexing raccoglie i dati provenienti da varie socket, aggiunge le informazioni necessarie nell'intestazione del livello di trasporto, crea i segmenti e li passa al livello di rete.**

### Demultiplexing
Il demultiplexing sarà il processo inverso. 
Un host riceve dei segmenti dalla rete, il livello di trasporto deve capire: **"Questo segmento a quale socket va consegnato?"**
E qui avviene il demultiplexing, utilizzando le informazioni contenute nell'intestazione del segmento per consegnare i dati ricevuti alla socket corretta. (Possiamo immaginare il demultiplexing come gli svincoli di un'autostrada o come le code di imbarco negli aeroporti, mentre il multiplexing come l'immissione in un'autostrada).
**Più nel dettaglio:**
- L'host riceve i datagrammi IP 
- Ogni datagramma ha un'indirizzo IP di origine e uno di destinazione.
- Ogni datagramma trasporta 1 segmento a livello di trasporto.
- Ogni segmento ha un numero di porta di origine e un numero di porta di destinazione. 
L'host usa gli indirizzi IP e i numeri porta per inviare i segmenti alla socket corretta.

#### Demultiplexing senza connessione
Quando viene creata una socket, è possibile specificare il numero di porta. Oppure, molto più comune lato client, si può lasciare al sistema operativo il compito di assegnare a quella socket un numero di porta temporaneo. Quando si vuole spedire un messaggio attraverso la socket UDP, si deve specificare:
	- Indirizzo IP di destinazione 
	- Numero di porta di destinazione
Il segmento viene passato al livello di rete. 
Quando l'implementazione di UDP nell'host riceve un segmento UDP:
- Controlla il numero di porta di destinazione nel segmento.
- Invia il segmento UDP alla socket con quel numero di porta.
Datagrammi IP/UDP con lo stesso indirizzo IP e numero di porta di destinazione, ma indirizzi IP e/o numeri di porta di origine differenti vengono inviati alla stessa socket sull'host ricevente. 
Gli indirizzi IP di origine e il numero di porta di origine vengono utilizzati per eventuali risposte.

#### Demultiplexing orientato alla connessione 
A differenza di UDP, TCP deve distinguere connessioni diverse che possono avere lo stesso indirizzo IP e numero di porta di destinazione.

La socket TCP è identificata da quattro parametri: 
- Indirizzo IP di origine.
- Numero di porta di origine.
- Indirizzo IP di destinazione.
- Numero di porta di destinazione.
	
Demux: Il lato ricevente usa i quattro valori per inviare il segmento alla socket appropriata. 
Un host server crea una socket passiva specificando un numero di porta. 
La socket passiva viene usata per accettare le richieste di connessione, per ciascuna verrà creata una socket connessa.
