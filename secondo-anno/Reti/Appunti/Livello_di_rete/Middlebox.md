**Una middlebox è un dispositivo che si trova "in mezzo" al percorso tra due endpoint e svolge una funzione diversa rispetto all' inoltro di pacchetti.**
Un router, normalmente, una volta che riceve un pacchetto decide su quale porta indirizzarlo per l'invio. Una middlebox invece può analizzare, gestire, modificare e filtrare il traffico. 
Un esempio di middlebox che abbiamo già visto è il [[NAT|NAT]], esso infatti è in grado di modificare i dati; nei firewall controlla il traffico e decide se permetterlo. 

#    #🧠 Inoltro generalizzato e middlebox

## Inoltro generalizzato

Nel normale inoltro IP, il router decide la porta di uscita principalmente in base all'**indirizzo IP di destinazione**.

L'**inoltro generalizzato** estende questo meccanismo: il dispositivo può esaminare diversi campi dell'intestazione del pacchetto e, in base a questi, eseguire una determinata azione.

L'idea fondamentale è:

> **Match + Action**

- **Match** → vengono controllati uno o più campi del pacchetto;
- **Action** → viene eseguita l'azione associata alla regola.

Esempio:

```
MATCH:
IP destinazione = 10.2.0.0/24

ACTION:
forward → porta 3
```

# NFV

**NFV = Network Functions Virtualization**

NFV consiste nell'implementare le **funzioni di rete come software**, invece di vincolarle necessariamente a dispositivi hardware proprietari.

Per esempio, un firewall può essere realizzato come software eseguito su hardware generico:

```
Hardware COTS
      ↓
VM / software
      ↓
Firewall
```

Le funzioni di rete possono quindi essere eseguite su infrastrutture generiche e anche in ambienti cloud.

## SDN e NFV

SDN e NFV sono concetti **complementari**, ma affrontano problemi differenti.

### SDN

Separa il **piano di controllo** dal **piano dei dati** e rende programmabile il comportamento della rete.

```
Control plane
      ↓
Controller
      ↓
Data plane
      ↓
Switch / Router
```

### NFV

Separa la **funzione di rete dall'hardware dedicato**, permettendo di implementarla come software.

```
Funzione di rete
      ↓
    Software
      ↓
Hardware generico
```

---

## #🔑 Da ricordare

> **L'inoltro generalizzato si basa sull'astrazione match + action: il dispositivo identifica i pacchetti in base ai loro campi e applica l'azione associata.**

> **Le middlebox sono dispositivi intermedi che svolgono funzioni oltre al semplice forwarding, come NAT, firewall, IDS, load balancing e caching.**

> **NFV permette di implementare funzioni di rete come software su hardware generico, mentre SDN rende programmabile il comportamento della rete separando control plane e data plane.**


##  #🧠 La clessidra IP 

possiamo rappresentare questa idea così: 

```
        HTTP
        SMTP
        QUIC
        RTP
          ...
       TCP UDP
          │
          ▼
         IP
          │
          ▼
 Ethernet WiFi Bluetooth
 PPP PDCP ...
          │
          ▼
   rame  radio  fibra
```

La forma ricorda una clessidra. 
**Perché IP è il collo stretto?**
Perché ci sono: 
- Molti protocolli applicativi.
- Diversi protocolli di trasporto.
- Tantissimi protocolli di collegamento. 
- Diversi mezzi fisici
Ma al centro c'è **IP**, in pratica, **IP nasconde la tecnologia sottostante**. 


##  #📌 Principi architetturali di internet

>**L'obiettivo è la connettività, lo stumento è il protocollo Internet, e l'intelligenza deve stare più nel paradigma end-to-end che nascosta dentro la rete.**

Le tre convinzioni fondamentali sono: 
1. Connettività semplice, la rete deve permettere la trasmissione di datagrammi tra host. 
2. IP come "vita stretta", IP deve fare collante tra tecnologie differenti, IP nasconde l'eterogeneità della rete sottostante. 
3. Intelligenza della periferia, la rete cerca di rimanere relativamente semplice, mentre funzioni più complesse vengono realizzate agli estremi. In pratica, **la rete cerca di fare le cose fondamentali, mentre la complessità viene spostata verso gli host quando possibile.**


#🧠 #remember

> **Le middlebox sono dispositivi intermedi che svolgono funzioni oltre il semplice forwarding IP; la loro evoluzione, insieme a SDN, match+action e NFV, ha reso la rete sempre più programmabile e complessa, mentre il principio architetturale originario di Internet privilegia una rete semplice e l'intelligenza agli estremi secondo il paradigma end-to-end.**
