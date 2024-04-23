#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// struct Node *f = NULL;
// struct Node *r = NULL;

void linkedlist_traversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int is_empty(struct Node *f, struct Node *r)
{
    if (f == NULL)
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

int is_full()
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {

        return 1;
    }
    else
    {
        printf("queue is not full\n");
        return 0;
    }
}

void enqueue(struct Node *f, struct Node *r, int value)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL)
    {
        printf("queue is full\n");
    }
    else
    {
        n->data = value;

        if (f == NULL)
        {
            f = r = n;
            n->next = NULL;
            // r->next = NULL;
        }
        else
        {
            r->next = n;
            n->next = NULL;
            r = n;
        }
    }

}

int dequeue(struct Node *f, struct Node *r)
{
    int val = -1;
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr = f;

    // if (is_empty(f, r))
    if (f == NULL)
    {
        printf("queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    struct Node *f;
    f = (struct Node *)malloc(sizeof(struct Node));
    struct Node *r;
    r = (struct Node *)malloc(sizeof(struct Node));


    f = r = NULL;

    linkedlist_traversal(f);

    printf("deque element is %d\n", dequeue(f, r));
    enqueue(f, r, 10);
    enqueue(f, r, 20);
    enqueue(f, r, 30);
    printf("deque element is %d\n", dequeue(f, r));
    return 0;
}