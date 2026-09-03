# NAT : Network Address Translation

In una rete domestica, i vari dispositivi connessi utilizzano degli indirizzi privati, questi indirizzi possono essere utilizzati nella rete locale, ma solo lì e da nessun'altra parte. 

L'idea di NAT è che:
**Tutti i dispositivi della rete locale condividono un solo indirizzo IPv4 per il mondo esterno**.

## implementazione 
I router NAT devono: 
- Sostituire ogni indirizzo IP sorgente, numero di porta sorgente di ogni datagramma in uscita, con indirizzo IP NAT, nuovo n. di porta. 
- I client server remoti risponderanno con l'indirizzo IP NAT e il nuovo numero di porta come indirizzo di destinazione. 
- Ricordare nella tabella di traduzione NAT ogni coppia di traduzione da indirizzo IP e porta sorgente a indirizzo IP NAT e nuova porta. 
- Sostituire indirizzo IP NAT, nuovo numero di porta nei campi di destinazione di ogni datagramma in ingresso con il corrispondente indirizzo IP NAT e nuovo numero di porta memorizzato nella tabella NAT

Tutto rose e fiori? mhhhh...
Il NAT, pur essendo molto utile, rompe in parte il principio end-to-end di internet. 
Il router infatti deve guardare anche il livello di trasporto, poiché deve andare a modificare le porte TCP e UDP. 
Inoltre, sebbene NAT sia nato per risolvere la scarsità di indirizzi IPv4, questa non era la soluzione corretta: 
**IPv6 offre uno spazio di indirizzamento enormemente più grande.**
Oltre che, come già detto, viola il principio end-to-end di internet, infatti senza NAT, due endpoint possono comunicare utilizzando i propri indirizzi IP, con NAT vengono modificate le informazioni contenute nei pacchetti. Questo può complicare azioni e protocolli che si aspettano una comunicazione diretta tra gli endpoint. 

#remember 
Il NAT è controverso perché:

> **è molto utile per conservare indirizzi IPv4, ma altera il funzionamento end-to-end di Internet, richiede che i router considerino anche le porte di trasporto e può creare problemi alle applicazioni che devono stabilire connessioni attraverso un NAT.**

[[IPv6 | IPv6]]
