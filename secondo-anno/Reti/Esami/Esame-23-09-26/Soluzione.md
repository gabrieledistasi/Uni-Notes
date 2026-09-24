
Domanda 1. 

Si consideri un router IPv4 con diversi collegamenti Ethernet, la cui tabella di inoltro è data di seguito.  
Sono omesse le reti **212.189.0.0/24, 212.189.1.0/24 e 212.189.2.0/24**, direttamente connesse, rispettivamente, alle interfacce **eth0, eth1 ed eth2**.
```
|Rete di destinazione|Next Hop IP|Interfaccia|
|--------------------|-----------|-----------|
|0.0.0.0/0           |212.189.0.1|     eth0  |
|151.100.0.0/16      |212.189.0.1|     eth0  |
|151.100.16.0/24     |212.189.2.1|     eth2  |
|151.100.17.0/24     |212.189.1.1|     eth1  |
|151.100.18.0/24     |212.189.2.1|     eth2  |
|151.100.19.0/24     |212.189.2.1|     eth2  |
|151.100.128.0/23    |212.189.1.1|     eth1  |
|151.100.130.0/23    |212.189.1.1|     eth1  |
----------------------------------------------
```
Rispondere in maniera ragionata ai seguenti quesiti:

**I.** In quale livello avviene il calcolo delle tabelle di inoltro e quali sono i due principali approcci per farlo?

**II.** Il router riceve un datagramma IP destinato all’indirizzo **151.100.17.30**. Il datagramma è trasportato all’interno di un frame Ethernet. Indicare su quale interfaccia deve essere inoltrato il datagramma e specificare quali campi delle intestazioni dei vari livelli coinvolti vengono aggiornati dal router.

**III.** Ridurre — se possibile — la dimensione della tabella di inoltro.

--- 
## Soluzione
### I.
Il calcolo delle tabelle di inoltro avviene nel livello di rete, nel piano di controllo e i due metodi principali per svolgere questa operazione sono: 
Calcolo della tabella tramite il metodo tradizionale, questo metodo prevede che i router scambino le informazioni tra di loro per ottenere la topologia della rete e capire quali saranno i next hop. 
Il secondo approccio è attraverso SDN (software defined networking) questo metodo prevede l'utilizzo di un controller logico centralizzato che conosce l'intera topologia della rete e calcola le tabelle dei vari router, a quel punto verranno inviate le tabelle a tutti i router della rete. 

## II.
Il router riceve il datagramma IP destinato all'indirizzo **151.100.17.30**, per capire a quale interfaccia verrà inoltrato tale datagramma. 
La tabella di inoltro presenta destinazioni nella stessa sottorete, andremo a prendere: 
`151.100.17.0/24` e notiamo che: 
151.100.17.0/24, vuol dire che abbiamo 24 bit dedicati alla rete e 32-24 = 8 bit per gli host. 
Dunque l'ottetto sarà: 
`00000000.00000000.00000000.11111111`, a questo punto facciamo: 
$$
256 - 255 = 1 
$$
Quindi saltiamo di 1 nel quarto ottetto e dunque: 
dunque il datagramma appartiene alla rete `151.100.17.0/24`, sebbene appartenga anche alla rete `151.100.0.0/16` dobbiamo rispettare la regola del **Longest prefix match** dunque dovremo inviare il nostro datagramma sull'interfaccia `eth1`. 
L'header IP continua ad avere: 
```
IP sorgente --> invariato 
IP destinazione --> invariato 
Header checksum --> ricalcolato

Header Ethernet 
MAC sorgente--> MAC dell'interfaccia eth1 del router
MAC destinazione --> MAC del next hop 212.189.1.1
```

## III.
Per ridurre la dimensione della tabella di inoltro dobbiamo cercare i prefissi adiacenti e lo stesso next-hop  in modo da sostituirli con un prefisso più grande. 
```
151.100.18.0/24 --> 212.189.2.1 --> eth2
151.100.19.0/24 --> 212.189.2.1 --> eth2
```

Questi due prefissi sono adiacenti e quindi possono essere aggregati: 
`151.100.18.0/23 --> 212.189.2.1 --> eth2`

Perché `/23` copre: 
```
151.100.18.0
151.100.19.255
```
Eliminiamo due righe dalla tabella e ne lasciamo una. 
Possiamo concludere che la tabella si riduce da **8 a 7 voci**, la tabella risultante è: 

```
|Rete di destinazione|Next Hop IP|Interfaccia|
|--------------------|-----------|-----------|
|0.0.0.0/0           |212.189.0.1|     eth0  |
|151.100.0.0/16      |212.189.0.1|     eth0  |
|151.100.16.0/24     |212.189.2.1|     eth2  |
|151.100.17.0/24     |212.189.1.1|     eth1  |
|151.100.18.0/23     |212.189.2.1|     eth2  |
|151.100.128.0/23    |212.189.1.1|     eth1  |
|151.100.130.0/23    |212.189.1.1|     eth1  |
----------------------------------------------
```

