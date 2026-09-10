
# Connessioni e protocolli di accesso multiplo

**Abbiamo due tipi di collegamenti:**
- Point-to-point: un trasmittente a un'estremità del collegamento e un unico ricevente all'altra estremità. 
	- Collegamento punto-a-punto tra host e switch Ethernet 
	- protocollo PPP per accesso dial-up
- Broadcast: Un canale broadcast condiviso tra più nodi trasmittenti e riceventi, ciascun frame viene ricevuto da tutti i nodi. 

## Protocolli di accesso multiplo
- Singolo canale broadcast condiviso
- Due o più trasmissioni simultanee dai nodi: interferenza 
	- Collisione se un nodo riceve due o più segnali nello stesso istante. 

**Protocollo di accesso multiplo:**
*Algoritmo distribuito che determina come i nodi condividono il canale, determina quando i nodi possono trasmettere. La comunicazione sulla condivisione del canale deve utilizzare il canale stesso.*

## Un protocollo di accesso multiplo ideale
*dato:* un canale ad accesso multiplo con velocità di R bps
*desiderata:*
1. Quando un solo nodo vuole trasmettere, può inviare a velocità R.
2. Quando M nodi vogliono trasmettere, ciascuno può inviare a una velocità media R/M
3. Totalmente decentralizzato: 
	- nessun nodo speciale che coordina le trasmissioni
	- nessuna sincronizzazione degli orologi, slot temporali, etc.
4. Semplice

I protocolli di accesso multiplo vengono divisi in 3 famiglie 
- **A suddivisione del canale**
- **Ad accesso casuale**
- **A rotazione**
Queste tre famiglie si distinguono per il metodo di gestione del canale condiviso. 

## #🔑  TDMA 
**TDMA = Time Division Multiple Access**

Dividiamo il tempo in slot e assegniamo ogni slot a un nodo. 
Ogni nodo può trasmettere **solo nel proprio slot**. 
Se un nodo non ha nulla da trasmettere, lo slot rimane inutilizzato. 
**Lo svantaggio** è che, anche se c'è solo un nodo attivo, deve aspettare il proprio turno e può utilizzare soltanto la sua frazione del tempo. 
Se ci sono `N` nodi
$$
velocità \ media = \frac{R}{N}
$$
anche se gli altri non stanno trasmettendo. 

## #🔑 FDMA

**FDMA = Frequency Division Multiple Access**
Invece di dividere il tempo, dividiamo la frequenza. 
Ogni nodo ha **una banda di frequenza fissa**. Il vantaggio rispetto al TDMA: 
*Il nodo può iniziare a trasmettere appena ha dati, senza aspettare il proprio slot temporale.*
Però se un nodo non trasmette, la sua banda rimane inutilizzata. 

## Protocolli ad accesso casuale 
In questi protocolli non vengono assegnate preventivamente porzioni di canale. 
Quando un nodo ha un frame: 

>**Trasmette immediatamente alla massima velocità R.**

Ma se due nodi trasmettono contemporaneamente avremo una **collisione**. 
Il protocollo quindi deve stabilire: 
1. come rilevare la collisione
2. come recuperare dalla collisione
Il recupero avviene generalmente attraverso **ritrasmissioni con ritardo casuale.**

### #📌 Slotted ALOHA
Qui il tempo è diviso in slot, ogni slot dura quanto serve per trasmettere un frame: 
$$
T_{slot}=\frac{L}{R}
$$
I nodi possono iniziare a trasmettere **solo all'inizio di uno slot.**
Se un nodo ha un frame: 

Nessuna collisione e può trasmettere un nuovo frame nello slot successivo. 

Collisione
Ritrasmette negli slot successivi con probabilità **p**

## Pro e contro di slotted ALOHA

### Pro
- un singolo nodo attivo può utilizzare completamente il canale 
- decentralizzato 
- semplice
### Contro 
- Collisioni
- slot sprecati 
- slot inutilizzati
- necessita della sincronizzazione degli slot
- efficienza limitata

## Slotted ALOHA: efficienza
#esercizi

Con `N` nodi e la probabilità di trasmissione `p`: 
$$
eff(p)=Np(1-p)^{N-1}
$$
Il valore che massimizza l'efficienza è: 
$$
p^* = \frac{1}{N}
$$
e quindi: 
$$
eff(p^*)=(1-\frac{1}{N})^{N-1}
$$
per N $\rightarrow \infty$
$$
eff_{max}=\frac{1}{e}≈ 0.37
$$
Quindi slotted aloha raggiunge al massimo il 37% di efficienza. 

# ALOHA puro
Lo slotted ALOHA obbliga i nodi a iniziare negli slot. 
L'ALOHA puro invece: 
- **non ha slot e non richiede sincronizzazione**
Quando arriva un frame, viene trasmesso immediatamente. 
Problema?
Il periodo durante il quale può verificarsi una collisione è maggiore. 
Un frame trasmesso a $t_{0}$ può collidere con frame iniziati in: 
$[t_{0} - T, t_{0} + T]$ quindi la probabilità di collisione **aumenta.**
Risultato: 
$$
eff_max = \frac{1}{2e} ≈ 18\%
$$

# #📌 CSMA 
**CSMA = Carrier Sense Multiple Access**

La filosofia è: 

> "Prima ascolta, poi trasmetti."

Se il canale è: 
libero $\rightarrow$ trasmetto
occupato $\rightarrow$ aspetto

