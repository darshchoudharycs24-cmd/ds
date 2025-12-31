#include<stdio.h>
int MAX=5;
int f=-1;
int r=-1;
int queue[5];
void enqueue(int x){
    if(r==MAX-1){
        printf("The queue is full ");
    }
    else if(f==-1&&r==-1){
        f=0;
        r=0;
        queue[r]=x;
    }
    else{
        queue[r++]=x;
    }
}
void dequeue(){
    if(f==-1){
        printf("Queue is empty");
    }
    else if(f==r){
        printf("The dequeued element is : %d",queue[f]);
        f=-1;
        r=-1;
    }
    else{
        printf("The dequeued element is : %d",queue[f]);
        f++;
    }
}
void display(){
    for(int i=f;i<=r;i++){
        printf("%d/n",queue[i]);
    }
}
int main(){
    int ch;
    printf("Enter your choice : ");
    while(ch!=4){
        scanf("%d",&ch);
        if(ch==1){
            int x;
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