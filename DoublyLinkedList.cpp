#include <iostream>
#include <cstdlib>

using namespace std;

// Structure to represent a node in the doubly linked list
struct Node {
    int data;        // Data of the node
    Node* prev;      // Pointer to the previous node
    Node* next;      // Pointer to the next node
};

Node* head = nullptr; // Global variable to store the head of the linked list

// Function to create a doubly linked list from an array of elements
void createList(int arr[], int size) {
    head = nullptr; // Ensure the head is initially null

    // Iterate through the array to create and link the nodes
    for (int i = 0; i < size; i++) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = arr[i];     // Assign the data to the new node
        newNode->prev = nullptr;    // Set the previous pointer to null

        if (head == nullptr) {
            head = newNode; // If the list is empty, the new node becomes the head
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next; // Traverse to the last node
            }
            current->next = newNode;    // Link the new node to the last node
            newNode->prev = current;    // Set the previous pointer of the new node
        }
    }
}

// Function to print the elements of the doubly linked list
void printListElements() {
    Node* current = head; // Pointer to traverse the list
    cout << "Elements: [";
    while (current != nullptr) {
        cout << " " << current->data; // Print the data of the current node
        current = current->next;      // Move to the next node
    }
    cout << " ]" << endl;
}

// Function to insert a new element at the end of the doubly linked list
void insertAtEnd(int value) {
    Node* newNode = new Node();   // Create a new node
    newNode->data = value;        // Assign the data to the new node
    newNode->next = nullptr;      // Set the next pointer of the new node to null

    if (head == nullptr) {
        head = newNode;           // If the list is empty, the new node becomes the head
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; // Traverse to the last node
        }
        current->next = newNode;    // Link the new node to the last node
        newNode->prev = current;    // Set the previous pointer of the new node
    }
}

// Function to delete the last element from the doubly linked list
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;           // If there's only one node, delete it and set head to null
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next; // Traverse to the second last node
    }
    delete current->next;        // Delete the last node
    current->next = nullptr;     // Set the next pointer of the second last node to null
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    createList(arr, size); // Create the doubly linked list
    cout << "Doubly Linked List After Creation" << endl;
    printListElements();   // Print the elements of the doubly linked list

    insertAtEnd(6);        // Insert a new element at the end
    cout << "Doubly Linked List After Insertion" << endl;
    printListElements();   // Print the elements of the doubly linked list after insertion

    deleteAtEnd();         // Delete the last element
    cout << "Doubly Linked List After Deletion" << endl;
    printListElements();   // Print the elements of the doubly linked list after deletion

    return 0;
}
