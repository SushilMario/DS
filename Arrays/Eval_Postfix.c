#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size 30

double stack[size];
int stack_top = -1;

void push(int *top, double stack[], double num)
{
    stack[++(*top)] = num;
}

double pop(int *top, double stack[])
{
    return stack[(*top)--];
}

int isFull(int top)
{
    return (top == size-1) ? 1 : 0;
}

int isEmpty(int top)
{
    return (top == -1) ? 1 : 0;
}

double operate(char ch)
{
    double op1, op2;
    op2 = pop(&stack_top, stack);
    op1 = pop(&stack_top, stack);
    if(ch == '+')
    return op1 + op2;
    if(ch == '-')
    return op1 - op2;
    if(ch == '*')
    return op1 * op2;
    if(ch == '/')
    return op1 / op2;

    return op1 * op2;
}

double evaluate_post(char *ch)
{
    double num;
    while(*ch != '\0')
    {
        if(isdigit(*ch))
        {
            num = *ch - '0';
            push(&stack_top, stack, num);
        }
        else
        {
            push(&stack_top, stack, operate(*ch));
        }
        ch++;
    }
    return pop(&stack_top, stack);
}

int main()
{
    char *ch = (char *)malloc(30);

    printf("Enter the expression\n");

    scanf("%s", ch);

    printf("\nThe result is %lf\n",evaluate_post(ch));

    return 0;
}