## CSMA/CD
CD sta per collision detection. Non solo ascolto prima di trasmettere, ma rilevo anche se è avvenuta una collisione durante la trasmissione. 
Se rilevo una collisione: 
	**Interrompo immediatamente la trasmissione.**
Questo evita di sprecare tutto il tempo necessario per trasmettere il frame.

## CSMA: Collisioni
Ci si potrebbe chiedere come sia possibile collidere se siamo in ascolto prima di trasmettere su un canale?
La risposta è a causa **del ritardo di propagazione.** A inizia a trasmettere, ma il segnale di A non arriva istantaneamente a B. Nel frattempo B non sente niente, credendo che il canale sia libero inizia a trasmettere e si **verifica una collisione.**
**CSMA riduce le connessioni, ma non le elimina completamente.**

## Algoritmo CSMA/CD di Ethernet
1. Ethernet riceve un datagramma dal livello di rete, crea un frame
2. Se Ethernet ascolta il canale: 
	- Inutilizzato (idle): avvia la trasmissione del frame.
	- Occupato (busy): aspetta finché il canale è libero, poi trasmette. 
3. Se l'intero frame viene trasmesso senza collisioni, tutto ok
4. Se durante l'invio viene rilevata un'altra trasmissione: interrompere, inviare il segnale di disturbo(jam), tra l'altro assicura che ogni nodo scarti il frame per errore di CRC. 
5. Dopo aver interrotto, entra nella binary exponential backoff: 
	- dopo la m-esima collisione, scegli K casualmente tra $\{0,1,2,...,2^{m}-1\}$ Ethernet aspetta il tempo di trasmissione di K*512 bit, ritorna allo step 2. 
	- più collisioni: maggiore intervallodi backoff

### Vincolo fondamentale CSMA/CD

Definiamo: 
$\tau$ = ritardo di propagazione in una direzione;
$2\tau$ = ritardo andata e ritorno;
$L/R$ = tempo necessario per trasmettere un frame; 

Affinché A possa rilevare una collisione, deve essere ancora in trasmissione quando arriva il segnale di B. 
Quindi: 
$$
\frac{L}{R} \gt 2\tau
$$
**Il frame deve durare abbastanza a lungo da permettere al segnale di una collisione di tornare al mittente.**

## Slot mittente
Viene definito un ritardo massimo: 
$\tau_{max}$ 
Che comprende il ritardo di propagazione e altri contributi, più un margine di sicurezza. 
Lo **slot time** è pari a: 
$slot\ time=2\tau_{max}+durata_{max}(jam)$ 
In Ethernet è pari a: 
$$
512 \ bit = 64 \ byte
$$
## Efficienza CSMA/CD
La formula è: 
$$
efficienza = \frac{1}{1+5\frac{d_{prop}}{d_{trasm}}}
$$
dove: 
$d_{prop}$ = massimo ritardo di propagazione; 
$d_{trasm}$ = tempo di trasmissione del frame massimo; 
L'efficienza tende a 1 quando: 
- $d_{prop}\rightarrow0$
- $d_{trasm}\rightarrow\infty$
CSMA è molto più efficiente di ALOHA. 

# Protocolli a rotazione
Qui torniamo alle tre famiglie.

### Suddivisione del canale

Efficienti con **carico elevato**, ma inefficienti con basso carico.

Perché?

Se ho un solo nodo attivo, TDMA continua comunque ad assegnargli solo `1/N` del canale.

### Accesso casuale

Ottimo con **basso carico**:

> un nodo può usare tutto il canale.

Ma con carico elevato:

> aumentano le collisioni.

### A rotazione

Cercano di prendere **il meglio dei due mondi**.

I nodi si alternano nell'utilizzo del canale.

## Polling 
C'è un **controllore centrale**. 
Il controllore invita i nodi a trasmettere secondo un ordine, ad esempio round-robin. 
**Vantaggi**
- Niente collisioni
- Niente slot sprecati per collisioni 
**Problemi**
- Polling delay $\rightarrow$ bisogna aspettare il proprio turno; 
- Anche se c'è un solo nodo attivo, il controller deve continuare a interrogare gli altri; 
- Il controller è un singolo point of failure; 
Il **Bluetooth** utilizza il polling. 

## Token Passing
Qui non c'è necessariamente un controller centrale. 
Circola un frame speciale chiamato **token**. 
Solo chi possiede il token può trasmettere, dopo aver terminato la trasmissione passa il token al nodo successivo. 
**Problemi**
- Overhead del token;
- Latenza;
- Il token stesso può diventare un punto di rottura. 

## Rete di accesso via cavo
Una rete via cavo combina: 
- FDM $\rightarrow$ frequenze diverse; 
- TDM $\rightarrow$ slot temporali; 
- **accesso centralizzato**;
- **accesso casuale.**
Nel downstream: 
```
CMTS → utenti
```
Un solo CMTS trasmette, quindi non c'è problema di accesso multiplo. 

Nell'upstream: 
```
utenti → CMTS
```
molti utenti devono condividere il canale. Per questo alcuni slot vengono assegnati tramite **TDM**, mentre altri sono contesi utilizzando accesso casuale. 

### DOCSIS
E' lo standard per l'interfaccia dei servizi dati via cavo. 
pecifiche di interfaccia del servizio dati via cavo
- FDM su canali di frequenze upstream e downstream
- TDM upstream: alcuni slot assegnati, alcuni sono contesi
	- mFrame MAP in downstream: assegna i minislot in upstream
	- Richieste di frame in upstream (e dati) trasmessi con accesso casuale
	 (binary backoff) in slot selezionati


[[LAN|LAN]]