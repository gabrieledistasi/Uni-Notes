//calcolare la somma degli elementi in un array

public class Main{

    public static void main(String[] args){
        int[] numeri = {1, 2, 3, 4, 5}; 
        int sum = 0; 

        for(int i=0; i < numeri.length; i++){

            sum += numeri[i]; 
            
        }

        System.out.println(sum); 
    }
}