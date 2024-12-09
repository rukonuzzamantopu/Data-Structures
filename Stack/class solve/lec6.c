#include "Utility.h"

#define SIZE 100

void BubbleSort (int lb, int ub, int A[]) {
    //int N = ub + 1 - lb;
    for (int i = lb; i < ub; i++) {
        for (int j = lb; j < ub - i + lb; j++) {
            if (A[j] > A[j+1])
                Swap (j, j+1, A);
        }
    }
}

void InsertionSort (int lb, int ub, int A[]) {
    for (int i = lb + 1; i <= ub; i++) {
        int key = A[i];
        int j = i - 1;
        
        while (j >= lb && A[j] > key) {
            A[j + 1] = A[j];
            j -= 1;
        }
        A[j + 1] = key;
    }
}
    

int main () {
    int A[SIZE];
    int lb = 110, ub = 125;
    
    InserValuesInArray (lb, ub, A);
    PrintArray (lb, ub, A);
    
    BubbleSort (lb, ub, A);
    PrintArray (lb, ub, A);
    
    InsertionSort (lb, ub, A);
    PrintArray (lb, ub, A);
    
    return 0;
}