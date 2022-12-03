// Program to remove nth node from the begining in a linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int em_no;
    struct node *next;
};

typedef struct node Node;


int remove_node(Node *str, int n);
void print_list(Node *listp);

// Main Function
int main(void)
{
    Node *head = NULL;  // Head pointer
    Node *temp_ptr = NULL;  // Pointer to fill, print and do some other operation on list

    for (int i = 1; i <= 10; i++) // Adding 10 nodes
    {
        Node *current_ptr = (Node *) malloc(sizeof(Node));
        if (current_ptr != NULL)
        {
            
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
        
    }

    // Calling function for printing linked list
    print_list(head);

    int node_no;  // For taking input which node user want to remove

    printf("\nEnter the node number you want to remove from 1 to 10: ");
    scanf("%d", &node_no);

    if (node_no == 1)  // If user want to remove first node
    {
        head = head->next;
    }
    else  // Any other node than first node
    {
        // Calling function to remove nth node from list
        remove_node(head, node_no);
    }
    
    // Printing list after removing nth node
    print_list(head);
    return 0;
}


// Function to remove the node
int remove_node(Node *head, int num)
{
    Node *temp_ptr = NULL;
    if (num == 10)
    {
        temp_ptr = head;
        {
            while (temp_ptr->next->next != NULL)
            {
                temp_ptr = temp_ptr->next;
            }
            temp_ptr->next = NULL;
        }
    }
    else if (num > 1 && num < 10)
    {
        int count = 2;
        temp_ptr = head->next;
        Node *prev_ptr = head;
        while (count != num)
        {
            count++;
            temp_ptr = temp_ptr->next;
            prev_ptr = prev_ptr->next;
        }
        prev_ptr->next = temp_ptr->next;
    }
    
    else 
    {
        puts("Node not in List!");
    }
    return 0;
}

// Function to print linked list
void print_list(Node *list)
{
    Node *listptr = list;
    while (listptr != NULL)
    {
        printf("%d ", listptr->em_no);
        listptr = listptr->next;
    }
}