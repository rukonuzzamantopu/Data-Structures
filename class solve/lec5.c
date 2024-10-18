#include "Utility.h"
#define SIZE 100

void SelectionSort (int lb, int ub, int A[]) {
    for (int i = ub; i > lb; i--) {
        int min_idx = i;
        for (int j = i - 1; j >= lb;  j--) {
            if (A[j] > A[min_idx]) min_idx = j;
        }
        if (min_idx != i) Swap (i, min_idx, A);
    }
}

int main () {
    int A[SIZE];
    int lb = 0, ub = 10;
    
    InserValuesInArray (lb, ub, A);
    PrintArray (lb, ub, A);
    
    Swap (2, 5, A);
    PrintArray (lb, ub, A);
    
    SelectionSort (3, 6, A);
    PrintArray (lb, ub, A);
    
    return 0;
}