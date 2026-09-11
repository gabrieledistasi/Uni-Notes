# #🔑 Cos'è la mobilità?
Spettro della mobilità, dal punto di vista del livello di rete, non basta che un dispositivo si muova fisicamente. Se rimane sempre collegato alla stessa base station, dal punto di vista del livello di collegamento non c'è mobilità. Ci interessa soprattutto il caso in cui il dispositivo: 
- **Si sposta tra reti di accesso mantenendo connessioni in corso.**
## Il problema fondamentale della mobilità 
Immagina che il telefono abbia un indirizzo IP permanente: 
```
📱
IP = 128.119.40.186
```
All'inizio si trova nella rete Verizon.
Poi si sposta nella rete AT&T. 
```
Prima:

Internet → Verizon → 📱


Dopo:

Internet → ??? → AT&T → 📱
```
Il problema è: 
>	**Come fa Internet a sapere che quel dispositivo adesso si trova nella nuova rete?**

# Primo approccio: far gestire la mobilità ai router 
Una possibilità è lasciare che sia direttamente il routing di internet a gestire la posizione del dispositivo. 
La rete visitata potrebbe annunciare tamite **BGP:**

> "L'indirizzo IP permanente di questo dispositivo è raggiungibile attraverso di me."

Quando il dispositivo lascia la rete, l'annuncio viene ritirato. 
In teoria il normale routing Internet potrebbe quindi già gestire la mobilità usando la **longest prefix matching.**

# Secondo approccio: Gestire la mobilità alla periferia 
Due possibilità: 
1. **Routing indiretto**. 
2. **Routing direttto**. 

## Routing indiretto
Il dispositivo ha una home network, cioè la sua rete domestica. Quando si trova altrove, si trova in una **visited network.**
Il corrispondente continua a utilizzare l'**indirizzo IP permanente** del dispositivo. 
Il datagramma arriva quindi alla **home network**. 
Il gateway della home network scopre dove si trova il dispositivo e lo inoltra tramite un tunnel alla rete visitata. 
### Vantaggio del routing indiretto
Se il dispositivo cambia nuovamente rete: 
```
Visited A
   ↓
Visited B
   ↓
Visited C
```
Il corrispondente continua a mandare i pacchetti sempre allo stesso IP. 
E' la nuova rete visitata che aggiorna la propria posizione presso la **home network/HSS**
**La mobilità è trasparente al corrispondente.**

### Triangular routing
Il problema è che il percorso può diventare inefficiente. 
```
Visited A
   ↓
Visited B
   ↓
Visited C
```
anche se server e telefono sono magari molto vicini. 
Il traffico fa quindi una specie di **triangolo.**
Questo viene chiamato: 
	**Triangular routing**
ed è inefficiente soprattutto quando il corrispondente e il dispositivo mobile sono vicini o nella stessa rete. 

# Routing diretto
La seconda possibilità è evitare il passaggio della home network. 
Il corrispondente contatta la home network/HSS per sapere dove si trova il dispositivo. 
**care-of-address**
cioè l'indirizzo utilizzabile per raggiungere il dispositivo nella rete visitata. 

### Vantaggio
Si elimina l'inefficienza del triangular routing. 
### Svantaggio
Il corrispondente deve conoscere il **care-of-address.**
Quindi la mobilità **non è più completamente trasparente al corrispondente.**
Se il dispositivo cambia nuovamente rete, bisogna aggiornare questa informazione. 

# Mobilità nelle reti 4G: compiti di mobilità principali

## 1. Associazione alla stazione di base
Il dispositivo mobile si associa alla base station.
Durante questa fase fornisce il proprio IMSI, che permette di identificare: 
- Il dispositivo 
- La sua home network 
## 2. Configurazione del piano di controllo
La **MME** della rete visitata e l'HSS della home network stabiliscono lo stato del piano di controllo. 
In pratica la rete deve sempre sapere: 
> **"Questo dispositivo si trova attualmente nella visited network."**

L'MME utilizza le informazioni dell'IMSI per contattare l'HSS e recuperare le informazioni necessarie per **autenticazione, cifratura e servizi di rete.**

## 3. Configurazione del piano dei dati 
Ora bisogna stabilire **come far arrivare effettivamente i dati al dispositivo.**
La MME configura i tunnel necessari per l'inoltro. 
In particolare abbiamo il percorso: 
```
Home P-GW
     │
     │ tunnel
     ↓
    S-GW
     │
     │ tunnel
     ↓
Base Station
     │
     ↓
    📱
```
## 4. Mobile Handover
Infine il dispositivo può spostarsi da una base station a un'altra. 
Questo è l'handover. 
La rete deve quindi aggiornare il percorso dei dati affinché il traffico continui ad arrivare al dispositivo attraverso la nuova base station. 

