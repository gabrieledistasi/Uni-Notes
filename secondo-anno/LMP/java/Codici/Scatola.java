/*la classe generica Scatola<T> può contenere una String, un intero oppure un altro oggetto di altro tipo
senza Generics dovremmo ricorrere a object, perdendo parte della sicurezza sui tipi. 
Con i generics T è un parametro di tipo, quando creiamo una scatola, decidiamo quale tipo rappresenta.*/

public class Scatola<T> {

    private T contenuto;

    public Scatola(T contenuto) {
        this.contenuto = contenuto;
    }

    public T getContenuto() {
        return contenuto;
    }

    public static void main(String[] args) {
        Scatola<String> s1 = new Scatola<>("informatica");
        Scatola<Integer> s2 = new Scatola<>(42);
        Scatola<ElementoStudio> s3 = new Scatola<>(
            new ElementoStudio("Algoritmi", 10)
        );

        System.out.println(s1.getContenuto());
        System.out.println(s2.getContenuto());
        System.out.println(s3.getContenuto());
    }
}

    // s1 restituisce una stringa
    // s2 restituisce un intero
    // s3 restituisce un oggetto del tipo ElementoStudio 




