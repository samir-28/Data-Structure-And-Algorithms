#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Function to get the height of a node
int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to perform a left rotation on a given AVL tree node
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y; // New root of the subtree
}

// Function to print preorder traversal of AVL tree
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Constructing the AVL tree
    root = newNode(30);
    root->left = newNode(20);
    root->right = newNode(40);
    root->left->left = newNode(10);
    root->left->right = newNode(25);

    printf("AVL tree before left rotation:\n");
    preOrder(root);
    printf("\n");

    // Perform left rotation on the root node
    root = leftRotate(root);

    printf("AVL tree after left rotation:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
