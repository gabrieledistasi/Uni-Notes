Quando mandiamo una mail, il PC non "parla" direttamente con il dispositivo destinatario, abbiamo tre componenti principali tra il mittente e il destinatario:

- user agent
- mail server
- simple mail transfer protocol SMTP 
Il primo elemento è anche detto *Mail reader* e si occupa della composizione, editing e lettura dei messaggi, i messaggi in uscita o in arrivo vengono salvati sul server. 
Il mail server è invece la parte che contiene la **Mailbox** dell'utente, con tutti i messaggi ricevuti, il mail server contiene anche tutte le mail da trasmettere. 
Il protocollo SMTP è il metodo di scambio delle informazioni, in questo caso mail, dove il client è il mail server trasmittente e il server è il mail server ricevente. 

## SMTP RFC 5321

SMTP usa TCP per garantire affidabilità riguardo l'invio dei messaggi di posta elettronica al server, usa la porta 25. Il trasferimento dei messaggi avviene in tre fasi: 
- Handshaking
- Trasferimento dei messaggi
- Chiusura 
Interazione comando/risposta: 
comandi: testo ASCII a 7 bit 
risposta: codice di stato e espressione

##### Esempio
Alice vuole inviare una mail a Bob, Alice usa il suo user agent per comporre il messaggio da inviare alla mail di Bob. 
L'user agent di Alice invia un messaggio al suo server di posta e la mail viene posta nella coda dei messaggi. 
Il lato client di SMTP apre una connessione TCP con il mail server di Bob. 
Il client SMTP invia il messaggio di Alice sulla connessione TCP. 
Il mail server di Bob pone il messaggio nella casella di posta di Bob. 
Bob invoca il suo user agent per leggere il messaggio. 

### Note su SMTP 
La differenza principale tra HTTP e SMTP è che HTTP è client pull, mentre SMTP è client push: in parole povere, quando avviene una richiesta HTTP il client non fa altro che dire al server "dammi questa risorsa", con SMTP invece, il client dice al server "Sto inviando questo messaggio". Ma HTTP e SMTP sono protocolli completamente diversi? No, entrambi utilizzano un'interazione comando-risposta in ASCII con codici di stato. 

### Dot Stuffing 

Il dot stuffing è un meccanismo di SMTP per evitare che il server confonda un punto contenuto nel corpo della mail con la fine del messaggio. SMTP per risolvere questo problema fa in modo che il client invii due punti (..) quando si trova all'inizio di una riga e il server sostituisce ogni sequenza di due punti con un solo punto

## Formato dei messaggi di posta elettronica
Abbiamo detto che SMTP è un protocollo utilizzato per l'invio di messaggi di posta elettronica ed è definito da RFC 5321. RFC 2822 invece definisce la sintassi dei messaggi di posta elettronica 
- righe di intestazione, per esempio: 
- to
- from
- subject
- corpo (il messaggio da inviare con soli caratteri ascii)
RFC 2045 e 2046, inclusione di contenuti non testuali e la suddivisione del messaggio in più parti.

## Protocolli di accesso alla posta

**SMTP** consegna/memorizzazione sul server del destinatario.
protocollo di accesso alla posta: ottenere messaggi dal server. 
- IMAP: internet mail access protocol, i messaggi vengono salvati sul server, IMAP consente di recuperarli, cancellarli o archiviarli.
HTTP: gmail, Hotmail, Yahoo!, consentono un'interfaccia web sopra SMTP per il recupero delle mail. 

[[DNS | DNS]]