// Create and traverse a binary tree
// preorder, inorder, postorder

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    struct treeNode *leftPtr;  // Pointer to left subtree
    int data;  // node value
    struct treeNode *rightPtr;  // Pointer to right subtree
};

typedef struct treeNode TreeNode;

// Function Prototypes

void insertNode(TreeNode **treePtr, int value);
void inOrder(TreeNode *treePtr);
void preOrder(TreeNode *tree);
void postOrder(TreeNode *treePtr);

int main(void) 
{
    TreeNode *rootPtr = NULL;

    srand(time(NULL));
    puts("The numbers being placed in the tree are:");

    for (unsigned int i = 1; i <= 10; i++)
    {
        int item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
    }

    // traverse the tree Preorder
    puts("\n\n The preOrder traversal is:");
    preOrder(rootPtr);

    // traverse the tree inOrder
    puts("\n\n The inorder traversal is:");
    inOrder(rootPtr);

    // traverse the tree PostOrder
    puts("\n\n The postOrder traversal is:");
    postOrder(rootPtr);
}

// insert node into tree
void insertNode(TreeNode **treePtr, int value)
{
    // if tree is empty
    if (*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));

        // If memory was allocated, then assign data
        if (*treePtr != NULL) 
        {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else {
            printf("%d not inserted. Memory not available.\n", value);
        }
    }
    else {
        // data to insert is less than data in current node
        if (value < (*treePtr)->data) {
            insertNode(&((*treePtr)->leftPtr), value);
        }
        // data to insert is greater than data in current node
        else if (value > (*treePtr)->data) {
            insertNode(&((*treePtr)->rightPtr), value);
        }

        // duplicate data value ignored
        else {
            printf("%s", "dup");
        }
    }
}

// InOrder Traversal of Tree
void inOrder(TreeNode *treePtr)
{
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

// PreOrder traversal of Tree
void preOrder(TreeNode *treePtr)
{
    if (treePtr != NULL)
    {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

// PostOrder traversal of Tree
void postOrder(TreeNode *treePtr)
{
    if (treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}