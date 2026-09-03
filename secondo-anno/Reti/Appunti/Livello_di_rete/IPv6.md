Come detto in [[NAT|nat]] gli indirizzi IPv4 stanno diventando insufficienti. 
IPv4 utilizza indirizzi a 32 bit $2^{32} ~ 4,3 \ miliardi$ di indirizzi, possono sembrare tanti, ma non abbastanza da poter essere un problema remoto. 
Proprio per cercare di mitigare questo problema è nato NAT, facendo condividere a più dispositivi uno stesso indirizzo IPv4, riduciamo di molto gli indirizzi utilizzati. Però il NAT è una soluzione con diversi compromessi e non risolve alla radice il problema dello spazio di indirizzamento. 
Allora si è pensato di utilizzare, come soluzione, **IPv6**. 
IPv6 aumenta enormemente lo spazio degli indirizzi, abbiamo infatti $2^{128}$ indirizzi disponibili.

# Formato del datagramma IPv6
![[Pasted image 20260903153740.png]]

**La cosa interessante di IPv6 è che ha lunghezza fissa di 40 byte.** Questo è uno dei motivi per cui IPv6 è stato progettato anche per rendere più veloce l'elaborazione e l'inoltro dei pacchetti. 

## 1. Version
Indica la versione del protocollo e sono 4 bit, come per IPv4. 
## 2. Traffic Class
Serve per indicare come trattare il traffico. 
- i **6 bit più significativi** sono dedicati a **DiffServ**, utilizzato per classificare e differenziare il traffico;
- i **2 bit meno significativi** sono dedicati a **ECN**, cioè alla notifica esplicita della congestione.
**Traffic class permette di distinguere e trattare diversamente determinati tipi di traffico.**
## 3. Flow Label 
Serve a identificare i datagrammi appartenenti allo stesso flusso. 
L'idea è permettere alla rete di trattare questi pacchetti come appartenenti allo stesso flusso. 

## 4. Payload length
Indica la **lunghezza del carico utile** che segue l'intestazione IPv6. 

## 5. Next Header 
Questo campo indica che cosa viene dopo l'header IPv6; può indicare un protocollo di livello superiore. Questo è importante perché in IPv6 le opzioni non sono più inserite direttamente nell'header base come avveniva in IPv4: vengono gestite tramite intestazioni successive. 

## 6. Hop limit
E' l'equivalente del TTL in [[IP_Protocol| IPv4]]. 

## 7. Source address
E' l'indirizzo IPv6 del mittente 

## 8. Destination Address
E' l'indirizzo IPv6 del destinatario

## Cosa non troviamo rispetto a IPv4?
- **In IPv6 non troviamo il checksum dell'Header**, per velocizzare l'elaborazione presso i router. I livelli inferiori e superiori possono comunque effettuare i loro controlli. 
- Frammentazione router, in IPv6 i router NON frammentano i datagrammi. Se un pacchetto è troppo grande per il collegamento successivo, il router lo scarta e invia al mittente un messaggio ICMPv6: 
	`Packet too big`
- Options nell'header base, IPv4 poteva avere un campo options direttamente nell'header, mentre in IPv6 non troviamo questa cosa. 

# Notazione degli indirizzi IPv6
La notazione degli indirizzi IPv6 serve per rendere leggibili indirizzi che sono lunghi 128 bit. 
Un indirizzo IPv6 è normalmente rappresentato come 8 gruppi di 4 cifre esadecimali, separati da `:` . 
Ci sono due modi principali per accorciare la scrittura: 
1. Si possono eliminare gli zeri finali di ogni gruppo. 
2. Una sequenza consecutiva di 0 può essere sostituita da `::`
`::` può essere usato solo una volta per ogni indirizzo, altrimenti non sapremmo quanti gruppi di 0 rappresenta. 

# Transizione da IPv4 a IPv6
Non tutti i router possono essere aggiornati contemporaneamente, allora come fa la rete a funzionare in un misto di router IPv4 e IPv6?
**Come facciamo a far passare un datagramma IPv6 in un router che conosce solo IPv4?**
La risposta è utilizzando il **Tunneling.**
L'idea di fondo del tunneling è quella di mettere un datagramma IPv6 in un datagramma IPv4. 

        DATAGRAMMA IPv4
┌───────────────────────────────────┐
│ Header IPv4                                                                                    │
│                                                                                                             │
│   DATAGRAMMA IPv6                                                                  │
│  ┌─────────────────────────────┐          │
│  │ Header IPv6                                                                  │          │
│  │ Source IPv6                                                                   │          │
│  │ Destination IPv6                                                          │          │
│  │                                                                                           │           │
│  │ Payload TCP/UDP                                                        │          │
│  └─────────────────────────────┘           │
└───────────────────────────────────┘

Il router che possiede il datagramma IPv6 lo incapsula in un Ipv4 aggiungendo un header IPv4. L'header IPv4 contiene gli indirizzi IPv4 dei due estremi del tunnel (mittente, ricevente).
Mentre all'interno rimangono gli indirizzi IPv6 originali. 

[[Inoltro_generalizzato | Inoltro generalizzato]]


