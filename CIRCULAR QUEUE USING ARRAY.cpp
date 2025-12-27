#include <stdio.h>

#define SIZE 5   // Maximum size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to add an element to the circular queue
void enqueue(int value) {
    // Check for overflow condition
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue is full (Overflow)\n");
        return;
    }

    // First element insertion
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    queue[rear] = value;
    printf("%d inserted into the circular queue.\n", value);
}

// Function to remove an element from the circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty (Underflow)\n");
        return;
    }

    printf("%d deleted from the circular queue.\n", queue[front]);

    // If the queue now becomes empty
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

// Function to display the circular queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

