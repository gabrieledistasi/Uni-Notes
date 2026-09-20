# Domanda 1

Si consideri un host con un collegamento Ethernet a una sottorete cui è associato il prefisso **10.64.16.0/20**. Il router di default della sottorete ha indirizzo IP **10.64.16.1**; l'indirizzo IP assegnato all'host è **10.64.16.30**.

Rispondere in modo ragionato ai seguenti quesiti:

**I.** Qual è l’intervallo di indirizzi IP corrispondente al prefisso **10.64.16.0/20**?

**II.** All’interno di tale intervallo, quali indirizzi sono riservati e per quale scopo, e quanti possono essere assegnati alle interfacce collegate alla sottorete? Indicare se tali vincoli si applicano direttamente agli **switch Ethernet** che possono essere collegati alla sottorete.

**III.** Se l’host deve raggiungere destinazioni generiche su Internet, è necessario che lungo il percorso sia presente un router abilitato al **NAT**? Motivare la risposta.

**IV.** Si consideri l’invio di un datagramma IP verso due possibili destinazioni, **10.64.16.5** e **100.3.32.4**. Per ciascun caso, assumendo una tabella ARP vuota, indicare se una richiesta ARP viene effettuata, specificando il contenuto delle intestazioni dei livelli in cui la richiesta è incapsulata. Descrivere inoltre le risposte ARP corrispondenti, includendo le relative intestazioni.

--- 

## Soluzione 

### Punto I
Ci viene chiesto di individuare l'intervallo degli indirizzi IP corrispondenti al prefisso **10.64.16.0/20**.
Per prima cosa, sappiamo che quel prefisso indica il numero di bit che sono riservati alla rete, quindi avremo: 
$$32-20=12 \ bit \ riservati \ agli \ host$$
Andiamo a scrivere i nostri 4 ottetti: 
`00000000.00000000.00001111.11111111`

Guardiamo il terzo ottetto: 
$$
2^0 + 2^1 +2^2+2^3 = 1+2+4+8=15
$$
E facciamo: 
$$
255-15 = 240 \rightarrow 256-240 = 16
$$
quindi abbiamo salto 16 nel terzo ottetto, dunque: 
```
10.64.16.0 network
10.64.//.// indirizzi assegnabili agli host
10.64.31.255 canale broadcast 
```
Questo è l'intervallo corrispondente al prefisso dato. 

### Punto II
Come detto nel punto 1, l'indirizzo 10.64.16.0 è l'indirizzo riservato per la rete, l'indirizzo 10.64.31.255, le interfacce che possono essere collegate alla sottorete sono: 
32-20 = 12 $\rightarrow$ $2^{12}=4096$ indirizzi per gli host.   
Questi vincoli si applicano anche per gli switch ethernet. 

### Punto III
S', è necessario utilizzare il NAT poiché l'host 10.64.16.30, lungo il percorso deve essere presente un dispositivo NAT, perché appartiene allo spazio degli indirizzi privati. 
Il Nat traduce quindi l'indirizzo IP privato dell'host di un indirizzo IP pubblico utilizzabile sulla rete internet. 

### Punto IV 
L'host di partenza è: 
`IP = 10.64.16.30`

La sua rete è: 
`10.64.16.0/20`

e il default gateway è: 
`10.64.16.1`

Le destinazioni sono: 
```
A → 10.64.16.5
B → 100.3.32.4
```

La prima domanda da farsi è: *"Le destinazioni appartengono alla mia stessa sottorete?"*

## Caso 1: destinazione verso `10.64.16.5`
### 1. Verifico la sottorete 
La rete è: 
`10.64.16.0/20`

e l'intervallo è: 
```
10.64.16.0
        ↓
10.64.31.255
```
Quindi: 
`10.64.16.5`, è nella stessa rete di `10.64.16.30`
Pertanto il pacchetto deve essere inoltrato direttamente a **10.64.16.5**. 
Ma siccome l'host conosce l'IP e non il MAC, deve fare **ARP**. 


### ARP request 
La tabella ARP è vuota, quindi `10.64.16.30` manda una richiesta ARP, essa viene **incapsulata direttamente in un frame ethernet**, 

```
src MAC = MAC_30 
dst MAC = FF:FF:FF:FF:FF:FF
EtherType = 0x0806 
```
Il MAC destinazione è broadcast perché la tabella è vuota. 

```
ARP

Operation = request(1)

Sender MAC = MAC_30
Sender IP = 10.64.16.30

Target MAC = 00:00:00:00:00:00
Target IP = 10.64.16.5
```

### ARP Reply
L'host 10.64.16.5 riceve la richiesta e risponde, questa volta la risposta è **unicast** perché il mittente già conosce il MAC di 10.64.16.30. 

```
MAC sorgente = MAC_5 
MAC destinazione = MAC_30
EtherType = 0x0806
```

```
ARP Reply

Operation = reply(2)

Sender MAC = MAC_5
Sender_IP = 10.64.16.5

Target MAC = MAC_30
Sender_IP = 10.64.16.30
```

e può finalmente inviare il datagramma IP. 


## Caso 2: Destinazione verso `100.3.32.4`

Facciamo la stessa cosa per il primo caso, in questo caso però, l'indirizzo di destinazione non appartiene alla stessa sottorete, quindi non può consegnare direttamente il frame a `100.3.32.4`.
Deve mandarlo prima al **default gateway:**
`10.64.16.1`

