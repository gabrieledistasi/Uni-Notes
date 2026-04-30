#include <stdio.h>

int maxprod(int arr[], int n) {
    int max1 = arr[0] > arr[1] ? arr[0] : arr[1];
    int max2 = arr[0] > arr[1] ? arr[1] : arr[0];

    for(int i = 2; i < n; i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if(arr[i] > max2) {
            max2 = arr[i];
        }
    }
    return max1 * max2;
}

int main() {
    int n[] = {1, 2, 4, 5, 6};
    int size = sizeof(n)/sizeof(n[0]);
    printf("Il prodotto più grande è: %d\n", maxprod(n, size));
    return 0;
}
