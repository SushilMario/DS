#include<stdio.h>

int fact(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return (n * fact(n-1));
}

int main()
{
    int factorial = fact(6);
    printf("The factorial is %d\n",factorial);

    return 0;
}