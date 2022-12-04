// Remove nth element from end in a linked list
#include <stdio.h>
#include <stdlib.h>

// Structure containing a node number and containing address of next node
struct node {
	int em_no;
	struct node *next;
};

typedef struct node Node;


// Function Prototypes
void display_list(Node *ptr);
int remove_from_end(Node *ptr2, int n);
void free_list(Node *ptr1);

// Main Function
int main(void)
{
	Node *head = NULL;
	Node *temp_ptr = NULL;

	int length;
	printf("Enter length of list: ");
	scanf("%d", &length);

	for (int i = 1; i <= length; i++)  // Entering nodes in linked list
	{
		Node *current_ptr = (Node *) malloc(sizeof(Node));
		current_ptr->em_no = i;
		current_ptr->next = NULL;

		if (i == 1)
		{
			head = current_ptr;
		}

		temp_ptr = head;

		while (temp_ptr->next != NULL)
		{
			temp_ptr = temp_ptr->next;
		}
		if (i != 1)
		{
			temp_ptr->next = current_ptr;	
		}	
	}

    // Function call to display list
	display_list(head);

	int num;  // Element from end you want to remove
	printf("\nEnter node number from last which you want to remove: ");
	scanf("%d", &num);

	if (length - num + 1 == 1)  // If you want to remove first element of list
	{
		head = head->next;
	}
	else
	{
		remove_from_end(head, num);  // Function to remove other than head
	}

	display_list(head);  // display list after removing node
    free_list(head);  // Freeing memory
	return 0;
}


// Function to remove nth element from end
int remove_from_end(Node *head, int pos)
{
	Node *temp = head;
	int count = 1;

    // For counting number of element in list
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}

	int count2 = count - pos;  // Element from start

	Node *previousptr = head;
	Node *currentptr = head->next;

    // If you want to remove first element from last
	if (count2 == count)
	{

		while (currentptr->next != NULL)
		{
			currentptr = currentptr->next;
			previousptr = previousptr->next;
		}
		previousptr->next = NULL;
	}

    // Other than first and last element
	else if (count2 > 1)
	{
		count = 2;
		currentptr = head->next;
		while (count != count2)
		{
			currentptr = currentptr->next;
			previousptr = previousptr->next;
			count++;
		}
		currentptr = currentptr->next;
		previousptr->next = currentptr;
	}
	else
	{
		puts("Node does not exist");
	}
	
}


// Function to display list
void display_list(Node *headptr)
{
	Node *temp = headptr;

	while (temp != NULL)
	{
		printf("%d ", temp->em_no);
		temp = temp->next;
	}
}

// Function for freeing the memory
void free_list(Node *head)
{
    Node *tmp;

    while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}