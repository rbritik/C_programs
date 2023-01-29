// Operations in Max priority queue
/* 1. Getting largest element of priority queue
   2. Extracting maximum element of priority queue
   3. Increase key(priority of an element)
   4. Inserting an element(job) in priority queue
   5. Deleting an element from priority key*/

#include <stdio.h>

#define SIZE 15

// Function prototype
int Heap_Max(int *a);
void Max_Heapify(int *heap, int pos, int s);
int Heap_Extract_Max(int *arr, int *s);
void Heap_Increase_key(int *a, int i, int key);
void Max_Heap_Insert(int *p, int key, int *size);
void Delete_Key(int *A, int pos, int *size);
void Print_Heap(int *a, int s);

int main(void)
{
    int heap[SIZE] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int count = 10;  // Number of non-zero elements in current heap (will change when we insert or delete a node)

    puts("Initially heap is: ");
    Print_Heap(heap, count);  // Printing heap

    // Extracting maximum element from heap
    int max = Heap_Extract_Max(heap, &count);
    puts("After extracting largest from heap, heap is: ");
    Print_Heap(heap, count);  // Printing heap

    printf("Initially Maximum element in heap was: %d\n", max);
    printf("Now, maximum element in heap is: %d\n", Heap_Max(heap));
    puts("");

    // Increase key(value) at a index in Heap
    int key;
    int pos;
    printf("Enter position at which you want to insert value which is larger than current value: ");
    scanf("%d", &pos);
    printf("Enter value you want to enter: ");
    scanf("%d", &key);
    Heap_Increase_key(heap, pos, key);
    puts("After inserting value at a index, the priority queue is: ");
    Print_Heap(heap, count);

    // Inserting more elements in Priority queue
    int num;
    printf("How many elements you want to enter: ");
    scanf("%d", &num);
    while (num > 0)
    {
        printf("Enter element: ");
        scanf("%d", &key);
        Max_Heap_Insert(heap, key, &count);
        num--;
    }
    printf("After entering elements priority queue is: ");
    Print_Heap(heap, count);

    // Deletng an index from queue
    int ind;
    printf("Which position you want to delete: ");
    scanf("%d", &ind);
    Delete_Key(heap, ind - 1, &count);
    puts("After deleting a node, heap is: ");
    Print_Heap(heap, count);
    return 0;
}

// Maximum element in Heap
int Heap_Max(int *a)
{
    return a[0];
}

// Extract maximum element of heap (when a job with highest priority is finished then,
// job with second highest priority takes its place)
int Heap_Extract_Max(int *arr, int *size)
{
    if (*size < 1)
    {
        printf("Heap underflow\n");
        return -1;
    }
    int max = arr[0];
    arr[0] = arr[*size - 1];
    *size = *size - 1;
    Max_Heapify(arr, 0, *size);
    return max;
}

// Fix the position of ith element in Heap
void Max_Heapify(int *heap, int i, int size)
{
	int l = 2 * (i + 1) - 1;  // Left child of node
	int r = 2 * (i + 1);  // Right child of node
	int largest;

	if (l < size && heap[l] > heap[i])  // If left child is greater than parent
	{
		largest = l;
	}

	else
	{
		largest = i;
	}

	if (r < size && heap[r] > heap[largest])  // If right child is greater than parent
	{
		largest = r;
	}

	// recurisve step unless parent is bigger than its both child
	if (largest != i)
	{
		int temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		Max_Heapify(heap, largest, size);
	}
}

// Increasing Priority (key) of a job (element) in priority queue and then rearraning the queue
void Heap_Increase_key(int *A, int pos, int key)
{
    if (key < A[pos])
    {
        printf("Error: New key is smaller than current key\n");
    }
    else
    {
        A[pos] = key;
        int parent;  // Parent position of current index (node)
        while (pos > 0)
        {
            if (pos % 2 == 0)
            {
                parent = (pos/ 2) - 1;
            }
            else
            {
                parent = (pos - 1) / 2;
            }

            if (A[parent] > A[pos])
            {
                break;
            }
            else
            {
                int temp = A[parent];
                A[parent] = A[pos];
                A[pos] = temp;
                pos = parent;
            }
        }
    }
}

// Insert an element in priority queue
void Max_Heap_Insert(int *A, int key, int *size)
{
    if (*size == SIZE)
    {
        printf("Error: Queue is full!\n");
    }
    else
    {
        *size = *size + 1;
        A[*size - 1] = -1;
        Heap_Increase_key(A, *size - 1, key);
    }
}

// Delete an Index from priority queue
void Delete_Key(int A[], int pos, int *size)
{
    if (pos >= *size)
    {
        printf("Error: Index not in Queue\n");
    }
    else
    {
        if (A[pos] > A[*size - 1])
        {
            A[pos] = A[*size - 1];
            Max_Heapify(A, pos, *size);
        }
        else
        {
            Heap_Increase_key(A, pos, A[*size - 1]);
        }
        *size = *size - 1;
    }
}

// Printing priority queue
void Print_Heap(int *heap, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    puts("\n");
}

