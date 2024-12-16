#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("underflow\n");
    } else {
        temp = front;
        front = front->next;
        free(temp);

        // If the queue becomes empty, reset `rear` to NULL as well
        if (front == NULL) {
            rear = NULL;
        }
    }
}

void display() {
    struct node *temp;
    if (front == NULL) {
        printf("nothing in queue\n");
    } else {
        temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek() {
    if (front == NULL) {
        printf("nothing in queue\n");
    } else {
        printf("%d\n", front->data);
    }
}

int main() {
    enqueue(5);
    enqueue(6);
    enqueue(-2);
    display();    // Output: 5 6 -2
    dequeue();    // Removes 5
    peek();       // Output: 6
    display();    // Output: 6 -2

    return 0;
}
