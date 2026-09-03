Come ottenere un indirizzo IP?
In realtà questa domanda contiene altre due domande: 
- Come fa un host a ottenere l'indirizzo IP all'interno della sua rete?
- Come fa una rete a ottenere l'indirizzo IP?
Per il primo problema entra in gioco DHCP

# DHCP 

DHCP = Dynamic Host Configuration Protocol

è il protocollo che permette ad un dispositivo di ottenere la configurazione necessaria per comunicare sulla rete. Quindi anziché dover configurare manualmente tutti i computer, possiamo avere un **Server DHCP** in grado di configurare automaticamente gli indirizzi. 
L'host ottiene l'indirizzo dinamicamente, quando si "unisce" alla rete. DHCP permette, inoltre, il riutilizzo degli indirizzi. 

### Panoramica di DHCP 
- L'host invia in broadcast un messaggio DHCP discover 
- Il server DHCP risponde con un messaggio DHCP offer
- L'host richiede un indirizzo IP: messaggio DHCP request 
- Il server DHCP invia un indirizzo IP: messaggio DHCP ack

#remember 
DHCP permette a un host di ottenere automaticamente un indirizzo IP e gli altri parametri necessari per comunicare sulla rete.

# DHCP client-server scenario
Abbiamo una rete con un server DHCP: 

**DHCP server → 223.1.2.5**

e arriva un nuovo client che non possiede ancora un indirizzo IP. 
A questo punto, il client manda un DHCP discover in broadcast: 

`src:  0.0.0.0:68`
`dest: 255.255.255.255:67`

Il client non ha ancora un indirizzo IP in questa fase, quindi usa `src` mentre `255.255.255.255` è il limited broadcast. 

`68 → client DHCP`
`67 → server DHCP`

Il server DHCP `223.1.2.5` risponde: 
`
`src:  223.1.2.5:67`
`dest: 255.255.255.255:68`
`yiaddr: 223.1.2.4`
`lifetime: 3600 sec`

Il server DHCP in questo caso sta proponendo al client di utilizzare l'indirizzo `yiaddr` per 3600 secondi. Anche questa risposta viene mandata in broadcast perché il client non è ancora completamente configurato. 

A questo punto il client risponde con DHCP Request e comunica di voler utilizzare quell'indirizzo. 
#### Perché ancora broadcast?
Immaginiamo che ci siano più server DHCP: 

          Client
             │
       DHCP Discover
             │
      ┌──────┴──────┐
      ↓             ↓
   Server A       Server B
   Offer A        Offer B

Il client potrebbe ricevere più offerte. Con il DHCP broadcast comunica con tutti i server, in questo modo comunica a tutti i server qual è stata la sua scelta. A quel punto il server scelto procede, gli altri invece possono liberare l'indirizzo che avevano riservato per quel client. 
Infine il server risponde con **DHCP ACK** e conferma l'IP e il lifetime per quel client che a questo punto è configurato. 

Il DHCP può restituire più di un indirizzo IP: 
- Indirizzo del router first-hop o router predefinito
- Nome e indirizzo IP del server DNS 
- Maschera di sottorete

### Esempio
In questo esempio abbiamo un computer che si collega alla rete Wi-Fi/LAN. Il router ha al suo interno un server DHCP; il computer, per connettersi, deve ottenere: 
- Il proprio indirizzo IP
- L'indirizzo del router first-hop
- L'indirizzo del DNS
La richiesta al router arriva mediante **incapsulamento**, il messaggio DHCP viene incapsulato progressivamente. 
#### Perché ethernet usa ancora il broadcast?
Il client non conosce ancora il proprio IP e non conosce l'indirizzo del server DHCP. Perciò la richiesta viene inviata in broadcast sulla LAN. 
Il router riceve il frame ethernet e deve "spacchettarlo": 
Ethernet
   ↓
IP
   ↓
UDP
   ↓
DHCP

Ogni livello riconosce a quale protocollo/livello superiore passare i dati (la risposta farà il percorso inverso).

#remember 
>Una richiesta DHCP viene incapsulata in UDP, poi IP, poi Ethernet. Quando arriva al router, viene decapsulata progressivamente fino ad arrivare al protocollo DHCP.

Come fa la rete a ottenere la parte di rete dell'indirizzo IP?
Ottiene l'assegnazione di una porzione dello spazio di indirizzi del suo provider ISP. 

# Indirizzamento gerarchico: aggregazione di indirizzi 
L'indirizzamento gerarchico consente di pubblicizzare in modo efficiente le forme di routing. 
Come abbiamo detto sopra, un ISP possiede un grande blocco di indirizzi IP e lo divide tra le diverse organizzazioni. 

ISP
200.23.16.0/20

Questo blocco viene diviso in 8 blocchi /23: 

Organizzazione 0 → 200.23.16.0/23
Organizzazione 1 → 200.23.18.0/23
Organizzazione 2 → 200.23.20.0/23
...
Organizzazione 7 → 200.23.30.0/23

Il problema è che, senza aggregazione, l'ISP dovrebbe pubblicizzare separatamente gli 8 blocchi, quindi un router dovrebbe avere molte voci nella propria tabella di routing. Ma tutti questi indirizzi appartengono allo stesso ISP  e sono contenuti nello stesso blocco. 

**Come fa un ISP a ottenere un blocco di indirizzi IP?**
Un ISP ottiene un blocco di indirizzi IP nell'ambito della gerarchia di assegnazione degli indirizzi; successivamente suddivide quel blocco tra le reti dei propri clienti.

**Ci sono abbastanza indirizzi IP a 32 bit?**
L'ICANN ha assegnato l'ultima
porzione di indirizzi IPv4 ai RR
nel 2011.
- NAT (successivo) aiuta con l'esaurimento dello spazio degli indirizzi IPv4.
-  IPv6 ha uno spazio di indirizzi a 128 bit

[[NAT|NAT]]



