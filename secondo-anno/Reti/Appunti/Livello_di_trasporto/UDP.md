# UDP: User Data Protocol

**Perché esiste UDP?**
Abbiamo visto come [[TCP | TCP]] offre molte funzionalità: 
- Affidabilità 
- Consegna nell'ordine 
- Controllo di flusso 
- Controllo della congestione
- Instaurazione della connessione
UDP fa molto di meno rispetto a TCP, ed è proprio per questo che esiste, in quanto è **più semplice perché non cerca di risolvere tutti questi problemi.**

# 1. Servizio "Best Effort"
UDP offre una consegna "Best Effort", cioè: 
	Fa del suo meglio per consegnare i segmenti, ma non garantisce che arrivino correttamente. 
Un segmento UDP può essere perso, venire duplicato o arrivare fuori sequenza rispetto agli altri. 

# 2. UDP è senza connessione 
Con TCP, prima di iniziare il trasferimento dei dati, i due processi devono effettuare un setup della connessione, con UDP, ciò non avviene.  
Con UDP ogni segmento viene gestito indipendentemente e non c'è handshaking tra mittente e destinatario. Questo è importante perché il setup della connessione potrebbe aggiungere un ritardo prima di poter iniziare la comunicazione. 

# 3. UDP non mantiene lo stato della connessione 
TCP deve ricordare molte informazioni sulle connessioni attive, UDP invece, non deve mantenere una connessione stabilita con ciascun client. Per questo UDP è più semplice e può gestire numerosi client senza dover mantenere lo stato di una connessione UDP per ognuno. 

# 4. Intestazione corta
I segmenti UDP hanno un'intestazione semplice. 

# 5. Maggiore controllo dell'applicazione 
A differenza di TCP, che prende decisioni automaticamente, UDP lascia maggiore controllo all'applicazione su: 
- **Quali dati inviare**
- **Quando inviarli**
Ad esempio, immaginiamo una videochiamata: 
riceviamo i vari frame:

Frame 1 → Frame 2 → Frame 3 → Frame 4

Se si perde il frame 2 TCP cercherebbe di recuperarlo e intanto arriverebbero gli altri frame. In un'applicazione in tempo reale, potrebbe essere più utile andare avanti che aspettare un pezzo di informazione già passato.

### Dove viene utilizzato UDP?
- Applicazioni multimediali
- [[DNS | DNS]]
- SNMP
- [[HTTP | HTTP/3]]

Un'applicazione che si basa su UDP non è implicitamente inaffidabile, l'affidabilità e il controllo della congestione possono essere implementate a livello di applicazione. 

# UDP: azioni a livello di trasporto 

**Lato mittente:** 
- Viene passato un messaggio applicativo 
- Determina i valori dei campi di intestazione del segmento UDP
- Crea il segmento
- Passa il segmento a IP

**Lato ricevente:**
- Riceve il segmento da IP 
- Controllo del valore del campo di intestazione UDP checksum
- Estrae il messaggio applicativo
- Consegna il messaggio alla socket appropriata

# Struttura dei segmenti UDP

![[Pasted image 20260825175954.png]]


# CheckSum UDP 
*Obiettivo:* rilevare gli errori nel segmento trasmesso. 

				1 numero      2 numero   somma
	messaggio:      5            6         11
	 trasmesso:      5     +      6   + -11 = 0
	 ricevuto:       4     +      6   +-11 = -1
In questo caso viene rilevato un errore dal ricevente. 

# Checksum Internet 
Il checksum internet è la parte di UDP che serve a fare un controllo sugli errori nei dati trasmessi. 
**NON corregge errori, ma li rileva e basta.**
Questo checksum segue questa idea: Il mittente calcola un valore, chiamato checksum, e lo inserisce nell'intestazione UDP. Il destinatario ricalcola il controllo sui dati ricevuti e verifica se il risultato è quello atteso. Se non lo è: 
	**Qualcosa durante la trasmissione potrebbe essere andato storto.**
Il checksum internet lavora su parole da 16 bit, supponiamo di avere tre parole: 
0110011001100110
0001000100010001
0010001000100010

1. Le sommiamo con la somma in complemento a 1, se durante la somma si genera un riporto oltre i 16 bit, quel riporto viene riaggiunto all'inizio
   1111111111111111
   +0000000000000001
-------------------
    1 0000000000000000
    ↑
    riporto

**Diventa:**

	0000000000000000
               +
	0000000000000001
---------------
	0000000000000001


2. Facciamo il complemento a 1 del risultato, ovvero, invertiamo tutti i bit e il risultato è il checkusm. 

## Cosa fa il destinatario?
Esegue nuovamente la somma in complemento a 1 includendo anche il checksum ricevuto. Se il risultato è formato da tutti 1, non è stato rilevato alcun errore; un risultato differente indica un errore. Anche se l'esito di un checksum risulta positivo, non è detto che siano stati rilevati tutti gli errori. 
[[Trasferimento_Dati_Affidabile|Trasferimento dati affidabile]]
