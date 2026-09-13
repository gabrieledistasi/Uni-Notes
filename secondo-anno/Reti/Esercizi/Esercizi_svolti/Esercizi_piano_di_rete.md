Questi esercizi fanno riferimento alle slide: 
SOR2025-2026_Reti_22_Esercizi_Livello_di_rete_piano_dei_dati.pdf

---
Per questo tipo di esercizi l'algoritmo, a grandi linee, è questo: 
```
1. Guardo il primo ottetto
        ↓
2. Determino la classe
        ↓
3. Trovo /8, /16 o /24
        ↓
4. Divido RETE | HOST
        ↓
5. Host = n bit → 2^n - 2 host
        ↓
6. Broadcast = tutti i bit HOST a 1
```

# Esercizio 1

Si consideri il seguente indirizzo IP in notazione decimale puntata:
142.251.209.3
1. Qual è la sua rappresentazione in formato binario?
2. Considerando il sistema di indirizzamento a classi (ora non più in uso), dire:
2.a qual è la maschera di sottorete (in notazione decimale puntata)
2.b qual è il prefisso di rete in formato CIDR
2.c quali sono la parte di sottorete e la parte di host nell'indirizzo
2.d quante interfacce potrebbe supportare la sottorete
2.e indirizzo di broadcast diretto della sottorete

### 1. Rappresentazione binaria
Il nostro indirizzo IP è: 
`142.251.209.3` 

ricordiamo i pesi:
`128 64 32 16 8 4 2 1`

Partiamo da **142**:
`142 = 128 + 8 + 4 +2  che diventa, in binario: 10001110`

Stessa cosa con 251: 
`251 = 128 + 64 + 32 + 16 + 8 + 2 + 1 = 11111011`

Vediamo 209: 
`209 = 128 + 64 + 16 + 1 = 11010001` 

Infine 3: 
`3 = 00000011`

Tutto insieme diventa: 
`10001110.11111011.11010001.00000011`

### 2. Indirizzamento a classi
Ora bisogna guardare il primo ottetto: 
`142`

Le classi sono: 
|Classe|                Primo ottetto                            |Prefisso|
|---         |--                                                                    |                |
|A          |                     1–126                                      |     /8      |
|B          |                    128–191                                  |   /16      |
|C          |                    192–223                                  |   /24      |

dato che 142 è tra 128 e 191, l'indirizzo appartiene alla **classe B**. 

Quindi nel sistema classful: 
`rete = primi 16 bit`
`host = ultimi 16 bit`

### 2.a Maschera di sottorete
Una classe B ha: 
`/16`

quindi i primi 16 bit sono a 1 e gli ultimi 16 sono a 0: 
`11111111.11111111.00000000.00000000`

Convertendo tutto in decimale otteniamo: 
`255.255.0.0`

Questa è la maschera di sottorete.

### 2.b Prefisso di rete in CIDR

Abbiamo detto che **una classe B utilizza 16 bit per la rete.**
Per cui: 
`142.251.0.0/16`

Attenzione: `/16` indica la lunghezza del prefisso, mentre 142.251.0.0 è l'indirizzo di rete. 

### 2.c Parte di rete e parte di host
Abbiamo: 
`10001110.11111011.11010001.00000011`

La maschera è `/16`, quindi dividiamo dopo i primi 16 bit:
`10001110.11111011 | 11010001.00000011`
 `      RETE        |      HOST`

In decimale: 
`142.251 | 209.3`
`RETE   | HOST`

L'indirizzo di rete completo è: 
`142.251.0.0`

### 2.d Quante interfacce può supportare la rete?
Abbiamo **16 bit dedicati agli host.** Quindi gli indirizzi disponibili per gli host sono: 
$$
2^{16} = 65534
$$
Dunque la sottorete può supportare fino a 65534 interfacce. 

### 2.e Indirizzo di broadcast diretto
Abbiamo la rete: 
`142.251.0.0/16`

La parte host è costituita dagli ultimi 16 bit. 
Per ottenere il broadcast mettiamo **tutti i bit della parte host a 1:**
`11111111.11111111` 

Che corrisponde a: 
`255.255`

Quindi:
`255.255.142.251`

**Risposta:** `142.251.255.255`

---

# Esercizio 2

Si consideri la seguente tabella di inoltro: 

