// Remove nth element from end in a linked list
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure containing a node number and containing address of next node
struct node {
    int em_no;
    struct node *next;
};

typedef struct node Node;


// Function Prototypes
void display_list(Node *ptr);
int swap_node(Node *ptr2, int p, int q);
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


    if (length == 1)  // If length of linked list is 1
    {
        puts("\nNo nodes to swap with");
        return 0;
    }

    int num1, num2;  // Element you want to swap
    printf("\nEnter nodes which you want to swap: ");
    scanf("%d %d", &num1, &num2);

    if (num1 < 1 || num2 < 1)  // If negative value for pos is entered
    {
        puts("Position can only be positive integers");
    }

    else if (num1 > length || num2 > length)  // If value of pos is greater than length
    {
        puts("Node not in list");
        return 0;
    }

    else if (num1 != 1 && num2 != 1)
    {
        swap_node(head, num1, num2);  // Function to swap elements other than head
    }

    else  // if you want to swap with head
    {
        int count = 1;  // Iterating over linked list
        
        temp_ptr = head;
        Node *pptr = head;
        int bigger_pos = abs(num1 - num2);

        while (temp_ptr != NULL)
        {
            if (count == bigger_pos)
            {
                pptr = temp_ptr;
                break;
            }

            temp_ptr = temp_ptr->next;
            count++;
        }

        temp_ptr = head;

        Node *ptr = pptr->next;
        Node *ptr2 = ptr->next;

        if (count == 1)  // If you want to swap head with next element
        {
            ptr->next = head;
            temp_ptr->next = ptr2;
            head = ptr;
        }

        else
        {
            ptr->next = temp_ptr->next;

            head = ptr;  // Changing head to new head

            pptr->next = temp_ptr;
            temp_ptr->next = ptr2;
        }

        
    }
    

    display_list(head);  // display list after swaping node
    free_list(head);  // Freeing memory
    return 0;
}


// Function to remove nth element from end
int swap_node(Node *head, int pos1, int pos2)
{
    Node *temp = head;
    int count = 1;  // Iterating over linked list
    int count2 = 0;

    // Pointers previous to nodes which you want to swap
    Node *previousptr1 = head; 
    Node *previousptr2 = head;

    int flag1 = 0, flag2 = 0;  // Check when node position equals entered position

    while (temp != NULL)
    {
        if ((count == pos1 - 1) && (flag1 == 0))
        {
            previousptr1 = temp;
            flag1 = 1;
        }

        if ((count == pos2 - 1) && (flag2 == 0))
        {
            previousptr2 = temp;
            flag2 = 1;
        }
        
        if (flag1 == 1 && flag2 == 1)
        {
            break;
        }
        count++;
        temp = temp->next;
    }

    Node *ptr1 = previousptr1->next; 
    Node *ptr2 = previousptr2->next;
    Node *temp2 = ptr2->next;  // struct Variable to contain address of pointer next to

    if (abs(pos2 - pos1) == 1)  // If you want to swap two nodes which are continuous
    {
        previousptr1->next = ptr2;
        ptr2->next = ptr1;
        ptr1->next = temp2;
    }
    else
    {
        previousptr1->next = ptr2;
        ptr2->next = ptr1->next;

        previousptr2->next = ptr1;
        ptr1->next = temp2;
    }
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