// Counting Sort (complexit O(n + k)) (n number of elements, k -> largest element)

#include <stdio.h>

#define SIZE 15

int main(void)
{
    int A[SIZE] = {15, 12, 23, 9, 10, 24, 2 , 5, 2, 11, 27, 18, 5, 2, 24};

    int max = A[0];  

    for (int i = 0; i < SIZE; i++)  // To find largest element in the array
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    int B[SIZE] = {0};  // Array that will be containing sorted elements
    int C[max + 1];  // Array that will be storing counting of each elements

    for (int i = 0; i <= max; i++)
    {
        C[i] = 0;
    }

    for (int i = 0; i < SIZE; i++)  // To store counts of each elements of array A in C array
    {
        C[A[i]] = C[A[i]] + 1;
    }

    for (int i = 1; i <= max; i++)
    {
        C[i] += C[i - 1];  // Stores number of elements which are less or equal to index
    }

    for (int i = SIZE - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]] -= 1;
    }
    printf("Initial Array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", A[i]);
    }

    puts("");
    printf("Sorted Array: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", B[i]);
    }
    
    return 0;

}