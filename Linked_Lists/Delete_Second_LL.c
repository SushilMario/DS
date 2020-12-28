#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Order
{
    int amount;

    struct Order *next;
}Order;

Order *head, *newHead;  

Order *searchOrder(int amount)
{
    if(head == NULL)
    {
        return NULL;
    }

    Order *sptr = head;

    while(sptr != NULL)
    {
        if(sptr->next->amount == amount)
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

Order *returnLastOrder()
{
    Order *last_ptr;

    last_ptr = head;

    while(last_ptr->next != NULL)
    {
        last_ptr = last_ptr->next;
    }

    return last_ptr;
}

Order *createnewOrder(Order *next)
{
    Order *newOrder = (Order *)malloc(sizeof(Order));

    printf("Enter the order amount\n");
    scanf("%d", &newOrder->amount);

    newOrder->next = next;

    return newOrder;
}

void insert()
{
    Order *newOrder, *last_ptr;

    if(head == NULL)
    {
        newOrder = createnewOrder(head);
        head = newOrder;

        printf("First node created!\n");

        return;
    }

    newOrder = createnewOrder(NULL);

    last_ptr = returnLastOrder();

    last_ptr->next = newOrder;
}

void delete(Order *order)
{
    Order *before_order;

    before_order = searchOrder(order->amount);

    before_order -> next = order -> next;

    free(order);
}

int main()
{
    int count, track = 0;
    Order *delete_ptr;

    head = NULL;

    printf("Enter the number of elements\n");
    scanf("%d", &count);

    for(int i = 0; i < count; i++)
    {
        insert();
    }

    printf("The list is :-\n");

    printOrders();

    delete_ptr = head;

    while(delete_ptr != NULL)
    {
        if((track % 2 == 0) && (track != 0))
        {
            delete(delete_ptr);
        }

        track++;
        delete_ptr = delete_ptr -> next;
    }

    printf("The list is now :-\n");

    printOrders();
}