#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isBSTUtil(struct Node* node, int min, int max) {
    if (node == NULL) return 1;
    if (node->data < min || node->data > max)
        return 0;
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(8);

    if (isBST(root))
        printf("The tree is a BST\n");
    else
        printf("The tree is NOT a BST\n");

    return 0;
}
