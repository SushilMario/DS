#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack
{
    int value;

    struct Stack *previous;
    struct Stack *next;
}Stack;

Stack *top;  

void display()
{
    printf("\n");

    if(top == NULL)
    {
        printf("The stack is empty\n");

        return;
    }

    Stack *pointer = top;

    while(pointer->next != top)
    {
        printf(" %d", pointer->value);
        pointer = pointer->next;
    }

    printf(" %d\n", pointer->value);
}

Stack *createnewNode(Stack *previous, Stack *next)
{
    Stack *newNode = (Stack *)malloc(sizeof(Stack));

    printf("Enter the value\n");
    scanf("%d", &newNode->value);

    newNode->previous = previous;
    newNode->next = next;
    
    return newNode;
}

void push()
{
    Stack *newNode;

    if(top == NULL)
    {
        newNode = createnewNode(NULL, NULL);

        newNode->previous = newNode;
        newNode->next = newNode;

        top = newNode;

        printf("First node!\n");

        return;
    }
    
    newNode = createnewNode(top->previous, top);

    top->previous->next = newNode;
    top->previous = newNode;

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

    if(top->previous == top && top->next == top)
    {
        top = NULL;
    }

    else
    {
        ptr->previous->next = ptr->next;
        ptr->next->previous = ptr->previous;

        top = top->next;
    }
    

    printf("%d was deleted\n", ptr->value);

    free(ptr);
}

int main()
{
    top = NULL;

    int choice, loop = 1;

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