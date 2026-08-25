## BitTorrent
BitTorrent è un protocollo di tipo peer-to-peer utilizzato per la condivisione dei file su internet. 
L'idea di bitTorrent è quella di dividere i file in blocchi, generalmente da 256KB
I peer nel torrent inviano/ricevono i chunk del file per poter ricostruire il file richiesto. 
Un peer che entra a far parte del torrent non ha alcun chunk ma li accumula nel tempo. Il peer si registra con un tracker e ottiene una lista di un sottoinsieme di peer nel torrent, stabilisce una connessione con un sottoinsieme di peer appartenenti alla lista, detti "Neighbors" ovvero i peer vicini, intanto il peer che è entrato, informa periodicamente il tracker che lui è ancora nel torrent. 
Mentre un peer scarica un chunk, può inviare agli altri peer i chunk di cui lui è già in possesso, inoltre il peer può decidere di cambiare peer con cui scambiare chunk. I peer possono andare e venire e una volta che un peer ha acquisito un file può decidere di andare via dal torrent o rimanere per aiutare gli altri. 
## Richiesta e invio di chunk 

### Richiesta di chunk
In ogni momento, peer diversi hanno sottoinsiemi diversi di chunk, periodicamente un peer può chiedere ai suoi vicini la lista dei chunk in loro possesso. Il peer può richiedere agli altri i chunk mancanti adottando la strategia del **"rarest first"**: uniformando la distribuzione dei chunk, migliora la disponibilità globale e aumenta le possibilità di scambio. 
Un peer appena entrato può chiedere un chunk in maniera casuale in maniera da avere subito qualcosa da condividere, quando invece si trova vicino al completamento del file, adotta la strategia **end game** in cui richiede lo stesso blocco a più peer simultaneamente (più richieste faccio, più e probabile che qualcuno ce l'abbia). 

### Invio di chunk: tit-for-tat
Un peer invia chunk ai peer vicini che inviano chunk alla velocità più alta. I peer che non sono mai abbastanza veloci vengono "soffocati". Ogni 30 secondi: seleziona in modo casuale un vicino, inizia a inviare chunk, questo peer viene detto "optimistically unchoked" e il nuovo peer scelto può entrare nella top 4.
*Esempio*
- Il peer A sceglie B come "optimistically unchoked"
- A diventa uno dei primi quattro fornitori di B e B ricambia
- B diventa uno dei primi quattro fornitori di alice 
[[Streaming | streaming]]