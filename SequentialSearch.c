#include <stdio.h>

int sequential_search(int arr[], int n, int key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) {
            return i; // Key found, return index
        }
    }
    return -1; // Key not found
}

int main() {
    int n, key, comparisons = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = sequential_search(arr, n, key, &comparisons);

    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found.\n", key);
    }

    printf("Number of comparisons made: %d\n", comparisons);

    return 0;
}
