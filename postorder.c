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

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 25);

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
