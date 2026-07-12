#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* expand_digits(char *s){

    int new_len = 0;

    /* prima passata: calcolo dimensione finale */
    for(int i = 0; s[i] != '\0'; i++){

        if(isdigit(s[i])){
            new_len += s[i] - '0';
        }
        else{
            new_len++;
        }
    }

    char* res = malloc(new_len + 1);

    if(res == NULL){
        return NULL;
    }

    /* seconda passata: costruzione stringa */
    int k = 0;

    for(int i = 0; s[i] != '\0'; i++){

        if(isdigit(s[i])){

            int count = s[i] - '0';

            for(int j = 0; j < count; j++){
                res[k++] = '*';
            }
        }
        else{
            res[k++] = s[i];
        }
    }

    res[k] = '\0';

    return res;
}

////versione alessandro

char* expand_digits(char* s) {
    int length = strlen(s);

    char* output = (char *)malloc(sizeof(char)*length*9 + 1);
    int curr_pos = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            for (int j = 0; j < s[i]- '0'; j++) {
                output[curr_pos++] = '*';
            }
        } else {
            output[curr_pos++] = s[i];
        }
    }
    
    output[curr_pos] = '\0';

    return output;
}`