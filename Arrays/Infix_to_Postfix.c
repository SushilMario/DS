#include<stdio.h>
#include<ctype.h>
#define size 30

char stack[size], postfix[size];
double eval_stack[size];
int stack_top = -1, postfix_top = -1, eval_stack_top = -1;

void push(int *top, char stack[], char ch)
{
    stack[++(*top)] = ch;
}

void eval_push(int *top, double stack[], double num)
{
    stack[++(*top)] = num;
}

char pop(int *top, char stack[])
{
    return stack[(*top)--];
}

double eval_pop(int *top, double stack[])
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
            push(&postfix_top, postfix, *ch);
        }
        else if(*ch == '(')
        {
            push(&stack_top, stack, *ch);
        }
        else if(*ch == ')')
        {
            while((x = pop(&stack_top, stack)) != '(')
            {
                printf("%c ", x); 
                push(&postfix_top, postfix, x);
            }
        }
        else
        {
            while((priority(stack[stack_top]) >= priority(*ch)) && !isEmpty(stack_top))
            {
                x = pop(&stack_top, stack);
                printf("%c ", x); 
                push(&postfix_top, postfix, x);
            }
            push(&stack_top, stack, *ch);
        }
        ch++;
    }

    while(!isEmpty(stack_top))
    {
        x = pop(&stack_top, stack);
        printf("%c ", x);
        push(&postfix_top, postfix, x);
    }
}

double operate(char ch)
{
    double op1, op2;
    op2 = eval_pop(&eval_stack_top, eval_stack);
    op1 = eval_pop(&eval_stack_top, eval_stack);
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
            eval_push(&eval_stack_top, eval_stack, num);
        }
        else
        {
            eval_push(&eval_stack_top, eval_stack, operate(*ch));
        }
        ch++;
    }
    return eval_pop(&eval_stack_top, eval_stack);
}

int main()
{
    char *ch;

    printf("Enter the expression\n");

    scanf("%s", ch);

    convert_to_post(ch);

    printf("\nThe result is %lf\n",evaluate_post(postfix));

    return 0;
}