#include<stdio.h>
int main()
{
    int arr[100];
    int lb, ub;
    printf("Enter the Lower Bound & Upper Bound of the array:\n");
    scanf("%d %d", &lb, &ub);

    int i;
    printf("Input the values of array:\n");
    for(i=lb; i<=ub; i++){
        scanf("%d",&arr[i]);
    }

    printf("Array:");
    for(int i=lb; i<=ub; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int p;
    printf("Enter the position you want to delete: ");
    scanf("%d", &p);

    int j;
    for (j=p; j<=ub; j++) {
        arr[j] = arr[j+1];
    }
    ub--;

    printf("New Array:");
    for(int i=lb; i<=ub; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
