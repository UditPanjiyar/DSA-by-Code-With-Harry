#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int is_empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char value)
{
    if (is_full(ptr) == 1)
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", value);
        // return 0;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        // return 1;
    }
}

char pop(struct stack *ptr)
{
    if (is_empty(ptr) == 1)
    {
        return 0;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

char stack_top(struct stack *ptr)
{
    char top_value = ptr->arr[ptr->top];
    return top_value;
}

int is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
        return 0;
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
        return 0;
}

char *infix_to_postfix(char *infix)
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));

    int a = strlen(infix);
    sp->size = a;
    // sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix;
    postfix = (char *)malloc((strlen(infix)) * sizeof(char));

    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stack_top(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                while (is_empty(sp) != 1)
                {
                    postfix[j] = pop(sp);
                    j++;
                }
            }
        }
    }
    while (is_empty(sp) != 1)
    {
        {
            postfix[j] = pop(sp);
            j++;
        }
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{

    char *expression = "x-y/z-k*d";
    // char *expression = "a+b/c+d*q";

    // char *expression = "a/b*c+r-q";
    // char *expression = "a+b/c*d-q";
    // char *expression = "a+b-c*d/z";
    // infix_to_postfix(expression);

    printf("postfix is %s", infix_to_postfix(expression));

    return 0;
}