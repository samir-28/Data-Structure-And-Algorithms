#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert key into hash table
void insert(int hash_table[], int key) {
    int index = hash(key);

    // Linear probing to handle collisions
    while (hash_table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hash_table[index] = key;
}

// Function to display the hash table
void display(int hash_table[]) {
    printf("Index\tValue\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t%d\n", i, hash_table[i]);
    }
}

int main() {
    int hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1;
    }

    int keys[] = {20, 30, 24, 23, 58, 39, 13, 64, 25, 26};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    // Insert keys into the hash table
    for (int i = 0; i < num_keys; i++) {
        insert(hash_table, keys[i]);
    }

    // Display the hash table
    printf("Hash Table with Linear Probing\n");
    display(hash_table);

    return 0;
}
