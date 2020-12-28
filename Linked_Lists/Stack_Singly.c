#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack
{
    int value;

    struct Stack *next;
}Stack;

Stack *top;  

void display()
{
    printf("\n");

    if(top == NULL)
    {
        printf("Underflow!\n");

        return;
    }

    Stack *pointer = top;

    while(pointer != NULL)
    {
        printf("%d ", pointer->value);
        pointer = pointer->next;
    }
    
    printf("\n");
}

Stack *createnewNode(Stack *next)
{
    Stack *newNode = (Stack *)malloc(sizeof(Stack));

    printf("Enter the value\n");
    scanf("%d", &newNode->value);

    newNode->next = next;

    return newNode;
}

void push()
{
    Stack *newNode;
    
    newNode = createnewNode(top);

    if(top == NULL)
    printf("First node!\n");

    top = newNode;
}

void pop()
{
    Stack *ptr;

    if(top == NULL)
    {
        printf("The stack is empty!\n");

        return;
    }

    ptr = top;
    top = top->next;

    printf("%d was deleted\n", ptr->value);

    free(ptr);
}

int main()
{
    top = NULL;

    int choice, loop = 1, value;

    while(loop)
    {
        printf("Enter 1 to insert, 2 to delete, 3 to display, or 0 to exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: push();
                     
                    break;

            case 2: pop();

                    break;

            case 3: display();

                    break;

            default: printf("Exiting...\n");
                     loop = 0;
        }
    }  
}