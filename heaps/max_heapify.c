// When a node in heap is smaller than its child then, insert it in its right position to make the array 
// follow max heap property
#include <stdio.h>

#define SIZE 10

// Function prototype
void max_heapify(int *heap, int pos);

// Main function
int main(void)
{
	// In below array element 6 is violating heap property
	//int arr[SIZE] = {23, 17, 14, 6, 13, 10, 1, 5, 7, 12};
	int arr[SIZE] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	
	printf("Initial array is:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");

	// Calling max_heapify to fix the array according to heap property
	max_heapify(arr, 1);
	
	printf("Array after fixing the position of element violating heap property:\n"); 
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

// Function to fix heap
void max_heapify(int *heap, int i)
{
	int l = 2 * (i + 1) - 1;  // Left child of node
	int r = 2 * (i + 1);  // Right child of node
	int largest;

	if (l < SIZE && heap[l] > heap[i])  // If left child is greater than parent
	{
		largest = l;
	}

	else
	{
		largest = i;
	}

	if (r < SIZE && heap[r] > heap[largest])  // If right child is greater than parent
	{
		largest = r;
	}

	// recurisve step unless parent is bigger than its both child
	if (largest != i)
	{
		int temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		max_heapify(heap, largest);
	}
}

