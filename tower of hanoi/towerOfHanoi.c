#include <stdio.h>

void towerOfHanoi(int n, char beg, char aux, char end) {
    if (n == 1) {
        printf("Move disk from %c to %c\n", beg, end);
    }
    else{
    towerOfHanoi(n - 1, beg, end, aux);
    towerOfHanoi(1, beg, aux, end);
    towerOfHanoi(n - 1, aux, beg, end);
    }
}

int main() {
    int n;
    char a,b,c;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Tower of hanoi of %d disc\n",n);
    towerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}