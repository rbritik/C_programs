// Program to sort array using merge sort algorithm

#include <stdio.h>

//  Function Prototypes
int merge_sort(int *arr, int a, int b);
int merge(int *arr, int p, int q, int r);

#define SIZE 11

int main(void)
{
    int arr[SIZE] = {5, 2, 3, 8, 6, 3, 15, 9, 16, 14, 1};
    printf("Unsorted Array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calling function mergesort for sorting
    merge_sort(arr, 0, SIZE - 1);
    printf("\nSorted Array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    } 
}

// Function to merge two sorted arrays

int merge(int *arr, int p, int q, int r)
{
    int a = q - p + 1; // number of elements in left portion of array which are sorted
    int b = r - q;  // number of elements in right portion of array which are sorted

    // Intermediate arrays to store sorted portion of arrays
    int arr1[a];
    int arr2[b];

    // Storing left portion of array which is sorted
    for (int i = 0; i < a; i++)
    {
        arr1[i] = arr[p + i];
    }
    
    // Storing right portion of array;
    for (int j = 0; j < b; j++)
    {
        arr2[j] = arr[q + j + 1];
    }

    int i = 0;  // Index for left array
    int j = 0;  // Index for right array

    // Loop for copying arrays in original array after comparing
    for (int k = p; k <= r; k++)
    {
        if (i < a && j < b)
        {
            if (arr1[i] < arr2[j])
            {
                arr[k] = arr1[i];
                i++;
            }
            else {
                arr[k] = arr2[j];
                j++;
            }
        }

        else if (i < a)
        {
            arr[k] = arr1[i];
            i++;
        }

        else
        {
            arr[k] = arr2[j];
            j++;
        }
    }
    return 0;
}

// Recursice function to divide the array and call merge function to sort and merge array
int merge_sort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
    return 0;
}