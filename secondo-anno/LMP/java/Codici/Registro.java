/*Dobbiamo creare una classe Registro<T> che possa contenere una sequenza di elementi di qualsiasi tipo.

Requisiti:
1. La classe deve essere generica (Registro<T>).
2. Deve avere un attributo elementi di tipo ArrayList<T>.
3. Il costruttore deve inizializzare la lista.
4. Deve avere un metodo aggiungi(T elemento) per inserire un elemento.
5. Deve avere un metodo getElementi() che restituisce la lista.*/ 

import java.util.ArrayList; 
import java.util.Comparator;


/*Possibile DOMANDA: Perché nella dichiarazione Registro <T extends Comparable<T>> abbiamo scritto extends e non implements
anche quando il vincolo è un'interfaccia? 
RISPOSTA: 
In Java, quando dichiariamo un bounded type parameter, usiamo sempre extends, anche quando il vincolo è un'interfaccia.
Per dichiarare un bounded type parameter multiplo si inseriscono sempre prima le classi e poi le interfacce.
*/
public class Registro<T extends Comparable<T>>{
    private ArrayList<T> elementi; 

    public Registro(){
        elementi = new ArrayList<>(); 

    }

    public void aggiungi(T elemento){
        elementi.add(elemento); 
    }

    public ArrayList<T> getElementi(){
        return elementi; 
    }

    public T massimo(){

        if(elementi.isEmpty()){
            return null; 
        }

        T massimo = elementi.get(0); 

        for(int i = 1; i < elementi.size(); ++i){

            if(elementi.get(i).compareTo(massimo)>0){

                massimo = elementi.get(i); 

            }
        }

        return massimo; 
    }

    /*Questo metodo deve restituire quanti elementi della lista sono maggiori dell'elemento passato come parametro.*/
    public int contaMaggioriDi(T elemento){

        int c = 0; 

        for(int i = 0; i < elementi.size(); ++i){

            if(elementi.get(i).compareTo(elemento)>0){
                c++; 
            }
        }

        return c; 
        
    }

    public static <T> T ultimo(T[] valori){

        if (valori.length==0){
            return null;
        }

        return valori[(valori.length)-1]; 
    }

    //questo è il generico metodo per poter ordinare un'ArrayList in base ad un criterio
    public void ordina(Comparator<T> criterio){
        elementi.sort(criterio); 
        
        
    }

    public static void main(String[] args){
        Registro<Integer> voti = new Registro<>(); 
        Registro<String> nomi = new Registro<>(); 

        nomi.aggiungi("Mario"); 
        nomi.aggiungi("Alessandro"); 
        nomi.aggiungi("Luca"); 
        nomi.aggiungi("Rocca"); 
        nomi.aggiungi("Argo"); 
        nomi.aggiungi("Diego"); 

        voti.aggiungi(18); 
        voti.aggiungi(24); 
        voti.aggiungi(27); 
        voti.aggiungi(30); 

        //qui chiamiamo il metodo ordina per ordinare le stringhe dalla più corta alla più lunga
        nomi.ordina(
            (a, b) -> Integer.compare(a.length(), b.length())
        ); 

        System.out.println(voti.contaMaggioriDi(24)); 
        System.out.println(nomi.getElementi()); 

        //modificando ordina, possiamo ordinare le stringhe dalla più lunga alla più corta
        nomi.ordina(
            (a, b) -> Integer.compare(b.length(), a.length())
        ); 

        /* con questo metodo, aggiungiamo il controllo sulla parità: se due stringhe hanno lunghezza uguale
        procedi a controllare l'ordine lessicografico*/
        nomi.ordina(
            (a, b) -> {
                if(a.length()==b.length()){
                    return a.compareTo(b); 
                }

                return Integer.compare(b.length(), a.length()); 
            }
        ); 

        System.out.println(nomi.getElementi()); 


    }

}

