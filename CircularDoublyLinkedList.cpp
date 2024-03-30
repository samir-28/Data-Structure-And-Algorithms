#include <iostream>

using namespace std;

// Structure to represent a node in the circular doubly linked list
struct Node {
    int data;        // Data of the node
    Node* prev;      // Pointer to the previous node
    Node* next;      // Pointer to the next node
};

Node* head = nullptr; // Global variable to store the head of the linked list

// Function to create a circular doubly linked list from an array of elements
void createList(int arr[], int size) {
    if (size == 0) {
        return; // If the array is empty, do nothing
    }

    head = new Node();          // Create the head node
    head->data = arr[0];        // Assign the data to the head node
    head->prev = head;          // Set the previous pointer of the head node to itself
    head->next = head;          // Set the next pointer of the head node to itself

    Node* current = head;       // Pointer to traverse the list

    // Iterate through the array to create and link the nodes
    for (int i = 1; i < size; i++) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = arr[i];     // Assign the data to the new node
        newNode->prev = current;    // Set the previous pointer of the new node
        newNode->next = head;       // Set the next pointer of the new node to the head

        current->next = newNode;    // Link the current node to the new node
        current = newNode;          // Move to the new node
        head->prev = current;       // Update the previous pointer of the head node
    }
}

// Function to print the elements of the circular doubly linked list
void printListElements() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head; // Pointer to traverse the list
    cout << "Elements: [";
    do {
        cout << " " << current->data; // Print the data of the current node
        current = current->next;      // Move to the next node
    } while (current != head);        // Continue until the entire list is traversed
    cout << " ]" << endl;
}

// Function to insert a new element at the end of the circular doubly linked list
void insertAtEnd(int value) {
    Node* newNode = new Node();   // Create a new node
    newNode->data = value;        // Assign the data to the new node

    if (head == nullptr) {
        head = newNode;           // If the list is empty, the new node becomes the head
        head->prev = head;        // Set the previous pointer of the head node to itself
        head->next = head;        // Set the next pointer of the head node to itself
    } else {
        Node* last = head->prev;   // Get the last node
        newNode->prev = last;      // Set the previous pointer of the new node
        newNode->next = head;      // Set the next pointer of the new node to the head

        last->next = newNode;      // Link the last node to the new node
        head->prev = newNode;      // Update the previous pointer of the head node
    }
}

// Function to delete the last element from the circular doubly linked list
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    Node* last = head->prev;   // Get the last node
    if (head == last) {        // If there is only one node in the list
        delete head;           // Delete the node
        head = nullptr;        // Set head to null
    } else {
        Node* secondLast = last->prev;  // Get the second last node
        secondLast->next = head;        // Update the next pointer of the second last node
        head->prev = secondLast;        // Update the previous pointer of the head node
        delete last;                    // Delete the last node
    }
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    createList(arr, size); // Create the circular doubly linked list
    cout << "Circular Doubly Linked List After Creation" << endl;
    printListElements();   // Print the elements of the circular doubly linked list

    insertAtEnd(6);    
    insertAtEnd(7);  
    insertAtEnd(8);      // Insert a new element at the end
    cout << "Circular Doubly Linked List After Insertion" << endl;
    printListElements();   // Print the elements of the circular doubly linked list after insertion

    deleteAtEnd();         // Delete the last element
    cout << "Circular Doubly Linked List After Deletion" << endl;
    printListElements();   // Print the elements of the circular doubly linked list after deletion

    return 0;
}
