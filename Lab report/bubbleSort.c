#include <stdio.h>

int main() {
    int ar[100];
    int n, temp;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for(int j = 0; j < n - i - 1; j++) {
            if(ar[j] > ar[j + 1]) {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }

    printf("Sorted array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");

    return 0;
}
