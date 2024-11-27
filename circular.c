#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Size of the circular queue

struct CircularQueue {
    int arr[MAX];
    int front;
    int rear;
};

void initializeQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct CircularQueue *queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

int isEmpty(struct CircularQueue *queue) {
    return queue->front == -1;
}

void enqueue(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {  // Only one element was in the queue
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    printf("Dequeued %d\n", value);
    return value;
}

void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->arr[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    display(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display(&queue);

    enqueue(&queue, 60);
    enqueue(&queue, 70);

    display(&queue);

    return 0;
}
