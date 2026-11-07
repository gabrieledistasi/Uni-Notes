/* realizza una classe ElementoStudio che rappresenti un argomento da studiare
in particolare, la classe deve avere: 
nome: una stringa che identifica l'argomento
ore: un intero che indica quante ore servono per studiarlo
un costruttore che inizializzi gli attributi
i metodi getter per entrambi gli attributi
un metodo ToString() che restituisca una rappresentazione dell'oggetto*/


public class ElementoStudio{

    //attributi della classe ElementoStudio

    private String nome; 
    private int ore; 

    //Metodi getter per ottenere nome e ore della materia

    public String getName(){
        return nome; 
    }

    public int getOre(){
        return ore; 
    }

    //ridefiniamo toString @override serve al compilatore per capire che stiamo riscrivendo un metodo già esistente
    @Override
    public String toString(){

        return nome + " - " + ore + " ore"; 
    }

    //costruttore

    public ElementoStudio(String nome, int ore){
        this.nome = nome; 
        this.ore = ore; 
    }

    public static void main(String[] args){
        ElementoStudio[] elementi = new ElementoStudio[3]; 
        elementi[0] = new ElementoStudio("Algoritmi", 10); 
        elementi[1] = new ElementoStudio("Programmazione", 1); 
        elementi[2] = new ElementoStudio("Analisi", 15); 

        for(int i = 0; i < elementi.length; ++i){
            
            System.out.println(elementi[i]); 
        }
        

    }
}