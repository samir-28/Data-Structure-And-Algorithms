#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a structure for tree nodes
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the maximum element in a binary tree
int findMax(struct Node* root) {
    // Base case: If tree is empty, return INT_MIN
    if (root == NULL)
        return INT_MIN;
    
    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    // Compare max with leftMax and rightMax
    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;

    return max;
}

int main() {
    // Constructing the binary tree
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->right->left = newNode(15);
    root->right->right = newNode(25);

    // Finding the maximum element in the binary tree
    int maxElement = findMax(root);

    printf("Maximum element in the binary tree is: %d\n", maxElement);

    return 0;
}
