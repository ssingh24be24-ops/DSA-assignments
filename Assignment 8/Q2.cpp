#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Search (Recursive)
struct Node* searchRecursive(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// Search (Non-Recursive)
struct Node* searchIterative(struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return NULL;
}

// Minimum element
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Maximum element
struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Inorder successor
struct Node* inorderSuccessor(struct Node* root, struct Node* node) {
    if (node->right != NULL)
        return findMin(node->right);
    struct Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

// Inorder predecessor
struct Node* inorderPredecessor(struct Node* root, struct Node* node) {
    if (node->left != NULL)
        return findMax(node->left);
    struct Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    struct Node* temp = searchRecursive(root, 40);
    printf("\nSearch (Recursive): %s", temp ? "Found" : "Not Found");

    temp = searchIterative(root, 90);
    printf("\nSearch (Iterative): %s", temp ? "Found" : "Not Found");

    printf("\nMinimum: %d", findMin(root)->data);
    printf("\nMaximum: %d", findMax(root)->data);

    struct Node* node = searchRecursive(root, 60);
    struct Node* succ = inorderSuccessor(root, node);
    struct Node* pred = inorderPredecessor(root, node);

    printf("\nInorder Successor of %d: %d", node->data, succ ? succ->data : -1);
    printf("\nInorder Predecessor of %d: %d\n", node->data, pred ? pred->data : -1);

    return 0;
}
