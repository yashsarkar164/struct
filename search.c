#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *insert(struct Node *root, int x) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    if (root == NULL)
        root = temp;
    else if (root->data >= x)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

int search(struct Node *root, int data) {
    if (root == NULL)
        return 0;
    else if (root->data == data)
        return 1;
    else if (root->data >= data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int main() {
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 25);

    if (search(root, 25))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
