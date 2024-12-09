#include <stdio.h>
#define max_size 101
int A[max_size];
int top =-1;
void push(int x){
    if(top == max_size -1){
        printf("Error:stack overflow\n");
        return;

    }
    A[++top] =x;
}
void pop(){
    if(top == -1){
        printf("Error:no element to pop\n");
        return;
    }
    top--;

}
int Top(){
    return A[top];
}
void print(){
    int i;
    printf("stack: ");
    for(i=0;i<=top;i++)
    printf("%d",A[i]);
    printf("\n");
}
int main(){
push(2);print();
push(10);print();
push(12);print();
pop();print();
pop(2);print();
push(2);print();

}