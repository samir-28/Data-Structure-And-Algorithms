#include <stdio.h>
#include <stdlib.h>

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

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        // If the tree is empty, create a new node as the root
        return createNode(data);
    }

    // Otherwise, traverse the tree to find the appropriate position to insert the new node
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to find the maximum element in a BST
int findMax(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1; // Assuming -1 represents an empty tree
    }

    // Keep traversing to the right until the rightmost node is found
    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

// Function to find the minimum element in a BST
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return -1; // Assuming -1 represents an empty tree
    }

    // Keep traversing to the left until the leftmost node is found
    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Finding the maximum and minimum elements in the BST
    int max = findMax(root);
    int min = findMin(root);

    if (max != -1) {
        printf("Maximum element in the BST: %d\n", max);
    }

    if (min != -1) {
        printf("Minimum element in the BST: %d\n", min);
    }

    return 0;
}
