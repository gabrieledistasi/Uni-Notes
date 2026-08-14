Una web cache è un dispositivo che conserva copie delle risorse web richieste dagli utenti, così da poterle fornire direttamente senza doverle richiedere ogni volta al server originale. 
L'utente configura il browser per utilizzare una web cache (locale e il browser trasmette tutte le richieste HTTP alla cache 
- Se l'oggetto è nella cache, l'oggetto viene fornito al client
- Altrimenti la cache richiede l'oggetto al server di origine, la cache memorizza l'oggetto e infine lo restituisce al client. 

Vediamo un esempio

		HTTP/1.1 200 OK
		Date: Sun, 15 Mar 2026 20:00:00 GMT
		Content-Type: text/html; charset=utf-8
		Cache-Control: max-age=3600, must-revalidate
		Content-Length: 191
		<!DOCTYPE html>
		<html lang="it"> 

Il campo Date indica l'istante in cui il messaggio è stato generato. 
max-age indica per quanti secondi la risposta può essere considerata buona, partendo dalla creazione, per essere usata come potenziale cache per soddisfare le richieste client. 
Il campo cache-control può essere usato anche nelle richieste: 
cache-control : max-age = 3600
	Questa direttiva viene usata dal client per indicare di volere una risposta generata entro il numero di secondi indicato. Non riceverò *stale response* a meno che non venga consentito da altre direttive
Cache-control : no-cache 
	Il client non vuole una copia memorizzata in una cache senza che questa sia stata validata presso il server di origine. 


### GET condizionale (per la validazione della cache)
L'obiettivo è quello di non inviare una copia dell'oggetto, se la cache ha una versione aggiornata di quell'oggetto. 
Il client specifica la data della copia dell'oggetto nella richiesta HTTP. 
Nel server la risposta non contiene l'oggetto se la copia nella cache è aggiornata. 

### Ma perché il web caching?
Il web caching è una tecnica che permette la risoluzione di diversi problemi e porta diverse ottimizzazioni: 
- Riduce i tempi di risposta alle richieste dei client 
- La cache è più vicina ai client 
- Banda disponibile tra client e cache maggiore che nel percorso verso il server di origine 
- Riduce il traffico sul collegamento di accesso a internet istituzionale
- Riduce il traffico globale su internet

### NOTE
Il caching può essere effettuato da una web cache, uno speciale tipo di proxy oppure dal browser stesso. 

[[E-Mail| Mail]]


