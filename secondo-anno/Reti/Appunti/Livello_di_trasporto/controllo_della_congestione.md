# Congestione
La congestione si verifica quando: 
*Troppe sorgenti inviano troppi dati troppo velocemente perché la rete riesca a gestirli.*

**Cosa succede quando c'è una congestione?**
I principali sintomi della congestione sono: 
- Ritardi elevati
- Le code diventano sempre più lunghe 
- Perdita di pacchetti
I buffer dei router hanno una capacità finita, quando questi vengono saturati, i router non sono più in grado di accettare nuovi pacchetti. 

C'è una importante differenza da sottolineare: 
$controllo \  di \ flusso \neq controllo \ congestione$
Il controllo di flusso riguarda un mittente e il destinatario, mentre il controllo della congestione riguarda invece la rete. 

## Congestione: scenario 1
Abbiamo: 
- 2 flussi che attraversano lo stesso router 
- capacità dei collegamenti = R 
- buffer del router illimitati
- nessuna ritrasmissione

I due flussi condividono il collegamento di uscita del router, che ha capacità R. 
Essendo due flussi, se si dividono equamente le capacità, avremmo: 
$$
λ_{out} = \frac{R}{2}
$$
Quindi il throughput massimo per ciascuna connessione è R/2. 
**Ma se aumentassimo $λ_{in}?$**
Fin quando: 
$$
λ_{in} < \frac{R}{2}
$$
Il router riesce a smaltire i pacchetti abbastanza velocemente. 
Quindi se $λ_{in}$ aumenta, $λ_{out}$ aumenta e il throughput cresce linearmente. 
Quando però abbiamo: 
$$
λ_{in} → \frac{R}{2}
$$
Il router riceve i dati quasi alla stessa velocità con cui riesce a trasmetterli, di conseguenza i pacchetti iniziano ad accodarsi nel buffer. Così il throughput non può aumentare: 
$$
λ_{out} \leq \frac{R}{2}
$$
Ma il ritardo cresce enormemente. 

## Scenario 2: buffer finiti e ritrasmissioni
In questo scenario abbiamo: 
- un router con buffer finiti
- due flussi
- i pacchetti che arrivano quando il buffer è pieno vengono persi 
- Il mittente ritrasmette i pacchetti persi. 

Consideriamo $λ_{in}$ come il traffico generato originariamente dall'applicazione, mentre $λ'_{in}$
come il traffico che il livello di trasporto immette effettivamente nella rete e comprende dati originali e ritrasmissioni, quindi: 
$$
λ'_{in} \geq λ_{in}
$$
## Scenario realistico: duplicati non necessari
I pacchetti possono venire persi, scartati dal router a causa dei buffer pieni, richiedendo ritrasmissioni. 
Ma il mittente può andare in timeout prematuramente, inviando due copie, che vengono entrambe consegnate, il livello di trasporto può riconoscere il duplicato e scartarlo, ma il livello di rete **ha comunque sprecato banda per poterlo trasportare.**
Abbiamo quindi due tipi di ritrasmissione: 
**Ritrasmissione necessaria**:
- X → perso → ritrasmetto X

**Ritrasmissione non necessaria**:
- X ───────────────→ destinazione
	 \
	  └─ timeout → X ─→ destinazione

In quest'ultimo caso arrivano entrambe le copie. 
I costi della congestione che quindi possono derivare da questa situazione: 
- Più lavoro per ottenere lo stesso throughput. 
- Ritrasmissioni non necessarie, che trasportano copie duplicate. 
Questo porta ad una diminuzione del massimo throughput raggiungibile. 

## Scenario realistico:  percorsi multi-hop
In questo scenario abbiamo: 
- Quattro mittenti 
- Percorsi multi-hop
- buffer finiti
- timeout e ritrasmissioni

Host A ── Router ── Router ── Host B
             │
             │
Host C ── Router ── Router ── Host D

I diversi flussi possono condividere diversi collegamenti e router.
### Il problema principale: 
Supponiamo che il traffico aumenti. Ad un certo punto, un router diventa congestionato e comincia a scartare i pacchetti. Il problema principale è che quei pacchetti hanno già attraversato una parte della rete. Quindi tutta la capacità utilizzata per portarli fino al router congestionato è stata sprecata. 

## Intuizioni 

