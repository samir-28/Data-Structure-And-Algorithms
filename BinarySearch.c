#include <stdio.h>

int binary_search(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // Key found, return index
        } else if (arr[mid] < key) {
            left = mid + 1; // Key may be in the right half
        } else {
            right = mid - 1; // Key may be in the left half
        }
    }
    return -1; // Key not found
}

int main() {
    int n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = binary_search(arr, 0, n - 1, key);

    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found.\n", key);
    }

    return 0;
}
