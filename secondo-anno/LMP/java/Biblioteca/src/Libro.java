
public class Libro extends Supporto {

    private int numeroPagine;

    public Libro(String titolo, String entePubblicante, int annoDiPubblicazione, int numeroPagine) {

        super(titolo, entePubblicante, annoDiPubblicazione);
        this.numeroPagine = numeroPagine;
    }
}
