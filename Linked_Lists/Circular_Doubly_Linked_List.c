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
    if(head == NULL) 
    {
        return NULL;
    }

    Order *pointer = head;

    while(pointer->next != head)
    {
        if(pointer->amount == amount)
        {
            return pointer;
        }
            
        else
        {
            pointer = pointer->next;
        }   
    }

    if(pointer->amount == amount)
    {
        return pointer;
    }

    else
    {
        return NULL;
    }
}

void printOrders()
{
    printf("\n");

    if(head == NULL) 
    {
        printf("The linked list is  empty\n");
    }

    else
    {
        Order *ptr; 
        ptr = head; 

        while(ptr->next != head)
        {
            printf("Amount: Rs %d\n", ptr->amount);
            ptr = ptr->next;    
        }

        printf("Amount: Rs %d\n", ptr->amount);
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
    Order *newOrder, *sptr;

    if(head == NULL && tail == NULL)
    {
        newOrder = createnewOrder(head, tail);

        newOrder->previous = newOrder;
        newOrder->next = newOrder;

        head = newOrder;
        tail = newOrder;

        printf("First node created!\n");

        return;
    }

    sptr = searchOrder(amount);

    if(sptr == NULL)
    {
        printf("Order with specified amount does not exist\n");
        return;
    }  

    if(pos == 1)
    {
        // if(head == tail)
        // {
        //     newOrder = createnewOrder(tail, head);

        //     head->previous = newOrder;
        //     head->next = newOrder;

        //     head = newOrder;
        // }

        // else
        // {
            newOrder = createnewOrder(sptr->previous, sptr);

            sptr->previous->next = newOrder;
            sptr->previous = newOrder;

            if(sptr == head)
            {
                head = newOrder;
            }
        // }
    }

    else if(pos == 2)
    {
        // if(head == tail)
        // {
        //     newOrder = createnewOrder(head, tail);

        //     head->previous = newOrder;
        //     head->next = newOrder;

        //     tail = newOrder;
        // }

        // else
        // {
            newOrder = createnewOrder(sptr, sptr->next);

            sptr->next->previous = newOrder;
            sptr->next = newOrder;

            if(sptr == tail)
            {
                tail = newOrder;
            }
        // }
    }
}

void deleteAny(int amount)
{
    if(head == NULL && tail == NULL)
    {
        printf("The linked list is empty\n");
        return; 
    }

    Order *sptr = searchOrder(amount);

    if(sptr == NULL)
    {
        printf("Order with specified amount does not exist\n");

        return;
    }

    if(head == tail)
    {
        head = NULL;
        tail = NULL;   

        free(sptr);

        return;
    }

    sptr->previous->next = sptr->next;
    sptr->next->previous = sptr->previous;

    if(sptr == head)
    {
        head = sptr->next;
    }

    else if(sptr == tail)
    {
        tail = sptr->previous;
    }

    free(sptr);
}

int main()
{
    head = NULL;
    tail = NULL;

    int choice, loop = 1, pos, ref_amount;

    while(loop)
    {
        printf("Enter 1 to insert, 2 to delete, or 0 to exit\n");
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