Quindi avremo: 
```
ARP 

Operation = request(1)

Sender MAC = MAC_30
Sender_IP = 10.64.16.30

Target MAC = FF:FF:FF:FF:FF:FF
Target IP = 10.64.16.1
```

### ARP Reply del router 

```

Operation = reply(2)

Sender MAC = MAC_ROUTER
Sender IP = 10.64.16.1

Target MAC = MAC_30
Target_IP = 10.64.16.30
```

Il datagramma IP mantiene come destinazione `100.3.32.4`

---
# Domanda 2
Si descriva il concetto di **instradamento** nelle moderne reti a commutazione di pacchetto. In particolare, il candidato affronti i seguenti punti in maniera ragionata:

**I.** Descrivere la funzione di **instradamento (routing)** e la funzione di **inoltro (forwarding)** rispetto ai router, evidenziando come le decisioni di routing influenzano concretamente il processo di forwarding.

**II.** Presentare le diverse tipologie di instradamento introdotte da Internet, spiegandone motivazioni e obiettivi, e fornendo per ciascuna un esempio di protocollo.

**III.** Considerando uno scenario con più reti interconnesse:

- Mostrare come viene popolata la **tabella di inoltro** di un router per una destinazione esterna alla rete di appartenenza.
- Chiarire se tale processo avviene per ogni singolo indirizzo IP o secondo criteri differenti.

**IV.** Discutere quando la mobilità di un host costituisce una criticità per il livello di rete e illustrare i principali approcci per l’instradamento verso nodi mobili.

---
Il routing è la funzione del piano di controllo del router, questa permette di definire il cammino completo, lungo tutti i router, di un pacchetto. La funzione di inoltro è invece riguardante il piano dei dati del router, serve per determinare su quale porta di uscita bisogna inoltrare il pacchetto, per farlo, utilizza la *tabella di inoltro* una tabella che viene costruita in base ai messaggi che i vari router si scambiano in maniera da conoscere la topologia della rete. Possiamo quindi dire che la funzione di inoltro è una funzione locale. La tabella di inoltro nei router viene solitamente copiata all'interno delle porte di ingresso per un lookup più veloce e per ridurre il carico sul processore di instradamento(unità che riceve le informazioni degli altri router per calcolare i percorsi che possono variare). Internet utilizza diverse modalità di instradamento che possono essere distinte sia basandoci sull'algoritmo, sia in base all'ambito in cui avviene l'instradamento. Tra gli algoritmi troviamo il **link state**, in cui i router raccolgono informazioni sullo stato dei collegamenti e possono costruire una rappresentazione della topologia per calcolare i percorsi, e il **distance vector** basato sullo scambio di informazioni sulle distanze verso le destinazioni. Un esempio di link state è OSPF, mentre RIP è un esempio di distance vector. 
Dal punto di vista dell'ambito distinguiamo invece tra **intra-AS** ovvero l'instradamento all'interno dello stesso autonomous system e **inter-AS**, ovvero l'instradamento verso altri sistemi autonomi.  Per l'instradamento *intra-AS* vengono utilizzati, tra gli altri, OSPF e RIP, mentre l'instradamento inter-AS usa, come protocollo fondamentale, BGP. 
La distinzione tra inter-AS e intra-AS è motivata principalmente da politiche, scalabilità e prestazioni: tra AS differenti le politiche degli amministratori hanno un ruolo importante, mentre all'interno di un AS è possibile concentrarsi sulle prestazioni. 
Quando un router deve inoltrare un pacchetto ad un host che si trova in un'altra sottorete, deve utilizzare la funzione di routing. Quindi il router che deve inoltrare un pacchetto eseguirà un protocollo, ad esempio OSPF, i router scambiano informazioni relative alla rete. A questo punto, il router mittente scopre quale sarà il next hop, grazie al risultato del routing, e inserisce nella sua forwarding table il router successivo e infine inoltra il pacchetto. 
La forwarding table tuttavia non contiene tutti gli indirizzi IP della rete, sarebbe impraticabile e la tabella sarebbe grandissima. Per questo motivo è possibile raggruppare gli indirizzi IP attraverso i prefissi di rete. Un raggruppamento ad esempio è: `8.8.8.0/24`, questa raggruppamento contiene da `8.8.8.0` fino a `8.8.8.255`, dunque il router conosce a quale indirizzo IP è destinato il pacchetto e invia al gruppo con il *prefisso più grande* per via della regola del *"Longest common prefix."*
La mobilità di un host costituisce una criticità per il livello di rete perché l'indirizzo IP è associato anche alla **posizione topologica dell'host**, cioè alla rete a cui esso è collegato. Quando un host si sposta da una rete a un'altra, il suo indirizzo IP potrebbe quindi non essere più coerente con la nuova rete e i router potrebbero non riuscire a raggiungerlo correttamente.

Esistono principalmente due approcci:

- **cambiare indirizzo IP** quando l'host entra nella nuova rete, ottenendo un indirizzo appartenente al nuovo prefisso, ad esempio tramite DHCP. In questo caso l'instradamento è semplice, ma le comunicazioni che utilizzavano il precedente indirizzo IP devono essere aggiornate;
- **mantenere lo stesso indirizzo IP** nonostante il cambio di rete. In questo caso sono necessari meccanismi specifici per individuare la posizione attuale dell'host e inoltrare verso di essa i pacchetti destinati al suo indirizzo originale. Un esempio è **Mobile IP**, che utilizza meccanismi di inoltro e tunneling per mantenere la raggiungibilità del nodo mobile.


