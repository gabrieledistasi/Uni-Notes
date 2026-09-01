# Formato dei datagrammi IP 
![[Pasted image 20260902002600.png]]

## I campi principali dell'header IPv4
- **Version** 
	indica la versione del protocollo IP
- **Header Length/IHL**
	Indica quanto è lungo l'header IP. L'header IPv4 può avere dimensione variabile a causa delle opzioni. 
- **Total length**
	Indica la dimensione totale del datagramma IP: 
	$$
	TotalLength = Header + Payload
	$$
	Quindi comprende sia header che dati. 

- **Identification, Flags e Fragment Offset**
	Questi tre campi sono legati alla **frammentazione IP.**
	Se un datagramma è troppo grande per attraversare una rete con un determinato MTU, IPv4 può frammentarlo. 
	I tre campi permettono poi al destinatario di riconoscere i frammenti e ricostruire il datagramma originale. 

- **TTL**
	Il TTL impedisce che un pacchetto possa rimanere in rete per sempre, ad esempio a causa di un loop di routing.  Ogni router che inoltra il datagramma **decrementa il TTL**. Se il TTL raggiunge 0, il datagramma viene scartato.
	**TTL limita il numero di router che un datagramma può attraversare.**

- **Protocol**
	Indica a quale protocollo di livello superiore devono essere consegnati i dati. Permette al livello IP del destinatario di capire a quale protocollo di trasporto consegnare il payload. 
	Ad esempio, `Protocol = TCP` indica che il payload deve essere consegnato a TCP, mentre `Protocol = UDP` indica che deve essere consegnato a UDP.

- **Header checksum**
	E' un controllo per verificare se l'header IP è stato corrotto durante il trasferimento. Riguarda l'**Header**, non tutto il datagramma. 
	
- **Source e destination IP address** 
	Sono i campi che indicano: 
	- Da dove proviene il datagramma 
	- Dove deve arrivare
	Sono fondamentali per **identificare sorgente e destinazione** del datagramma e vengono utilizzati dai router per determinare dove inoltrarlo.

- **Data/Payload** 
	E' la parte che contiene i dati trasportati da IP. 
	Tipicamente contiene un segmento TCP o un datagramma UDP: 
	┌─────────────────────┐
	│      IP header             │
	├─────────────────────┤
	│    TCP segment        │
	│       oppure                 │
	│    UDP datagram      │
	└─────────────────────┘
	

# Indirizzamento IP 

*Indirizzo IP:* Identificatore a 32 bit associato a ciascuna interfaccia di host e router. 
*interfaccia:* Connessione tra host/router e collegamento fisico
- I router hanno tipicamente più interfacce.
- gli host hanno tipicamente una o due interfacce. 

# Sottoreti 

**Cos'è una sottorete?**
Una sottorete è un insieme di interfacce che possono comunicare direttamente tra loro senza attraversare un router. 

Gli indirizzi IP hanno una struttura: 
- Parte della sottorete: i dispositivi della stessa sottorete hanno in comune i bit di ordine superiore
- Parte dell'host: i rimanenti bit di ordine inferiore

**Procedura per definire le sottoreti:**
Si sgancino le interfacce da host e router in maniera tale da creare "isole" di reti isolate delimitate dalle interfacce.
Ognuna di queste reti isolate viene detta sottorete. 
![[Pasted image 20260902004638.png]]


# Indirizzamento IP: CIDR 
**CIDR: Classless InterDomain Routing** 

- Il CIDR permette di dire **quanti bit di un indirizzo IPv4 appartengono alla rete**, senza essere vincolati alle vecchie classi A, B e C.
Il formato è a.b.c.d/x
dove x indica quanti bit costituiscono il prefisso di rete. 
Un **IPv4 ha sempre 32 bit**. 
Ad esempio: 

>200.23.16.0/23 
>
>vuol dire che: 
>
>23 bit -> rete
>9 bit -> host

Quindi possiamo rappresentarlo così: 

11001000 00010111 00010000 00000000
<------ 23 bit -------><--9-->
       RETE             HOST

## Perché si parla di suddividere una rete?

Supponiamo che un'organizzazione abbia ricevuto: 

`200.23.16.0/23`

Ha quindi un certo blocco di indirizzi a sua disposizione. L'organizzazione può decidere di dividerlo in **sottoreti interne**. 
Per suddividere il blocco in sottoreti, si **estende il prefisso di rete**, prendendo alcuni bit dalla parte host e utilizzandoli per identificare le sottoreti. Ad esempio, si può passare da `/23` a `/25`.
Più aumenta il valore del prefisso `/x`, più bit sono dedicati alla rete e meno ne rimangono per gli host.

## Il numero di host
Nell'esempio in cui introduciamo il CIDR abbiamo visto che rimangono 9 bit per l'host. Con 9 bit posso rappresentare: 
$$
2^{9} = 512 \ indirizzi
$$
Ma ne posso usare solo 510, perché due indirizzi hanno un significato speciale: 
- **Tutti i bit host a 0 → indirizzo rete**

200.23.16.0 rappresenta la rete, quindi non viene assegnato a nessun host

- **Tutti i bit host a 1 → directed broadcast**
	per `/23`: 
	200.23.17.255
	è il broadcast della rete. 
	
**Limited broadcast:** `255.255.255.255`. Indica il broadcast sulla rete locale e non identifica una specifica rete.




