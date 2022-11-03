// Program for searching an element in an array using binary recursive search

#include <stdio.h>

#define SIZE 10


// Function Prototypes
size_t recursive_Search(int a[], int key, size_t ind1, size_t ind2);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);

// Main Function
int main(void)
{
	int arr1[SIZE] = {2, 3, 4, 7, 9, 12, 14, 22, 24, 28};  // Array in ascending order
	int element;  // Element to be searched (entered by the user)

	scanf("%d", &element);

	printHeader();

	size_t index = recursive_Search(arr1, element, 0, SIZE - 1);
	
	if (index == -1)
	{
		printf("Element not found!");
	}

	else
	{
		printf("%d is at position %u", element, index + 1);
    }

	return 0;
}  // End of main Function


// Function for searching an element in an array recursively
size_t recursive_Search(int arr[], int element, size_t lower_index, size_t higher_index)
{
	size_t middle_index = (lower_index + higher_index) / 2;

	printRow(arr, lower_index, higher_index, middle_index);  // Call function for printing row

	if (lower_index > higher_index)  // If element is not in array then return -1
	{
		return -1;
	}

	else if (arr[lower_index] == element)  
	{
		return lower_index;
	}
	else if (arr[higher_index] == element)
	{
		return higher_index;
	}

	else
	{
		if (element > arr[middle_index])  // If element lies toward higher index
		{
			lower_index = middle_index + 1;
			recursive_Search(arr, element, lower_index, higher_index);  
		} 

		else if (element < arr[middle_index])  // If element lies toward lower index
		{
			higher_index = middle_index - 1;
			recursive_Search(arr, element, lower_index, higher_index);
		}

		else  // If element is equal to the middle index
		{
			return middle_index;
		} 
	}
}


// Print a header for the output
void printHeader(void)
{
	puts("\nIndices:");

	// output column head
	for (unsigned int i = 0; i < SIZE; ++i) {
		printf("%3u ", i);
	} 

	puts(""); // start new line of output

	// output line of - characters
	for (unsigned int i = 1; i <= 4 * SIZE; ++i) {
		printf("%s", "-");
	} 

	puts(""); // start new line of output
} 


// Print one row of output showing the current
// part of the array being processed.
void printRow(const int b[], size_t low, size_t mid, size_t high)
{ 
    // loop through entire array
	for (size_t i = 0; i < SIZE; ++i) 
	{ 
	    // display spaces if outside current subarray range
	    if (i < low || i > high) 
	    {
	    	printf("%s", " ");
		} 
		else if (i == mid) 
		{ 
			// display middle element
			printf("%3d*", b[i]); // mark middle value
		} 
		else
		{ 
			// display other elements in subarray
			printf("%3d ", b[i]);
		} 
	} 
	puts(""); // start new line of output
}