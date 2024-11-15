#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1, new_data;

    // Fast input: Insert nodes at the head
    printf("Enter values for the linked list (0 to stop):\n");
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return -1;  // Exit if memory allocation fails
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = head;  // Link the new node to the current head
        head = newnode;  // Move the head to the new node

        printf("Do you want to enter another value? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    }

    // Print the linked list
    printf("The linked list is: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Input a value to insert at the front (head) of the linked list
    printf("Enter a value to insert at the front of the list: ");
    scanf("%d", &new_data);

    // Insert the new data at the front of the list
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    newnode->data = new_data;
    newnode->next = head;  // Link the new node to the current head
    head = newnode;  // Move the head to the new node

    // Print the linked list after insertion
    printf("The updated linked list is: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free allocated memory
    temp = head;
    while (temp != NULL) {
        struct node* tempNode = temp;
        temp = temp->next;
        free(tempNode);  // Free each node
    }

    return 0;
}
