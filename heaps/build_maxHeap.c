// To take a random array and format it in the form of max heap
#include <stdio.h>

#define SIZE 10

// Function Prototype
void max_heapify(int *arr, int pos);

// Main function
int main(void)
{
	int arr[SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	
	printf("Intially array is: ");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}

	// Call max_heapify function to rearrange nodes which violates max heap
	// property (since leaf nodes always follows that property trivially so
	// start from nodes above leaves
	for (int i = SIZE / 2 ; i >= 0; i--)
	{
		max_heapify(arr, i);
	}
	puts("");

	printf("After arranging data in form of heap array is: ");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

// Function to put an array element to its right place
void max_heapify(int *heap, int i)
{
	int l, r;  // Left and right node for parent node
	int largest;  // Node which is greater among parent and children
	while (i < SIZE)
	{
		l = 2 * ((i + 1)) - 1;
		r = 2 * (i + 1);
		largest = i;
		if (l < SIZE && heap[l] > heap[i])
		{
			largest = l;
		}

		if (r < SIZE && heap[r] > heap[largest])
		{
			largest = r;
		}
		if (largest == i)
		{
			break;
		}
		else
		{
			int temp = heap[i];
			heap[i] = heap[largest];
			heap[largest] = temp;
			i = largest;
		}
	}
}// End of max_heap function

/* Initially the array was in the form
                      4
		    /   \
		   1     3
		  /  \   / \
		 2   16  9 10
		/ \  /
	      14  8  7
   
After max heapifying the array it becomes:

                      16
		    /   \
		   14     10
		  /  \   / \
		 8   7  9   3
		/ \  /
	       2  4 1

*/
