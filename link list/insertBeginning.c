#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to insert a new node at the beginning of the linked list
void insert_at_beginning(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

// Function to print the linked list elements
void print_list() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The linked list elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice = 1, value;

    while (choice) {
        printf("Enter the value to insert at the beginning: ");
        scanf("%d", &value);
        insert_at_beginning(value);

        printf("Do you want to insert another value (0 for no, 1 for yes)? ");
        scanf("%d", &choice);
    }

    // Print the linked list
    print_list();

    return 0;
}
