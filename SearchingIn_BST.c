#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for tree nodes
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Forward declaration of the searchValue function
bool searchValue(struct Node* root, int value);

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

// Function to search for a value in the BST
bool searchValue(struct Node* root, int value) {
    if (root == NULL) {
        // If the tree is empty or the value is not found, return false
        return false;
    }

    // If the value matches the data of the current node, return true
    if (root->data == value) {
        return true;
    }

    // Recursively search in the left subtree if the value is less than the current node's data
    if (value < root->data) {
        return searchValue(root->left, value);
    }

    // Recursively search in the right subtree if the value is greater than the current node's data
    if (value > root->data) {
        return searchValue(root->right, value);
    }

    return false; // Value not found
}

// Function to perform inorder traversal and print the BST
void printBST(struct Node* root) {
    if (root != NULL) {
        printBST(root->left);
        printf("%d ", root->data);
        printBST(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Display the BST
    printf("Binary Search Tree (Inorder Traversal): ");
    printBST(root);
    printf("\n");

    // Ask the user for the value to search
    int value;
    printf("Enter the value you want to search for: ");
    scanf("%d", &value);

    // Searching for the value in the BST
    if (searchValue(root, value)) {
        printf("Value %d is present in the BST.\n", value);
    } else {
        printf("Value %d is not present in the BST.\n", value);
    }

    return 0;
}
