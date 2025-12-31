#include<stdio.h>
int top=-1;
int N;
int *stack;
void push(int x){
    if(top==N-1){
        printf("\nStack Overflow");
    }
    else{
        stack[++top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("\nStack Underflow");
    }
    else{
        printf("%d",stack[top--]);
    }
}
void peek(){
    if(top==-1){
        printf("\n stack is empty");
    }
    printf("%d",stack[top]);
}
void display(){
    if(top==-1){
        printf("\nStack empty");
    }
    else{
        for(int i=top;i<=0;i--){
            printf("\nThe stack elements are : %d",stack[i]);
        }
    }
}
int main(){
printf("Enter the size of the stack : ");
scanf("%d",&N);
int stack_array[N];
stack=stack_array;
int ch=0;
while(ch!=5){
    printf("\n Enter the choice 1. push, 2. pop ,3.peek, 4.display, 5.exit ");
    scanf("%d",&ch);
    if(ch==1){
         int x;
         printf("Enter the element to push : ");
         scanf("%d",&x);
         push(x);
}
    else if(ch==2){
         pop();
}
    else if(ch==3){
         peek();
}
    else if(ch==4){
        display();
    }

}
return 0;
}

