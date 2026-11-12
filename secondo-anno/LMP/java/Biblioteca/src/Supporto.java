
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;

public class Supporto {

    private String titolo;
    private String entePubblicante;
    private int annoDiPubblicazione;
    private ArrayList<Prestito> prestiti = new ArrayList<>();
    private static int giorniRiconsegna;

    public Supporto(String titolo, String entePubblicante, int annoDiPubblicazione) {

        this.titolo = titolo;
        this.entePubblicante = entePubblicante;
        this.annoDiPubblicazione = annoDiPubblicazione;

    }

    public void aggiungiPrestito(Prestito prestito) {
        prestiti.add(prestito);
    }

    public static void setGiorniRiconsegna(int giorni) {

        if (giorni <= 0) {
            throw new IllegalArgumentException("Giorni non validi");
        }

        giorniRiconsegna = giorni;

    }

    public long periodoMassimo() {

        long massimo = 0;

        for (Prestito prestito : prestiti) {

            if (prestito.getDataRiconsegnaEffettiva() == null) {
                continue;
            }

            long giorni = ChronoUnit.DAYS.between(prestito.getDataInizioPrestito(), prestito.getDataRiconsegnaEffettiva());

            if (giorni > massimo) {
                massimo = giorni;
            }

        }

        return massimo;
    }

    public ArrayList<ArrayList<Prestito>> TrovaInconsistenze() {

        ArrayList<ArrayList<Prestito>> inconsistenze = new ArrayList<>();
        for (int i = 0; i < prestiti.size(); i++) {
            for (int j = i + 1; j < prestiti.size(); j++) {

                Prestito p1 = prestiti.get(i);
                Prestito p2 = prestiti.get(j);

                boolean condizione1
                        = p1.getDataRiconsegnaEffettiva() == null
                        || p2.getDataInizioPrestito().isBefore(p1.getDataRiconsegnaEffettiva());

                boolean condizione2
                        = p2.getDataRiconsegnaEffettiva() == null
                        || p1.getDataInizioPrestito().isBefore(p2.getDataRiconsegnaEffettiva());

                if (condizione1 && condizione2) {
                    ArrayList<Prestito> coppia = new ArrayList<>();

                    coppia.add(p1);
                    coppia.add(p2);
                    inconsistenze.add(coppia);
                }

            }
        }

        return inconsistenze;
    }

}
