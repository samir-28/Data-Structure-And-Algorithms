#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for tree nodes
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform inorder traversal of the tree and check if it's a BST
bool isBSTUtil(struct Node* root, int* prev) {
    // Base case: empty tree is a BST
    if (root == NULL) {
        return true;
    }

    // Check the left subtree
    if (!isBSTUtil(root->left, prev)) {
        return false;
    }

    // Check current node
    if (root->data <= *prev) {
        return false;
    }

    // Update previous value
    *prev = root->data;

    // Check the right subtree
    return isBSTUtil(root->right, prev);
}

// Function to check if the tree is a BST
bool isBST(struct Node* root) {
    int prev = -1; // Initialize previous value to an invalid value
    return isBSTUtil(root, &prev);
}

int main() {
    // Constructing the binary tree
    struct Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    // Checking if the tree is a BST
    if (isBST(root)) {
        printf("The tree is a Binary Search Tree (BST).\n");
    } else {
        printf("The tree is not a Binary Search Tree (BST).\n");
    }

    return 0;
}
