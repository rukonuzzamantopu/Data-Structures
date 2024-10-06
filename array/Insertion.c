#include <stdio.h>

int main() {
    int size, pos, value;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size + 1];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the position where you want to insert the new element (1 to %d): ", size + 1);
    scanf("%d", &pos);
    // Validate position
    if (pos < 1 || pos > size + 1) {
        printf("Invalid position!\n");
        return 1;
    }
    printf("Enter the value of the new element: ");
    scanf("%d", &value);
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    size++; 
    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
