#include <stdio.h>
#include <stdlib.h>

void AssignIntValuesToArray (int lb, int ub, int *Ar) {
    for (int i = lb; i <= ub; i++) 
        Ar[i] = rand() % 101;
}

void PrintArray (int lb, int ub, int Ar[]) {
    for (int i = lb; i <= ub; i++) 
        printf ("%d\t", Ar[i]);
    printf ("\n");
}