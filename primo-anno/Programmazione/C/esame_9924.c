/*
char *string_center(char *a, int w, char c)
la funzione deve ritornare una stringa di lunghezza w contenente una copia di a posizionata al centro della stringa e circondata da caratteri c 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_center(char *a, int w, char c){

    char *b = malloc(w*sizeof(char)); 
    int n = strlen(a); 
    int middle = (w-n)/2; 
    int flag = 0,j=0; 

    for(int i = 0; i < w; i++){
        if(i < middle || flag == 1){
            b[i] = c;  
            printf("1) b[%d] = %c\n",i,b[i]);
        }
        else{
            b[i] = a[j];
            printf("2) b[%d] = %c\n",i,b[i]);
            j++;
        } 

        if (b[i] == '\0'){
            b[i] = c;
            flag = 1; 
            printf("3) b[%d] = %c\n",i,b[i]);
        }
    }


    return b; 


}


int main(){
    char a[] = "ciao"; 
    int w = 10; 
    char c = '*'; 
    char *res = string_center(a, w, c); 

    //printf("%d\n",strlen(res));

    for(int k = 0; k < w; k++){
        printf("%c",res[k]); 
    }
    printf("\n");

}