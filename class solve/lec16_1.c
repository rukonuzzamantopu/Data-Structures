#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#define N 5

int queue [N];
int front = -1;
int rear = -1;

bool isFull () {
    if ((rear + 1) % N == front) return true;
    else return false;
}

bool isEmpty () {
    if (front == -1 && rear == -1) return true;
    else return false;
}

void insert_rear (int item) {
    if (isFull())
        printf ("Queue is full\n");
    else if (isEmpty()) {
        front = rear = 0;
        queue[rear] = item;
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = item;
    }
}

void insert_front (int item) {
    if (isFull())
        printf ("Queue is full\n");
    else if (isEmpty()) {
        front = rear = 0;
        queue[rear] = item;
    }
    else {
        front = (front - 1 + N) % N;
        queue[front] = item;
    }
}

void delete_front () {
    if (isEmpty()) 
        printf ("Queue is empty\n");
    else if (front == rear)
        front = rear = -1;
    else 
        front = (front + 1) % N;
}

void delete_rear () {
    if (isEmpty()) 
        printf ("Queue is empty\n");
    else if (front == rear)
        front = rear = -1;
    else 
        rear = (rear - 1 + N) % N;
}

int peek () {
    assert (isEmpty());
    return queue[front];
}

void display () {
    if (isEmpty()) return;
    
    int i = front;
    while (i != rear + 1) {
        printf ("%d ",  queue[i]);
        i = (i + 1) % N;
    }
    
    printf ("\n");
}

int main () {
    insert_rear(5);
    insert_rear(10);
    display();
    insert_front(3);
    insert_front(7);
    display();
    delete_front();
    display();
    delete_rear();
    display();
    return 0;
}