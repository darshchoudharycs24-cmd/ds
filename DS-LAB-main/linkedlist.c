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
        printf("Enter vald position\n");
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
void display(){
    struct Node* temp=head;
    if(head==NULL){
        printf("Empty");
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
    printf("Enter first value to create Linked List : ");
    scanf("%d",&data);
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    head=newNode;
    int ch;
    while(ch!=5){
        printf("Enter Choice 1.Insert at start 2.Insert at position 3.Insert at end 4.Display 5.Exit");
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
        else{
            display();
        }
    }



