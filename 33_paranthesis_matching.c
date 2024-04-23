#include <stdio.h>
#include <stdlib.h>
# include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int is_empty_stack(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        // printf("stack is empty\n");
        return 1;
    }
    else
    {
        // printf("stack is not empty\n");
        return 0;
    }
}

int is_full_stack(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack is full\n");
        return 1;
    }
    else
    {
        printf("stack is not full\n");
        return 0;
    }
}

void push(struct stack *ptr, char value)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow ! canot push %c to stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if ( ptr->top== -1)
    {
        printf("stack under flow\n");
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        // printf("popped element is %c\n", value);
        ptr->top--;
        return value;
    }
}

int parenthesis_match(char *exp)
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));

    int a = strlen(exp);
    sp->size = a;
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (is_empty_stack(sp) == 1)
            {
                return 0;
                break;
                
            }
            else
            {
                pop(sp);
            }
        }
    }

    if (is_empty_stack(sp) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    // char *expression = "3(+(7*2*1)))";
    // char *expression = ")";
    // char *expression = "3(+(7*()4(2*1)))";
    char *expression = "3(+(7*(4(2*1)";

    if (parenthesis_match(expression) == 1)
    {
        printf("parenthesis is balanced in the expression\n");
    }
    else
    {
        printf("parenthesis is not balanced in the expression\n");
    }

    return 0;
}