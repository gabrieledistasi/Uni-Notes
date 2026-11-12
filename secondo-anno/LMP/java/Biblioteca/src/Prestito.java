
import java.time.LocalDate;

public class Prestito {

    private LocalDate dataInizioPrestito;
    private LocalDate dataRiconsegnaPrevista;
    private LocalDate dataRiconsegnaEffettiva;
    private String nomeRichiedente;
    private String cognomeRichiedente;
    private double costoAffitto;

    public Prestito(LocalDate dataInizioPrestito, LocalDate dataRiconsegnaPrevista, LocalDate dataRiconsegnaEffettiva, String nomeRichiedente, String cognomeRichiedente, double costoAffitto) {
        this.dataInizioPrestito = dataInizioPrestito;
        this.dataRiconsegnaPrevista = dataRiconsegnaPrevista;
        this.dataRiconsegnaEffettiva = dataRiconsegnaEffettiva;
        this.nomeRichiedente = nomeRichiedente;
        this.cognomeRichiedente = cognomeRichiedente;
        this.costoAffitto = costoAffitto;

    }

    public LocalDate getDataInizioPrestito() {
        return dataInizioPrestito;
    }

    public LocalDate getDataRiconsegnaEffettiva() {
        return dataRiconsegnaEffettiva;
    }

    public LocalDate getDatarionsegnaPrevista() {
        return dataRiconsegnaPrevista;
    }

    public String getNomerichiedente() {
        return nomeRichiedente;
    }

    public String getCognomeRichiedente() {
        return cognomeRichiedente;
    }

    public double getCostoAffitto() {
        return costoAffitto;
    }

}
