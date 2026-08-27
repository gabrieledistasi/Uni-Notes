Ma se UDP non è affidabile, allora come possiamo realizzare un trasferimento dati affidabile?
L'idea è quella di costruire un protocollo di trasferimento dati affidabile, chiamato rdt, che permetta alle applicazioni di comunicare in modo affidabile anche se il canale sottostante può presentare dei problemi. 
Dal punto di vista delle applicazioni, il protocollo rdt deve far apparire la comunicazione come un canale affidabile, occupandosi dei possibili problemi presenti al livello sottostante. 
La complessità del protocollo dipende dalle caratteristiche del canale: se il canale è perfetto, il protocollo sarà molto semplice; se invece il canale può introdurre errori o perdite, saranno necessari meccanismi aggiuntivi. 

## RDT Interfacce

**Lato mittente:**

- rdt_send(): chiamata dall'alto, trasferisce i dati da consegnare al livello superiore del ricevente. 
- Successivamente, il canale rdt prepara il pacchetto e lo invia attraverso il canale sottostante utilizzando: udt_send(packet); dove udt rappresenta il canale sottostante, che potrebbe essere inaffidabile. 

**Lato ricevente:**
	- Quando un pacchetto arriva dal canale sottostante, viene consegnato al protocollo rdt del ricevente attraverso: *rdt_rcv(packet)*
	- il protocollo rdt controlla ed elabora il pacchetto ricevuto e, se tutto è corretto, consegna i dati all'applicazione usando: *deliver_data(data)*

# rdt1.0: trasferimento affidabile su canale affidabile 
- Canale sottostante perfettamente affidabile: nessun errore nei bit, nessuna perdita di pacchetti. 
	- Macchine a stati finiti *distinto* per il mittente e il ricevente: il mittente invia i dati al canale sottostante, il ricevente legge i dati dal canale sottostante. 
# rdt2.0: canale con errori nei bit
- Il canale sottostante può invertire i bit nel pacchetto 
		checksum per rilevare gli errori nei bit 
- Come fare recover dagli errori?
Le soluzioni possono essere: 
	- notifica positiva, acknowledgements (ACKs): il ricevente comunica espressamente al mittente che il pacchetto ricevuto è corretto. 
	- notifica negativa, negative acknowledgements(NAKs): il ricevente comunica espressamente al mittente che il pacchetto contiene errori 
	- il mittente ritrasmette il pacchetto se riceve NAK 

### Stop and Wait 
Il mittente attende la notifica di ricezione del pacchetto in corso prima di procedere con l'invio di nuovi dati. 

## rdt2.0: specifica della FSM

![[Pasted image 20260827164016.png]]

Perché una FSM? Perché una FSM permette di rappresentare il comportamento di un protocollo indicando in quale stato si trova e come reagisce agli eventi che possono verificarsi. Un protocollo, non esegue sempre le stesse operazioni: il comportamento dipende dallo stato in cui si trova. Quando si verifica un evento, il protocollo può: 
- eseguire un'azione 
- passare a un nuovo stato
- oppure rimanere nello stesso stato
Nelle rappresentazioni delle FSM, ogni stato è rappresentato da un cerchio, mentre le frecce rappresentano le transizioni da uno stato all'altro. 


## rdt2.1: discussion 

**Mittente**: 
- aggiunge il numero di sequenza al pacchetto 
- saranno sufficienti due numeri di sequenza (0,1)
- deve controllare se gli ACK/NAK sono danneggiati 
- Il doppio di stati
		- lo stato deve "ricordarsi" se il pacchetto "corrente" ha il numero di sequenza 0 o 1
	
**Ricevente:**
- deve controllare se il pacchetto ricevuto è duplicato 
	- Lo stato indica se il numero di sequenza previsto è 0  o 1
nota: il ricevente non può sapere se il suo ultimo ACK/NAK è stato ricevuto correttamente dal mittente.

