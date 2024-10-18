#include <stdio.h>

/*
int BinarySearch (int lb, int ub, int item, int A[]) {
    int BEG = lb, END = ub;
    
    while (BEG <= END) {
        int MID = (BEG + END) / 2;
        if (A[MID] == item) return MID;
        
        if (A[MID] < item) BEG = MID + 1;
        else END = MID - 1;
    }
    return -1;
}

int main () {
    int A[] = {5, 9, 12, 24, 33, 54, 68, 72, 84, 93};
    int size = sizeof (A) / sizeof (A[0]);
    int lb = 0, ub = size - 1;
    int item = 100;
    
    int idx = BinarySearch (lb, ub, item, A);
    if (idx >= 0) printf ("Item is found at %d\n", idx);
    else printf ("Item is not found\n");
    
    return 0;
}
*/

void MatrixMultiplication (int M[3][3], int N[3][3], int C[3][3], int r1, int r2, int c1, int c2) {
    if (r1 != c2) return;
    
    for (int I = 0; I < r1; I++) {
        for (int J = 0; J < c2; J++) {
            int sum = 0;
            for (int K = 0; K < r1; K++) {
                sum += M[I][K] * N[K][J];
            }
            C[I][J] = sum;
        }
    }
}

int main () {
    int M[3][3] = {8, 7, 8,
                   5, 9, 1,
                   3, 5, 9};
    int N[3][3] = {8, 7, 8,
                   5, 9, 1,
                   3, 5, 9};
    int C[3][3];
    
    MatrixMultiplication (M, N, C, 3, 3, 3, 3);
    
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++)
            printf ("%d ", C[i][j]);
        printf ("\n");
    }
    
    return 0;
}