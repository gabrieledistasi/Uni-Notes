### Il problema della risoluzione dei nomi
Un computer in internet può essere identificato in due modi: 
- tramite l'indirizzo IP 
- tramite un nome, ad esempio cs.umass.edu
L'indirizzo IP serve alla rete per indirizzare i datagrammi, mentre il nome è molto più comodo per gli esseri umani e quindi sorge spontanea la domanda: **Come introduciamo un nome in un indirizzo IP e viceversa?**
Una soluzione potrebbe essere quella del **File hosts**, ovvero l'idea di associare un indirizzo IP a uno o più hostname. Locale a un nodo, il suo contenuto non deve necessariamente coincidere con quello di altri nodi. Negli anni '70 venne introdotto HOSTS.TXT, mantenuto dal Network Information Center, reso disponibile su un host designato veniva installato dagli amministratori di sistema sui singoli nodi. Questa soluzione presentava però dei problemi come la crescita del file e il traffico generato sull'host dov'era pubblicato. 

# Domain Name System 
Il DNS è un database distribuito implementato in una gerarchia di name server che permette di risolvere i nomi degli host, ovvero di tradurre: 
**Hostname -> indirizzo IP**
Il DNS è anche un protocollo a livello di applicazione, consente agli host e ai server DNS di comunicare per risolvere i nomi.
### Servizi e Struttura 
I servizi principali del DNS non si limitano a risolvere i nomi degli host, ma abbiamo altri servizi: 
- Host aliasing, un host può avere più alias e un solo nome vero, tramite il record CNAME il DNS può tradurre anche gli alias 
- Mail server aliasing, il DNS può indicare quale server di posta è responsabile per un determinato dominio. Serve quando un mail server deve sapere a quale server SMTP consegnare una mail. 
- Load distribution, il DNS può essere utilizzato per distribuire il carico: un singolo nome può corrispondere a più indirizzi IP, quindi richieste diverse possono essere indirizzate verso server differenti. 

**Perché non centralizzare il DNS?**
Brevemente, se centralizzassimo il DNS non scalerebbe, a causa di un unico punto di fallimento e un enorme volume di traffico che si troverebbe a dover gestire 

## Root Name Server
Sono i server "radice" che forniscono gli indirizzi dei server TLD. Ne esistono 13 in tutto il mondo, replicati in centinaia di istanze. I root name server sono di fondamentale importanza, senza di essi internet non potrebbe funzionare.
ICANN (Internet Corporation for assigned names and numbers) gestisce il root DNS domain

## Top-Level domain, authoritative servers
**Top-level domain DNS server:**
Si occupano dei domini .com, .org ecc. e di tutti i domini locali come .it, .uk, .ch ecc. 

**DNS server autoritativo**
Appartengono ad organizzazioni e forniscono le mappature ufficiali per i propri host, possono essere mantenuti dall'organizzazione o dal service provider.

## Name server DNS locali 
Anche detti "resolver", appartengono solitamente agli ISP e fungono da intermediari tra gli host e la gerarchia DNS. 

## Interrogazione iterativa VS interrogazione ricorsiva
Nel sistema DNS, la risoluzione dei nomi può avvenire attraverso due modalità di interrogazione: **Iterativa e ricorsiva**. 
### Interrogazione ricorsiva
In un'interrogazione ricorsiva, l'host o il server che riceve la query si assume il compito di tradurre il nome per conto del richiedente. Se il serve interrogato non conosce la mappatura, contatterà lui stesso altri server nella gerarchia dino a trovare la risposta o un errore. Tipicamente l'interrogazione ricorsiva viene utilizzata nella comunicazione tra l'host richiedente e il suo DNS server locale. Lo svantaggio di questo tipo di interrogazione è che può generare un carico di lavoro molto pesante per i server ai livelli superiori della gerarchia.

### Interrogazione iterativa
In un'interrogazione iterativa, il server contattato non risolve il nome direttamente se non lo conosce, ma fornisce al richiedente un riferimento al server successivo da consultare.
Il funzionamento di questa interrogazione ha come idea di base "Io non conosco questo nome, ma puoi chiederlo al server che ti indico". Il richiedente riceve l'indirizzo IP del server DNS di livello inferiore e procede a interrogarlo direttamente. 
Questa è la modalità standard utilizzata dai DNS server locali per navigare la gerarchia DNS. 

### caching e record update
Una volta che un name server impara la mappatura la mette nella cache e restituisce il mapping nella cache in risposta a una query. La tecnica del caching migliora i tempi di risposta.
## Record DNS
Nel DNS non esiste alcuna limitazione che impedisca di associare allo stesso name più record di tipi diversi. La principale eccezione è rappresentata dal fatto che non può esserci un record CNAME e nessun altro tipo di record per lo stesso name. 
Ogni tipo di record risponde a una domanda diversa, posta da client diversi in momenti diversi.
## Sicurezza del DNS
Il DNS può essere soggetto ad attacchi DDoS, il tentativo di bombardare il traffico di root server non ha avuto molto successo. Bombardare i server TLD è potenzialmente il più pericoloso. 
Un altro possibile attacco è lo spoofing attacco, intercettando le query DNS è possibile restituire risposte fasulle. 
[[Architettura P2P | Architettura P2P]]
