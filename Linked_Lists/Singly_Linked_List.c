#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Order
{
    int amount;

    struct Order *next;
}Order;

Order *head;  

Order *searchOrder(int amount)
{
    if(head == NULL)
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

    if(head == NULL)
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

Order *createnewOrder(Order *next)
{
    Order *newOrder = (Order *)malloc(sizeof(Order));

    printf("Enter the order amount\n");
    scanf("%d", &newOrder->amount);

    newOrder->next = next;

    return newOrder;
}

void insertAny(int pos, int amount)
{
    Order *newOrder;

    if(head == NULL)
    {
        newOrder = createnewOrder(head);
        head = newOrder;

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
        newOrder = createnewOrder(sptr);

        if(sptr == head)
        {
            head = newOrder;
        }

        else
        {
            Order *before_sptr = head;

            while(before_sptr->next != sptr)
            {
                before_sptr = before_sptr->next;
            }

            before_sptr->next = newOrder;
        }
    }

    else if(pos == 2)
    {
        newOrder = createnewOrder(sptr->next);
        sptr->next = newOrder;
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

    if(sptr == head)
    {
        head = head->next;
    }

    else 
    {
        Order *before_sptr = head;

        while(before_sptr->next != sptr)
        {
            before_sptr = before_sptr->next;
        }

        before_sptr->next = sptr->next; 
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