# #📌 Panoramica di NETCONF
NETCONF è un protocollo utilizzato per gestire e configurare attivamente i dispositivi della rete. Opera tra il server di gestione/controller e gli agenti dei dispositivi gestiti. 
Cosa permette di fare?
NETCONF permette al server di: 
- retrieve, recuperare configurazioni e dati. 
- set/modify, impostare e modificare configurazioni
- activate configurations, attivare configurazioni
- eseguire modifiche in modo atomico su più dispositivi
- interrogare dati operativi e statistiche
- sottoscrivere notifiche provenienti dai dispositivi. 

## NETCONF usa RPC
Il paradigma utilizzato è quello della **Remote Procedure Call**: 
> Il server chiede al dispositivo di eseguire una determinata operazione, come se stesse chiamando una funzione su una macchina remota. 

I messaggi NETCONF sono codificati in XML e vengono trasportati attraverso un protocollo di trasporto affidabile e sicuro, ad esempio SSH o TLS. 

## Operazioni NETCONF selezionate
![[Pasted image 20260908171231.png]]

--- 
# YANG
YANG è un linguaggio di modellazione dei dati utilizzato per specificare la struttura, la sintassi e la semantica dei dati di gestione della rete NETCONF. 
Documento XML che descrive il dispositivo, può essere generato dalla descrizione YANG. 
Può esprimere vincoli tra i dati che devono essere soddisfatti da una configurazione NETCONF valida. 

## Esempio
### 🧠 Esempio terra terra

Immagina di voler configurare un'interfaccia di un router.

YANG definisce **quali informazioni esistono** e **come sono organizzate**, ad esempio:

```
interface
 ├── name
 ├── description
 ├── ip-address
 └── status
```

NETCONF invece permette al controller di dire:

> "Modifica la configurazione dell'interfaccia `eth0`."

Quindi **YANG non è il protocollo di comunicazione**: quello è NETCONF.