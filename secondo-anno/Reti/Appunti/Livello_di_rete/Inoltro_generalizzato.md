# Inoltro generalizzato
L'inoltro generalizzato: match plus action è il collegamento tra il normale forwarding IP e SDN/OpenFlow. 

Prima avevamo questo:
	**Inoltro basato sulla destinazione**
Il router guarda principalmente **l'indirizzo IP di destinazione** e decide la porta di uscita. 
Nell'inoltro generalizzato, invece, possiamo guardare più campi dell'intestazione e decidere diverse azioni. La logica è proprio **MATCH + ACTION.**

# Tabella dei flussi
- **flusso:** definito dai valori dei campi di intestazione
- **inoltro generalizzato:** semplici regole per la gestione dei pacchetti 
	- **match:** pattern sui valori dei campi di intestazione
	- **actions:** per il pacchetto in cui viene trovata una corrispondenza: scartare (drop), inoltrare (forward),  modificare l'intestazione(modify), o inviare al controllore
	- **priorità:** disambigua pattern sovrapposti
	- **contatori:** numero di byte e numero di pacchetti, marca temporale ultimo aggiornamento

## Astrazione in OpenFlow
Router, switch, firewall e NAT sono dispositivi diversi, ma possiamo descrivere il loro comportamento attraverso la stessa astrazione: match + action. 

### Router
Nel caso di un router: 

`MATCH:
`prefisso IP di destinazione

`ACTION:
`forward attraverso un collegamento`
Quindi il normale inoltro è basato sulla destinazione. 

### Switch
Per uno switch ethernet: `
`MATCH:
`prefisso IP di destinazione

`ACTION:
`forward attraverso un collegamento`

### Firewall
`MATCH:
`indirizzi IP e numeri di porta TCP/UDP
`ACTION:
`consentire (permit), negare (deny)

### NAT
`MATCH:`
`Indirizzo IP e porta`
`ACTION:`
`riscrive (rewrite) l'indirizzo e la porta`

## Riassunto 
L'astrazione **Match plus action** trova corrispondenze (match) nei bit nell'intestazione dei pacchetti in arrivo, agisce (action)
- trova corrispondenze su molti campi
- azioni locali: scarta,  inoltra, modifica, o invia il pacchetto al controllore
- "programmare" comportamenti di rete
Una forma semplice di "programmabilità della rete"
- "elaborazione" programmabile per pacchetto 

[[Middlebox|Middlebox]]
