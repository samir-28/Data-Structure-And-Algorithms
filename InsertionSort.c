#include <stdio.h>
#include <conio.h>

void InsertionSort(int arr[], int size) 
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while(current < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

int main()
{
    int size = 6;
    int arr[] = {3, 7, 9, 6, 1, 0};
    InsertionSort(arr, size);
    printf("Array after Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
}