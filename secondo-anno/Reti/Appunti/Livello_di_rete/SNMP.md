
# SNMP: Management Information Base
MIB descrive quali informazioni del dispositivo di rete possono essere gestite tramite SNMP. 
Il dispositivo gestito possiede dei managed objects, cioè delle informazioni/variabili che rappresentano: 
- dati **operativi**
- dati **statistici**
- alcuni dati di configurazione
Questi oggetti sono organizzati in **moduli MIB**, esistono circa 400 moduli MIB definiti tramite RFC, oltre a molti moduli specifici dei singoli produttori. 

## OID
Ogni managed object ha un OID (Object Identifier) univoco. 
L'OID è: 
- gerarchico
- identifica in maniera univoca l'oggetto
L'OID è sostanzialmente **l'identificatore dell'informazione che voglio leggere/gestire.**

### Due tipi di managed object
1. Oggetti scalari
	Hanno una sola istanza, si identificano aggiungendo `.0` all'OID
2. Oggetti tabulari
	Possono avere molteplici valori, organizzati come una tabella. 
	Ogni valore viene identificato aggiungendo all'OID l'indice della riga, a partire da 1. 

### E la SMI?
La structure of management information è **il linguaggio di definizione dei dati** utilizzato per descrivere la struttura degli oggetti della MIB. 

## Protocollo SNMP
Due modi per trasmettere le informazioni MIB e comandi: 

### 1. modalità richiesta/risposta
Il server di gestione fa una richiesta all'agent del dispositivo gestito. L'agent recupera le informazioni richieste dalla MIB e restituisce una risposta. Questa modalità viene utilizzata **quando è il server a voler ottenere o modificare informazioni**.

### 2. Trap mode
Qui cambia il verso della comunicazione: in questo caso **non è il server a fare richiesta**. E' il dispositivo gestito che, tramite il proprio agent, invia autonomamente un **messaggio trap** al server per segnalare un evento. Il server viene quindi informato senza avere precedentemente chiesto quell'informazione. 

## Tipi di messaggio
![[Pasted image 20260908165042.png]]

## Formati dei messaggi

### #📦 Messaggi di tipo 0-3: get/set
La struttura è: 
`PDU type | Request ID | Error Status | Error Index | Name | Value | Name | Value | ...`
1. **PDU TYPE**
	Indica **il tipo di messaggio**, con valori 0-3.
	Quindi identifica se si tratta, ad esempio, di una chiamata get/set.
2. **Request ID**
	E' un identificatore della richiesta. Serve ad associare richiesta ↔ risposta. Questo è particolarmente utile perché i messaggi SNMP viaggiano tramite [[UDP|UDP]], quindi il request ID permette al manager di capire a quale richiesta si riferisce una determinata risposta. 
3. **Error Status**
	Indica se nella gestione della richiesta si è verificato un errore. 
4. **Error Index**
	Indica **a quale variabile si riferisce l'errore,** per alcuni specifici valori di error status, come noSuchName. 
5. **Name/Value**
	Sono le variabili coinvolte nell'operazione: 
	```
	Name    → OID della variabile
	Value   → valore della variabile
	```

### Messaggi di tipo 4: Trap
Il trap ha un formato diverso: 
```
PDU type | Enterprise | Agent Addr | Trap Type |
Specific Code | Time Stamp | Name | Value | ...
```

- **Enterprise** è un OID che descrive il tipo di agente che ha inviato la Trap. 
- **Agent Addr** è l'indirizzo dell'agente che ha inviato la trap. 
- **Trap Type** indica il tipo di evento trap. 
- **Specific Code:** Qualifica ulteriormente il tipo di enterprise-specific trap. 
- **Time Stamp** Indica il **timestamp** associato all'evento. 

[[NETCONF|NETCONF]]
