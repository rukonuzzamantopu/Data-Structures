#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define SZ 5

struct Node {
    int element;
    int priority;
};

int rear = -1;
struct Node PQ[SZ];

bool isEmpty () {
    if (rear == -1) return true;
    return false;
}

bool isFull () {
    if (rear == SZ - 1) return true;
    return false;
}

int getHighestPriority () {
    int p = -1;
    
    if (!isEmpty()) {
        for (int i = 0; i < rear + 1; i++) {
            if (PQ[i].priority > p) 
                p = PQ[i].priority;
        }
    }
    return p;
}

void enqueue (int ele, int p) {
    if (!isFull()) {
        rear += 1;
        PQ[rear].element = ele;
        PQ[rear].priority = p;
    }
}

void dequeue () {
    int i;
    int p = getHighestPriority ();
    
    if (p < 0) return;
    
    for (i = 0; i < rear + 1; i++) {
        if (p == PQ[i].priority) break;
    }
    
    if (i < rear) {
        for (int j = i; j < rear; j++) {
            PQ[j].element = PQ[j+1].element;
            PQ[j].priority = PQ[j+1].priority;
        }
    }
    rear -= 1;
}

void display () {
    if (isEmpty()) return;
    printf ("Priority Queue\n");
    for (int i = 0; i < rear + 1; i++) 
        printf ("(%d, %d)\n", PQ[i].element, PQ[i].priority);
}

int peek () {
    int ele;
    int p = getHighestPriority();
    
    if (!isEmpty()) {
        for (int i = 0; i < rear + 1; i++) {
            if (p == PQ[i].priority) {
                ele = PQ[i].element;
                return ele;
            }
        }
    }
}

int main () {
    enqueue (9, 1);
    enqueue (12, 3);
    enqueue (5, 2);
    display ();
    dequeue ();
    display ();
    dequeue ();
    display ();
    enqueue (8, 4);
    display ();
    dequeue ();
    display ();
    
    return 0;
}
