#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to display the doubly linked list in forward direction
void displayForward(struct Node* head) {
    printf("Doubly Linked List (Forward): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to display the doubly linked list in reverse direction
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("Doubly Linked List (Backward): List is empty\n");
        return;
    }

    // Traverse to the end of the list to get the tail
    while (head->next != NULL) {
        head = head->next;
    }

    printf("Doubly Linked List (Backward): ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}


// Function to free the memory allocated for the doubly linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    // Display the doubly linked list
    displayForward(head);
    displayBackward(head);

    // Free the memory
    freeList(head);

    return 0;
}