#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int value;

    struct Node *previous;
    struct Node *next;
}Node;

Node *head, *tail;

Node * search(int value)
{
    Node *sptr = head;

    while(sptr != NULL)
    {
        if(value < sptr->value)
        {
            return sptr;
        }

        sptr = sptr->next;
    }

    return sptr;
}

void display()
{
    if(head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    Node *ptr = head;

    while(ptr != NULL)
    {
        printf("%d ", ptr->value);

        ptr = ptr->next;
    }

    printf("\n");
}

Node * create(int value, Node *previous, Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->value = value;
    newNode->previous = previous; 
    newNode->next = next; 

    return newNode;
}

void insert()
{
    int value;
    Node * newNode;

    printf("Enter the value\n");
    scanf("%d", &value);

    if(head == NULL && tail == NULL)
    {
        newNode = create(value, head, tail);
        head = newNode;
        tail = newNode;

        return;
    }

    if(value < head->value)
    {
        newNode = create(value, head->previous, head);

        head->previous = newNode;
        head = newNode;

        return;
    }

    Node *sptr = search(value);

    if(sptr == NULL)
    {
        newNode = create(value, tail, tail->next);

        tail->next = newNode;
        tail = newNode; 

        return;
    }

    newNode = create(value, sptr->previous, sptr);

    sptr->previous->next = newNode;
    sptr->previous = newNode;
}

int main()
{
    head = tail = NULL;

    int exit = 1;

    do
    {
        insert();

        printf("Enter 0 to exit\n");
        scanf("%d", &exit);

        if(exit == 0)
        {
            display();
            break;
        }
    }while(1);
}
