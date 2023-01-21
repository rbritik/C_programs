// Solving maximum subarray problem using brute force method, runs in O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void)
{
    int arr[SIZE];
    srand(time(NULL));

    // Assiging random values to array
    for (unsigned int i = 0; i < SIZE; i++)
    {
        arr[i] = -15 + (rand() % 30);  // Random values between -15 and 15
    }

    puts("The values in array are:");
    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    int left_index, right_index;  // Indices of maximum subarray
    int max_sum = -100;
    for (unsigned int i = 0; i < SIZE; i++)
    {
        int sum = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            sum += arr[j];
            if (sum > max_sum)
            {
                left_index = j;
                right_index = i;
                max_sum = sum;
            }
        }
    }
    puts("\n\nThe maximum subarray is:");
    for (unsigned int k = left_index; k <= right_index; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n\n left index: %d\n right index: %d\n maximum sum: %d\n", left_index, right_index, max_sum);

    return 0;
}