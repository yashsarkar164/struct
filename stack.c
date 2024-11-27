#include<stdio.h>
#define MAX 7
int stack[MAX],top = -1;

void push(int n){
    if(top == MAX-1){
        printf("Stack Overflow");
    }
    else{
        stack[++top]=n;
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        printf("The poped element is %d",stack[top]);
        top--;
    }
}

void display(){
    if(top == -1){
        printf("No element in the stack");
    }
    else{
        printf("Stack Elements are : ");
        for(int i = 0; i <= top ; i++){
            printf("%d \n",stack[i]);
        }
    }
}

int main(){
    printf("Stack Operation : \n");

    // display();
    push(10);
    push(20);
    push(30);
    pop();

    // display();
    push(100);
    display();
    
    return 0;

}