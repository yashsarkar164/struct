#include<stdio.h>
#define MAX 7
int queue[MAX] , front = -1 , rare = -1;

void enqueue(int n){
    if(rare == MAX-1){
        printf("Overflow");
    }
    else{
        if(front==-1){
            front = 0;
        }
        queue[++rare]=n;
    }
}

void dequeue(){
    if(front == -1 || front > rare){
        printf("Underflow");
        front = rare = -1;
    }
    else{
        front++;
    }
}

void display(){
    if(front==-1||front>rare){
        printf("Empty");
    }
    printf("Queue elements : ");
    for(int i = front; i<=rare ;i++){
        printf("%d \n",queue[i]);
    }
}

int main(){
    // display();

    enqueue(10);
    enqueue(20);
    enqueue(30);

    // dequeue();
    display();

    enqueue(100);
    // display();

    return 0;
}