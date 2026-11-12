
public class DVD extends Supporto {

    private int durata;

    public DVD(String titolo, String entePubblicante, int annoDiPubblicazione, int durata) {
        super(titolo, entePubblicante, annoDiPubblicazione);
        this.durata = durata;
    }
}