## rdt2.2: protocollo senza NAK 
Questo protocollo ha le stesse funzionalità di rdt2.1, ma utilizza soltanto ACK. 
Al posto di NAK, il destinatario invia un ACK per l'ultimo pacchetto ricevuto correttamente: 
			- Il destinatario deve includere esplicitamente il numero di sequenza del pacchetto con l'ACK 
Un ACK duplicato presso il mittente determina la stessa azione del NAK: ritrasmettere il pacchetto corrente 

## rdt2.2: frammenti del mittente e del ricevente 

![[Pasted image 20260827165223.png]]

## rdt3.0: canali con errori e perdite 
Ma se i canali sottostanti perdono i pacchetti?
Il mittente attende un ACK per un certo periodo di tempo. Ritrasmette se non riceve ACK in questo periodo, se il pacchetto ACK è soltanto in ritardo e non perso: 
		- La ritrasmissione sarà duplicata, ma l'uso dei numeri di sequenza gestisce già questo
		- Il destinatario deve specificare il numero di sequenza del pacchetto da riscontrare 
Utilizzare un timer per il conto alla rovescia per interrompere dopo un periodo di tempo ragionevole.

## rdt3.0: mittente 

![[Pasted image 20260827165628.png]]


## rdt3.0 in azione 

![[Pasted image 20260827165730.png]]

# Prestazioni di rdt3.0 (stop&wait)

$U_{mittente}$ : utilizzazione, la frazione di tempo in cui il mittente è stato effettivamente occupato nell'invio di bit sul canale. 
*Esempio:*
Collegamento da 1Gbps, ritardo di propagazione 15 ms, pacchetti da 1000 byte (8000 bit)
Tempo per trasmettere un pacchetto sul collegamento: 
$$
D_{trasm} = \frac{L}{R} = \frac{8000\ bit}{10^{9}\ bit/s} = 8μs
$$
# rdt3.0: funzionamento con stop-and-wait
![[Pasted image 20260827170603.png]]

$U_{mittente}=\frac{\frac{L}{R}}{RTT+\frac{L}{R}}$

il throughput effettive generato dal mittente: 
$U_{mittente}=\frac{\frac{L}{R}}{RTT+\frac{L}{R}}$ = $U_{mittente}$ * R = 267 kbps
Le prestazioni di rdt3.0 sono pessime. 
Il protocollo limita le prestazioni dell'infrastruttura sottostante. 

## rdt3.0: funzionamento con pipeline 

**Il mittente:** Il mittente ammette più pacchetti in transito, ancora da notificare
- L'intervallo dei numeri di sequenza deve essere incrementato 
- buffering dei pacchetti presso il mittente e, in certi casi, il ricevente 

## Protocollo con pipeline: Go-Back-N
Il mittente può avere contemporaneamente fino a N pacchetti già inviati ma per cui non ho ancora ricevuto la conferma. 
![[Pasted image 20260827172532.png]]

