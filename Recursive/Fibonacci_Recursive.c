#include <stdio.h>
#include <stdlib.h>

void fib(int n1, int n2, int count)
{
    if(count)
    {
        int next = n1 + n2;
        printf("%d ", next);

        fib(n2, next, count-1);
    }
}

int main()
{
    int count;

    printf("Enter the count\n");
    scanf("%d", &count);

    if(count >= 0)
    {
        printf("0 ");
        if(count == 1)
        {
            exit(0);
        }

        printf("1 ");
        
        if(count == 2)
        {
            exit(0);
        }

        else
        {
            fib(0, 1, count-2);
        }
    }

    return 0;
}