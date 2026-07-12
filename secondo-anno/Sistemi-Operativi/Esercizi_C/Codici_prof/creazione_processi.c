#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(){
    __pid_t p1 = fork(); 

    if(p1 == 0){
            printf("ciao, sono il processo P1: %d\n", getpid()); 

    }
    else{
        __pid_t p2 = fork(); 
        if(p2 == 0){

            sleep(2); 
            printf("ciao, sono il processo P2: %d\n", getpid()); 

        }
        else{
            wait(NULL); //attesa
            wait(NULL); //attesa
            printf("ciao, sono il padre P: %d\n", getpid()); 
        }
    }


    return 0; 
}

/*

Questo programma introduce una cosa nuova: il padre usa `wait()` per aspettare la terminazione dei figli.

Disegniamo l'albero:

```text
        P0
       /  \
     P1    P2
```

---

### 1. Prima fork

```c
__pid_t p1 = fork();
```

Crea `P1`.

* P1 ha `p1 == 0`
* P0 ha `p1 > 0`

---

### 2. Esecuzione di P1

P1 entra qui:

```c
if(p1 == 0){
    printf("ciao, sono il processo P1: %d\n", getpid());
}
```

e stampa subito.

Output:

```text
ciao, sono il processo P1: ...
```

Poi termina.

---

### 3. Esecuzione di P0

P0 entra nell'`else`:

```c
__pid_t p2 = fork();
```

e crea P2.

---

### 4. Esecuzione di P2

P2 ha:

```c
p2 == 0
```

quindi entra qui:

```c
sleep(2);

printf("ciao, sono il processo P2: %d\n", getpid());
```

Aspetta 2 secondi e poi stampa.

Output:

```text
ciao, sono il processo P2: ...
```

---

### 5. Esecuzione del padre P0

P0 entra nell'ultimo `else`:

```c
wait(NULL);
wait(NULL);
```

Ogni `wait()` aspetta che termini **un figlio qualunque**.

Poiché il padre ha due figli:

```text
P1
P2
```

servono due `wait()`.

---

### Cosa succede temporalmente?

Supponiamo:

```text
t = 0
```

P1 stampa immediatamente:

```text
ciao, sono il processo P1
```

e termina.

P0 esegue:

```c
wait(NULL);
```

e raccoglie P1.

Poi esegue:

```c
wait(NULL);
```

ma P2 è ancora vivo perché sta facendo:

```c
sleep(2);
```

Quindi il padre si blocca.

Dopo 2 secondi:

```text
ciao, sono il processo P2
```

P2 termina.

Il secondo `wait()` ritorna.

A questo punto il padre può stampare:

```text
ciao, sono il padre P
```

---

### Ordine dell'output

Con il `sleep(2)` l'ordine diventa praticamente:

```text
ciao, sono il processo P1: ...
ciao, sono il processo P2: ...
ciao, sono il padre P: ...
```

Perché:

1. P1 termina subito.
2. P2 aspetta 2 secondi.
3. Il padre aspetta entrambi con i due `wait()`.

---

### Perché due wait?

Perché il padre ha due figli:

```text
P0
├── P1
└── P2
```

Un solo:

```c
wait(NULL);
```

aspetterebbe la terminazione di **uno solo** dei due.

Con:

```c
wait(NULL);
wait(NULL);
```

sei sicuro di raccogliere entrambi i figli prima di proseguire.

Questo è un esercizio molto tipico d'esame perché combina:

* `fork()`
* gerarchia dei processi
* `sleep()`
* `wait()`
* sincronizzazione padre-figli

e il professore spesso chiede proprio: **"Qual è l'ordine delle stampe?"**.

*/