#include<stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void InsertAtBeginning(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if (head==NULL) {
        newNode->next=NULL;
        head=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
    printf("Inserted \n");


}
void InsertAtPosition(int val,int pos){
    struct Node* temp=head;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(pos<1){
        printf("Enter valid position\n");
    }
    else if(pos==1){
        InsertAtBeginning(val);
    }
    else{
        for(int i=1;i<pos-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            printf("Position out of range\n");
        }
        else{
            newNode->next=temp->next;
            temp->next=newNode;
            printf("Inserted Succesfully\n");
        }

    }
}
void InsertAtEnd(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    printf("Inserted Succesfully\n");

}
void DeleteAtFirst() {
    if (head==NULL) {
        printf("Empty");
        return;
    }

    struct Node* temp=head;
    head=temp->next;
    printf("The deleted value is : %d\n",temp->data);
    free(temp);
}
void DeleteAValue(int val) {
    struct Node* prev=NULL;
    struct Node* temp=head;
    while (temp->data!=val) {
        prev=temp;
        temp=temp->next;

    }
    prev->next=temp->next;
    printf("The deleted value is : %d\n",temp->data);
    free(temp);
}
void DeleteAtLast() {
    if (head==NULL) {
        printf("Empty Linked List");
        return;
    }
    else if (head->next==NULL) {
        printf("The deleted value is : %d\n",head->data);
        free(head);
        return;
    }
    struct Node* prev=NULL;
    struct Node* temp=head;
    while (temp->next!=NULL) {
        prev=temp;
        temp=temp->next;
    }
    printf("The deleted value is : %d\n",temp->data);
    prev->next=NULL;
    free(temp);

}
void display(){
    struct Node* temp=head;
    if(head==NULL){
        printf("\nEmpty\n");
    }
    else{
        while(temp!=NULL){
            printf(" %d-> ",temp->data);
            temp=temp->next;
        }
        printf("End\n");

    }
}
int main(){
    int data;
    printf("Enter first value to create Linked List :  ");
    scanf("%d",&data);
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    head=newNode;
    int ch=0;
    while(ch!=8){
        printf("Enter Choice\n 1.Insert at start\n 2.Insert at position\n 3.Insert at end\n 4.Delete at first\n 5.Delete a value\n 6.Delete at last\n 7.Display\n 8.Exit\n");
        scanf("%d",&ch);
        if(ch==1){
            int val;
            printf("Enter value : ");
            scanf("%d",&val);
            InsertAtBeginning(val);
        }
        else if(ch==2){
            int val;
            int pos;
            printf("Enter value and position : ");
            scanf("%d %d",&val,&pos);
            InsertAtPosition(val,pos);
        }
        else if(ch==3){
            int val;
            printf("Enter value : ");
            scanf("%d",&val);
            InsertAtEnd(val);
        }
        else if (ch==4) {
            DeleteAtFirst();
        }
        else if (ch==5) {
            int val;
            printf("Enter the value to delete : ");
            scanf("%d",&val);
            DeleteAValue(val);
        }
        else if (ch==6) {
            DeleteAtLast();
        }
        else if (ch==7){
            display();

        }



    }
}