1. **Il ritardo aumenta avvicinandosi alla capacità**
	$$
	λin​→R/2⇒delay↑↑
	$$
2. **Perdite e ritrasmissioni riducono il throughput effettivo**
	Parte della capacità viene utilizzata per dati che devono essere ritrasmessi anziché per nuovi dati utili. 
	
3. **I duplicati peggiorano ulteriormente la situazione**
	Una ritrasmissione può essere inutile se il pacchetto originale era solamente in ritardo. 

4. **Il throughput non può superare la capacità**
$$
λout​≤\frac {R}{2}
$$
5. **Nei percorsi multi-hop si può sprecare capacità a monte**
	Un pacchetto può attraversare dei link e poi essere scartato più avanti.  

## Controllo della congestione end-to-end
**La rete non fornisce al mittente informazioni esplicite sulla congestione. E' il mittente a dedurla osservando ciò che succede ai pacchetti.**
Questo metodo è adottato da TCP. 

## Controllo della congestione assistito dalla rete
Nel controllo assistito dalla rete, un router può ad esempio marcare un pacchetto per segnalare che sta rilevando congestione. Il destinatario può poi comunicare questa informazione al mittente. 

## ACK normali
La ricezione di ACK non duplicati indica che i segmenti stanno arrivando a destinazione 

## End-to-end vs assistito dalla rete 
Il mittente deduce la congestione osservando: 
- perdite
- ritardi 
**Assistito dalla rete:**
I router forniscono un feedback esplicito sulla congestione, ad esempio marcando i pacchetti. 

## Trasmissione dati affidabile vs Controllo della congestione
- Trasmissione dati affidabile: 
	- reagisce alla perdita dei pacchetti, possibilmente causata dalla congestione
	- "Tratta i sintomi della congestione"
- Controllo della congestione
	- "Cura la malattia"
	- Evita che la malattia si aggravi fino a degenerare fino allo scenario di "collasso di congestione"

# Controllo della congestione TCP
TCP deve decidere quanto velocemente può inviare dati nella rete senza provocare congestione. 
Per farlo utilizza una variabile fondamentale: 
$$
cwnd
$$
cioè la congestion window, la finestra di congestione.
L'idea è: 
_cwnd_ stabilisce quanti byte TCP può avere contemporaneamente **in volo** nella rete, cioè inviati ma non ancora confermati da un ACK. 
La condizione è: 
$$
LastByteSent - LastByteAcked \leq cwnd
$$
Se, ad esempio: 
$$
cwnd = 10 KB 
$$
TCP può avere al massimo circa 10KB non ancora riscontrati. 
## Come si comporta TCP? 
Trascurando il tempo di trasmissione, (seguendo le slide) facciamo questa semplificazione: 
- TCP invia cwnd byte
- Aspetta gli ACK 
- Dopo circa un RTT riceve gli ACK 
- Può inviare altri byte

Quindi il tasso di invio è approssimativamente: 
$$
throughput ≈ \frac {cwnd}{RTT}
$$
Il che significa che aumentando cwnd si aumenta anche il tasso di trasmissione. 

## CWND non è l'unico limite
Il mittente non deve rispettare soltanto cwnd, ma anche rwnd, perciò: 
$$
LastByteSent - LastByteAcked \leq min(rwnd, cwnd)
$$
# Come decide TCP se aumentare o diminuire cwnd?
TCP osserva ciò che accade. 
**Se riceve ACK normali**, significa che la rete sta consegnando correttamente i segmenti, TCP può allora provare ad aumentare cwnd per sfruttare più banda. 
**Se rileva una perdita** significa che probabilmente la rete è congestionata, portando TCP a ridurre cwnd e quindi il tasso di invio. 

# Tre fasi di TCP 
Il TCP classico presenta tre fasi principali: 
1. **Slow start**
2. **Congestion avoidance**
3. **Fast recovery**

# Slow start
Nonostante il nome, questa fase fa crescere molto velocemente cwnd, supponiamo all'inizio: 
$$
cwnd = 1MSS
$$
Poi TCP aumenta cwnd per ogni ACK ricevuto. Il risultato è che raddoppia circa ogni RTT (crescita esponenziale). 

**Perché farlo?**
Perché inizialmente TCP non sa quanta banda sia disponibile. 

