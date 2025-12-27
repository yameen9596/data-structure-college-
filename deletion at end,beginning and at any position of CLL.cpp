#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Display the circular linked list
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = tail->next; // head
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Delete at beginning
struct Node* deleteAtBeginning(struct Node* tail) {
    if (tail == NULL) return NULL; // empty list

    struct Node* head = tail->next;

    if (head == tail) { // only one node
        free(head);
        return NULL;
    }

    tail->next = head->next;
    free(head);
    return tail;
}

// Delete at end
struct Node* deleteAtEnd(struct Node* tail) {
    if (tail == NULL) return NULL; // empty list

    struct Node* head = tail->next;

    if (head == tail) { // only one node
        free(tail);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next != tail)
        temp = temp->next;

    temp->next = tail->next; // point to head
    free(tail);
    tail = temp;
    return tail;
}

// Delete at any position (1-based index)
struct Node* deleteAtPosition(struct Node* tail, int pos) {
    if (tail == NULL) return NULL; // empty list

    struct Node* head = tail->next;

    if (pos == 1)
        return deleteAtBeginning(tail);

    struct Node* temp = head;
    struct Node* prev = NULL;
    int i = 1;

    while (i < pos && temp != tail) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == tail && i != pos) { // position out of bounds
        printf("Position out of bounds!\n");
        return tail;
    }

    prev->next = temp->next;

    if (temp == tail) // deleting tail
        tail = prev;

    free(temp);
    return tail;
}

// Insert at end (helper for creating list)
struct Node* insertAtEnd(struct Node* tail, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (tail == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
    return tail;
}

// Main function
int main() {
    struct Node* tail = NULL;
    int n, choice, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        tail = insertAtEnd(tail, value);
    }

    display(tail);

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
                tail = deleteAtBeginning(tail);
                break;
            case 2:
                tail = deleteAtEnd(tail);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                tail = deleteAtPosition(tail, pos);
                break;
            case 4:
                display(tail);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

