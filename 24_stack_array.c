#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
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

void is_full_stack(struct stack *ptr)
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

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));

    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.ptr = (int *)malloc(s.size * sizeof(int));

    s->size = 1;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // pussing an element in stack manually
    s->arr[0] = 7;
    s->top++;

    is_empty_stack(s);
    is_full_stack(s);

    if (is_empty_stack(s) == 1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack is not empty\n");
    }

    return 0;
}
