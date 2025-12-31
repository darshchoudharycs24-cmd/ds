#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char c){
    if(top==MAX-1){
        printf("Stack Overflow");
    }
    else{
        stack[++top]=c;
    }
}
char pop(){
    if(top==-1){
        printf("Stack Underflow");
        return '\0';
    }
    else{
        return stack[top--];
    }
}
char peek(){
     if(top==-1){
        return '\0';
    }
    else{
        return stack[top];
    }
}
int precedence(char op){
    if(op=='^'){
        return 3;
    }
    else if(op=='*'||op=='/'){
        return 2;
    }
    else if(op=='+'||op=='-'){
        return 1;
    }
    else{
        return  0;
    }
}
int associativity(char op){
    if (op=='^'){
        return 1;
    }
    else{
        return 0;
    }
}
void infixtopostfix(char infix[],char postfix[]){
    int i,j=0;
    for(i=0;infix[i]!='\0';i++){
        char ch=infix[i];
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(peek()!='('&&top!=-1){
                postfix[j++]=pop();

            }
            pop();
        }
        else{
            while(top!=-1&&precedence(ch)<precedence(peek())||precedence(ch)==precedence(peek())&&associativity(ch)!=1&&peek()!='('){
                postfix[j++]=pop();

            }
            push(ch);
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("The postfix expression is : %s",postfix);
    return 0;
}
