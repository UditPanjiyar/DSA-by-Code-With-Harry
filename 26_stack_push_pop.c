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

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    is_empty(s);
    is_full(s);

    printf("afetr push operation\n");
    push(s, 10);
    is_empty(s);
    is_full(s);

    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    push(s, 70);
    push(s, 80);
    push(s, 90);
    push(s, 100); // pushed 10 values in stack
    is_empty(s);
    is_full(s);

    push(s, 500); // stack over flow


    printf("afetr pop operation\n");
    pop(s);

    is_empty(s);
    is_full(s);

    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    return 0;
}