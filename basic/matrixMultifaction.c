#include<stdio.h>

int main() {
    int A[20][20], B[20][20], C[20][20];
    int i, j, k, rA, cA, rB, cB;

    printf("Enter the number of rows and columns in A matrix:\n");
    scanf("%d %d", &rA, &cA);

    printf("Enter the number of rows and columns in B matrix:\n");
    scanf("%d %d", &rB, &cB);

    if (cA != rB) {
        printf("Error: The number of columns in A must equal the number of rows in B for multiplication.\n");
        return 0;
    }

    printf("Enter the elements of A matrix:\n");
    for (i = 0; i < rA; i++) {
        for (j = 0; j < cA; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of B matrix:\n");
    for (i = 0; i < rB; i++) {
        for (j = 0; j < cB; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < rA; i++) {
        for (j = 0; j < cB; j++) {
            C[i][j] = 0;
            for (k = 0; k < cA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant matrix after multiplication:\n");
    for (i = 0; i < rA; i++) {
        for (j = 0; j < cB; j++) {
            printf("%5d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
