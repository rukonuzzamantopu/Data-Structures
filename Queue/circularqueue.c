#include <stdio.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

// Function prototypes
void enqueue(int x);
void dequeue();
void display();
void peek();

int main() {
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();

    return 0;
}

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } 
    else if(((rear +1)%N)==front){
        printf("queue is full");

    } else {
        rear =(rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("underflow\n");
    } else if (front == rear) {
        front = rear -1;
    } else {
        front =(front +1)%N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("nothing in queue\n");
    } else {
        for (int i = front; i != rear; i=(i+1)%N) {
            printf("%d ", queue[i]);
        }
        printf("%d\n",queue[rear]);
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("nothing in queue\n");
    } else {
        printf("%d\n", queue[front]);
    }
}
