#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;   // First Linked List
struct Node* head2 = NULL;  // Second Linked List

// ---------------- FIRST LIST FUNCTIONS ----------------

void InsertAtBeginning(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    printf("Inserted in List1\n");
}

void InsertAtPosition(int val,int pos){
    struct Node* temp = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if(pos < 1){
        printf("Enter valid position\n");
        return;
    }
    else if(pos == 1){
        InsertAtBeginning(val);
        return;
    }

    for(int i = 1; i < pos-1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Position out of range\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted in List1\n");
}

void InsertAtEnd(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted in List1\n");
}

void DeleteAtFirst() {
    if (head == NULL) {
        printf("List1 is Empty\n");
        return;
    }

    struct Node* temp = head;
    head = temp->next;
    printf("Deleted value: %d\n", temp->data);
    free(temp);
}

void DeleteAValue(int val) {
    if (head == NULL) {
        printf("List1 is Empty\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp->data == val) {
        head = temp->next;
        printf("Deleted value: %d\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted value: %d\n", temp->data);
    free(temp);
}

void DeleteAtLast() {
    if (head == NULL) {
        printf("List1 is Empty\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted value: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted value: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void reverse() {
    struct Node* prev = NULL;
    struct Node* nxt = NULL;
    struct Node* curr = head;

    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    head = prev;
    printf("List1 Reversed Successfully\n");
}

void display(){
    struct Node* temp = head;

    if(head == NULL){
        printf("List1 is Empty\n");
        return;
    }

    printf("List1: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("End\n");
}


// ---------------- SECOND LIST FUNCTIONS ----------------

void InsertAtEnd2(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head2 == NULL) {
        head2 = newNode;
        return;
    }

    struct Node* temp = head2;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("Inserted in List2\n");
}

void display2(){
    struct Node* temp = head2;

    if(head2 == NULL){
        printf("List2 is Empty\n");
        return;
    }

    printf("List2: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("End\n");
}


// ---------------- CONCATENATE FUNCTION ----------------

void concatenate() {

    if (head == NULL) {
        head = head2;
        head2 = NULL;
        printf("List2 concatenated to empty List1\n");
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;
    head2 = NULL;
    printf("Lists concatenated successfully\n");
}


// ---------------- MAIN PROGRAM ----------------

int main(){
    int data;
    printf("Enter first value to create List1: ");
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    head = newNode;

    int ch = 0;

    while(ch != 12){
        printf("\nEnter Choice\n"
               "1.Insert at start (List1)\n"
               "2.Insert at position (List1)\n"
               "3.Insert at end (List1)\n"
               "4.Delete at first (List1)\n"
               "5.Delete a value (List1)\n"
               "6.Delete at last (List1)\n"
               "7.Reverse List1\n"
               "8.Display List1\n"
               "9.Insert at end (List2)\n"
               "10.Display List2\n"
               "11.Concatenate List1 + List2\n"
               "12.Exit\n");

        scanf("%d", &ch);

        if(ch == 1){
            int val;
            printf("Enter value: ");
            scanf("%d", &val);
            InsertAtBeginning(val);
        }
        else if(ch == 2){
            int val, pos;
            printf("Enter value and position: ");
            scanf("%d %d", &val, &pos);
            InsertAtPosition(val, pos);
        }
        else if(ch == 3){
            int val;
            printf("Enter value: ");
            scanf("%d", &val);
            InsertAtEnd(val);
        }
        else if(ch == 4){
            DeleteAtFirst();
        }
        else if(ch == 5){
            int val;
            printf("Enter value to delete: ");
            scanf("%d", &val);
            DeleteAValue(val);
        }
        else if(ch == 6){
            DeleteAtLast();
        }
        else if(ch == 7){
            reverse();
        }
        else if(ch == 8){
            display();
        }
        else if(ch == 9){
            int val;
            printf("Enter value for List2: ");
            scanf("%d", &val);
            InsertAtEnd2(val);
        }
        else if(ch == 10){
            display2();
        }
        else if(ch == 11){
            concatenate();
        }
    }
}
