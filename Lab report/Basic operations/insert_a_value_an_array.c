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

    int p,v;
    printf("Enter the position where you want to insert: ");
    scanf("%d", &p);
    printf("Enter the value: ");
    scanf("%d", &v);

    arr[p]=v;

    printf("New Array:");
    for(int i=lb; i<=ub; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
