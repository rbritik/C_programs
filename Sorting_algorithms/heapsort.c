// Sort an array using heapsort (time complexity O(n))

#include <stdio.h>

#define SIZE 11

// Function prototypes
void build_heap(int *arr);
void max_heapify(int *heap, int pos, int s);

// Main function
int main(void)
{
	int arr[SIZE] = {5, 2, 18, 7, 1, 55, 13, 45, 4, 22, 3};
	printf("Initial array is:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("\n");

	// Calling function to arrange elements of array in form of max heap
	build_heap(arr);
	printf("Array after arranging in form of max heap is:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("\n");
	
	int size2 = SIZE;  // For nodes except leaf nodes
	for (int i = size2 - 1; i >= 1; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		size2--;
		max_heapify(arr, 0, size2);
	}
	
	printf("Sorted array is:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");
	return 0;
}

// Function to arrange data of array in form of max heap
void build_heap(int *arr)
{
	// Starting nodes with height 1 (nodes which are just above leaves) to root node
	for (int i = SIZE/2; i >=0; i--)
	{
		max_heapify(arr, i, SIZE);
	}
}

// Function to put element in right place in heap
void max_heapify(int *heap, int i, int size)
{
	int l = 2 * (i + 1) - 1;  // Left child of node
	int r = 2 * (i + 1);  // right child of node

	if (i < size)
	{
		int largest;  // which one is maximum between childs and the parent node
		if (l < size && heap[l] > heap[i])
		{
			largest = l;
		}
		else
		{
			largest = i;
		}
		if (r < size && heap[r] > heap[largest])
		{
			largest = r;
		}

		// Recursive step
		if (largest != i)
		{
			int temp = heap[i];
			heap[i] = heap[largest];
			heap[largest] = temp;
			max_heapify(heap, largest, size);
		}
	}
}
// End of heapify function