**Verde (already ack'ed):**
sono i pacchetti che:
- sono stati inviati
- sono stati ricevuti correttamente 
- il mittente ha ricevuto l'ack
Quindi sono pacchetti già sistemati e non bisogna più pensarci.

**Giallo (sent, not yet ack'ed)**:
Sono pacchetti già inviati, ma il mittente non ha ancora ricevuto il riscontro.
Sono quindi pacchetti ancora in transito o comunque non ancora confermati. 

**Blu (Usable, not yet sent)**
Questi sono pacchetti che: 
- Il mittente può già inviare 
- Ma non li ha ancora inviati

**Bianco (not usable)**
Questi pacchetti non possono ancora essere inviati.
Il motivo è che la finestra ha una dimensione massima: 
- N pacchetti non ancora confermati 
Finché non arrivano degli ACK, il mittente non può continuare a mandare pacchetti all'infinito

**Send base**
Indica il numero di sequenza del pacchetto non ancora riscontrato più vecchio. 

ACK ricevuti
      │
      ▼
🟢 🟢 🟢 │ 🟡 🟡 🟡 🔵 🔵
         ↑
     send_base
 è il primo pacchetto della finestra. 

**Nextseqnum**
nextseqnum indica il numero di sequenza che verrà assegnato al prossimo pacchetto da inviare. 
🟡 🟡 🟡 │ 🔵 🔵 🔵
          ↑
      nextseqnum

Tutto ciò che sta prima di nextseqnum è già stato inviato, se è dentro la finestra
## Riscontri cumulativi 
In Go-Back-N gli ACK sono cumulativi. `ACK(n)` conferma che tutti i pacchetti con numero di sequenza minore o uguale a `n` sono stati ricevuti correttamente. Alla ricezione di un ACK, la finestra viene spostata in avanti e `send_base` viene aggiornato. 
## Timer e timeout
Il mittente utilizza un timer per il pacchetto più vecchio ancora in transito e non riscontrato. Se si verifica un `timeout(n)`, il mittente ritrasmette il pacchetto `n` e tutti i pacchetti successivi già inviati ma non ancora riscontrati. Da questo comportamento deriva il nome **Go-Back-N**.

# Protocolli con pipeline: Go-Back-N (ricevente)

## Solo ACK
invia sempre un ACK per un pacchetto ricevuto correttamente con il numero di sequenza più alto in sequenza. 
- Potrebbe generare ACK duplicati 
- Deve memorizzare solo rcv_base
Alla ricezione di un pacchetto fuori sequenza: 
- Può scartarlo o inserirlo in un buffer: la implementazione che vedremo scarta i pacchetti fuori sequenza e deve solo gestire la variabile rcv_base. 
- rimanda un ACK per il pacchetto con il numero di sequenza più alto in sequenza 

# Protocolli con pipeline: selective repeat 
- pipelining: più pacchetti in transito 
- il ricevente riscontro individualmente ciascuno dei pacchetti ricevuti correttamente. 
	- buffer dei pacchetti, se necessario, per eventuali consegna in sequenza al livello superiore 
- **Mittente:**
	- mantiene un timer per ogni pacchetto non riscontrato 
		- timeout: ritrasmette il singolo pacchetto non riscontrato associato al timeout
	- mantiene una "finestra" su N numeri di sequenza consecutivi 
		- Limita i pacchetti in pipeline, "in transito", per rientrare in questa finestra
# Selective repeat: mittente e ricevente

### Mittente
Il mittente mantiene una finestra di dimensione `N`. Quando arriva un nuovo dato dall'applicazione, può inviare il relativo pacchetto solo se il successivo numero di sequenza disponibile si trova all'interno della finestra. Se si verifica un `timeout(n)`, il mittente ritrasmette il pacchetto `n` e tutti i pacchetti successivi già inviati ma non ancora riscontrati, riavviando il timer. Quando riceve un `ACK(n)`, il mittente considera riscontrato il pacchetto `n`. Poiché gli ACK sono cumulativi, vengono considerati ricevuti anche tutti i pacchetti precedenti. La base della finestra (`sendBase`) viene quindi avanzata fino al primo pacchetto non ancora riscontrato. 
### Ricevente 
Il ricevente mantiene una finestra che va da `rcvBase` a `rcvBase + N - 1`, dove `rcvBase` rappresenta il primo pacchetto ancora atteso. Se riceve un pacchetto che rientra nella finestra, invia `ACK(n)`. Se il pacchetto arriva fuori sequenza, viene temporaneamente memorizzato nel buffer. Se invece arriva in sequenza, viene consegnato all'applicazione; vengono inoltre consegnati anche eventuali pacchetti successivi che erano già stati ricevuti e memorizzati nel buffer. Se riceve un pacchetto appartenente all'intervallo `[rcvBase-N, rcvBase-1]`, significa che si tratta di un pacchetto già ricevuto e consegnato. Il ricevente invia nuovamente `ACK(n)` ma non consegna nuovamente i dati all'applicazione. Tutti gli altri pacchetti vengono ignorati.

[[TCP | TCP]]
