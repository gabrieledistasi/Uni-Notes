#include <stdio.h>
#include <string.h>

char *lexord(char *a){
    int n = strlen(a);
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                // Scambio dei caratteri
                char temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return a;
}

int main(){
    char a[] = "acbdefgaazklm"; 
    char *sc = lexord(a); 

    printf("Stringa ordinata: %s\n", sc);
}
