#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL; // top pointer for the stack

void push(int value);
void pop();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Implementation Using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to push an element onto the stack
void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Overflow check (malloc fails)
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    struct Node *temp;

    // Underflow check
    if (top == NULL) {
        printf("Stack Underflow! No element to pop.\n");
        return;
    }

    temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}

// Function to display stack elements
void display() {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

