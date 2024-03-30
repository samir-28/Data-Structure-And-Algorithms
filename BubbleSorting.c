#include <stdio.h>
#include <conio.h>


void bubblesort(int arr[],int size){
  int i, j,choice;
  printf("1.Ascending Order \n2.Descending Order\n");
  printf("Choose As You Want To Sort:\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:
    for (i = 0; i < size - 1; i++)
    { // Indicate how many times we should run loop to check every element
        for (j = 0; j < size - i - 1; j++)
        { // Indicate for comparison between element
           
            
            if (arr[j] > arr[j + 1])
            {
                int temp=arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array after Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    break;
    case 2:
     for (i = 0; i < size - 1; i++)
    { // Indicate how many times we should run loop to check every element
        for (j = 0; j < size - i - 1; j++)
        { // Indicate for comparison between element
           
            
            if (arr[j] < arr[j + 1])
            {
                int temp=arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array after Sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    break;
    default:printf("Invalid Choice \n");
    break;
}
}


int main()
{
    int size = 6;
    int arr[] = {3, 7, 9, 6, 1, 0};
    bubblesort(arr,size);
}