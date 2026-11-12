public class EserciziGenerics{

    public static <T extends Comparable<T>> T maggiore(T a, T b){

        if(a.compareTo(b)>0){
            return a; 
        }

        else{
            return b; 
        }

    }; 

    public static void main(String[] args){
     

    
        System.out.println(maggiore(15, 8));
        System.out.println(maggiore("banana", "mela" ));


    }
}