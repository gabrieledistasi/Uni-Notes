package src; 
import java.time.LocalDate; 
import java.util.ArrayList;


public class Dipendente{

    private String nome; 
    private String cognome; 
    private LocalDate dataDiNascita; 
    private LocalDate dataDiAssunzione; 
    private static int contatore = 0;
    private String matricola; 
    private Dipartimento dipartimento; 
    private Mansione mansione; 
    private int livello; 
    private Dipendente capo; 
    private static ArrayList<Dipendente> dipendenti = new ArrayList<>(); 

    public enum Mansione{
        SVILUPPATORE,
        ANALISTA,
        ADDETTO_MARKETING,
        RESPONSABILE_RISORSE_UMANE, 
        GOAT

    }


    public Dipendente(String nome, String cognome, LocalDate dataDiNascita, LocalDate dataDiAssunzione, Dipartimento dipartimento,  Mansione mansione, int livello, Dipendente capo){
        this.nome = nome; 
        this.cognome = cognome; 
        this.dataDiNascita = dataDiNascita; 
        this.dataDiAssunzione = dataDiAssunzione; 
        this.dipartimento = dipartimento; 

        if(livello < 1 || livello > 8){
            throw new IllegalArgumentException("Livello non valido"); 
        }

        contatore++; 
        this.matricola = "CLT_"+contatore; 
        this.mansione = mansione; 
        this.livello = livello; 
        
        this.capo = capo; 
        dipendenti.add(this); 

    }

    public Dipendente trovaSostituto(){
        if(this.capo==null){
                return null;
            }
            
        for(Dipendente candidato: dipendenti){
            if(candidato==this || this.mansione != candidato.mansione){
                continue; 
            }

        

            

            if(this.capo == candidato.capo && this.mansione == candidato.mansione){

                    return candidato; 
                    
                }
                


        }

        return null; 

    }

        public static ArrayList<ArrayList<Dipendente>> trovaAssunzioniComuni() {
        ArrayList<ArrayList<Dipendente>> gruppi = new ArrayList<>();
        ArrayList<Dipendente> giaInseriti = new ArrayList<>();

        for (Dipendente d1 : dipendenti) {
            if (giaInseriti.contains(d1)) {
                continue;
            }

            ArrayList<Dipendente> gruppo = new ArrayList<>();
            gruppo.add(d1);

            for (Dipendente d2 : dipendenti) {
                if (d1 == d2 || giaInseriti.contains(d2)) {
                    continue;
                }

                if (d1.dataDiAssunzione.getMonth() == d2.dataDiAssunzione.getMonth()
                        && d1.dataDiAssunzione.getYear() == d2.dataDiAssunzione.getYear()
                        && d1.dipartimento == d2.dipartimento) {

                    gruppo.add(d2);
                }
            }

            if (gruppo.size() > 1) {
                gruppi.add(gruppo);
                giaInseriti.addAll(gruppo);
            }
        }

        return gruppi;
    }

    public ArrayList<Dipendente> chainOfCommand(){

        ArrayList<Dipendente> superiori = new ArrayList<>(); 
        Dipendente corrente = this.capo; 

        while(corrente != null){
            superiori.add(corrente); 
            corrente = corrente.capo; 
        }

        return superiori; 

    }

    

    

    public String getMatricola(){
        return matricola; 
    }





}