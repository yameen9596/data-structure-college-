#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to create doubly circular linked list
struct Node* createList(int n, struct Node **tail) {
    struct Node *head = NULL, *newNode;
    int data, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            *tail = head;
        } else {
            newNode->prev = *tail;
            newNode->next = head;
            (*tail)->next = newNode;
            head->prev = newNode;
            *tail = newNode;
        }
    }
    return head;
}

// Display list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("\nDoubly Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Delete at beginning
struct Node* deleteAtBeginning(struct Node *head, struct Node **tail) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    // Only one node
    if (head->next == head) {
        free(head);
        *tail = NULL;
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    head->prev = *tail;
    (*tail)->next = head;
    free(temp);
    return head;
}

// Delete at end
struct Node* deleteAtEnd(struct Node *head, struct Node **tail) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    // Only one node
    if (head->next == head) {
        free(head);
        *tail = NULL;
        return NULL;
    }

    struct Node *temp = *tail;
    (*tail) = (*tail)->prev;
    (*tail)->next = head;
    head->prev = *tail;
    free(temp);
    return head;
}

// Delete at any position (1-based)
struct Node* deleteAtPosition(struct Node *head, struct Node **tail, int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    // If deleting first node
    if (pos == 1)
        return deleteAtBeginning(head, tail);

    struct Node *temp = head;
    int i = 1;

    while (i < pos && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (i < pos) {
        printf("Invalid position!\n");
        return head;
    }

    // If deleting last node
    if (temp == *tail)
        return deleteAtEnd(head, tail);

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return head;
}

// Main
int main() {
    struct Node *head = NULL, *tail = NULL;
    int n, choice, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n, &tail);

    display(head);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Delete at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Delete at Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = deleteAtBeginning(head, &tail);
                break;
            case 2:
                head = deleteAtEnd(head, &tail);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, &tail, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

