#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// a) Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// b) Insert to the left of a node with given value
void insertLeft(int value, int newData) {
    struct Node* temp = head;

    // search for the node
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    struct Node* newNode = createNode(newData);

    // inserting at the beginning (left of head)
    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // inserting in the middle
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;

    printf("Inserted %d to the left of %d\n", newData, value);
}

// c) Delete a node by value
void deleteNode(int value) {
    struct Node* temp = head;

    // search the node
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    // deleting the only node
    if (temp->prev == NULL && temp->next == NULL) {
        head = NULL;
    }
    // deleting head node
    else if (temp == head) {
        head = temp->next;
        head->prev = NULL;
    }
    // deleting last node
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    // deleting middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    printf("Deleted %d\n", value);
    free(temp);
}

// d) Display the list
void display() {
    struct Node* temp = head;
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

// a) Create doubly linked list (append at end)
void createList(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    int choice, value, newData;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create Node\n");
        printf("2. Insert to Left of Node\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            createList(value);
            break;

        case 2:
            printf("Enter value of node to insert left of: ");
            scanf("%d", &value);
            printf("Enter new node value: ");
            scanf("%d", &newData);
            insertLeft(value, newData);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
