#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;          // here top is same as head in linkedlist
    struct Node *next; // that we are already aware
};

void linked_traversal(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int is_empty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int if_full(struct Node *top)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int value)
{

    if (if_full(top) == 1)
    {
        printf("stack overflow");
    }
    else
    {
        struct Node *ptr;
        ptr = (struct Node *)malloc(sizeof(struct Node));

        ptr->data = value;
        ptr->next = top;  // push = insert at first in linkedlist
        top = ptr;
        return top;
    }
}

struct Node *pop(struct Node *top)
{
    struct Node *ptr;
    if (is_empty(top) == 1)
    {
        printf("stack underflow");
    }
    else
    {
        ptr = top;      // pop = deletion at first in LL
        top = top->next;

        int x = ptr->data;
        printf("deleted/popped element is %d\n", x);

        free(ptr);
        return top;
    }
}

int peek(struct Node *top, int position)
{
    struct Node *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL) ; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stack_top(struct Node * top)
{
    printf("top element in stack is: %d\n",top->data);
}

int stack_bottom(struct Node *top)
{
    struct Node * p = top;
    while(p->next != NULL)
    {
        p = p->next;
    }
    printf("bottom element in stack is %d\n",p->data);
}
int main()
{
    struct Node *top;
    top = (struct Node *)malloc(sizeof(struct Node));

    top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    linked_traversal(top);

    // top = pop(top);
    // top = pop(top);
    // top = pop(top);
    // top = pop(top);
    // linked_traversal(top);

// for peek operation
    for (int i = 1; i <= 4; i++)
    {
        int p1 = peek(top, i);
        printf("%d\n", p1);
    }

    // stack_top(top);
    // stack_bottom(top);

    return 0;
}