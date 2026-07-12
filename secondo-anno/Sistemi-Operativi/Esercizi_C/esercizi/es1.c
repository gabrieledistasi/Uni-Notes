/*Il figlio P1 esegue un ciclo indeterminato durante il quale genera casualmente numeri interi compresi tra 0 a 100. 
P1 comunica, ad ogni interazione, il numero al padre solo se esso è pari.*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>

void p(const char *msg) {printf("[%d -> %d] %s", getpid(), getpid(), msg);}


int main(){

    int fd[2]; 
    pipe(fd); 

    __pid_t p1 = fork(); 


    if(p1==0){
        close(fd[0]); //chiude la lettura perché p1 deve solo scrivere 
        p("ciao sono il processo P1 \n"); 

        srand(time(NULL));//genera numeri casuali  
        for(int i = 0; i < 10; i++){ //esegue l'iterazione 10 volte 
            int random = rand() %10; 

            if((random%2==0)){ //filtro pari 
                printf("Random Number : %d\n", random); 
                write(fd[1], &random, sizeof(random)); 
            }
        }
        close(fd[1]); 

    }
    else{

        close(fd[1]); 
        int rec; 
        while(read(fd[0], &rec, sizeof(int))){ //
            p("Received\n"); 
            printf("%d\n", rec); 

        }
        close(fd[0]);

        wait(NULL); 
    }

    return 0; 
}

/*
Questo è un bellissimo esempio di **IPC (Inter Process Communication)** tramite **pipe** tra padre e figlio.

Ti spiego esattamente cosa succede.

---

# 1. Creazione della pipe

```c
int fd[2];
pipe(fd);
```

La `pipe()` crea un canale di comunicazione.

Restituisce due file descriptor:

```text
fd[0] --> lettura
fd[1] --> scrittura
```

Possiamo immaginarla come un tubo:

```text
       write()
          |
          V
+------------------+
|      PIPE        |
+------------------+
          |
          V
       read()
```

---

# 2. Fork

```c
pid_t p1 = fork();
```

Ora abbiamo:

```text
       Padre
          |
       fork()
          |
      Figlio
```

Entrambi ereditano la pipe:

```text
Padre:
 fd[0]
 fd[1]

Figlio:
 fd[0]
 fd[1]
```

---

# 3. Codice del figlio

Entra qui:

```c
if (p1 == 0)
```

---

## Chiusura del lato lettura

```c
close(fd[0]);
```

Il figlio scrive soltanto.

Non gli serve leggere.

```text
Figlio

fd[0] X chiuso
fd[1] aperto
```

---

## Messaggio iniziale

```c
p("Ciao sono il processo P1\n");
```

La funzione:

```c
void p(const char *msg) {
    printf("[%d -> %d] %s",
           getppid(),
           getpid(),
           msg);
}
```

stampa:

```text
[PID_padre -> PID_figlio] Ciao sono il processo P1
```

ad esempio:

```text
[1234 -> 1235] Ciao sono il processo P1
```

---

# 4. Numeri casuali

```c
srand(time(NULL));
```

inizializza il generatore.

Poi:

```c
for (int i = 0; i < 10; i++)
```

esegue 10 iterazioni.

---

## Generazione

```c
int random = rand() % 10;
```

Produce numeri:

```text
0 1 2 3 4 5 6 7 8 9
```

---

## Filtraggio dei pari

```c
if ((random % 2) == 0)
```

Passano solo:

```text
0 2 4 6 8
```

---

## Stampa

```c
printf("Number random : %d\n", random);
```

esempio:

```text
Number random : 8
```

---

## Scrittura nella pipe

```c
write(fd[1], &random, sizeof(int));
```

Questa è la parte importante.

Scrive nella pipe:

```text
4 byte
```

contenenti il valore dell'intero.

Se:

```c
random = 8;
```

nella pipe finiscono i byte che rappresentano il numero 8.

---

# 5. Fine del figlio

```c
close(fd[1]);
```

Chiude il lato scrittura.

Fondamentale.

Perché?

Perché il padre deve capire che non arriveranno altri dati.

---

# 6. Codice del padre

Il padre entra nell'`else`.

---

## Chiude il lato scrittura

```c
close(fd[1]);
```

Il padre non scrive.

Legge soltanto.

```text
Padre

fd[0] aperto
fd[1] chiuso
```

---

# 7. Lettura continua

```c
while (read(fd[0], &rec, sizeof(int)))
```

Qui succede qualcosa di molto elegante.

---

### Prima iterazione

Il figlio scrive:

```text
8
```

Il padre esegue:

```c
read(...)
```

e riceve:

```c
rec = 8;
```

---

### Stampa

```c
p("Received ");
printf("%d\n", rec);
```

Output:

```text
[1234 -> 1234] Received 8
```

(Notare che qui sia padre che figlio sono il padre stesso perché la funzione usa `getppid()` e `getpid()` del processo corrente.)

---

### Seconda iterazione

Legge il prossimo numero.

Supponiamo:

```text
4
```

Output:

```text
Received 4
```

---

# Quando termina il while?

Questa è la parte più importante.

Quando il figlio fa:

```c
close(fd[1]);
```

non esistono più scrittori sulla pipe.

A quel punto:

```c
read(...)
```

restituisce:

```c
0
```

che significa:

```text
EOF
```

(Fine dei dati)

Quindi:

```c
while(read(...))
```

diventa

```c
while(0)
```

e termina.

---

# 8. Wait

```c
wait(NULL);
```

Aspetta che il figlio sia terminato.

Evita zombie process.

---

# Schema finale

```text
               PIPE
        +----------------+
        |                |
        |                |
        +----------------+
          ^          |
          |          v

       Padre      Figlio
       read()     write()
```

Sequenza:

```text
Figlio genera numeri
        |
        v
scrive nella pipe
        |
        v
Padre legge
        |
        v
stampa
        |
        v
Figlio chiude fd[1]
        |
        v
read() restituisce 0
        |
        v
while termina
        |
        v
wait()
```

Questa è praticamente l'implementazione base del modello **produttore-consumatore**: il figlio produce numeri e il padre li consuma leggendo dalla pipe. È uno degli esempi più classici che possono chiedere all'esame di Sistemi Operativi quando si parla di IPC.


*/

