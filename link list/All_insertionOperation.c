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

// Function to insert at a specific position
void insert_at_position(struct node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;

    // Inserting at the head
    if (position == 1) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct node *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If the position is greater than the number of nodes
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

int main() {
    struct node *head = NULL;
    int choice = 1, data, position;

    // Fast input: Insert nodes at the head
    printf("Enter values for the linked list (0 to stop):\n");
    while (choice) {
        printf("Enter data: ");
        scanf("%d", &data);
        insert_at_head(&head, data);

        printf("Do you want to enter another value? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    }

    // Print the current linked list
    printf("The linked list is: ");
    print_list(head);

    // Ask for the insertion point and value
    printf("Enter the value to insert: ");
    scanf("%d", &data);

    printf("Choose the insertion method:\n");
    printf("1. Insert at the head\n");
    printf("2. Insert at the tail\n");
    printf("3. Insert at a specific position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insert_at_head(&head, data);
            break;
        case 2:
            insert_at_tail(&head, data);
            break;
        case 3:
            printf("Enter the position to insert the value: ");
            scanf("%d", &position);
            insert_at_position(&head, data, position);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    // Print the linked list after insertion
    printf("The updated linked list is: ");
    print_list(head);

    // Free allocated memory
    struct node *temp = head;
    while (temp != NULL) {
        struct node* tempNode = temp;
        temp = temp->next;
        free(tempNode);  // Free each node
    }

    return 0;
}
