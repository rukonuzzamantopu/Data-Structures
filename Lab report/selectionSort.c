#include <stdio.h>

int main() {
    int ar[100], n, temp;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ar[j] < ar[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = ar[min_idx];
            ar[min_idx] = ar[i];
            ar[i] = temp;
        }
    }

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");

    return 0;
}