--- 
## Domanda 2 
L'obiettivo del **reliable data transfer** è quello di garantire l'integrità dei dati trasferiti e che i pacchetti inviati non vengano persi, sebbene i livelli al di sotto del livello di trasporto contengono i propri algoritmi di correzione di errore, come FEC o CRC ecc. tuttavia non possono garantire l'integrità dei dati sull'intero percorso. 
Il reliable data transfer è possibile vederlo come degli automi a stati finiti, il primo RDT è l'1.0 che è il modello teorico, in cui non sono presenti perdite o errori. In RDT 2.0 vengono invece introdotti gli errori e vengono aggiunti ACK e NAK, due segnali che vengono inviati dal ricevente per segnalare al mittente che i pacchetti sono o non sono arrivati. 
In RDT 2.1 viene aggiunto un bit per determinare l'azione da effettuare in caso di ricezione di uno dei due segnali, questo duplica gli stati della FSM. RDT 2.2 invece elimina NAK, l'idea è che se un pacchetto arriva correttamente al ricevente, basta un ACK, se invece il pacchetto non viene ricevuto correttamente, il mittente capirà che il pacchetto è stato perso perché il segnale di ACK non è arrivato. L'RDT 3.0 introduce invece il timeout, se il segnale di ACK non viene inviato dal ricevente, il mittente attende un periodo di tempo per determinare se quel pacchetto è stato perso oppure è solo in ritardo, il timeout tuttavia non deve essere troppo breve, perché questo comporterebbe lo scadere del tempo prima del timeout rispetto all'arrivo del segnale di ACK, se fosse troppo grande comporterebbe invece l'attesa inutile di un pacchetto perso.
RDT precedentemente funzionava attraverso il meccanismo di *stop-and-wait*, ovvero, quando un mittente inviava un pacchetto doveva attendere l'invio dell'ACK da parte del ricevente e la ricezione di questo. Tuttavia questo meccanismo rallenta di molto la comunicazione tra due endpoint. Per questo motivo venne introdotto il meccanismo di pipeline, in questo modo non era più necessario attendere la ricezione degli ACK inviati dal ricevente per inviare un nuovo pacchetto ma era possibile inviare più pacchetti senza attendere gli acknowledgment, portando a un maggiore utilizzo del collegamento e un throughput maggiore. Nel contesto di internet, il trasferimento affidabile dei dati viene realizzato principalmente dal protocollo TCP, che integra i meccanismi di trasferimento affidabile con il controllo di flusso e il controllo di congestione. 
TCP utilizza alcuni meccanismi come ad esempio **Go-Back-N** e **Selective repeat** questi due meccanismi vengono utilizzati per garantire il trasferimento affidabile. Go-Back-N utilizza ACK cumulativi, ovvero, dato l'MSS(maximum segment size), il mittente invia segmenti di 1 MSS, quando il ricevente ottiene il segmento invia un ACK in cui segnala il prossimo byte che si aspetta di ricevere. Il GBN inoltre non utilizza un buffer per memorizzare i segmenti che vengono ricevuti fuori sequenza, quando arrivano 3 ACK duplicati viene rinviata tutta la finestra: 
Supponiamo che la finestra sia di 4 MSS con e abbiamo 5 segmenti, supponendo che il secondo segmento viene perso, arriva il primo ACK per il primo segmento, per i successivi invece vengono rinviati gli ACK, a quel punto la finestra viene spostata e viene rinviato anche S2 e tutti i successivi segmenti. 
Selective repeat utilizza invece il buffer e ACK per singolo segmento, in maniera che, se un segmento viene perso, può essere rinviato senza dover rinviare l'intera finestra. Inoltre viene utilizzato un buffer per mantenere i segmenti fuori sequenza. 
TCP oltre a fornire un trasferimento dati affidabile, implementa anche due meccanismi fondamentali per regolare la quantità di dati che il mittente può trasmettere: il controllo di flusso e il controllo della congestione. 
Il controllo di flusso serve ad evitare il sovraccarico di un host ricevente da parte di un host mittente, che invia dati ad una velocità maggiore di quanto il ricevente è in grado di elaborare. A questo scopo TCP utilizza la receive window, o rwnd, che nel momento in cui raggiunge il valore 0, indica che non è più in grado di ricevere, in questa situazione il mittente invia periodicamente un bit per capire se può ricominciare la trasmissione oppure no. 
Diverso è il problema della congestione, che riguarda invece la capacità della rete. Anche se il ricevitore è in grado di ricevere molti dati, ad esempio un router con un buffer di accodamento molto grande, la rete potrebbe essere congestionata a causa di una enorme quantità di traffico. 
