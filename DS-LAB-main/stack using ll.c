#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;   // Stack top pointer

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if (top==NULL) {
        newNode->next=NULL;
        top=newNode;
    }
    else {
        newNode->next=top;
        top=newNode;
    }

}

void pop() {
    if (top==NULL) {
        printf("Empty");
        return;
    }
    struct Node* temp=top;
    printf("The popped element is : %d ",top->data);
    top=top->next;
    free(temp);
}


void displayStack() {
    struct Node* temp = top;

    if (temp == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, val;

    while (1) {
        printf("\nSTACK MENU\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;


            case 3:
                displayStack();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
}
