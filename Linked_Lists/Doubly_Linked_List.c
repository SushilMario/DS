#include<stdio.h>
#include<stdlib.h>

typedef struct Order
{
    int amount;

    struct Order *previous;
    struct Order *next;
}Order;

Order *head, *tail;  

Order *searchOrder(int amount)
{
    if(head == NULL && tail == NULL)
    {
        return NULL;
    }

    Order *sptr = head;

    while(sptr != NULL)
    {
        if(sptr->amount == amount)
        {
            return sptr;
        }
        else
        {
            sptr = sptr->next;
        }
    }

    return sptr;
}

void printOrders()
{
    printf("\n");

    if(head == NULL && tail == NULL)
    {
        printf("The linked list is empty\n");

        return;
    }

    Order *pointer = head;

    while(pointer != NULL)
    {
        printf("Amount: Rs %d\n", pointer->amount);
        pointer = pointer->next;
    }
    
    printf("\n");
}

Order *createnewOrder(Order *previous, Order *next)
{
    Order *newOrder = (Order *)malloc(sizeof(Order));

    printf("Enter the order amount\n");
    scanf("%d", &newOrder->amount);

    newOrder->previous = previous;
    newOrder->next = next;

    return newOrder;
}

void insertAny(int pos, int amount)
{
    Order *newOrder;

    if(head == NULL && tail == NULL)
    {
        newOrder = createnewOrder(head, tail);

        head = newOrder;
        tail = newOrder;

        printf("First node created!\n");

        return;
    }

    Order *sptr = searchOrder(amount);

    if(sptr == NULL)
    {
        printf("No order with the given amount exists\n");

        return;
    }

    if(pos == 1)
    {
        newOrder = createnewOrder(sptr->previous, sptr);

        if(sptr == head)
        {
            sptr->previous = newOrder;

            head = newOrder;
        }

        else
        {
            sptr->previous->next = newOrder;
            sptr->previous = newOrder;
        }
    }

    else if(pos == 2)
    {
        newOrder = createnewOrder(sptr, sptr->next);

        if(sptr == tail)
        {
            sptr->next = newOrder;

            tail = newOrder;
        }

        else
        {
            sptr->next->previous = newOrder;
            sptr->next = newOrder;
        }
    }
}

void deleteAny(int amount)
{
    if(head == NULL)
    {
        printf("The linked list is empty!\n");

        return;
    }

    Order *sptr = searchOrder(amount);

    if(sptr == NULL)
    {
        printf("No order with the entered amount exists\n");

        return;
    }

    if(head == tail)
    {
        head = NULL;
        tail = NULL;
    }

    else if(sptr == head)
    {
        head = head->next;

        head->previous = NULL;
    }

    else if(sptr == tail)
    {
        tail = tail->previous;

        tail->next = NULL;
    }

    else 
    {
        sptr->previous->next = sptr->next;
        sptr->next->previous = sptr->previous;
    }

    free(sptr);
}

int main()
{
    head = NULL;

    int choice, loop = 1, pos, ref_amount;

    while(loop)
    {
        printf("Enter 1 to insert, 2 to delete, 3 to display, or 0 to exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("Enter 1 to insert before, or 2 to insert after a particular order\n");
                    scanf("%d", &pos);

                    printf("Enter the amount of the order you wish to insert before / after\n");
                    scanf("%d", &ref_amount);

                    insertAny(pos, ref_amount);
                     
                    break;

            case 2: printf("Enter the amount of the order you wish to delete\n");
                    scanf("%d", &ref_amount);

                    deleteAny(ref_amount);

                    break;

            case 3: printOrders();
                    break;

            default: printf("Exiting...\n");
                     loop = 0;
        }
    }  
}