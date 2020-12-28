#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 30

char stack[size];
int top = -1;

void push(int *top, char stack[], char ch)
{
    stack[++(*top)] = ch;
}
char pop(int *top, char stack[])
{
    return stack[(*top)--];
}

int priority(char op)
{
    if(op == '(')
    return -1;
    else if(op == '^')
    return 2;
    else if(op == '*' || op == '/' || op == '%')
    return 1;
    else
    return 0;
}

int isFull(int top)
{
    return (top == size-1) ? 1 : 0;
}

int isEmpty(int top)
{
    return (top == -1) ? 1 : 0;
}

void convert_to_post(char *ch)
{
    char x;
    int i = 0;

    printf("\nThe postfix expression is :- \n");

    while(*ch != '\0')
    {
        if(isalnum(*ch))
        {
            printf("%c ", *ch);
        }
        else if(*ch == '(')
        {
            push(&top, stack, *ch);
        }
        else if(*ch == ')')
        {
            while((x = pop(&top, stack)) != '(')
            {
                printf("%c ", x); 
            }
        }
        else
        {
            while((priority(stack[top]) >= priority(*ch)) && !isEmpty(top))
            {
                x = pop(&top, stack);
                printf("%c ", x); 
            }
            push(&top, stack, *ch);
        }
        ch++;
    }

    while(!isEmpty(top))
    {
        x = pop(&top, stack);
        printf("%c ", x);
    }

    printf("\n");
}

int main()
{
    char *ch = (char *)malloc(30);

    printf("Enter the expression\n");

    scanf("%s", ch);
    
    convert_to_post(ch);

    return 0;
}