```
Prefisso             |          Porta
142.251.200.0/24     |           0
142.251.192.0/18     |           1
142.251.0.0/16       |           2
0.0.0.0/0            |           3 
```


**Verso quale porta viene inoltrato un pacchetto destinato all'indirizzo IP**
**142.251.209.3?**


### Soluzione
In questo esercizio dobbiamo applicare il principio del **longest prefix match:** se un IP corrisponde a più prefissi, scegliamo quello con il prefisso più lungo. 
IP destinazione: 
`142.251.209.3`

Controlliamo le righe della tabella: 

#### 0/24

`142.251.200.0/24` non può essere, perché comprende gli indirizzi: 
142.251.200.0 $\rightarrow$ 142.251.200.255 ( perché con 8 bit $2^8 = 256$).

Il nostro IP è: 
142.251.209.3

#### 0/18

Mentre `142.251.192.0/18` comprende
`142.251.192.0` $\rightarrow$ `142.251.255.255`

e infatti 142.251.209.3 è dentro questo range. 

#### 0/16

Qui abbiamo 
`142.251.192.0/16`, i primi 16 bit sono rete, rendendo la maschera: 
`255.255.0.0`
Il che vuol dire che la rete è: 
`142.251.255.255` il nostro indirizzo rientra in questo range, quindi ok.

#### 0/0
Qui significa che 0 bit sono dedicati alla rete, rendendo la maschera: 
`00000000.00000000.00000000.00000000`
cioè: `0.0.0.0` e non abbiamo nessun bit da confrontare. 
Quando vediamo questa cosa possiamo pensare: `qualsiasi indirizzo IPv4`
e quindi l'intervallo diventa: 
```
0.0.0.0
   ↓
255.255.255.255
```

A questo punto, come detto ad inizio esercizio, possiamo prendere l'indirizzo IP con il prefisso più lungo, in questo caso 0/18. La domanda era a quale porta verrà indirizzato un pacchetto destinato a quell'IP, basta semplicemente andare a vedere la tabella e possiamo concludere che la porta **è la porta 1.**

--- 
# Esercizio 3
Definire un piano di partizionamento per la seguente rete (131.175.0.0/21), gli
indirizzi dei router, gli indirizzi di broadcast, e le tabelle di inoltro. Il numero di host non include i
router.
![[Pasted image 20260913214529.png]]

### Capire quanto è grande ogni sottorete

Prima di calcolare la dimensione delle subnet, dobbiamo osservare bene la figura.

**750 host e 250 host appartengono alla stessa LAN**, quindi fanno parte della **stessa sottorete A**.

Inoltre, il numero di host indicato nella traccia **non include i router**, quindi dobbiamo aggiungere l'interfaccia del router quando calcoliamo quante interfacce deve supportare ogni subnet.

Otteniamo quindi:

```
Subnet A → 750 + 250 + 1 router = 1001 interfacce
Subnet B → 255 + 1 router = 256 interfacce
Subnet C → 50 + 1 router = 51 interfacce
Subnet D → 200 + 1 router = 201 interfacce
Subnet E → 2 interfacce (R1 e R2)
```

Il professore ordina poi le subnet dalla più grande alla più piccola.

### Subnet A: 750 + 250 host

Abbiamo bisogno di supportare **1001 interfacce**.

La formula è:

$$2^h−2≥1001$$

Proviamo:

$$2^9−2=510-2=510$$

Non è sufficiente.

Proviamo:

$$2^10−2=1024-2=1022$$

Quindi ci servono **10 bit per gli host**.

Di conseguenza:

$$32−10=22$$

Quindi:

```
Subnet A → /22
```

Una `/22` contiene:

```
1024 indirizzi totali
1022 indirizzi utilizzabili
```

---

### Subnet B: 255 host

Dobbiamo aggiungere il router:

$255+1=256$

Quindi:

$$2^h−2≥256$$

Con 8 bit:

$$2^8−2=254$$

Non basta.

Con 9 bit:

$$2^9−2=510$$

È sufficiente.

Quindi:

$$32−9=23$$

```
Subnet B → /23
```

---

### Subnet D: 200 host

Aggiungiamo il router:

$$200+1=201$$

Quindi:

$$2^h−2≥201$$

Con 8 bit:

$$2^8−2=254$$

È sufficiente.

Quindi:

$$32−8=24$$

