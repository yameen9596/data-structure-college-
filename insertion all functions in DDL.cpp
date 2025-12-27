#include <stdio.h>
#include <stdlib.h>

// Define structure for Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a Doubly Linked List
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    return head;
}

// Function to display the Doubly Linked List
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("\nDoubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head != NULL){
        head->prev = newNode;
    }
        newNode->next=head;
    head = newNode;
    return head;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

/*// Insert at the end (O(1) using tail pointer)
void insertAtEnd(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = *tail;

    if (*tail != NULL)
        (*tail)->next = newNode;
    else
        *head = newNode; // list was empty

    *tail = newNode;
}
*/

// Function to insert a node at a given position
struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return head;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    else
	{
    newNode->next = temp->next;
    newNode->prev = temp;

  
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}
}
// Main Function
int main()
{
    struct Node* head = NULL;
    int n, choice, data, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n);
    displayList(head);

    while (1) {
        printf("\n--- Insertion Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtPosition(head, data, pos);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

