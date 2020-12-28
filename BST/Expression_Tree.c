#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    double result;
    char value;
    
    struct tree *left;
    struct tree *right;
}tree;

tree *root = NULL;

tree *create()
{
    char value;
    tree *newNode;

    printf("Enter the value of, or 0 to skip this node\n");
    scanf("%c", &value);

    if(value == 0)
    {
        return NULL;
    }

    newNode = (tree *)malloc(sizeof(tree));
    newNode->value = value;

    printf("Creation of node to the left of %d :-\n", newNode->value);
    newNode->left = create();

    printf("Creation of node to the right of %d :-\n", newNode->value);
    newNode->right = create();

    return newNode;
}

double operate(double op1, double op2, char ch)
{
    if(ch == '+')
    return op1 + op2;
    if(ch == '-')
    return op1 - op2;
    if(ch == '*')
    return op1 * op2;
    if(ch == '/')
    return op1 / op2;

    return op1 * op2;
}

double evaluate(tree *root)
{
    tree *left_node, *right_node;
    double left, right, result;

    if(root != NULL)
    {
        left_node = evaluate(root->left);
        right_node = evaluate(root->right);

        if(left == NULL && right == NULL)
        {
            result = (double)(root->value - '0');
            free(root);
            return result;
        }

        else
        {
            result = operate(left, right, root->value);

            free(root);

            return result;
        }
    }
}

int main()
{
    double result;
    
    root = create();

    printf("The result is %lf\n", evaluate(root));

    return 0;
}