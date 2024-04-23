#include <stdio.h>
#include <stdlib.h>

struct circular_Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int is_empty(struct circular_Queue *ptr)
{
    if (ptr->r = ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(struct circular_Queue *ptr)
{
    if (((ptr->r + 1) % ptr->size) == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circular_Queue *ptr, int value)
{
    if (is_full(ptr))
    {
        printf("This Queue is full\n");
    }
    else
    {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = value;
        printf("enqueued element is %d\n", value);
    }
}

int dequeue(struct circular_Queue *ptr)
{

    if (is_empty(ptr) == 1)
    {
        printf("queue underflow\n");
        return 0;
    }
    else
    {
        ptr->f = (ptr->f + 1) % ptr->size;
        int val = ptr->arr[ptr->f];
        return val;
    }
}

int main()
{
    struct circular_Queue *q;
    q = (struct circular_Queue *)malloc(sizeof(struct circular_Queue));

    q->size = 4;
    q->r = q->f = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    // enqueue(q, 1);

    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));

    // enqueue(q, 10);
    // enqueue(q, 20);
    // enqueue(q, 30);

    if (is_empty(q))
    {
        printf("queue is empty\n");
    }

    if (is_full(q))
    {
        printf("queue is full\n");
    }

    return 0;
}
