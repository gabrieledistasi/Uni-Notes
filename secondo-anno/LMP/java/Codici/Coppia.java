public class Coppia<K, V>{
    private K chiave; 
    private V valore; 

    public Coppia(K chiave, V valore){
        this.chiave = chiave; 
        this.valore = valore; 

    }

    public K getChiave(){
        return chiave; 
    }

    public V getValore(){
        return valore; 
    }

    public static void main(String[] args){
        Coppia<String, Integer> c = new Coppia<>("eta", 22 ); 
        
    }
}