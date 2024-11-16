#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to print the linked list
void print_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert at the head
void insert_at_head(struct node **head, int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

// Function to insert at the tail
void insert_at_tail(struct node **head, int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    
    if (*head == NULL) {
        *head = newnode;  // If the list is empty, the new node becomes the head
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;  // Link the last node to the new node
}

// Function to delete a node at the head
void delete_at_head(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;  // Move head to the next node
    free(temp);             // Free the old head
    printf("Node at the head deleted\n");
}

// Function to delete a node at the tail
void delete_at_tail(struct node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = *head;

    // If there's only one node
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        printf("Node at the tail deleted\n");
        return;
    }

    // Traverse to the second-to-last node
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;  // Remove the last node
    free(temp);         // Free the last node
    printf("Node at the tail deleted\n");
}

// Function to delete a node at a specific position
void delete_at_position(struct node **head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or list is empty\n");
        return;
    }

    struct node *temp = *head;

    // Deleting the head node
    if (position == 1) {
        *head = temp->next;  // Move head to the next node
        free(temp);          // Free the old head node
        printf("Node at position %d deleted\n", position);
        return;
    }

    // Traverse to the node before the one to delete
    struct node *prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If the position is greater than the number of nodes
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;  // Unlink the node
    free(temp);               // Free the node
    printf("Node at position %d deleted\n", position);
}

// Function to delete the first node with a specific value
void delete_by_value(struct node **head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = *head;

    // If the head node holds the value
    if (temp->data == value) {
        *head = temp->next;  // Move head to the next node
        free(temp);          // Free the old head
        printf("Node with value %d deleted\n", value);
        return;
    }

    // Traverse the list to find the node with the value
    struct node *prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value is not found
    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    // Unlink the node and free it
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted\n", value);
}

int main() {
    struct node *head = NULL;
    int choice, data, position;

    // Insert nodes for testing
    printf("Enter values for the linked list (0 to stop):\n");
    while (1) {
        printf("Enter data: ");
        scanf("%d", &data);
        if (data == 0) break;
        insert_at_tail(&head, data);
    }

    // Print the linked list
    printf("The linked list is: ");
    print_list(head);

    // Menu for delete operations
    while (1) {
        printf("\nChoose a delete operation:\n");
        printf("1. Delete at the head\n");
        printf("2. Delete at the tail\n");
        printf("3. Delete at a specific position\n");
        printf("4. Delete by value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                delete_at_head(&head);
                break;
            case 2:
                delete_at_tail(&head);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete_at_position(&head, position);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                delete_by_value(&head, data);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }

        // Print the updated linked list
        printf("The updated linked list is: ");
        print_list(head);
    }

    return 0;
}
