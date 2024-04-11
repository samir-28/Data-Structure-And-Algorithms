#include <stdio.h>
#include <stdlib.h>

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

// Function to calculate the height of the binary tree
int height(struct Node* root) {
    // Base case: If tree is empty, return 0
    if (root == NULL)
        return 0;
    
    // Calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return the maximum of left and right subtree heights, plus 1 for the root
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    // Constructing the binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Calculating the height of the binary tree
    int treeHeight = height(root);

    printf("Height of the binary tree is: %d\n", treeHeight);

    return 0;
}
