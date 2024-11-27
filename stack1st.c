#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int value) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = value;
    }
}

int pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1;
}

int findAndRemove(struct Stack *stack, int value) {
    int temp[MAX], tempTop = -1, found = 0;

    while (!isEmpty(stack)) {
        int current = pop(stack);
        if (current == value && !found) {
            found = 1;
        } else {
            temp[++tempTop] = current;
        }
    }

    for (int i = tempTop; i >= 0; i--) {
        push(stack, temp[i]);
    }

    return found;
}

void display(struct Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    display(&stack);

    if (findAndRemove(&stack, 30)) {
        printf("Element 30 removed.\n");
    } else {
        printf("Element not found.\n");
    }

    display(&stack);

    return 0;
}
