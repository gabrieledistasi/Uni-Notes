## Panoramica su HTTP 
Protocollo a livello di applicazione web 
modello client-server: 

**client**: browser che richiede, riceve e "visualizza" gli oggetti del web
**server**: il server web che invia oggetti in risposta alle richieste

**HTTP usa TCP**, il client inizializza la connessione TCP con il server sulla porta 80. 
Il server accetta la connessione TCP dal client
Messaggi HTTP scambiati tra browser e server web. 
Connessione chiusa TCP 
HTTP è un protocollo senza stato: il server non mantiene le informazioni sulle richieste fatte dal client. 
NOTA: I protocolli mantenenti lo stato sono complessi, la storia passata deve essere memorizzata.
Se il server e/o client si bloccano, le loro viste dello stato poSenza nometrebbero essere contrastanti e dovrebbero essere riconciliate. 

### Esistono due connessioni HTTP 

#### connessioni non persistenti 
- connessione TCP aperta 
- una singola coppia richiesta risposta HTTP per un singolo oggetto 
- connessione TCP chiusa
In queste connessioni, l'utente immette l'URL e a questo punto: 
Il client HTTP inizializza una connessione TCP con il server sulla porta 80, all'URL inserito dal client. 
Il server HTTP all'host dell'URL in attesa di una connessione TCP alla porta 80 "accetta" la connessione e avvisa il client.
Il client HTTP trasmette un messaggio di richiesta HTTP nella socket della connessione TCP, il messaggio indica che il client vuole l'oggetto all'interno dell'URL. 
Il server HTTP riceve il messaggio di richiesta, forma il messaggio che contiene l'oggetto richiesto e invia il messaggio nella sua socket. 
A questo punto il server chiude la connessione TCP, il client HTTP riceve il messaggio di risposta che contiene il file HTML, trova i riferimenti a 10 oggetti JPEG, e a questo punto si ripete tutto fino a quando non vengono inviati tutti e 10 i file JPEG. 

### Tempi di risposta delle connessioni non persistenti
**RTT**: tempo impiegato da un piccolo pacchetto per andare dal client al server e ritornare al client 
**Tempo di risposta (per oggetto):**
- Un RTT per inizializzare la connessione TCP 
- un RTT perché ritornino la richiesta HTTP e i primi byte della risposta HTTP 
- tempo di trasmissione per file/oggetto: 
	- $tempo \ di \ risposta\ connessioni \ non \ persistenti = 2RTT + tempo \ trasmissione \ file$
#### Connessioni persistenti 
- Connessione TCP al server aperta 
- Più coppie richiesta/risposta HTTP, per trasmettere più oggetti su una singola connessione TCP tra client e server 
- Connessione TCP chiusa

## Connessioni persistenti
**Svantaggi delle connessioni non persistenti**
- richiedono 2 RTT per oggetto
- allocazione di buffer e variabili per ogni connessione TCP
- Controllo della congestione: throughput inizialmente limitato per nuove connessioni
**Svantaggi delle connessioni persistenti**
Il server lascia la connessione TCP aperta dopo l'invio di una risposta 
I successivi messaggi tra gli stessi client/server vengono trasmessi sulla connessione aperta 
Il client invia le richieste non appena incontra un oggetto referenziato
Un solo RTT per tutti gli oggetti referenziati

### Messaggi di richiesta HTTP

HTTP possiede due tipi di messaggi: richiesta, risposta. Questi messaggi sono in formato ASCII, dunque leggibile dagli utenti. Nei messaggi di richiesta sono presenti alcuni campi di intestazione, essi servono al client per specificare cosa sta richiedendo o per esprimere le proprie preferenze:

**Host**
Hostname e numero di porta del server al quale sarà inviata la richiesta. Obbligatorio in HTTP/1.1; Se non è presente, il server potrebbe corrispondere con Error 400 Bad Request. 

**User Agent**
Identifica l'applicazione, il sistema operativo, il vendor e/o la versione dell'user agent che sta effettuando la richiesta 

**Accept** 
Tipi di contenuto, compresi dal client

**Accept-Language**
Linguaggi naturali o locali preferiti dai client

**Accept encoding**
Algoritmi di codifica compresi dal client

**Connection**
Verifica se, una volta terminato lo scambio richiesta/risposta, la connessione rimarrà aperta o chiusa. Il valore *close* indica la chiusura, altrimenti una lista non vuota di proxy non trasparente o cache, indica che la connessione rimarrà aperta. 

**Date**
Data e ora in cui il messaggio è stato originato

**Server**
descrive il software usato dal server di origine per gestire la richiesta

**Last Modified**
Data e ora che il server di origine riferisce all'ultima modifica effettuata sulla risorsa

**Accept-Ranges**
Indica il supporto del server ai download parziali; Il valore, se diverso da none, indica l'unità che si può usare per esprimere l'intervallo richiesto. 

**Content Length**
Lunghezza in byte del corpo inviato dal ricevente 

**Content Type**
media type del corpo dell'entità inviato al ricevente 

### Altri messaggi di richiesta HTTP

#### Metodo POST: 
La pagina web include un form per l'input dell'utente, quando l'utente preme invio il browser invia dati al server, utilizzando una richiesta HTTP Post. I dati inviati finiscono nel corpo della richiesta HTTP POST 

