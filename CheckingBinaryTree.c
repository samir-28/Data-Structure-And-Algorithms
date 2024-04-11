#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for tree nodes
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert nodes recursively
struct Node *insertNode(int arr[], struct Node *root, int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        struct Node *temp = newNode(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertNode(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertNode(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to calculate the height of the binary tree
int height(struct Node *root)
{
    // Base case: If tree is empty, return 0
    if (root == NULL)
        return 0;

    // Calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return the maximum of left and right subtree heights, plus 1 for the root
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to check if the binary tree is balanced
bool isBalanced(struct Node *root)
{
    // Base case: If tree is empty, return true
    if (root == NULL)
        return true;

    // Calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Check if the absolute difference in heights of left and right subtrees is not more than 1
    // Also, check recursively if left and right subtrees are balanced
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    // If any of the conditions fail, return false
    return false;
}

// Function to print tree in inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Creating the binary tree
    struct Node *root = insertNode(arr, root, 0, n);

    // Printing the tree in inorder traversal
    printf("Inorder traversal of the constructed binary tree: \n");
    inorder(root);
    printf("\n");

    // Checking if the binary tree is balanced
    if (isBalanced(root))
        printf("The binary tree is balanced.\n");
    else
        printf("The binary tree is not balanced.\n");

    return 0;
}
