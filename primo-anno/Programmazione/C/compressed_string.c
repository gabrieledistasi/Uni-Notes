/*si scriva una funzione con il seguente prototipo
char *compressed_string(char *a)
la stringa a contiene soltanto lettere alfabetiche minuscole
la funzione deve restituire una nuova stringa allocata dinamicamente nella quale ogni sequenza consecutiva di
caratteri uguali venga sostituita dal carattere seguito dal numero di occorrenze */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *compressed_string(char *a) {
    if (a == NULL || *a == '\0') {
        return NULL; // Return NULL for empty input
    }

    int length = strlen(a);
    char *result = malloc(length * 2 + 1); // Allocate enough space for worst case
    if (result == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    int count = 1;
    int j = 0; // Index for result string

    for (int i = 1; i <= length; i++) {
        if (a[i] == a[i - 1]) {
            count++; // Increment count for consecutive characters
        } else {
            result[j++] = a[i - 1]; // Store the character
            j += printf(&result[j], "%d", count); // Store the count as string
            count = 1; // Reset count for new character
        }
    }

    result[j] = '\0'; // Null-terminate the result string
    return result; // Return the compressed string
}

int main() {
    char input[] = "aaabbbccdaa";
    char *compressed = compressed_string(input);
    if (compressed != NULL) {
        printf("Compressed string: %s\n", compressed);
        free(compressed); // Free the allocated memory
    } else {
        printf("Input string is empty or memory allocation failed.\n");
    }
    return 0;
}

