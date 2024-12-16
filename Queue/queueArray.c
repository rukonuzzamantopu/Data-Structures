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
    if (rear == N - 1) {
        printf("overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("underflow\n");
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("nothing in queue\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("nothing in queue\n");
    } else {
        printf("%d\n", queue[front]);
    }
}
