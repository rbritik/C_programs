// Sorting a linked list using bubble sort
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure containing a node number and containing address of next node
struct node {
    int em_no;
    struct node *next;
} *head;

typedef struct node Node;


// Function Prototypes
void create_list(int n);
void display_list(Node *ptr);
int sort_list(int n);
void free_list(Node *ptr1);

// Main Function
int main(void)
{
    int length;
    do
    {
        printf("Enter length of list: ");
        scanf("%d", &length); 
    }
    while (length < 1);
    

    create_list(length);

    // Function call to display list
    printf("Entered list is: ");
    display_list(head);


    if (length == 1)  // If length of linked list is 1
    {
        puts("List is already sorted");
    }    
    else
    {
        // Calling function to sort the list
        sort_list(length);
    }

    // Display the sorted list
    puts("");
    printf("Sorted list: ");

    display_list(head);  

    // Freeing memory
    free_list(head); 
    return 0;
}


// Function to create a list
void create_list(int len)
{
    Node *temp_ptr = NULL;

    puts("Enter data");
    for (int i = 1; i <= len; i++)  // Entering nodes in linked list
    {
        Node *current_ptr = (Node *) malloc(sizeof(Node));
        scanf("%d", &(current_ptr->em_no));  // Input from user
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
}


// Function to sort the list
int sort_list(int len)
{
    // Pointers to update the lists
    Node *temp = NULL; 
    Node *pptr = NULL;  
    Node *ptr = NULL;
    
    int a = 0;  // For counting number of times loops run

    // Outer loop to run for elements other than head
    for (int count = 2; count < len; count++)
    {
        temp = head->next; // Central pointer
        pptr = head;  // previous pointer
        ptr = temp->next;  // With which we have to compare

        // Inner loop to run for right position of temp variable
        while ((ptr != NULL))
        {
            if ((temp->em_no > ptr->em_no))
            {
                pptr->next = ptr;
                temp->next = ptr->next;
                ptr->next = temp;

                pptr = pptr->next;
                ptr = temp->next; 
            }

            else
            {
                temp = temp->next;
                pptr = pptr->next;
                ptr = ptr->next;
            }
            a++;
        }
    }

    temp = head->next;

    // For taking element at head at its correct position
    if (head->em_no > temp->em_no)
    {
        head->next = temp->next;  
        temp->next = head;
        head = temp;

        temp = head->next;
        pptr = head;
        ptr = temp->next; 

        while (ptr != NULL && (temp -> em_no > ptr->em_no))
        {
            pptr->next = ptr;
            temp->next = ptr->next;
            ptr->next = temp;

            pptr = pptr->next;
            ptr = temp->next;
            a++;
        }
    }

    //printf("\nNumber of times loops run: %d", a);

    return 0;   
}  // End of sorting function


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