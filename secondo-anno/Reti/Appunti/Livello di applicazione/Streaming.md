Iniziamo definendo la differenza tra streaming e video. Un video è una sequenza di immagini chiamate frame riprodotte a una velocità costante, ad esempio: 
$$ 
24\ frame / s
$$
significa che ogni secondo vengono riprodotte 24 immagini. 
Ma un video potrebbe essere grandissimo, e per questo è necessario comprimerlo sfruttando la ridondanza: 
- Ridondanza spaziale: 
		se ho n pixel colorati allo stesso modo, non sarà necessario memorizzare in modo separato il colore di ciascun pixel. Ma si potrebbe fare una cosa del tipo: viola x N dove N è il numero di pixel colorati di viola.
- Ridondanza temporale: 
		Tra frame consecutivi se essi sono simili non devo necessariamente inviare tutto il secondo frame: posso codificare le differenze rispetto al precedente 

## CBR VS VBR 

### CBR (constant bit rate)
bit rate costante
## VBR
bit rate cambia con la quantità di ridondanza spaziale e temporale 

Ma come si trasmette il video attraverso internet? 
--
supponiamo che il server stia inviando il video, ma la rete non è perfetta, la larghezza di banda tra server e client può cambiare nel tempo a causa della congestione

tempo →

banda
10 Mbps ────────┐
                │
 5 Mbps         └───────┐
                        │
 2 Mbps                 └────────

Il ritardo diventa un problema per il video perché quest'ultimo deve essere riprodotto continuamente alla velocità del client, e qui si ha un vincolo: 

**Quando la riproduzione inizia, dovrebbe procedere secondo i tempi originali del video**

Soluzione al problema? **Il buffer**.
Il client non riproduce immediatamente tutto quello che riceve, prima accumula una certa quantità di video, (è la linea grigia di youtube, che va più avanti prima della linea rossa quando si guarda un video), quindi il buffer funziona come una riserva. 

## Streaming UDP
Con UDP il server può inviare pacchetti cercando di seguire correttamente il bitrate del video; Il vantaggio di UDP è che non ha controllo sulla congestione di TCP, quindi il mittente ha maggiore controllo sulla velocità di invio. 
Tuttavia c'è un problema: 
se il video richiedesse, ad esempio 2 Mbps ma la banda scendesse a 1 Mbps il server continuerebbe a voler inviare 2Mbps, la rete ne permetterebbe solo 1 Mbps, causando **starvation** e facendo bloccare il video. UDP non riesce a rispettare il vincolo di riproduzione continua se la banda scende periodicamente sotto il bitrate del video. 

## Streaming HTTP
Con HTTP il server trasmette alla massima velocità consentita dalla rete/TCP. 
Supponiamo che il bitrate sia 2Mbps e che il throughput disponibile sia 5 Mbps
Il buffer continua a crescere, questo viene detto **prefetching**. 
Quando il buffer raggiunge una data dimensione, il controllo del flusso può limitare la trasmissione verso il tasso di consumo del client. 
HTTP è migliore di UDP perché **può assorbire le fluttuazioni del throughput**
Ma anche qui rimane un problema: 
Immaginiamo una rete fatta così: 

10 Mbps --> --> --> 1 Mbps -->-->--> 8 Mbps
se il video è sempre disponibile solo a 5 Mbps, quando la rete scende a 1 Mbps si ha comunque un problema. Come risolviamo?

## DASH 

DASH significa Dynamic, Adaptive Streaming over HTTP
L'idea di DASH è di non tenere una sola versione del video ma di prepararne diverse con qualità e bitrate differenti, sarà il client a scegliere quale versione scaricare in base alla banda disponibile. 
Il video non viene visto come un blocco unico, ma diviso in segmenti, e ogni qualità ha i propri segmenti. In questo modo il client può guardare un numero di segmenti in qualità più alta e altri in qualità più bassa evitando così che il video si blocchi continuamente. 
### Manifest File
Il server mette a disposizione un file, un XML che descrive: 
- quali versioni del video esistono
- quali bitrate hanno
- come richiedere i segmenti

In DASH è il client che decide quando chiedere un segmento, quale bitrate chiedere e da quale server scaricare il video (il client deve scegliere un server quanto più vicino possibile e che abbia maggiore banda disponibile).
#remember 
banda più alta --> qualità maggiore
banda più bassa --> qualità minore

## Reti per la distribuzione di contenuti (CDNs)

Dash permette agli utenti di scegliere la qualità del video, ma rimane un problema: da dove scarico i segmenti? 
E qui entrano in gioco le CDNs. 
Ma come facciamo a distribuire i contenuti agli utenti simultaneamente?
Una prima opzione è quella di utilizzare un unico e grande datacenter. Tuttavia questa opzione non è scalabile, avere un unico datacenter significa avere un unico punto di rottura, inoltre per i clienti più lontani dal datacenter potrebbero subire perdita di qualità video o rallentamenti.
L'altra idea è quella di distribuire copie dei contenuti in molti punti della rete, questi punti sono chiamati server CDN o edge server. L'utente cerca di ottenere il contenuto da un server geograficamente e/o topologicamente vicino. 
Nella CDN non viene salvato tutto internet, vengono inseriti i contenuti più richiesti dall'utenza. Il client DASH può scegliere quale segmento e quale qualità scaricare e la CDN può fornirglieli da un server vicino. 
**La CDN migliora le prestazioni perché porta i contenuti vicino agli utenti**.
L'infrastruttura CDN può utilizzare meccanismi di instradamento/richiesta per indirizzare il client verso un server appropriato. La CDN cerca di scegliere un punto che permetta di servire il contenuto in modo efficiente. 
#### Ma se il server CDN non possiede ancora il contenuto? 
Supponiamo che la CDN di Roma non abbia il video richiesto dal client, può richiederlo all'origin server. Dal momento in cui la CDN di Roma riceve il video, altri utenti possono ottenere il contenuto direttamente dalla CDN di Roma. La CDN funziona come una gigantesca rete di **cache distribuite**.
La CDN è particolarmente utile per lo streaming in quanto quest'ultimo genera molto traffico, il contenuto viene distribuito una volta per ciascun area/server CDN, invece di dover percorrere continuamente l'intera internet per ogni singolo utente. 




