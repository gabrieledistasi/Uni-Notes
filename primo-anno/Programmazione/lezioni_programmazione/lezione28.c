

//Array dinamici
struct lista {
    double *a; // la sequenza è memorizzata in questo array
    int n, c;  // numero di elementi nella lista e capacità dell'array
};
typedef struct lista lista;

lista nuova_lista();
lista append(lista, double);
lista rem_last(lista);
void mostra_lista(lista);
Ritorna una lista vuota

lista nuova_lista(){
    lista lst = {NULL, 0, 0};
    return lst;
}
//Stampa le informazioni sulla lista e i sui elementi

void mostra_lista(lista lst){
    printf("[");
    for(int i = 0; i < lst.n; i++){
        printf("%f ", lst.a[i]);
    }
    printf("]");
    printf("\n\tc = %d; n = %d\n", lst.c, lst.n);
}
//Aggiunge un nuovo elemento x in fondo alla lista, ritorna la lista modificata
lista append(lista lst, double x){
    if ( lst.c == lst.n ){
        lst.c = 2*lst.c+1;
        lst.a = realloc(lst.a, lst.c*sizeof(double));
    }
    lst.a[lst.n] = x;
    lst.n++;
    return lst;
}
/*Nel caso peggiore la realloc deve allocare l'intero spazio per un nuovo array e copiare tutti gli n
elementi nel nuovo spazio. In questo caso la complessità temporale è O(n). Nel caso in cui nell'array ci sia ancora spazio o la riallocazione è avvenuta espandendo 
l'array corrente, 
la complessità è costante.
Si osservi che dopo una operazione di inserimento "costosa" di costo 
cn(per una opportuna costante c′), il nuovo array avrà n
posizioni libere. Questo garantirà che le successive n
operazioni di inserimento in coda saranno eseguite in tempo costane. Sia cquesta costante allora, nel caso peggiore n
operazioni di append hanno un costo temporale totale pari a 
cn+nc ovvero O(n). Mediando, una singola operazione ha costo costante. Questo tipo di analisi della complessità è detta ammortizzata e valuta il costo medio per operazione su una sequenza di operazioni anche quando alcune sono più costose.
Poichè, nel caso peggiore, l'array contiene n
posizioni libere, queste devono essere considerate memoria extra e quindi la complessità spaziale è lineare in n*/n