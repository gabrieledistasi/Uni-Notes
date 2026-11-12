import src.*; 
 
 public class Main{


    public static void main(String[] args){


        Dipendente d1 = new Dipendente(
            "Rocca", "Di Papa",LocalDate.of(2005, 7, 4), LocalDate.of(2024, 12, 1), Dipartimento.MARKETING, Mansione.GOAT, 8, null
        ); 

        Dipendente d2 = new Dipendente(
            "Giorgio", "Rotella", LocalDate.of(2005, 12, 28), LocalDate.of(2025, 7, 15), Dipartimento.DEVELOPMENT, Mansione.ANALISTA, 3, d1
        ); 

        


        }


 }