#### Metodo GET: 
Il metodo GET viene utilizzato quando si vuole richiedere una risorsa al server, normalmente GET non viene utilizzato per apportare modifiche alle risorse sul server, alcuni esempi di utilizzo del metodo GET sono ad esempio: 
- Aprire una pagina web
- Scaricare un'immagine
- ottenere un file 

#### Metodo HEAD: 
Il metodo HEAD è come GET, ma senza il corpo della risposta. Con head otteniamo solo gli **header** della risorsa richiesta, senza il contenuto. Questo metodo permette di capire se la risorsa esiste, quanto è grande, che contenuto è e ultima modifica. 

#### Metodo PUT 
Il metodo PUT permette la creazione/sostituzione di una risorsa. 
Con PUT il client indica una risorsa specifica che vuole modificare o creare e invia il nuovo contenuto. 

## HTTP: idempotenza

**Un'operazione si dice idempotente se l'effetto inteso sul server di una singola richiesta è lo stesso di quello di più richieste identiche**.
In parole povere: Se ripeto la stessa richiesta più volte, dopo la prima volta il risultato finale sul server non cambia.
GET, PUT, HEAD sono idempotenti, POST no.
Un form può essere implementato utilizzando GET se l'operazione associata al form è idempotente, con POST se non lo è.

## Codici di stato della risposta HTTP
Nella prima riga del messaggio di risposta dal server al client, i codici sono definiti da RFC 9110 e sono raggruppati in 5 categorie: 
- **1xx Informational:** risposta intermedia che indica l'avanzamento della richiesta, prima della risposta finale 
- **2xx Successful**: La richiesta è stata ricevuta con successo, compresa e accettata. 
- **3xx Redirect**: il client deve eseguire ulteriori azioni per soddisfare la richiesta
- **4xx Client Error** La richiesta è sintatticamente errata (404 Not Found)
- **5xx Server error** Il server ha fallito nell'inviare una richiesta apparentemente valida  (500 internal server error)

Alcune espressioni possono essere: 
- 200 OK
- 301 Moved permanently, l'oggetto richiesto è stato trasferito
- 400 bad request
- 404 not found
- 406 not acceptable 
- 505 HTTP version not supported

# Cookies 
I siti web e i browser client usano cookies per il mantenimento dello stato tra le transazioni. 
Quattro componenti: 
1) Una riga di intestazione nel messaggio di risposta HTTP 
2) Una riga di intestazione nel messaggio di richiesta HTTP
3) Un file cookie mantenuto sul sistema dell'utente e gestito dal browser dell'utente
4) Un database sul sito

*Esempio*
Susan usa il browser dal portatile,*
*visita uno specifico siti di commercio*
*elettronico per la prima volta*
*▪ quando la richiesta HTTP iniziale*
*arriva al sito, il sito crea:*
*• un identificativo unico*
*• una voce nel proprio database,*
*indicizzata dal numero*
*identificativo*
*▪ Il server ritorna una risposta che*
*include l'intestazione Set-cookie, che*
*contiene l'identificativo unico e che*
*sarà aggiunto al file dei cookie*
*▪ le successive richieste del browser di*
*Susan per questo sito conterranno*
*l'identificativo in una intestazione*
*cookies*

I cookie possono essere utilizzati per autorizzazioni, carrello degli acquisti, raccomandazioni e stato della sessione corrente. Inoltre i cookie vengono utilizzati per:
- tracciare il comportamento degli utenti su un dato sito
- tracciare il comportamento degli utenti su più siti senza neppure che l'utente abbia mai scelto di visitare il sito del tracker
- Il tracciamento può essere invisibile all'utente 
Se i cookies possono identificare un individuo, i cookie diventano dati personali, soggetti alla normativa GDPR(General Data Protection Regulation) sui dati personali. 

# HTTP/2
L'obiettivo principale di HTTP/2 è quello di diminuire il ritardo nelle richieste HTTP agli oggetti. HTTP1.1: ha introdotto GET multiple in pipeline su una singola connessione TCP 
- Il server risponde in ordine alle richieste GET
- Con FCFS, oggetti più piccoli possono dover aspettare la trasmissione di oggetti più grandi
- Il recupero delle perdite blocca la trasmissione di oggetti 
- Metodi, codici di stato e campi di intestazione rimangono inalterati rispetto a HTTP1.1
- Introduce la codifica binaria dei messaggi
- L'ordine di trasmissione degli oggetti richiesti è basata su una priorità degli oggetti specificata dal client 
- Invio push al client di oggetti aggiuntivi, senza che il client li abbia richiesti
- dividere gli oggetti in frame, alternare i frame di oggetti diversi per mitigare il blocco HOL
HTTP/2 vuole permettere di scaricare una pagina con più oggetti attraverso una singola connessione TCP. 
### Da HTTP/2 a HTTP/3

HTTP/2 su una singola connessione TCP significa: 
- Il recupero dalla perdita di pacchetti blocca comunque tutte le trasmissioni di oggetti
- Come in HTTP 1.1, i browser sono incentivati ad aprire più connessioni TCP parallele per ridurre lo stallo e aumentare il throughput complessivo. 
- nessuna sicurezza su una connessione TCP semplice 
- HTTP/3 aggiunge sicurezza, un controllo di errore e congestione su UDP (vedi [[Livello_di_trasporto | Livello di trasporto]])

[[Web Cache| Web Cache]]