```
Subnet D → /24
```

---

### Subnet C: 50 host

Aggiungiamo il router:

50+1=51

Quindi:

$$2h−2≥51$$

Con 6 bit:

$$2^6−2=62$$
È sufficiente.

Quindi:

$$32−6=26$$

```
Subnet C → /26
```

---

### Subnet E: collegamento R1-R2

Qui non abbiamo una normale LAN: abbiamo solamente il collegamento tra **R1 e R2**.

Ci servono quindi **2 interfacce**.

Cerchiamo il minimo numero di bit host:

$$2h−2≥2$$

Con 2 bit:

$$2^2−2=2$$

Perfetto.

Quindi:

$$32−2=30$$

```
Subnet E → /30
```

Una `/30` contiene:

```
4 indirizzi totali
2 indirizzi utilizzabili
```

---

# Come assegniamo concretamente gli indirizzi?

Nel VLSM conviene partire dalla **sottorete più grande** e procedere verso quelle più piccole.

Abbiamo quindi:

```
Subnet A → /22
Subnet B → /23
Subnet D → /24
Subnet C → /26
Subnet E → /30
```

La rete di partenza è:

```
131.175.0.0/21
```

---

## 1. Subnet A → `/22`

Partiamo dall'inizio della rete:

```
131.175.0.0/22
```

La maschera è:

```
255.255.252.0
```

Il blocco è:

```
256 - 252 = 4
```

Quindi una `/22` occupa 4 valori del terzo ottetto.

La nostra subnet A occupa:

```
131.175.0.0
fino a
131.175.3.255
```

Quindi:

```
NETWORK:
131.175.0.0

BROADCAST:
131.175.3.255
```

Il primo indirizzo utilizzabile per il router sarà:

```
R1 = 131.175.0.1
```

Il **prossimo spazio disponibile** è:

```
131.175.4.0
```

---

## 2. Subnet B → `/23`

Partiamo dal primo spazio libero:

```
131.175.4.0/23
```

La maschera è:

```
255.255.254.0
```

Il blocco è:

```
256 - 254 = 2
```

Quindi occupa due valori del terzo ottetto:

```
131.175.4.0
fino a
131.175.5.255
```

Quindi:

```
NETWORK:
131.175.4.0

BROADCAST:
131.175.5.255
```

Il router R2 può avere:

```
R2 = 131.175.4.1
```

Il prossimo spazio disponibile è:

```
131.175.6.0
```

---

## 3. Subnet D → `/24`

Partiamo da:

```
131.175.6.0/24
```

La maschera è:

```
255.255.255.0
```

Il blocco è:

```
256 - 255 = 1
```

Quindi occupa un solo valore del terzo ottetto:

```
131.175.6.0
fino a
131.175.6.255
```

Quindi:

```
NETWORK:
131.175.6.0

BROADCAST:
131.175.6.255
```

L'interfaccia di R1 sarà:

```
R1 = 131.175.6.1
```

Il prossimo spazio disponibile è:

```
131.175.7.0
```

---

## 4. Subnet C → `/26`

Ora abbiamo:

```
131.175.7.0
```

e ci serve una `/26`.

La maschera è:

```
255.255.255.192
```

Guardiamo l'ultimo ottetto:

```
256 - 192 = 64
```

Quindi i blocchi `/26` avanzano di **64**:

```
131.175.7.0/26
131.175.7.64/26
131.175.7.128/26
131.175.7.192/26
```

Usiamo il primo:

```
131.175.7.0/26
```

che occupa:

```
131.175.7.0
fino a
131.175.7.63
```

Quindi:

```
NETWORK:
131.175.7.0

BROADCAST:
131.175.7.63
```

Il router R2 avrà:

```
R2 = 131.175.7.1
```

Il prossimo spazio disponibile è:

```
131.175.7.64
```

---

## 5. Subnet E → `/30`

Finalmente utilizziamo il primo spazio disponibile:

```
131.175.7.64/30
```

La maschera è:

```
255.255.255.252
```

Il blocco è:

```
256 - 252 = 4
```

Quindi abbiamo:

```
131.175.7.64  → NETWORK
131.175.7.65  → R1
131.175.7.66  → R2
131.175.7.67  → BROADCAST
```

Quindi:

```
R1 = 131.175.7.65
R2 = 131.175.7.66
```