# ICMP 
**ICMP è un protocollo del livello di rete utilizzato da host e router per comunicare le informazioni relative alla rete, soprattutto errori e informazioni di controllo.**
ICMP non serve al trasporto dei dati delle applicazioni come [[TCP|TCP]] e [[UDP|UDP]].
Se un router non riesce ad consegnare un pacchetto, può generare un messaggio ICMP per informare il mittente del problema.

## #🔑 Dove si trova ICMP?
>ICMP è un protocollo a livello di rete "sopra" [[IP_Protocol|IP]]

I messaggi ICMP vengono infatti **incapsulati dentro datagrammi IP**. 
Non è considerato un protocollo di trasporto perché non viene utilizzato dalle applicazioni per trasferire i propri messaggi 

## #📌 Struttura di un messaggio ICMP

┌────────┬────────┬──────────┬────────────────────┐
│  Tipo  │ Codice │ Checksum │ resto intestazione │
└────────┴────────┴──────────┴────────────────────┘
│                    Dati                         │
└─────────────────────────────────────────────────┘

I primi tre campi sono particolarmente importanti: 
- **Tipo** $\rightarrow$ indica la categoria del messaggio;
- **Codice** $\rightarrow$ specifica più precisamente il motivo; 
- **Checksum** $\rightarrow$ permette di rilevare errori nel messaggio ICMP
In alcuni messaggi vengono inseriti inoltre l'**header e i primi 8 byte del datagramma IP che ha causato l'errore.** Questo permette al mittente di capire **quale pacchetto ha generato il problema** e, quando possibile, identificare il processo/porta coinvolta. 
![[Pasted image 20260908154836.png]]

Dal secondo all'ottavo tipo, possono essere inviati dai vari router lungo il percorso. I router, oggi, inviano messaggi relativi a "rete irraggiungibile" ogni volta che non possono inoltrare un pacchetto attraverso una rete; In passato il router inviava il messaggio di rete irraggiungibile nel momento in cui sapeva che quella rete esisteva, ma che riteneva "irraggiungibile" in quel momento: ad esempio perché l'interfaccia di uscita era down oppure il next hop non rispondeva. 
`dest protocol unreachable` e `dest port unreachable` dovrebbero essere inviati dall'host di destinazione, quando il protocollo o la porta non sono attivi. Il protocollo TCP gestisce il secondo caso attraverso l'invio di segmenti RST. Tuttavia, il lato mittente deve gestire anche l'analogo messaggio ICMP. I messaggi destination unreachable devono essere passati dal livello di rete a quello di trasporto, che dovrebbe farne un uso appropriato. 
`Source quench` può essere inviato da un router congestionato per forzare l'host mittente a ridurre il tasso di trasmissione. Permette una forma di controllo della congestione informato dalla rete. Oggi deprecato. 
`echo reply` e `echo request` la risposta *ping* contiene gli stessi dati della richiesta ping: può anche includere un timestamp per calcolare RTT in maniera stateless. 
La richiesta viene inviata solitamente attraverso il comando minimo ping; il lato server, che invia la risposta, è solitamente implementato all'interno del sistema operativo. 
`TTL expired` viene usato da *traceroute*. 

---
## #🌐 TraceRoute e ICMP

Supponiamo di voler raggiungere: 
Host A ── R1 ── R2 ── R3 ── R4 ── Destinazione

traceroute vuole scoprire **quanti router ci sono lungo il percorso e quanto tempo impiega il pacchetto a raggiungerli.**
Per fare ciò sfrutta il campo **TTL** dei datagrammi IP. 

### #📦 1. TTL = 1
La sorgente invia un datagramma UDP con `TTL = 1`, il pacchetto arriva al primo router R1.
Il router decrementa TTL e, in questo caso, TTL=0. 
A questo punto il router **scarta il datagramma** e genera: 
```
ICMP
Tipo = 11
Codice = 0
TTL expired
```
Il messaggio torna alla sorgente. 
La sorgente quindi scopre: 
	Il primo router del percorso è R1. 
Inoltre, misurando il tempo trascorso, ottiene l'RTT verso quel router.
Questo metodo viene utilizzato allo stesso modo anche per TTL = 2, TTL = 3 ecc. fin quando non di raggiunge la destinazione. 
**La destinazione viene raggiunta quando non viene più generato TTL expired,  perché a quel punto il TTL è sufficiente.**

#🔑 
**Traceroute invia serie di datagrammi UDP con TTL crescente. Ogni router in cui il TTL scade scarta il datagramma e invia alla sorgente un ICMP "TTL expired" (tipo 11, codice 0), permettendo di identificare i router attraversati e misurarne l'RTT. Quando il datagramma raggiunge la destinazione, questa risponde con ICMP "destination port unreachable" (tipo 3, codice 3), indicando a traceroute di terminare.**
[[gestione_della_rete | gestione della rete]]
