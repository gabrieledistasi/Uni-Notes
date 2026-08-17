Nelle architetture P2P non è necessario, a differenza delle architetture client-server, avere un server sempre attivo: i dispositivi degli utenti, chiamati peer, comunicano tra di loro.
Inoltre, ogni peer può essere sia client che server, infatti un peer può richiedere servizi ad un peer mentre offre un servizio ad un altro peer. 
Questa architettura è interessante per una proprietà, ovvero la **scalabilità intrinseca**, ogni peer contribuisce con la propria capacità di upload, portando con sé nuove richieste di servizio ma anche nuove capacità di servizio. 
Ma è tutto rose e fiori? vediamo meglio. 
I peer sono connessi a intermittenza e cambiano indirizzo IP e ciò comporta un gestione dei peer molto più complessa rispetto al modello client-server. 

## Distribuzione di file: client vs P2P
*Quanto tempo per distribuire un file di dimensione F da un server a N peer?*

#esercizi
Siano: 
- F = dimensione del file
- N = numero di peer
- $u_{s} = velocità \ di \ upload \ del \ server$
- $u_i = velocità \ di \ upload \ del \ peer \ i$
- $d_{i} = velocità \ di \ download \ del \ peer \ i$
- $d_{min} = velocità \ di \ download \ del \ peer \ più \ lento$

## File transmission: client-server 

Trasmissione via server: deve inviare in sequenza N copie di file: 
- Tempo per inviare una copia: $\frac {F}{u_{s}}$
- Tempo per inviare N copie: $N* \frac{F}{u_{s}}$
Ogni client deve scaricare una copia del file: 
- $d_{min} = banda \ di \ download \ più \ bassa$
- Tempo di download per il client con banda minima è almeno: $\frac{F}{d_{min}}$

Tempo per distribuire F a N clienti con client-server: 
$$
D_{c-s} \geq max{\{\frac{NF}{u_{s}}, \frac{F}{d_{min}}\}}
$$
## Distribuzione di file P2P
Trasmissione via server: deve trasmettere almeno una copia del file: 
$tempo \ per \ l'invio \ di \ una \ copia: \frac {F}{u_{s}}$
client: ogni client deve scaricare una copia del file: 
$tempo \ per \ il \ client \ più \ lento, \ almeno \ \frac {F}{d_{min}}$
I client: come aggregato devono scaricare NF bit 
- Capacità totale di upload è $u_{s} + \sum{u_{i}}$

Tempo per distribuire F a N client usando l'approccio P2P  
$$ 
D_{P2P} \geq max{\{\frac{F}{u_{s}}, \frac{F}{d_{min}}, \frac{NF}{u_{s}+\sum{u_{i}}}\}}
$$
[[BitTorrent | BitTorrent]]
