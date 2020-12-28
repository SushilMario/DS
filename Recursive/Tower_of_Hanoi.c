#include<stdio.h>

void move(int n, char S, char T, char D)
{
    if(n == 1)
    {
        printf("Move %d from %c to %c\n",n,S,D);
        return;
    }

    move(n-1,S,D,T);

    printf("Move %d from %c to %c\n",n,S,D);

    move(n-1,T,S,D);

    return;
}

int main()
{
    move(3,'A','B','C');

    return 0;
}