#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
        if(amount > sptr->amount)
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

Order *createnewOrder(Order *previous, Order *next, int amount)
{
    Order *newOrder = (Order *)malloc(sizeof(Order));

    newOrder->amount = amount;

    newOrder->previous = previous;
    newOrder->next = next;

    return newOrder;
}

void insert()
{
    Order *newOrder, *sptr;
    int amount;

    printf("Enter the order amount\n");
    scanf("%d", &amount);

    if(head == NULL && tail == NULL)
    {
        newOrder = createnewOrder(head, tail, amount);

        head = newOrder;
        tail = newOrder;

        printf("First node created!\n");

        return;
    }

    if(amount < head->amount)
    {
        newOrder = createnewOrder(head->previous, head, amount);

        head->previous = newOrder;

        head = newOrder;

        return;
    }

    sptr = searchOrder(amount);

    if(sptr == NULL)
    {
        newOrder = createnewOrder(tail, tail->next, amount);

        tail->next = newOrder;
        tail = newOrder;

        return;
    }

    newOrder = createnewOrder(sptr, sptr->next, amount);

    if(head == tail)
    {
        tail->next = newOrder;
        tail = newOrder;

        return;
    }

    sptr->next->previous = newOrder;
    sptr->next = newOrder;
}

int main()
{
    head = NULL;

    int exit = 1;

    do
    {
        insert();

        printf("Enter 0 to exit\n");
        scanf("%d", &exit);

        if(exit == 0)
        {
            printOrders();
            break;
        }
    }while(1);
}