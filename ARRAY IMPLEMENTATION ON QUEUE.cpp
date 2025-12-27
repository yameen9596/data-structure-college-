#include <stdio.h>

#define SIZE 5   // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full (Overflow)\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty (Underflow)\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
        // Reset queue when all elements are dequeued
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Operations ---\n");
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
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

