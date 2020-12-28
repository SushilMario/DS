#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20

int q[MAX_SIZE], front = 0, rear = -1;

int is_full()
{
    return (rear == MAX_SIZE - 1) ? 1 : 0;
}

int is_empty()
{
    return (front > rear) ? 1 : 0;
}

void enqueue()
{
    int value;

    if(is_full())
    {
        printf("Queue overflow!\n");
        return;
    }

    printf("Enter the value to be inserted\n");
    scanf("%d", &value);

    q[++rear] = value;
}

void dequeue()
{
    if(is_empty())
    {
        printf("Queue underflow!\n");
        return;
    }

    printf("%d deleted\n", q[front++]);

    if(front > rear)
    {
        front = 0;
        rear = -1;
    }
}

void display()
{
    if(is_empty())
    {
        printf("No elements to display\n");
        return;
    }
    
    printf("The elements are :-\n");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", q[i]);
    }

    printf("\n");
}

int main()
{
    while(1)
    {
        int choice;
        
        printf("Enter 1 to insert, 2 to delete an element, 3 to display the queue or any other integer to exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:  enqueue();
                     break;
            case 2:  dequeue();
                     break;
            case 3:  display();
                     break;
            default: exit(0);
        }
    }

    return 0;
}