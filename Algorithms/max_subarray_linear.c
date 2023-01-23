// Find subarray giving maximum sum in O(n)

#include <stdio.h>

#define SIZE 12

int main(void)
{
	int arr[SIZE] = {5, -2, 13, -17, 21, -10, 25, 7, -15, 35, -5, 4};

	int sum = 0; // To store sum temporarily
	int best = 0;  // to store largest sum
	int left_index = 0, right_index = SIZE - 1;  // To store left and right index of max_subarray
	int left_temp = 0, right_temp = SIZE - 1; // To store left index and right index of max_subarray temporarily

	puts("Array is: ");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > sum + arr[i])
		{
			sum = arr[i];
			left_temp = i;
		}
		else
		{
			sum = sum + arr[i];
			right_temp = i;
		}

		if (sum > best)
		{
			best = sum;
			left_index = left_temp;
			right_index = right_temp;
		}
	}
	
	// Print maximum subarray
	puts("\n\nMaximum Subarray is: ");
	for (int i = left_index; i <= right_index; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nMaximum sum is: %d", best);

	return 0;
}

