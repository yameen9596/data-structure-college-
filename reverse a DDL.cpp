#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;  // Global head pointer

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Display DLL
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse DLL
void reverseDLL() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = NULL;
    struct Node *current = head;

    while (current != NULL) {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is prev after swap)
        current = current->prev;
    }

    // Adjust head to the new first node
    if (temp != NULL)
        head = temp->prev;

    printf("Doubly Linked List reversed.\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Display\n");
        printf("2. Reverse DLL\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        
            case 1:
                display();
                break;
            case 2:
                reverseDLL();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

