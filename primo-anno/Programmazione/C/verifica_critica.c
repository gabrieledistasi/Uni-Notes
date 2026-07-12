#include <stdio.h>

int verifica_critica(float capacità){

    if(capacità<20.0){
        return 1; 
    }

    else{
        return 0; 
    }


}

int main(){
    int n; 
    printf("inserisci il numero di batterie: \n"); 
    scanf("%d", &n); 

    int counter = 0; 

    for(int i = 0; i < n; i++){
        int codici; 
        float capacità; 

        printf("inserisci codice batteria\n"); 
        scanf("%d", &codici); 
        printf("inserisci capacità batteria\n");
        scanf("%f", &capacità);

        if(verifica_critica(capacità)==1){
            printf("batteria %d da sostituire\n", codici); 
            counter++; 

        }
        else{
            printf("batteria %d OK \n", codici); 
        }
    }

    printf("batterie in stato critico: %d \n", counter); 

    return 0; 

}