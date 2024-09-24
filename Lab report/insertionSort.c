#include <stdio.h>

int main() {
int ar[100]; int n,temp;
printf("Enter the size of aray:"); scanf("%d",&n);

for(int i=0; i<n; i++){ scanf("%d",&ar[i]);
}

for (int i = 1; i < n; i++) { int v = ar[i];
int j = i - 1;

while (j >= 0 && ar[j] > v) { ar[j + 1] = ar[j];
j--;
}
ar[j + 1] = v;
}

printf("Sorted array: \n"); for (int i = 0; i < n; i++) {
printf("%d ", ar[i]);
}

return 0;
}
