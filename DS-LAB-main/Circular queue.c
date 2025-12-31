#include<stdio.h>
int f=-1;
int r=-1;
int queue[5];
void enqueue(int x){
    if(f==-1&&r==-1){
        f=0;
        r=0;
        queue[r]=x;
    }
    else if(f==(r+1)%5){
        printf("Queue is full");
    }
    else{
        r=(r+1)%5;
        queue[r]=x;
    
    }
}
void dequeue(){
    if(r==-1&&f==-1){
        printf("queue is empty");

    }
    else if(f==r){
        printf("The dequeued element is : %d",queue[f]);
        r=0;
        f=0;
    }
    else{
        printf("The dequeued element is : %d",queue[f]);
        f=(f+1)%5;
    }
}
void display(){
    if(f==-1&&r==-1){
        printf("queue is empty");

    }
    int i=0;
    while(i<(r+1)%5){
        printf("%d\n",queue[i]);
        i=(i+1)%5;
    }
}
int main(){
    int ch;
    printf("Enter your choice : ");
    while(ch!=4){
        scanf("%d",&ch);
        if(ch==1){
            int x;
            printf("Enter element to enqueue");
            scanf("%d",&x);
            enqueue(x);
        }
        else if(ch==2){
            dequeue();
        }
        else{
            display();
        }
    }
    printf("DONE");
}