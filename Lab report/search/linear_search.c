#include <stdio.h>

int linearSearch(int ar[], int v, int i, int size) {
    if (i >= size) {
        return -1;
    }
    else if (ar[i] == v) {
        return i; 
    }
    return linearSearch(ar, v, i + 1, size);
}

int main() {
    int ar[] = {4, 12, 3, 67, 4, 9, 32, 1};
    int v;
    int size = sizeof(ar) / sizeof(ar[0]);
    
    printf("\nEnter the character to search: ");
    scanf(" %d", &v);

    int i=0;
    int result = linearSearch(ar, v, i, size);
    
    if (result == -1) {
        printf("Value '%d' not found in the ar.\n", v);
    } else {
        printf("Value '%d' found at index %d.\n", v, result);
    }
    return 0;
}
