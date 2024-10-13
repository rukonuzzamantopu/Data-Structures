#include "Utility.h"
#define SIZE 100

void CountingSort (int lb, int ub, int A[]) {
    int M = FindMax (lb, ub, A);
    //printf ("%d\n", M);
    
    int C[M+1];
    InitArray (0, M, C);
    PrintArray (0, M, C);
    
    for (int i = lb; i <= ub; i++) C[A[i]] += 1;
    PrintArray (0, M, C);
    
    for (int i = 1; i <= M; i++) C[i] += C[i-1];
    PrintArray (0, M, C);
    
    int B[ub + 1];
    for (int i = ub; i >= lb; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]] -= 1;
    }
    PrintArray (lb, ub, B);
}

int main () {
    int A[SIZE];
    int lb = 0, ub = 10;
    
    InserValuesInArray (lb, ub, A);
    PrintArray (lb, ub, A);
    
    CountingSort (lb, ub, A);
    
    return 0;
}

