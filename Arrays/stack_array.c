#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20

int stack[MAX_SIZE], top = -1;

int is_full()
{
    return (top == MAX_SIZE - 1) ? 1 : 0;
}

int is_empty()
{
    return (top == -1) ? 1 : 0;
}

void push()
{
    int value;

    if(is_full())
    {
        printf("Stack overflow!\n");
        return;
    }

    printf("Enter the value to be pushed\n");
    scanf("%d", &value);

    stack[++top] = value;
}

void pop()
{
    if(is_empty())
    {
        printf("Stack underflow!\n");
        return;
    }

    printf("%d deleted\n", stack[top--]);
}

void display()
{
    if(is_empty())
    {
        printf("No elements to display\n");
        return;
    }
    
    printf("The elements are :-\n");

    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    while(1)
    {
        int choice;
        
        printf("Enter 1 to insert, 2 to delete an element, 3 to display the stack or any other integer to exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:  push();
                     break;
            case 2:  pop();
                     break;
            case 3:  display();
                     break;
            default: exit(0);
        }
    }

    return 0;
}