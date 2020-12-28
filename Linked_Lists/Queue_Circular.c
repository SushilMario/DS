#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue
{
    int value;

    struct Queue *previous;
    struct Queue *next;
}Queue;

Queue *front, *rear;  

void display()
{
    printf("\n");

    if(front == NULL)
    {
        printf("The queue is empty\n");

        return;
    }

    Queue *pointer = front;

    while(pointer->next != front)
    {
        printf(" %d", pointer->value);
        pointer = pointer->next;
    }

    printf(" %d\n", pointer->value);
    
    printf("\n");
}

Queue *createnewNode(Queue *previous, Queue *next)
{
    Queue *newNode = (Queue *)malloc(sizeof(Queue));

    printf("Enter the value\n");
    scanf("%d", &newNode->value);

    newNode->previous = previous;
    newNode->next = next;
    
    return newNode;
}

void push()
{
    Queue *newNode;

    if(front == NULL && rear == NULL)
    {
        newNode = createnewNode(NULL, NULL);

        newNode->previous = newNode;
        newNode->next = newNode;

        front = rear = newNode;

        printf("First node!\n");

        return;
    }
         
    newNode = createnewNode(rear, rear->next);

    rear->next->previous = newNode;
    rear->next = newNode;

    rear = newNode;
}

void pop()
{
    Queue *ptr;

    if(front == NULL)
    {
        printf("The Queue is empty!\n");

        return;
    }

    ptr = front;

    if(front->previous == front && front->next == front)
    {
        front = rear = NULL;
    }

    else
    {
        ptr->previous->next = ptr->next;
        ptr->next->previous = ptr->previous;

        front = front->next;
    }
    

    printf("%d was deleted\n", ptr->value);

    free(ptr);
}

int main()
{
    front = rear = NULL;

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