//aritmetica dei puntatori 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrCat(char *, char*);

int main(){
    char str0[] = "programmazione";
    char str1[] = " dei calcolatori";
    char *str2;

    str2 = StrCat(str0, str1);
    printf("%s\n", str2);
    free(str2);


    printf("%s\n", str0+1); // indirizzo del byte successivo

    char str3[] = "012";
    strcpy(str0+1, str3); //  copia a partire dal secondo byte di str0
    printf("%s\n", str0);

    printf("%c\n", *(str1+5) ); // equivalente a printf("%c\n", str1[5] )

    int a[10] = {3,1,2};
    printf("%d\n", *(a+2) );

    for(int i; i < 10; i++){
        printf("%d\n", *(a+i) );
    }
}



//Acquisizione di input e conversione
int main(){
    char testo[100];
    float pi;
    printf("Digita un testo qualsiasi: ");
    scanf("%s", testo);
    printf("%s\n", testo);
    printf("Digita le prime 3 cifre di pi greco: ");
    scanf("%f", &pi);
    printf("%f\n", pi);
    int giorno, mese, anno;
    printf("Data di nascita g-m-a: ");
    int conversioni = scanf("%d-%d-%d", &giorno, &mese, &anno);
    if (conversioni == 3){
        printf("Giorno: %d\n", giorno);
        printf("Mese:   %d\n", mese);
        printf("Anno:   %d\n", anno);
    }
    char stringa_da_convertire[] = "15-12-2025";
    conversioni = sscanf(stringa_da_convertire, "%d-%d-%d", &giorno, &mese, &anno);
    if (conversioni == 3){
        printf("Giorno: %d\n", giorno);
        printf("Mese:   %d\n", mese);
        printf("Anno:   %d\n", anno);
    }
}
