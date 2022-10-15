// Selection Sort 
/* Three steps
		a) The smallest value in the array is found.
		b) It is swapped with the value in the first position of the array.
		c) The above steps are repeated for the rest of the array starting at the second position and
		advancing each time.
	Eventually the entire array is divided into two parts: the sub-array of items already sorted
	which is built up from left to right and is found at the beginning, and the sub-array of
	items remaining to be sorted, occupying the remainder of the array.
*/

#include <stdio.h>

// Size of array
#define SIZE 10

// Function for sorting the array
int selection_sort(int a[]);


// Starting of main Function
int main(void)
{
	int array[SIZE] = {5,2,3,8,6,3,15,9,16,14};

	// Calling the sort function
	selection_sort(array);

	//  Printing the array
	for (size_t i = 0; i < SIZE; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}


// Function for sorting the array
int selection_sort(int arr[])
{
	for (size_t i = 0; i < SIZE; i++)
	{
		int temp;
		int index = i;
		int small = arr[i];
		for(size_t j = i + 1; j < SIZE; j++)
		{
			if (arr[j] < small)
			{
				small = arr[j];
				index = j;
			}
		}

		// Swapping the smallest(in array portion which has greater index than i) element with ith element
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	return 0;
}