#include <stdio.h>

int linearSearch(char ar[], char v, int i, int size) {
    if (i >= size) {
        return -1;
    }
    else if (ar[i] == v) {
        return i; 
    }
    return linearSearch(ar, v, i + 1, size);
}

int main() {
    char ar[] = {'a', 'b', 'c', 'd', 't', 'f', 'g', 'h'};
    char v;
    int size = sizeof(ar) / sizeof(ar[0]);
    
    printf("\nEnter the character to search: ");
    scanf(" %c", &v);

    int i=0;
    int result = linearSearch(ar, v, i, size);
    
    if (result == -1) {
        printf("Character '%c' not found in the ar.\n", v);
    } else {
        printf("Character '%c' found at index %d.\n", v, result);
    }
    return 0;
}
