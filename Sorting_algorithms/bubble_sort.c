#include <stdio.h>

#define SIZE 10
int main(void)
{
    int arr[SIZE] = {22, 12, 23, 3, 1, 37, 23, 2, 55, 1};
    printf("Array before sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    puts("");
    for (int count = 1; count < SIZE; count++)
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    puts("");
    printf("Array after sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
}