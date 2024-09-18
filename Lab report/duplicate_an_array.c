#include <stdio.h>
int main() {
    int arr[100];
    int lb, ub;

    printf("Enter the Lower Bound & Upper Bound of the array:\n");
    scanf("%d %d", &lb, &ub);

    printf("Input the values of the array:\n");
    for (int i = lb; i <= ub; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray: ");
    for (int i = lb; i <= ub; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int duplicate[100]={0};
    for (int i = lb; i <= ub; i++) {
        for (int j = lb; j <= ub; j++) {
            if (i==j) {
                break;
            }
            else if(arr[i]==arr[j]){
                duplicate[i] = 1;
            }            
        }        
    }

    int sum =0;
    for(int i=lb;i<=ub;i++){
            sum +=duplicate[i];
        
    }
    printf("Total number of duplicate elements: %d\n", sum);

    return 0;
}
