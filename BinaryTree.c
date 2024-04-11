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

// Function to insert nodes recursively
struct Node* insertNode(int arr[], struct Node* root, int i, int n) {
    // Base case for recursion
    if (i < n) {
        struct Node* temp = newNode(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertNode(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertNode(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to print tree in inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Creating the binary tree
    struct Node* root = insertNode(arr, root, 0, n);

    // Printing the tree in inorder traversal
    printf("Inorder traversal of the constructed binary tree: \n");
    inorder(root);
    printf("\n");

    return 0;
}