**Quando termina slow start?**
Qui compare ssthresh, ovvero **slow start threshold**
*Quando cwnd raggiunge circa la metà del valore che aveva prima dell'evento di perdita, TCP passa alla congestion avoidance, dove l'aumento diventa lineare.*
ssthresh serve quindi a stabilire il punto in cui smettere di crescere esponenzialmente. 
In caso di perdita: 
$$
ssthresh = \frac{cwnd}{2}
$$
Dove cwnd è il valore immediatamente precedente alla perdita, quando viene raggiunto quel valore, **si passa in congestion avoidance**. 

# Congestion Avoidance 
Nella fase di congestion avoidance, la finestra di congestione viene incrementata di $MSS * \frac {MSS}{cwnd}$
per ogni nuovo ACK; poiché in un RTT ci si aspettano $\frac {cwnd}{MSS}$ ACK, il risultato finale è un incremento di 1 MSS ogni RTT. 

# Fast recovery 
Nella fase di fast recovery, in assenza di nuovi ACK, la finestra del mittente non avanza verso destra, bloccando contemporaneamente l'invio di nuovi segmenti; tuttavia, la cwnd viene incrementata per ogni ACK duplicato, finché non diventa sufficientemente grande da permettere l'invio di nuovi segmenti, la fase di *fast recovery* dura all'incirca un RTT affinché arrivi l'ACK del segmento ritrasmesso. 
## TCP Reno & TCP Tahoe
In TCP Reno, il mittente riduce il tasso di invio in risposta a eventi di perdita: 
- Dimezzamento in caso di perdita rilevata da un triplo ACK duplicato 
- Taglio a 1 MSS("maximum segment size") quando la perdita è rilevata dal timeout 
Una versione precedente, detta TCP tahoe, la risposta a qualsiasi evento di perdita era il taglio a 1 MSS e il passaggio a Slow Start. 

# AIMD (Additive Increase, Multiplicative Decrease)
AIMD considera l'andamento della velocità di invio TCP ignorando la fase iniziale di slow start e assumendo che le perdite siano rilevate tramite triplo ACK duplicato, quindi con Fast recovery. 

*TCP aumenta gradualmente la velocità finché trova il limite della rete; quando rileva una perdita, la riduce bruscamente.*

# Additive Increase 
Durante la congestion avoidance, TCP aumenta la propria velocità di invio di: 
$$
1MSS \ ogni\ RTT
$$
finché non viene rilevata una perdita. 
**Perché "additivo"?**
Perché aggiungiamo sempre una quantità fissa. 
$$
cwnd←cwnd+1 MSS
$$
# Multiplicative decrease 
Quando TCP rileva una perdita, invece, applica il **decremento moltiplicativo**. 
$$
cwnd ← \frac{cwnd}{2}
$$
Quindi la velocità viene dimezzata ad ogni evento di perdita. 

### Perché AIMD?

AIMD è un algoritmo:
- asincrono;
- distribuito.

È stato dimostrato che:
- ottimizza i flussi congestionati nella rete;
- possiede proprietà desiderabili di stabilità.

# TCP CUBIC 
Esiste un modo migliore di AIMD per capire quanta banda è utilizzabile?
consideriamo $w_{max}$ come la **dimensione della finestra di controllo della congestione nel momento in cui viene rilevata la perdita.**
Un'evoluzione del modo in cui TCP aumenta `cwnd` durante la Congestion Avoidance.
TCP intanto aumenta: 
cwnd = 10
cwnd = 11
cwnd = 12
...
cwnd = 20

A 20 si verifica una perdita, $w_{max}=20$, cubic considera Wmax come una sorta di punto di riferimento. 

## Dopo la perdita
Dopo la perdita, la finestra viene sempre ridotta. 
Nel grafico della slide vediamo che si passa circa da: 
	$$
	w_{max}
	$$
a: 
$$
\frac {w_{max}}{2}
$$
Lo stato di congestione del collegamento bottleneck non è cambiato molto dopo la perdita. 
Quindi se prima della perdita riuscivamo ad arrivare a:
$$
w_{max} = 20
$$
è ragionevole pensare che 20 sia ancora vicino alla capacità utilizzabile. 

## Come torna verso Wmax?
Dopo aver dimezzato la finestra, CUBIC aumenta il più velocemente per tornare Wmax. 
Ma quando si avvicina a Wmax, diventa più prudente. 

