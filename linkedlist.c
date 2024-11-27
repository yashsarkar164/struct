#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int n){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=n;
    newNode->next=top;
    top = newNode;
}

void pop(){
    if(top==NULL){
        printf("Underflow");
    }
    else{
        struct Node* temp = top;
        printf("The popped value is : ",top->data);
        top = top->next;
        free(temp);
    }
}

void display(){
    if(top==NULL){
        printf("Empty");
    }
    else{
        struct Node* temp = top;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    display();

    push(10);
    push(20);
    push(30);

    display();
    pop();
    
    display();


    return 0;
}