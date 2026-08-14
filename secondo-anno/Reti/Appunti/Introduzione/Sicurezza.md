Internet originariamente nacque senza dare troppo peso alla sicurezza: l'idea era che pochi utenti fidati potessero accedere ad una rete trasparente. Oggi gli utenti sono miliardi, non tutti hanno buone intenzioni.
Ma come fanno i malintenzionati a sfruttare la rete per i loro scopi? 
Hanno a disposizione alcune tecniche e strumenti per ottenere informazioni non destinate a loro: 
- Packet sniffing, tramite alcuni strumenti è possibile leggere i pacchetti in viaggio in una rete, gli utenti legittimi hanno dalla loro la cifratura come strumento di difesa.
- IP Spoofing, invio di pacchetti ad un destinatario sotto un "nome" falso.
- Attacchi DoS, il denial of service rende impossibile l'accesso, da parte degli utenti legittimi, ad un servizio. 
Gli attacchi DoS possono essere di tre tipologie: 

###### Attacco alla vulnerabilità
L'attaccante invia pochi pacchetti, ma mirati a sfruttare una vulnerabilità del sistema operativo o dell'applicazione, mandando così in crash l'obiettivo. 

###### Bandwith Flooding
In questo caso invece non si tratta più di sfruttare vulnerabilità, ma si invia una quantità di traffico enorme alla vittima. 
La banda viene saturata e il traffico legittimo non riesce più a raggiungere il server.

###### Connection flooding
Qui l'attaccante crea un grande numero di connessioni TCP verso la vittima. L'obiettivo è quello di consumare le risorse necessarie a gestire le connessioni, impedendo al server di accettare quelle legittime. 

#### Linee di difesa 
Contro gli attacchi DoS, alcune misure di difesa che possiamo applicare: 
- Autenticazione: dimostrare chi siamo 
- Riservatezza: attraverso la cifratura 
- Integrità: Le firme digitali prevengono/rilevano le manomissioni
- Restrizioni di accesso: VPN protette da password
- Firewalls: "middlebox" specializzate nelle reti di accesso e di base: 
		- Off by default, filtra i pacchetti in entrata per limitare i mittenti, i destinatari e le applicazioni 
		- rilevare/reagire agli attacchi DoS
# Livelli di protocollo e modelli di riferimento 
Internet è un sistema molto complesso, costituito da diversi componenti sia hardware che software. Un modo per poter rendere più semplice la progettazione e lo studio della rete si utilizza la stratificazione, ovvero la suddivisione delle funzionalità in più livelli. Ogni livello ha specifici compiti e utilizza servizi del livello sottostante. 

## Pila di protocolli di internet 

- **Applicazione**: supporto alle applicazioni di rete 
- **Trasporto**: trasporto di dati tra processi 
- **Rete**: trasferimento di pacchetti di rete, detti datagrammi, da un host all'altro 
- **Collegamento**: trasferimento di dati tra elementi di rete vicini
- **Fisico**: bit sul "filo"
## Servizi, Stratificazione e Incapsulamento
Una rete è troppo complessa per considerarla come un unico blocco: abbiamo router, host, switch, mezzi trasmissivi; Perciò è meglio suddividere il problema grande in problemi più piccoli. 
![[Pasted image 20260811161541.png]]

### Modello di servizio 
Insieme dei servizi offerti da un livello a quello superiore 
I diversi servizi possono essere implementati da protocolli diversi 
Il livello di collegamento può offrire servizi diversi in base al protocollo impiegato sul link
Un protocollo a livello di collegamento può prevedere diversi protocolli a livello fisico dipendentemente dalla tecnologia di trasmissione e dal mezzo trasmissivo del link.

## Incapsulamento 
L'intestazione del datagramma contiene gli indirizzi dell'host sorgente e dell'host di destinazione, questi indirizzi sono gli estremi della comunicazione e generalmente rimangono invariati durante la procedura di comunicazione. 
Il frame di livello 2 contiene invece gli indirizzi MAC del dispositivo sorgente e del dispositivo destinazione del singolo hop. Ad ogni router attraversato viene quindi creato/aggiornato il frame per il collegamento successivo: il MAC sorgente diventa quello del dispositivo che sta inviando il frame e il MAC destinazione quello del dispositivo immediatamente adiacente. 

## Modello di riferimento ISO/OSI
Due strati non presenti nella pila di protocolli internet 

- presentazione: consente alle applicazioni di interpretare il significato dei dati, ad esempio crittografia, compressione, convenzioni specifiche della macchina. 
- sessione: sincronizzazione, checkpointing, ripristino dello scambio dei dati 
La pila internet "manca" di questi strati. Questi servizi, se necessari, devono essere implementati nelle applicazioni. 

[[Applicazioni_di_rete | Applicazioni di rete]]
