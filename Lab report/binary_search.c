#include <stdio.h>

int binarySearch(char ar[], char v, int left, int right) {
    
    if (left > right) {
        return -1;
    }

    int middle = left + (right - left) / 2;
    if (ar[middle] == v) {
        return middle; 
    }
    else if (ar[middle] > v) {
        return binarySearch(ar, v, left, middle - 1);
    }
    else{
    return binarySearch(ar, v, middle + 1, right);
    }
}

int main() {
    
    char ar[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char v;
    
    int size = sizeof(ar) / sizeof(ar[0]);
    
    printf("\nEnter the character to search: ");
    scanf("%c", &v);
    int i=0;
    int result = binarySearch(ar, v, i, size - 1);
    
    if (result == -1) {
        printf("Character '%c' not found in the ar.\n", v);
    } else {
        printf("Character '%c' found at index %d.\n", v, result);
    }
    return 0;
}
