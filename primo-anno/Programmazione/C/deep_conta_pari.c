//int conta_pari(int *a, int n)

int conta_pari(int *a, int n){
    
    if (n == 0){
        return 0; 
    }
    else{
        int ultimo = a[n-1]; 
        int pari = (ultimo%2==0)? 1 : 0; //operatore ternario
        return pari + conta_pari(a, n-1); 
    }
}