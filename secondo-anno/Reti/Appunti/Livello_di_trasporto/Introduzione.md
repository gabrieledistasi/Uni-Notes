Il livello di trasporto si occupa della comunicazione tra i processi in esecuzione su host differenti. Si basa sui servizi offerti dal livello di rete, che realizza una comunicazione logica tra host. 
Le funzionalità offerte da questo livello sono il **multiplexing** e **demultiplexing** il **trasferimento dati affidabile**, il **controllo di flusso** e il **controllo della congestione**. Su internet i principali protocolli del livello di trasporto sono [[UDP | UDP]] e [[TCP|TCP]]. 

## Servizi e protocolli di trasporto
Come già detto sopra, i protocolli di trasporto forniscono la comunicazione logica tra processi applicativi di host differenti. 
I protocolli di trasporto vengono eseguiti nei sistemi periferici: 

**Lato invio**: 
	Combina il messaggio di un'applicazione con un'intestazione per creare un segmento e lo passa al livello di rete. Ad esempio, immaginiamo che il browser voglia inviare un messaggio HTTP:
	
	GET /index.html HTTP/1.1
	
Il processo applicativo mostra questo messaggio al livello di trasporto:

		Applicazione
	      │
	      │ Messaggio
	      ▼
	┌────────────────────┐
	│ Livello trasporto  │
	└────────────────────┘

Il livello di trasporto aggiunge la sua intestazione, il risultato si chiama **Segmento**
A questo punto entra in gioco il livello di rete, che prende il segmento e lo incapsula all'interno del datagramma IP. 

**Lato ricezione**:
	Il processo è l'inverso. Il livello di rete riceve il datagramma e passa il segmento al livello di trasporto. Il livello di trasporto estrae i dati del segmento e li passa al livello applicativo. 
	Il punto importante è che non li passa a caso: deve capire a quale processo/applicazione consegnarli. [[Multiplexing_Demultiplexing | Multiplexing Demultiplexing]]

I router nel cammino da un host all'altro operano solo su intestazione del datagramma, ignorando il segmento incapsulato al suo interno. 