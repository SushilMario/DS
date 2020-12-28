#include<stdio.h>

int gcd(int a, int b)
{
    if(a == 0)
    return b;

    if(b == 0)
    return a;

    if(a == b)
    return a;

    if(a > b)
    return gcd(a - b, b);

    return gcd(a, b - a);
}

int main()
{
    int a, b;

    printf("Enter a\n");
    scanf("%d", &a);

    printf("Enter b\n");
    scanf("%d", &b);

    printf("Their GCD is %d\n", gcd(a, b));

    return 0;
}