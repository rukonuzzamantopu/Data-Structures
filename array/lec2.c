#include "Utility.h"

#define SIZE 100

int Insert (int k, int n, int item, int Ar[]) {
    int j = n;
    while (j >= k) {
        Ar[j + 1] = Ar[j];
        j -= 1;
    }
    Ar[k] = item;
    return n + 1;
}

int Delete (int k, int n, int Ar[]) {
    int j = k;
    while (j < n) {
        Ar[j] = Ar[j+1];
        j += 1;
    }
    return n - 1;
}

int Search (int lb, int ub, int item, int Ar[]) {
    for (int i = lb; i <= ub; i++) {
        if (Ar[i] == item) return i;
    }
    return -1;
}

int main () {
    int Arr[SIZE] = {0};
    int lb = 0, ub = 5, k = 3;
    
    AssignIntValuesToArray (lb, ub, Arr);
    PrintArray (lb, ub, Arr);

    ub = Insert (k, ub, 10, Arr);
    PrintArray (lb, ub, Arr);
    
    ub = Delete (k, ub, Arr);
    PrintArray (lb, ub, Arr);
    
    ub = Delete (1, ub, Arr);
    PrintArray (lb, ub, Arr);
    
    if (Search(lb, ub, 53, Arr) >= 0) printf ("Item found\n"); 
    else printf ("Item not found\n"); 
    
    
    return 0;
}