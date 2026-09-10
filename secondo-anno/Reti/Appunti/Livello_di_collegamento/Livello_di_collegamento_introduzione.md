Il livello di collegamento è il livello 2 dello stack TCP/IP/Internet. 
Gli obiettivi del livello di collegamento sono: 
1. **Rilevazione e correzione di errori**
Durante la trasmissione alcuni bit possono essere alterati, il livello di collegamento deve poter rilevare l'errore e, in alcuni casi, correggerlo. 
2. **Accesso multiplo**
Se più dispositivi condividono lo stesso mezzo trasmissivo, bisogna stabilire: 
**Chi può trasmettere e quando?**
Questo è il **MAC: medium access control**. 
3. **Indirizzamento a livello di collegamento**
Qui entrano in gioco gli indirizzi MAC. Da non confondere con gli indirizzi IP. 

#🔑 
IP $\rightarrow$ livello di rete 
MAC $\rightarrow$ livello di collegamento

4. **LAN**
Studieremo le reti locali e le tecnologie principali:
Web Cache- Ethernet 
- VLAN
- reti dati data center
- switch

# #📌 Livello di collegamento: servizi

*Framing:* Incapsula i datagrammi in frame, aggiungendo un'intestazione e un trailer. 

*Accesso al collegamento*: Un protocollo che controlla l'accesso al mezzo trasmissivo se il mezzo trasmissivo è condiviso. Indirizzi MAC nell'intestazione dei frame per identificare la sorgente e la destinazione. 

*Half-duplex e full-duplex*: Con half-duplex, i nodi ad entrambi gli estremi del collegamento possono trasmettere ma non contemporaneamente, cosa possibile con full-duplex. 

*Consegna affidabile tra nodi adiacenti:* usato raramente con canali a basso tasso di errore. Collegamenti wireless: tassi di errore elevati. 

*Controllo di flusso:* velocità tra nodi trasmittente e ricevente adiacenti. 

*Rilevazione degli errori:* gli errori sui bit sono causati dall'attenuazione del segnale e dal rumore. 

## Implementazione del livello di collegamento negli host
In ogni singolo host, il livello di collegamento è implementato dall'adattatore di rete o scheda di rete, questi dispositivi si collegano al bus di sistema e sono una combinazione di hardware, software e firmware. 
### Adattatore negli host
Lato mittente, il controllore: 
- Incapsula il datagramma in un frame 
- Aggiunge bit di controllo per gli errori,  implementa il controllo del flusso e il trasferimento dati affidabile. 
Lato ricevente, il controllore: 
- verifica la presenza di errori e si occupa del trasferimento dati affidabile, del controllo di flusso ecc. 
- Estrae il datagramma e lo passa al livello superiore. 

## Rilevazione degli errori
**EDC:** error detection and correction
**D:** dati protetti dal controllo d'errore, può includere i campi intestazione. 

### Controllo di parità 
- Rileva un numero dispari di errori
- Il ricevente: 
	- Calcola la parità dei d bit ricevuti
	- Lo confronta con il bit di parità ricevuto, se differente allora è stato rilevato un errore.

**Parità bidimensionale**
- Rileva tutte le combinazioni di al più 3 errori 
- Rileva un numero dispari di errori 
- Rilevazione e correzione di errori singoli

# Checksum Internet 
*Obiettivo: rilevare gli errori nel segmento trasmesso*

#### Mittente 
- Tratta il contenuto del segmento come una sequenza di interi a 16 bit. 
- Checksum: complemento a 1 della somma. 
- Pone il valore del checksum nel campo checksum del segmento UDP 

#### Ricevente 
- Calcola la somma in complemento a 1 allo stesso modo del mittente, includendo però il checksum ricevuto. 
- Il risultato è costituito da tutti bit 1? Se sì, non è stato rilevato nessun errore, altrimenti è stato rilevato un errore. 
Oppure, si esegue il complemento a 1 finale: si è calcolato il checksum di tutti i dati ricevuti e si verifica che sia formata da soli 0. 

## CRC (Cyclic Redundancy Check)
Il **CRC è una tecnica per la rilevazione degli errori durante la trasmissione**. 
L'idea è: 
	Il mittente aggiunge ai dati alcuni bit di controllo, in modo che la sequenza risultante abbia una proprietà precisa. Il ricevente controlla se questa proprietà è ancora rispettata. 

### Come funziona?
- D = dati da trasmettere, lunghi d bit
- G = generatore, una sequenza di r+1 bit
- R = gli `r` bit di CRC che dobbiamo calcolare 

Il mittente deve trovare R in modo che: 
$(D, R)$
Sia **divisibile esattamente per G**, utilizzando l'aritmetica modulo 2.

[[Protocolli_di_accesso_multiplo | protocolli di accesso multiplo]]

