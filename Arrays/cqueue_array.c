#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int cq[MAX_SIZE], front = 0, rear = -1, count = 0;

int is_full()
{
    return (count == MAX_SIZE) ? 1 : 0;
}

int is_empty()
{
    return (count == 0) ? 1 : 0;
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

    rear = (rear + 1) % MAX_SIZE;
    cq[rear] = value;
    count++;
}

void dequeue()
{
    if(is_empty())
    {
        printf("Queue underflow!\n");
        return;
    }

    printf("%d deleted\n", cq[front]);
    front = (front + 1) % MAX_SIZE;
    count--;
}

void display()
{
    int duplicate_count = count;

    if(is_empty())
    {
        printf("No elements to display\n");
        return;
    }

    printf("The elements are :-\n");

    for(int i = front ; duplicate_count != 0 ; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", cq[i]);
        duplicate_count--;
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