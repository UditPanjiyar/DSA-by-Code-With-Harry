#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void is_empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack is not empty\n");
    }
}

void is_full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack is full\n");
    }
    else
    {
        printf("stack is not full\n");
    }
}

void push(struct stack *ptr, int value)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow ! canot push %d to stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

void pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("stack under flow");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        printf("%d\n", value);
        ptr->top--;
    }
}

int peek(struct stack *ptr, int i)
{
    int position = ptr->top - i + 1;
    if (position < 0)
    {
        printf("invalid position");
        return 0;
    }
    else
    {
        return ptr->arr[position];
    }
}

void stack_top(struct stack *ptr)
{
    int top_value = ptr->arr[ptr->top];
    printf("top element is %d\n", top_value);
}

void stack_bottom(struct stack *ptr)
{
    printf("bottom element in stack is %d\n", ptr->arr[0]);
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 50;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("afetr push operation\n");
    push(s, 10); // 0
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    push(s, 70);
    push(s, 80);
    push(s, 90);
    push(s, 100);

    stack_top(s);
    stack_bottom(s);

    return 0;
}