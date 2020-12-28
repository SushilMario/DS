#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    int value;
    
    struct Tree *left;
    struct Tree *right;
}Tree;

Tree *root = NULL;

Tree *create()
{
    int value;
    Tree *newNode;

    printf("Enter the value of, or 0 to skip this node\n");
    scanf("%d", &value);

    if(value == 0)
    {
        return NULL;
    }

    newNode = (Tree *)malloc(sizeof(Tree));
    newNode->value = value;

    printf("Creation of node to the left of %d :-\n", newNode->value);
    newNode->left = create();

    printf("Creation of node to the right of %d :-\n", newNode->value);
    newNode->right = create();

    return newNode;
}

void preOrder(Tree *root)
{
    if(root != NULL)
    {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Tree *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

void postOrder(Tree *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

int main()
{
    root = create();

    printf("Pre-order traversal :-\n");
    preOrder(root);

    printf("\n");

    printf("In-order traversal :-\n");
    inOrder(root);

    printf("\n");

    printf("Post-order traversal :-\n");
    postOrder(root);

    return 0;
}