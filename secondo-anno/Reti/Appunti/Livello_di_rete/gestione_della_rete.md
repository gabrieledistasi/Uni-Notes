# #🌐 Gestione della rete
**Sistema autonomo**: migliaia di componenti software e hardware che interagiscono tra loro. 

#🔑 
*La gestione della rete comprende il funzionamento, l'integrazione e il coordinamento di hardware, software e personale tecnico per monitorare, verificare, analizzare valutare e controllare le risorse della rete affinché soddisfino le funzionalità in tempo reale e i requisiti di qualità del servizio a un costo accettabile.*

## Componenti della gestione della rete
### Server di gestione
raccolta, elaborazione e analisi delle informazioni, invio di informazioni e comandi, in genere con i gestori della rete nel loop. Possiamo immaginarlo come il punto principale da cui l'amministratore controlla la rete. 

### Protocollo di gestione di rete
Protocollo a livello di applicazione utilizzato dal server di gestione per interrogare lo stato dei dispositivi e agire su di essi attraverso un agente di gestione. Utilizzato dagli agenti per informare il server di gestione dati ed eventi. 

### Dispositivo di rete gestito
Apparecchiature con componenti hardware e software gestibili e configurabili. 

### Dati
"stati" del dispositivo: dati di configurazione, dati operativi, statistiche. 

### Agente di gestione
comunica con il server di gestione, agisce su un dispositivo gestito

## Approcci dell'operatore di rete per gestire la rete
### CLI 
L'operatore scrive comandi su una console del dispositivo o esegue script da remoto. 
Molti dispositivi hanno anche una UI web. 

### SNMP/MIB 
L'operatore interroga/imposta i dati contenuti negli oggetti MIB utilizzando il **Simple Networking Management Protocol**. Usato principalmente per accedere a dati operativi e statistici.

### NETCONF/YANG
- Più astratto, a livello di rete
- Enfasi sulla gestione della configurazione multidispositivo
- YANG: linguaggio di modellazione dei dati
- NETCONF: comunicare azioni/dati compatibili con YANG a/da/tra dispositivi remoti

[[SNMP | SNMP]]


