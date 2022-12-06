// Remove nth element from end in a linked list
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
int reverse_list(void);
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
        puts("Reversed list is same as initial list");
    }    
    else
    {
        // Calling function to reverse the list
        reverse_list();
    }

    // Display the reversed list
    puts("");
    printf("Reversed list: ");

    display_list(head);  // display list after reversing

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

// Function to reverse the list
int reverse_list(void)
{
    // Pointers to update the lists
    Node *temp = head->next; 
    Node *pptr = temp->next;  
    Node *ptr = head;
    
    while (temp != NULL)
    {
        temp->next = pptr;
        pptr = temp;
        temp = ptr;

        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
    }

    head->next = NULL;
    head = pptr;  // Changing head to last element
    return 0;
    
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