## K 
`K` = istante futuro in cui la finestra TCP raggiungerà nuovamente `Wmax`.
-  lontano da `K` → aumenti maggiori; 
-  vicino a `K` → aumenti minori e più cauti. 
CUBIC aumenta `W` come funzione del cubo della distanza tra l'istante corrente e `K`. 

## TCP e collegamente bottleneck congestionato
TCP aumenta la velocità di invio di TCP finché non si verifica una perdita di pacchetti all'uscita di un router: il collegamento "collo bottiglia". 

## Controllo di congestione basato sul ritardo
mantenere il percorso tra mittente e destinatario sufficientemente pieno da sfruttare il **bottleneck**, ma senza riempire eccessivamente le code dei router.
Il problema è che TCP classico/cubic utilizza principalmente la perdita di pacchetti come segnale di congestione. 
Ma quando avviene la perdita?
Quando la coda del router è già arrivata a una situazione critica, cioè quando il buffer può traboccare. 

## Explicit congestion notification 
Le implementazioni di TCP spesso implementano un controllo della congestione assistito dalla rete. 
- Due bit (ECN) nell'intestazione IP (all'interno del campo ToS) impostati da un router di rete per indicare la congestione 
	- policy per indicare la marcatura scelta dall'operatore di rete
- indicazione di congestione portata a destinazione
- La destinazione imposta il bit ECE sul segmento ACK per notificare al mittente la presenza di una congestione 
- Il mittente dimezza la finestra di congestione e imposta il bit CWR nel segmento successivo
	- Coinvolge sia l'IP che il TCP.
ECN viene negoziato in fase di instaurazione di una connessione TCP mediante opportune opzioni. Il mittente imposta i bit ECN nell'intestazione IP per indicare che contengono i segmenti di una connessione in grado di gestire ECN. Come TCP vegas, TCP ECN permette di reagire all'insorgenza della congestione prima che si verifichi la perdita di pacchetti. 

## TCP fairness 
*Obiettivo di equità*: se K sessioni TCP condividono lo stesso collegamento a collo di bottiglia con larghezza di banda R, ciascuna dovrebbe avere una velocità media R/K. 

**TCP è fair?**
Si, ma solo sotto assunzioni idealizzate.

Le due assunzioni indicate sono:
- tutte le connessioni hanno lo **stesso RTT**;
- c'è un **numero fisso di sessioni** che si trovano nella fase di **Congestion Avoidance**.

Queste condizioni sono importanti perché il meccanismo AIMD deve far convergere le connessioni verso una condivisione equa.

## Evoluzione della funzionalità del livello di trasporto 
**TCP e UDP sono stati i principali protocolli più utilizzati per 40 anni**.
Tuttavia col tempo sono state create più versioni di TCP per determinati scenari. Ma come mai?
La risposta è che TCP non si comporta allo stesso modo per diversi scenari. 
Alcuni scenari problematici: 

# TCP su long, fat pipes
In questo scenario si riscontrano: 
- RTT elevato 
- Capacità elevata 
Quindi abbiamo una rete che può trasmettere moltissimi dati, ma con un ritardo significativo.
Il problema è che possono esserci moltissimi pacchetti in volo. 
Se si verifica una perdita, la pipeline viene interrotta. 
A causa dell'RTT elevato, il controllo della congestione è meno reattivo. 
Per esempio, dopo aver dimezzato `cwnd`, la **Congestion Avoidance** impiega più tempo per tornare vicino al valore di `cwnd` che aveva prima del dimezzamento

$$
RTT↑⇒reazione\ al\ controllo\ della\ congestione\ piuˋ\ lenta\
$$
# QUIC: Quick UDP Internet Connections
Quic è un protocollo di applicazione, sopra UDP. 
Aumenta le prestazioni di HTTP 
Impiegati in molti server e app di Google 
Adotta gli approcci visti precedentemente per instaurare connessioni, controllo errori e il controllo della congestione. 
multiplexing di molteplici "flussi" (stream) a livello di applicazione su una singola connessione QUIC. 
- Stato del trasferimento dati affidabile e della sicurezza separati
- stato del controllo della congestione condiviso.

![[Pasted image 20260901191145.png]]

Con QUIC basta 1 Handshake.

[[Livello_di_rete_introduzione | Livello di rete]]
