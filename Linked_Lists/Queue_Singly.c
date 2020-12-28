#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue
{
    int value;

    struct Queue *next;
}Queue;

Queue *front;  

void display()
{
    printf("\n");

    if(front == NULL)
    {
        printf("The queue is empty\n");

        return;
    }

    Queue *pointer = front;

    while(pointer != NULL)
    {
        printf(" %d", pointer->value);
        pointer = pointer->next;
    }
    
    printf("\n");
}

Queue *createnewNode(Queue *next)
{
    Queue *newNode = (Queue *)malloc(sizeof(Queue));

    printf("Enter the value\n");
    scanf("%d", &newNode->value);

    newNode->next = next;

    return newNode;
}

void enqueue()
{
    Queue *newNode, *sptr;
    
    newNode = createnewNode(NULL);

    if(front == NULL)
    {
        printf("First node!\n");

        front = newNode;
        return;
    }

    sptr = front;

    while(sptr->next != NULL)
    {
        sptr = sptr->next;
    }

    sptr->next = newNode;
}

void dequeue()
{
    Queue *ptr;

    if(front == NULL)
    {
        printf("The queue is empty!\n");

        return;
    }

    ptr = front;
    front = front->next;

    printf("%d was deleted\n", ptr->value);

    free(ptr);
}

int main()
{
    front = NULL;

    int choice, loop = 1;

    while(loop)
    {
        printf("Enter 1 to insert, 2 to delete, 3 to display, or 0 to exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enqueue();
                     
                    break;

            case 2: dequeue();

                    break;

            case 3: display();

                    break;

            default: printf("Exiting...\n");
                     loop = 0;
        }
    }  
}