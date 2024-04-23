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

    printf("%d\n", s->top);

    //  printf("the value at 1st position is %d\n", peek(s, 1));

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("the value at %d position is %d\n", j, peek(s, j));
    }

    return 0;
}