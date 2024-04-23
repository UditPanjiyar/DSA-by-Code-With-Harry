#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
void queue_traversal(struct queue * ptr)
{
    for (int i = ptr->f +1; i <= ptr->r; i++)
    {
        printf("%d ",ptr->arr[i]);
    }
    printf("\n");
    
}

int is_empty(struct queue *ptr)
{
    if (ptr->f == ptr->r)
    {
        // printf("queue is empty\n");
        return 1;
    }
    else
    {
        // printf("queue is not empty\n");
        return 0;
    }
}

int is_full(struct queue *ptr)
{
    if (ptr->r == ptr->size - 1)
    {
        // printf("queue is full\n");
        return 1;
    }
    else
    {
        // printf("queue is not full\n");
        return 0;
    }
}

void enqueue(struct queue *ptr, int value)
{
    if (is_full(ptr) == 1)
    {
        printf("queue overflow\n");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = value;
        printf("enqueued element is %d\n", value);
    }
}

int dequeue(struct queue *ptr)
{
    int a;
    if (is_empty(ptr) == 1)
    {
        printf("queue underflow\n");
        return -1;
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
        return a;
    }
}


int main()
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));

    q->size = 3;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    queue_traversal(q);

    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    queue_traversal(q);
    printf("Dequeuing element %d\n", dequeue(q));

    if (is_empty(q) == 1)
    {
        printf("queue is empty\n");
    }

    if (is_full(q) == 1)
    {
        printf("queue is full\n");
    }

    return 0;
}